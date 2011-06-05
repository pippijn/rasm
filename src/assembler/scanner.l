%{ 
#include <cstdlib>
#include <cstring>
#include <vector>

#include <jit.h>
#include <rio/exception.h>
#include <rio/type_traits.h>
#include <assembler/parser.h>
#include <assembler/ast.h>
#include "parser.h"

static void lexwarning (rio::srcinf const &si, char const *msg, ...);
static void lexerror (rio::srcinf const &si, char const *msg, ...);

#define lexwarning(msg...)      lexwarning (SRCINF, msg)
#define lexerror(msg...)        lexerror (SRCINF, msg)

// Tracked integral
struct integral
{
  integral operator ++ (int)
  {
    integral tmp (*this);
    ++*this;
    return tmp;
  }

  integral &operator ++ ()
  {
    ++i;
    std::printf ("incrementing %p, new value: %d\n", this, i);
    return *this;
  }

  integral operator -- (int)
  {
    integral tmp (*this);
    --*this;
    return tmp;
  }

  integral &operator -- ()
  {
    --i;
    std::printf ("decrementing %p, new value: %d\n", this, i);
    return *this;
  }

  integral (int v = 0)
  : i (v)
  {
  }

  operator int () const
  {
    return i;
  }

  operator int & ()
  {
    return i;
  }

  int i;
};

struct delayint
{
  delayint &operator ++ ()
  {
    ++r;
    static char i = 0;
    if (!i)
      i = 1;
    else
      ++this->i;
    return *this;
  }

  template<typename T>
  typename rio::meta::type_if<delayint, rio::meta::is_integral<T>::value>::type &
  operator += (T v)
  {
    static T i = 0;
    this->r += v;
    this->i += i;
    i = v;
    return *this;
  }

  delayint (unsigned v = 0)
  : i (v), r (i)
  {
  }

  unsigned i;
  unsigned r;
};

static struct state
{
  struct file
  {
    std::string name;
    FILE *fh;
    delayint row;
    delayint col;
  } file;

  unsigned lines;
  unsigned mnemonics;
  unsigned integers;
  unsigned floats;
  struct comments
  {
    unsigned count;
    unsigned nesting;

    comments ()
    : count (0), nesting (1)
    {
    }
  } comments;
  struct expression
  {
    unsigned count;
    unsigned nesting;

    expression ()
    : count (0), nesting (1)
    {
    }
  } expr;
  struct string
  {
    unsigned count;
    std::string value;

    string ()
    : count (0)
    {
    }
  } string;
  struct function
  {
    unsigned count;
    std::string name;

    function ()
    : count (0)
    {
    }
  } function;
  unsigned registers;
  unsigned assignments;

  std::vector<struct file> files;

  state ()
  : mnemonics (0), integers (0), floats (0), registers (0), assignments (0)
  {
  }
} state;

%}

%option nounput

%x COMMENT
%x STRING

ws              [ \t]+
digit           [0-9]
hexdigit        [0-9a-fA-F]
octdigit        [0-7]
integer         -?(0x{hexdigit}+|0{octdigit}+|{digit}+)
float           [-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?
id              [a-zA-Z_][a-zA-Z0-9_]*
cppid           [a-zA-Z_][a-zA-Z0-9_:<>]*
nonws           [^ \t\n]+

%%

^#function{ws}{nonws}\n         {
                                  ++state.file.row;
                                  state.file.col = 1;
                                  char *file = std::strrchr (yytext, ' ') + 1;
                                  state.function.name.assign (file, std::strlen (file) - 1);
                                  yylval.string = state.function.name.c_str ();
                                  ++state.function.count;
                                  printf (">%s<\n", yylval.string);
                                  return CHGFUNC;
                                }

^#include{ws}{nonws}\n        {
                                  ++state.file.row;
                                  state.file.col = 1;
                                  char *file = std::strrchr (yytext, ' ') + 1;
                                  file[std::strlen (file) - 1] = '\0';
                                  lexer::scanfile (file);
                                }

(#|\/\/).*\n?                   { // Comments
                                  ++state.file.row;
                                  state.file.col = 1;
                                  ++state.comments.count;
                                  return EOL;
                                }

"("                             {
                                  ++state.expr.nesting;
                                  ++state.file.col;
                                  return *yytext;
                                }

")"                             {
                                  ++state.file.col;
                                  ++state.expr.count;
                                  if (--state.expr.nesting <= 0)
                                    {
                                      lexwarning ("found closing parenthesis without opening one");
                                    }
                                  return *yytext;
                                }

"*/"                            {
                                  lexwarning ("comment nesting error");
                                  state.file.col += 2;
                                }

"/*"                            {
                                  BEGIN (COMMENT);
                                  state.comments.nesting = 1;
                                  state.file.col += 2;
                                }

<COMMENT>"/*"                   {
                                  ++state.comments.nesting;
                                  state.file.col += 2;
                                }

<COMMENT>"*/"                   {
                                  state.file.col += 2;
                                  if (--state.comments.nesting <= 0)
                                    {
                                      BEGIN (INITIAL);
                                    }
                                  ++state.comments.count;
                                }

<COMMENT>([^*][^/])+            {
                                  state.file.col += std::strlen (yytext);
                                }

<COMMENT>.                      {
                                  ++state.file.col;
                                }

<COMMENT>\n                     {
                                  ++state.file.row;
                                  state.file.col = 1;
                                  return yytext[0];
                                }

<INITIAL>\"                     {
                                  ++state.file.col;
                                  BEGIN (STRING);
                                  state.string.value.clear ();
                                }

<STRING>\"                      {
                                  ++state.file.col;
                                  ++state.string.count;
                                  BEGIN (INITIAL);
                                  yylval.string = state.string.value.c_str ();
                                  return TK_STRING;
                                }

<STRING>\\.                     {
                                  state.file.col += 2;
                                  switch (yytext[1])
                                    {
                                    case '"': state.string.value += '"'; break;
                                    case 'n': state.string.value += '\n'; break;
                                    case 'r': state.string.value += '\r'; break;
                                    case 't': state.string.value += '\t'; break;
                                    case 'a': state.string.value += '\a'; break;
                                    case 'f': state.string.value += '\f'; break;
                                    case 'v': state.string.value += '\v'; break;
                                    case 'b': state.string.value += '\b'; break;
                                    case '0': state.string.value += '\0'; break;
                                    default: lexerror ("unknown escape sequence: '\\%c'", yytext[1]);
                                    }
                                }

<STRING>[^"\\]+|.               {
                                  std::size_t len = std::strlen (yytext); 
                                  state.file.col += len;
                                  state.string.value.append (yytext, yytext + len);
                                }

{integer}                       { // Integers
                                  errno = 0;
                                  yylval.integer = strtol (yytext, NULL, 0);
                                  if (errno == ERANGE)
                                    lexwarning ("integer out of range: %s\n", yytext);
                                  state.file.col += std::strlen (yytext);
                                  ++state.integers;
                                  return IMM_INT;
                                }

{float}                         { // Floating point
                                  errno = 0;
                                  yylval.decimal = strtod (yytext, NULL);
                                  if (errno == ERANGE)
                                    lexwarning ("floating point number out of range: %s\n", yytext);
                                  state.file.col += std::strlen (yytext);
                                  ++state.floats;
                                  return IMM_FLT;
                                }

^{id}                           { // Mnemonics
                                  state.file.col += std::strlen (yytext);
                                  yylval.string = yytext;
                                  ++state.mnemonics;
                                  return MNEMONIC;
                                }

^{ws}{id}                       { // Mnemonics prepended with whitespace
                                  state.file.col += std::strlen (yytext);
                                  // Find last whitespace character
                                  yylval.string = std::strrchr (yytext, ' ');
                                  if (yylval.string == NULL)
                                    yylval.string = std::strrchr (yytext, '\t');
                                  ++yylval.string;
                                  ++state.mnemonics;
                                  return MNEMONIC;
                                }

%(sp|fp|ret)                    { // Special pointers
                                  state.file.col += std::strlen (yytext);
                                  ++state.registers;
                                  switch (yytext[1])
                                    {
                                    case 's': return REG_SP;
                                    case 'f': return REG_FP;
                                    case 'r': return REG_RET;
                                    }
                                  lexwarning ("FATAL: unreachable code reached");
                                }

%[rv]{digit}+                   { // General purpose registers
                                  std::size_t length = std::strlen (yytext);
                                  state.file.col += length;
                                  if (length > 3)
                                    lexwarning ("invalid register: `%s'", yytext);
                                  ++state.registers;
                                  if (yytext[1] == 'r')
                                    {
                                      switch (yytext[2] - '0')
                                        {
                                        case 0: yylval.reg = jit::R0; break;
                                        case 1: yylval.reg = jit::R1; break;
                                        case 2: yylval.reg = jit::R2; break;
                                        default: lexwarning ("invalid R-register: `%s'", yytext);
                                        }
                                      return REG_R;
                                    }
                                  switch (yytext[2] - '0')
                                    {
                                    case 0: yylval.reg = jit::V0; break;
                                    case 1: yylval.reg = jit::V1; break;
                                    case 2: yylval.reg = jit::V2; break;
                                    default: lexwarning ("invalid V-register: `%s'", yytext);
                                    }
                                  return REG_V;
                                }

%fpr{digit}+                    { // Floating point registers
                                  std::size_t length = std::strlen (yytext);
                                  state.file.col += length;
                                  if (length > 5)
                                    lexwarning ("invalid floating point register: `%s'", yytext);
                                  ++state.registers;
                                  switch (yytext[4] - '0')
                                    {
                                    case 0: yylval.freg = jit::FPR0; break;
                                    case 1: yylval.freg = jit::FPR1; break;
                                    case 2: yylval.freg = jit::FPR2; break;
                                    case 3: yylval.freg = jit::FPR3; break;
                                    case 4: yylval.freg = jit::FPR4; break;
                                    case 5: yylval.freg = jit::FPR5; break;
                                    default: lexwarning ("invalid floating point register: `%s'", yytext);
                                    }
                                  return REG_FPR;
                                }

[\=$@&!]{id}                    {
                                  yylval.string = yytext + 1;
                                  switch (yytext[0])
                                    {
                                    case '=': return ENTRY;
                                    case '$': return INTVAR;
                                    case '@': return PTRVAR;
                                    case '&': return FLTVAR;
                                    case '!': return COMPCALL;
                                    }
                                }

\*{cppid}                       {
                                  yylval.string = yytext + 1;
                                  return FUNCTION;
                                }

\n                              { // Newlines
                                  ++state.file.row;
                                  state.file.col = 1;
                                  return EOL;
                                }

[|^%&/*+\-,]|~                  { // Single characters
                                  ++state.file.col;
                                  return *yytext;
                                }

"&&"                            {
                                  state.file.col += 2;
                                  return AND;
                                }

"||"                            {
                                  state.file.col += 2;
                                  return OR;
                                }

"<<"                            {
                                  state.file.col += 2;
                                  return LSH;
                                }

">>"                            {
                                  state.file.col += 2;
                                  return RSH;
                                }

"**"                            {
                                  state.file.col += 2;
                                  return POW;
                                }

"=>"                            { // Assignment
                                  state.file.col += 2;
                                  ++state.assignments;
                                  return ASGN;
                                }

{ws}                            { // Whitespace
                                  state.file.col += std::strlen (yytext);
                                }

.                               { // Everything else
                                  lexwarning ("stray `%c' in program", *yytext);
                                  ++state.file.col;
                                }

%%

int
yywrap(void)
{
  if (state.files.empty ())
    {
      if (lexer::verbose)
        {
          std::printf ("Lexical analysis summary:\n"
                       "%7u line%s\n"
                       "%7u mnemonic%s\n"
                       "%7u integer literal%s\n"
                       "%7u floating point literal%s\n"
                       "%7u comment%s\n"
                       "%7u string literal%s\n"
                       "%7u function switch%s\n"
                       "%7u expression%s\n"
                       "%7u register access%s\n"
                       "%7u variable assignment%s\n",
                       state.lines, state.lines == 1 ? "" : "s",
                       state.mnemonics, state.mnemonics == 1 ? "" : "s",
                       state.integers, state.integers == 1 ? "" : "s",
                       state.floats, state.floats == 1 ? "" : "s",
                       state.comments.count, state.comments.count == 1 ? "" : "s",
                       state.string.count, state.string.count == 1 ? "" : "s",
                       state.function.count, state.function.count == 1 ? "" : "s",
                       state.expr.count, state.expr.count == 1 ? "" : "s",
                       state.registers, state.registers == 1 ? "" : "es",
                       state.assignments, state.assignments == 1 ? "" : "s"
                       );
        }
      return 1;
    }

  /*std::printf ("leaving `%s'\n", state.file.name.c_str ());*/

  state.lines += state.file.row.r;
  state.file = state.files.back ();
  yyin = state.file.fh;
  state.files.pop_back ();

  /*std::printf ("entering `%s' again\n", state.file.name.c_str ());*/

  return 0;
}

static char const *
file()
{
  return lexer::file ().c_str ();
}

static unsigned
row()
{
  return state.file.row.r;
}

static unsigned
col()
{
  return state.file.col.r;
}

static bool
processing(char const *name)
{
  if (state.file.name == name)
    return true;

  std::vector<struct state::file>::const_iterator it = state.files.begin ();
  std::vector<struct state::file>::const_iterator et = state.files.end ();
  
  while (it != et)
    {
      if (it->name == name)
        return true;
      ++it;
    }
  return false;
}

void
lexer::scanfile (char const *name)
{
  if (processing (name))
    lexerror ("tried to include `%s' while processing it", name);

  FILE *fh = name[0] == '-' ? stdin : std::fopen (name, "r");

  if (fh == NULL)
    lexerror ("unable to open file `%s': %s", name, strerror (errno));

  if (state.file.fh != NULL)
    {
      /*std::printf ("leaving `%s'\n", state.file.name.c_str ());*/
      state.files.push_back (state.file);
    }

  state.file.name = name;
  state.file.fh   = yyin = fh;
  state.file.row  = 1;
  state.file.col  = 1;

  /*std::printf ("entering `%s'\n", state.file.name.c_str ());*/
}

void
lexer::scanstring (std::string const &str)
{
  state.file.name = "<string>";
  state.file.fh = stdin;
  state.file.row = 1;
  state.file.col  = 1;

  yy_scan_bytes (str.data (), str.length ());
}

void
lexer::cleanup ()
{
  yylex_destroy ();
  if (state.file.fh != stdin)
    std::fclose (state.file.fh);
  state.file.fh = NULL;
  state.file.name = "<unknown>";
  state.file.row = 0;
  state.file.col = 0;
}

std::string const &
lexer::function ()
{
  return state.function.name;
}

std::string const &
lexer::file ()
{
  return state.file.name;
}

unsigned
lexer::row ()
{
  return state.file.row.r;
}

unsigned
lexer::col ()
{
  return state.file.col.i;
}

bool lexer::fatal = true;
bool lexer::verbose = false;

#undef lexerror
#undef lexwarning

void
lexwarning(rio::srcinf const &si, char const *msg, ...)
{
  char buf[BUFSIZ];
  std::va_list ap;

  va_start (ap, msg);
  std::vsnprintf (buf, BUFSIZ - 1, msg, ap);
  va_end (ap);

  if (lexer::fatal)
    throw lexer_exception (si, "%s:%d:%d: %s", file (), row (), col (), buf);

  std::printf ("%s:%d:%d: %s\n", file (), row (), col (), buf);
}

void
lexerror(rio::srcinf const &si, char const *msg, ...)
{
  char buf[BUFSIZ];
  std::va_list ap;

  va_start (ap, msg);
  std::vsnprintf (buf, BUFSIZ - 1, msg, ap);
  va_end (ap);

  throw lexer_exception (si, "%s:%d:%d: %s", file (), row (), col (), buf);
}
