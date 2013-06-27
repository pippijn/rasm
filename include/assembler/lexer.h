#ifndef ASSEMBLER_LEXER_H_INCLUDED
#define ASSEMBLER_LEXER_H_INCLUDED

extern int yylex (void);

struct lexer
{
  static void scanfile (char const *file);
  static void scanstring (std::string const &file);
  static void cleanup ();
  static bool fatal;
  static bool verbose;

  static std::string const &function ();
  static std::string const &file ();
  static unsigned row ();
  static unsigned col ();
};

#endif /* ASSEMBLER_LEXER_H_INCLUDED */
