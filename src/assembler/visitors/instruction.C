#include <ostream>

#include "instruction.h"

namespace visitors
{
  char const *
  machine::instruction::operand::type_string (otype type)
  {
    switch (type)
      {
      case instruction::operand::NONE:       return "<invalid>";
      case instruction::operand::IVARIABLE:  return "integer variable";
      case instruction::operand::FVARIABLE:  return "floating point variable";
      case instruction::operand::ENTRY:      return "function entry point";
      case instruction::operand::PVARIABLE:  return "label reference";
      case instruction::operand::FUNCTION:   return "non-local jump";
      case instruction::operand::COMPCALL:   return "internal call";
      case instruction::operand::REG_R:      return "R-register";
      case instruction::operand::REG_V:      return "V-register";
      case instruction::operand::REG_FPR:    return "floating point register";
      case instruction::operand::REG_RET:    return "return value register";
      case instruction::operand::REG_FP:     return "frame pointer";
      case instruction::operand::IIMMEDIATE: return "immediate integer";
      case instruction::operand::FIMMEDIATE: return "immediate floating point number";
      }
    die (type, "impossible type detected");
  }

  static std::ostream &
  operator << (std::ostream &os, machine::instruction::operand const &op)
  {
    os << '(';
    if (op.is_string ())
      os << op.string ();
    else if (op.is_integral ())
      os << op.integer ();
    else
      os << op.decimal ();
    os << ": " << op.type_string (op.type ()) << ')';
    return os;
  }

  std::ostream &
  operator << (std::ostream &os, machine::instruction const &insn)
  {
    os << "Mnemonic: " << insn.mnemonic ();
    if (insn.ret.type   () != machine::instruction::operand::NONE) os << "\n ret = "   << insn.ret;
    if (insn.op[0].type () != machine::instruction::operand::NONE) os << "\n op[0] = " << insn.op[0];
    if (insn.op[1].type () != machine::instruction::operand::NONE) os << "\n op[1] = " << insn.op[1];
    if (insn.op[2].type () != machine::instruction::operand::NONE) os << "\n op[2] = " << insn.op[2];
    return os << '\n';
  }

  machine::instruction::operand::operand (std::string const &v, otype t)
  : str (v), imm (0), dec (0), typ (t)
  {
  }

  machine::instruction::operand::operand (long v, otype t)
  : str ("<invalid>"), imm (v), dec (0), typ (t)
  {
  }
  
  machine::instruction::operand::operand ()
  : str ("<invalid>"), imm (0), dec (0), typ (NONE)
  {
  }
  
  void
  machine::instruction::operand::operator () (std::string const &v, otype t)
  {
    imm = 0;
    dec = 0.0;
    str = v;
    typ = t;
  }
  
  void
  machine::instruction::operand::operator () (long v, otype t)
  {
    imm = v;
    dec = 0.0;
    str = "<invalid>";
    typ = t;
  }
  
  void
  machine::instruction::operand::reset ()
  {
    imm = 0;
    dec = 0.0;
    str = "<invalid>";
    typ = NONE;
  }
  
  bool
  machine::instruction::operand::is_string () const
  {
    return typ == IVARIABLE
        || typ == FVARIABLE
        || typ == ENTRY
        || typ == PVARIABLE
        || typ == FUNCTION
        || typ == COMPCALL
        || typ == MNEMONIC
        ;
  }

  bool
  machine::instruction::operand::is_integral () const
  {
    return !is_string ()
        && typ != FIMMEDIATE
        ;
  }

  void
  machine::instruction::operand::type_check (otype t) const
  {
    if (t != type ())
      die (type, "expected `%s' but got `%s'", type_string (t), type_string (type ()));
  }
}
