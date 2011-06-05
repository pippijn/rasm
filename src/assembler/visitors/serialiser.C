#include <assembler/visitors.h>

namespace visitors
{
  void
  serialiser::visit (ast::code const &v)
  {
    code << uint8_t (CHGFUNC) << *v.func << uint16_t (v.statements.size ());
    std::vector<std::tr1::shared_ptr<ast::statement> >::const_iterator it = v.statements.begin ();
    std::vector<std::tr1::shared_ptr<ast::statement> >::const_iterator et = v.statements.end ();

    while (it != et)
      {
        (*it)->invite (*this);
        ++it;
      }
  }

  void
  serialiser::visit (ast::instruction const &v)
  {
    code << uint8_t (INSTRUCTION);
    code << uint8_t (v.argc ());
    v.mnemonic ().invite (*this);
    if (v.argc () >= 1) v.operand1 ().invite (*this);
    if (v.argc () >= 2) v.operand2 ().invite (*this);
    if (v.argc () >= 3) v.operand3 ().invite (*this);
  }

  void
  serialiser::visit (ast::assignment const &v)
  {
    code << uint8_t (ASSIGNMENT);
    v.lhs ().invite (*this);
    v.rhs ().invite (*this);
  }

  void
  serialiser::visit (ast::imm_flt const &v)
  {
    code << uint8_t (IMM_FLT);
    code << float (v.value ());
  }

  void
  serialiser::visit (ast::imm_int const &v)
  {
    code << uint8_t (IMM_INT);
    code << int32_t (v.value ());
  }

  void
  serialiser::visit (ast::reg_r const &v)
  {
    code << uint8_t (REG_R);
    code << uint8_t (v.value ());
  }

  void
  serialiser::visit (ast::reg_v const &v)
  {
    code << uint8_t (REG_V);
    code << uint8_t (v.value ());
  }

  void
  serialiser::visit (ast::reg_fpr const &v)
  {
    code << uint8_t (REG_FPR);
    code << uint8_t (v.value ());
  }

  void
  serialiser::visit (ast::reg_sp const &v)
  {
    code << uint8_t (REG_SP);
  }

  void
  serialiser::visit (ast::reg_fp const &v)
  {
    code << uint8_t (REG_FP);
  }

  void
  serialiser::visit (ast::reg_ret const &v)
  {
    code << uint8_t (REG_RET);
  }

  void
  serialiser::visit (ast::mnemonic const &v)
  {
    code << uint16_t (jit::opcode (v.name ()));
  }

  void
  serialiser::visit (ast::entry const &v)
  {
    code << uint8_t (ENTRY);
    code << v.name ();
  }

  void
  serialiser::visit (ast::ptrvar const &v)
  {
    code << uint8_t (PTRVAR);
    code << v.name ();
  }

  void
  serialiser::visit (ast::intvar const &v)
  {
    code << uint8_t (INTVAR);
    code << v.name ();
  }

  void
  serialiser::visit (ast::fltvar const &v)
  {
    code << uint8_t (FLTVAR);
    code << v.name ();
  }

  void
  serialiser::visit (ast::compcall const &v)
  {
    code << uint8_t (COMPCALL);
    code << jit::opcode (v.name ());
  }

  void
  serialiser::visit (ast::function const &v)
  {
    code << uint8_t (FUNCTION);
    code << v.name ();
  }

  std::string
  serialiser::get ()
  {
    return code;
  }

  serialisation_base::optype
  serialisation_base::type_for (int type)
  {
    switch (optype (type))
      {
      case INSTRUCTION: return INSTRUCTION;
      case ASSIGNMENT:  return ASSIGNMENT;

      case IMM_FLT:     return IMM_FLT;
      case IMM_INT:     return IMM_INT;

      case REG_R:       return REG_R;
      case REG_V:       return REG_V;
      case REG_FPR:     return REG_FPR;
      case REG_SP:      return REG_SP;
      case REG_FP:      return REG_FP;
      case REG_RET:     return REG_RET;

      case ENTRY:       return ENTRY;
      case PTRVAR:      return PTRVAR;
      case INTVAR:      return INTVAR;
      case FLTVAR:      return FLTVAR;
      case COMPCALL:    return COMPCALL;
      case FUNCTION:    return FUNCTION;
      }
    die (type, "got invalid operand type: %d", type);
  }

  char const *
  serialisation_base::type_string (optype type)
  {
    switch (optype (type))
      {
      case INSTRUCTION: return "instruction";
      case ASSIGNMENT:  return "assignment";

      case IMM_FLT:     return "immediate floating point number";
      case IMM_INT:     return "immediate integer";

      case REG_R:       return "R-register";
      case REG_V:       return "V-register";
      case REG_FPR:     return "floating point register";
      case REG_SP:      return "stack pointer";
      case REG_FP:      return "frame pointer";
      case REG_RET:     return "return value register";

      case ENTRY:       return "function entry point";
      case PTRVAR:      return "pointer variable";
      case INTVAR:      return "integer variable";
      case FLTVAR:      return "floating point variable";
      case COMPCALL:    return "compile-time function call";
      case FUNCTION:    return "function reference";
      }
    die (type, "got invalid operand type: %d", type);
  }
}
