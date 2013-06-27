%{
#include <cstdio>
#include <cstdarg>
#include <cerrno>
#include <iostream>

#include <rio/exception.h>
#include <jit.h>
#include <assembler/parser.h>
#include <assembler/ast.h>

void yyerror (int state, rio::srcinf const &si, char const *msg);
void yyerror (char const *msg, int state);

static ast::program program;

#define yyerror(msg) yyerror (yystate, SRCINF, msg)

#define YYERROR_VERBOSE 1
#if !YYERROR_VERBOSE
# undef YYERROR_VERBOSE
#endif
#if defined (LARGE_FILE)
# define YYSTACK_ALLOC_MAXIMUM 32768
# define YYMAXDEPTH 400000
#endif
%}

%union {
  /* From lexer */
  long             integer;
  double           decimal;
  jit::reg32       reg;
  jit::freg32      freg;
  char const       *string;

  /* Parser-internal */
  ast::mnemonic    *mnemonic;
  ast::operand     *operand;
  ast::variable    *variable;
  ast::instruction *instruction;
  ast::statement   *statement;
  ast::code        *code;
}

%token            YYEOF       0 "end of file"
%token            EOL           "end of line"
%token <string>   MNEMONIC      "mnemonic"
%token <string>   TK_STRING     "string literal"

%token <integer>  IMM_INT       "immediate integer"
%token <decimal>  IMM_FLT       "immediate floating point number"
%token <reg>      REG_R         "R-register"
%token <reg>      REG_V         "V-register"
%token <freg>     REG_FPR       "floating point register"

%token            REG_FP        "frame pointer"
%token            REG_SP        "stack pointer"
%token            REG_RET       "return value register"

%token <string>   ENTRY         "function entry point"
%token <string>   PTRVAR        "pointer variable"
%token <string>   INTVAR        "integer variable"
%token <string>   FLTVAR        "floating point variable"
%token <string>   COMPCALL      "compile-time function call"
%token <string>   FUNCTION      "function reference"

%token <string>   CHGFUNC       "function switch"

%token            ASGN          "assignment"
%token            AND           "`and' operator"
%token            OR            "`or' operator"
%token            POW           "`power' operator"
%token            LSH           "`left shift' operator"
%token            RSH           "`right shift' operator"

%type <code>            code
%type <mnemonic>        mnemonic
%type <operand>         operand expression register
%type <instruction>     instruction
%type <variable>        variable
%type <statement>       assignment statement
%type <integer>         INTexpr INT_or_expr INT_xor_expr INT_and_expr INT_shift_expr INT_additive_expr INT_multiplicative_expr INT_pow_expr INT_value
%type <decimal>         FLTexpr FLT_additive_expr FLT_multiplicative_expr FLT_pow_expr FLT_value

%start program

%%

program:
          CHGFUNC code program                          { program.functions[$1].reset ($2); }
        |
        ;

code:
          code EOL                                      { $$ = $1; }
        | code statement EOL                            { $$ = $1; $$->statements.push_back (std::tr1::shared_ptr<ast::statement> ($2)); $$->func = &$2->func (); }
        |                                               { $$ = new ast::code; }
        ;

statement:
          instruction                                   { $$ = $1; }
        | assignment                                    { $$ = $1; }
        ;

assignment:
          instruction ASGN variable                     { $$ = new ast::assignment ($1, $3); }
        | operand ASGN variable                         { $$ = new ast::assignment (
                                                                 new ast::instruction (
                                                                   new ast::mnemonic ("assign_" + $1->type ()), $1
                                                                 ), $3
                                                               );
                                                        } // FIXME: HACK
        ;

variable:
          INTVAR                                        { $$ = new ast::intvar ($1); }
        | ENTRY                                         { $$ = new ast::entry ($1); }
        | PTRVAR                                        { $$ = new ast::ptrvar ($1); }
        | FLTVAR                                        { $$ = new ast::fltvar ($1); }
        ;

instruction:
          mnemonic                                      { $$ = new ast::instruction ($1); }
        | mnemonic operand                              { $$ = new ast::instruction ($1, $2); }
        | mnemonic operand ',' operand                  { $$ = new ast::instruction ($1, $2, $4); }
        | mnemonic operand ',' operand ',' operand      { $$ = new ast::instruction ($1, $2, $4, $6); }
        ;

operand:
          register                                      { $$ = $1; }
        | expression                                    { $$ = $1; }
        | variable                                      { $$ = $1; }
        | COMPCALL                                      { $$ = new ast::compcall ($1); }
        | FUNCTION                                      { $$ = new ast::function ($1); }
        ;

register:
          REG_R                                         { $$ = new ast::reg_r ($1); }
        | REG_V                                         { $$ = new ast::reg_v ($1); }
        | REG_FPR                                       { $$ = new ast::reg_fpr ($1); }
        | REG_RET                                       { $$ = new ast::reg_ret; }
        | REG_SP                                        { $$ = new ast::reg_sp; }
        | REG_FP                                        { $$ = new ast::reg_fp; }
        ;

mnemonic:
          MNEMONIC                                      { $$ = new ast::mnemonic ($1); }
        ;

expression:
          INTexpr                                       { $$ = new ast::imm_int ($1); }
        | FLTexpr                                       { $$ = new ast::imm_flt ($1); }
        ;

INTexpr:
          INT_or_expr                                   { $$ = $1; }
        ;

INT_or_expr:
          INT_xor_expr                                  { $$ = $1; }
        | INT_or_expr '|' INT_xor_expr                  { $$ = $1 | $3; }
        ;

INT_xor_expr:
          INT_and_expr                                  { $$ = $1; }
        | INT_xor_expr '^' INT_and_expr                 { $$ = $1 ^ $3; }
        ;

INT_and_expr:
          INT_shift_expr                                { $$ = $1; }
        | INT_and_expr '&' INT_shift_expr               { $$ = $1 & $3; }
        ;

INT_shift_expr:
          INT_additive_expr                             { $$ = $1; }
        | INT_shift_expr LSH INT_additive_expr          { $$ = $1 << $3; }
        | INT_shift_expr RSH INT_additive_expr          { $$ = $1 >> $3; }
        ;

INT_additive_expr:
          INT_multiplicative_expr                       { $$ = $1; }
        | INT_additive_expr '+' INT_multiplicative_expr { $$ = $1 + $3; }
        | INT_additive_expr '-' INT_multiplicative_expr { $$ = $1 - $3; }
        ;

INT_multiplicative_expr:
          INT_pow_expr                                  { $$ = $1; }
        | INT_multiplicative_expr '*' INT_pow_expr      { $$ = $1 * $3; }
        | INT_multiplicative_expr '/' INT_pow_expr      { $$ = $1 / $3; }
        | INT_multiplicative_expr '%' INT_pow_expr      { $$ = $1 % $3; }
        ;

INT_pow_expr:
          INT_value                                     { $$ = $1; }
        | INT_pow_expr POW INT_value                    { $$ = std::pow (double ($1), int ($3)); }
        ;

INT_value:
          IMM_INT                                       { $$ = $1; }
        | '+' INT_value                                 { $$ = $2; }
        | '-' INT_value                                 { $$ = -$2; }
        | '~' INT_value                                 { $$ = ~$2; }
        | '(' INT_or_expr ')'                           { $$ = $2; }
        ;


FLTexpr:
          FLT_additive_expr                             { $$ = $1; }
        ;

FLT_additive_expr:
          FLT_multiplicative_expr                       { $$ = $1; }
        | FLT_additive_expr '+' FLT_multiplicative_expr { $$ = $1 + $3; }
        | FLT_additive_expr '-' FLT_multiplicative_expr { $$ = $1 - $3; }
        ;

FLT_multiplicative_expr:
          FLT_pow_expr                                  { $$ = $1; }
        | FLT_multiplicative_expr '*' FLT_pow_expr      { $$ = $1 * $3; }
        | FLT_multiplicative_expr '/' FLT_pow_expr      { $$ = $1 / $3; }
        | FLT_multiplicative_expr '%' FLT_pow_expr      { $$ = std::fmod ($1, $3); }
        ;

FLT_pow_expr:
          FLT_value                                     { $$ = $1; }
        | FLT_pow_expr POW FLT_value                    { $$ = std::pow ($1, $3); }
        ;

FLT_value:
          IMM_FLT                                       { $$ = $1; }
        | '+' FLT_value                                 { $$ = $2; }
        | '-' FLT_value                                 { $$ = -$2; }
        | '(' FLT_additive_expr ')'                     { $$ = $2; }
        ;

%%

ast::program &
parser::parse_file (char const *file)
{
  lexer::scanfile (file);
  /*while (yylex ());*/
  yyparse ();
  lexer::cleanup ();

  return program;
}

ast::program &
parser::parse_string (std::string const &str)
{
  lexer::scanstring (str);
  /*while (yylex ());*/
  yyparse ();
  lexer::cleanup ();

  return program;
}

bool parser::fatal = true;
