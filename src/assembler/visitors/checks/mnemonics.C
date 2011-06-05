#include <iostream>

#include <assembler/visitors.h>
#include <assembler/parser.h>

namespace visitors
{
  namespace checks
  {
    void
    mnemonics::visit (ast::instruction const &v)
    {
      v.mnemonic ().invite (*this);
      if (v.argc () >= 1) v.operand1 ().invite (*this);
      if (v.argc () >= 2) v.operand2 ().invite (*this);
      if (v.argc () >= 3) v.operand3 ().invite (*this);
    }
  
    void
    mnemonics::visit (ast::assignment const &v)
    {
      v.lhs ().invite (*this);
      v.rhs ().invite (*this);
    }
  
    void
    mnemonics::visit (ast::compcall const &v)
    {
      if (!jit::can (v.name ()))
        croak (v, "unknown instruction: %s", v.name ().c_str ());
    }

    void
    mnemonics::visit (ast::mnemonic const &v)
    {
      if (!jit::can (v.name ()))
        croak (v, "unknown instruction: %s", v.name ().c_str ());
    }
  }
}
