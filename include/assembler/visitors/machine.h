#ifndef ASSEMBLER_VISITORS_MACHINE_H_INCLUDED
#define ASSEMBLER_VISITORS_MACHINE_H_INCLUDED

#include <memory>

#include <assembler/ast.h>
#include <vector>

namespace visitors
{
  struct machine : ast::const_visitor
  {
    void visit (ast::code const &v);
    DECL_CONSTVISIT;

    machine ();
    ~machine ();

    struct instruction;
    struct mstate;
    mstate *state;
    jit::map<std::string, std::vector<instruction> > functions;
  };

  std::ostream &operator << (std::ostream &os, machine::instruction const &insn);
}

#endif /* ASSEMBLER_VISITORS_MACHINE_H_INCLUDED */
