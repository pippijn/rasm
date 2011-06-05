#include <rio/exception.h>
#include <assembler/parser.h>

#include "parser.h"

static unsigned const yymaxstate = 739;
static unsigned const yymaxtoken = 400;

struct errtable
{
  struct state
  {
    bool i;
    char const *msg;
  } state[yymaxtoken];

  errtable &operator () (char const *m, unsigned c1 = -1, unsigned c2 = -1, unsigned c3 = -1)
  {
    if (c1 == -1)
      for (unsigned i = 0; i < yymaxtoken; i++)
        {
          state[i].i = true;
          state[i].msg = m;
        }
    else
      {
        state[c1].i = true;
        state[c1].msg = m;
        if (c2 != -1)
          {
            state[c2].i = true;
            state[c2].msg = m;
          }
        if (c3 != -1)
          {
            state[c3].i = true;
            state[c3].msg = m;
          }
      }
    return *this;
  }
} errtab[yymaxstate + 1];

bool
yyerror_init ()
{
#include "yymsg.h"
}

static bool yyerror_isinitialized = yyerror_init ();

static int errors;
extern int yychar;

void
yyerror (int state, rio::srcinf const &si, char const *msg)
{
  char sbuf[128];
#if 0
  if (std::strstr (msg, "stack"))
    return;
#endif
  if (errors++ > 10)
    die (parser, "too many errors, aborting");
  if ((!std::strncmp (msg, "syntax error", 12) || !std::strncmp (msg, "parse error", 11)) && (state >= 0 && state <= yymaxstate))
    if (errtab[state].state[yychar].i)
      msg = errtab[state].state[yychar].msg;
  if (0 && !std::strncmp (msg, "syntax error", 12) || !std::strncmp (msg, "parse error", 11))
    {
      std::sprintf (sbuf, "%s (%d;%d)", msg, state, yychar);
      msg = sbuf;
    }
  if (parser::fatal)
    throw parser_exception (si, "%s:%d:%d: %s (%d;%d)", lexer::file ().c_str (), lexer::row (), lexer::col (), msg, state, yychar);
  std::fprintf (stderr, "%s:%d:%d: %s (%d;%d)\n", lexer::file ().c_str (), lexer::row (), lexer::col (), msg, state, yychar);
}
