#ifndef OPERAND_H_INCLUDED
#define OPERAND_H_INCLUDED

struct operand
{
  union value
  {
    imm32 imm;
    reg32 reg;
    std::string const *str;
    insn *ins;

    value (void *v)              : ins (static_cast<insn *> (v)) { }
    value (insn *v)              : ins (v) { }
    value (imm32 v)              : imm (v) { }
    value (reg32 v)              : reg (v) { }
    value (std::string const *v) : str (new string (v)) { }
  } u;

  enum otype
  {
    IMM,
    REG,
    STR,
    INS
  } type;

  operand (void *v)              : u (v), type (INS) { }
  operand (insn *v)              : u (v), type (INS) { }
  operand (imm32 v)              : u (v), type (IMM) { }
  operand (reg32 v)              : u (v), type (REG) { }
  operand (std::string const &v) : u (v), type (STR) { }

  ~operand ()
  {
    if (type == STR)
      delete u.str;
  }

  insn *ins ()
  {
    type_check (SRCINF, INS);
    return u.ins;
  }

  imm32 imm ()
  {
    type_check (SRCINF, IMM);
    return u.imm;
  }

  reg32 reg ()
  {
    type_check (SRCINF, REG);
    return u.reg;
  }

  std::string const &str ()
  {
    type_check (SRCINF, STR);
    return *u.str;
  }

  static char const *type_string (otype t)
  {
    switch (t)
      {
      case IMM: return "immediate";
      case REG: return "register";
      case STR: return "string operand";
      case INS: return "instruction pointer";
      }
    die (type, "got invalid type");
  }

  void type_check (rio::srcinf const &si, otype t)
  {
    if (type != t)
      throw type_exception (si, "%s operand expected, got %s", type_string (t), type_string (type));
  }
};

#endif /* OPERAND_H_INCLUDED */
