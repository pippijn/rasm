#ifndef ASSEMBLER_COMPILER_H_INCLUDED
#define ASSEMBLER_COMPILER_H_INCLUDED

#include <assembler.h>

struct compiler
{
  void compile_file (char const *file);
  void compile_string (std::string const &str);
  void check ();
  void print (std::ostream &os);
  void assemble (assembler &as);

  std::string store ();
  void load (std::string const &codestr);

  static void croak (rio::srcinf const &si, ast::node const &v, char const *fmt, ...);

private:
  void take (ast::program &prog);

  ast::program program;
};

#define croak(inviter, msg...) ::compiler::croak (SRCINF, inviter, msg)

#endif /* ASSEMBLER_COMPILER_H_INCLUDED */
