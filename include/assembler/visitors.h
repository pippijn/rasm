#ifndef ASSEMBLER_VISITORS_H_INCLUDED
#define ASSEMBLER_VISITORS_H_INCLUDED

#include <assembler/ast.h>
#include <rio/io/buffer.h>

namespace visitors
{
  struct serialisation_base
  {
    enum optype
    {
      CHGFUNC,
      INSTRUCTION,
      ASSIGNMENT,

      IMM_FLT,
      IMM_INT,

      REG_R,
      REG_V,
      REG_FPR,
      REG_SP,
      REG_FP,
      REG_RET,

      ENTRY,
      PTRVAR,
      INTVAR,
      FLTVAR,
      COMPCALL,
      FUNCTION,
    };

    static optype type_for (int type);
    static char const *type_string (optype type);

  protected:
    serialisation_base ()
    {
    }
  };

  namespace checks
  {
    struct mnemonics : ast::const_visitor
    {
      void visit (ast::instruction const &v);
      void visit (ast::assignment const &v);
      void visit (ast::mnemonic const &v);
      void visit (ast::compcall const &v);
    };
  }
}

#include <assembler/visitors/machine.h>
#include <assembler/visitors/rasm.h>
#include <assembler/visitors/serialiser.h>

#endif /* ASSEMBLER_VISITORS_H_INCLUDED */
