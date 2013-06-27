#ifndef ASSEMBLER_PARSER_H_INCLUDED
#define ASSEMBLER_PARSER_H_INCLUDED

#include <assembler/ast.h>
#include <assembler/compiler.h>

struct parser
{
  static ast::program &parse_file (char const *file);
  static ast::program &parse_string (std::string const &file);
  static bool fatal;
};

#endif /* ASSEMBLER_PARSER_H_INCLUDED */
