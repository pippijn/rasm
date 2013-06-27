#include <iostream>

struct deserialiser : visitors::serialisation_base
{
  deserialiser (rio::io::nbinreader &reader)
  : code (reader)
  {
  }

  jit::map<std::string, std::tr1::shared_ptr<ast::code> > read ()
  {
    jit::map<std::string, std::tr1::shared_ptr<ast::code> > functions;

    while (code.remain ())
      {
        optype type = read_type ();
        ensure (type, type == CHGFUNC);
        std::string const &func = read_string ();

        functions[func] = std::tr1::shared_ptr<ast::code> (read_code ().release ());
      }

    return functions;
  }

private:
  std::auto_ptr<ast::code> read_code ()
  {
    std::auto_ptr<ast::code> ast (new ast::code);

    uint16_t stmtc = read_u16 ();

    for (uint16_t i = 0; i < stmtc; i++)
      {
        optype type = read_type ();

        if (type == INSTRUCTION)
          ast->statements.push_back (std::tr1::shared_ptr<ast::instruction> (read_instruction ()));
        else if (type == ASSIGNMENT)
          ast->statements.push_back (std::tr1::shared_ptr<ast::assignment> (read_assignment ()));
        else
          die (type, "invalid statement type: %s", type_string (type));
      }

    return ast;
  }

  optype read_type ()
  {
    return type_for (read_u8 ());
  }

  ast::operand *read_operand ()
  {
    optype type = read_type ();
    switch (type)
      {
      case REG_R:    return new ast::reg_r (jit::reg_for (read_u8 ()));
      case REG_V:    return new ast::reg_v (jit::reg_for (read_u8 ()));
      case REG_FPR:  return new ast::reg_fpr (jit::freg_for (read_u8 ()));
      case REG_RET:  return new ast::reg_ret ();
      case REG_FP:   return new ast::reg_fp ();
      case REG_SP:   return new ast::reg_sp ();

      case IMM_INT:  return new ast::imm_int (read_s32 ());
      case IMM_FLT:  return new ast::imm_flt (read_f32 ());

      case INTVAR:   return new ast::intvar (read_string ());
      case ENTRY:    return new ast::entry (read_string ());
      case PTRVAR:   return new ast::ptrvar (read_string ());
      case FLTVAR:   return new ast::fltvar (read_string ());
      case COMPCALL: return new ast::compcall (jit::mnemonic_for (read_u16 ()));
      case FUNCTION: return new ast::function (read_string ());

      case INSTRUCTION: return read_instruction ();
      }
    die (type, "invalid type for operand: %s", type_string (type));
  }

  ast::variable *read_variable ()
  {
    optype type = read_type ();
    switch (type)
      {
      case INTVAR: return new ast::intvar (read_string ());
      case ENTRY:  return new ast::entry  (read_string ());
      case PTRVAR: return new ast::ptrvar (read_string ());
      case FLTVAR: return new ast::fltvar (read_string ());
      }
    die (type, "invalid type for variable: %s", type_string (type));
  }

  ast::instruction *read_instruction ()
  {
    uint8_t argc = read_u8 ();
    uint16_t opcode = read_u16 ();

    ast::operand *op1 = 0;
    ast::operand *op2 = 0;
    ast::operand *op3 = 0;

    if (argc >= 1) op1 = read_operand ();
    if (argc >= 2) op2 = read_operand ();
    if (argc >= 3) op3 = read_operand ();

    ast::mnemonic *mne = new ast::mnemonic (jit::mnemonic_for (opcode));

    return new ast::instruction (mne, op1, op2, op3);
  }

  ast::assignment *read_assignment ()
  {
    ast::operand *lhs = read_operand ();
    ast::variable *rhs = read_variable ();
    return new ast::assignment (lhs, rhs);
  }

  uint8_t read_u8 ()
  {
    uint8_t ui;
    code >> ui;
    return ui;
  }

  uint16_t read_u16 ()
  {
    uint16_t ui;
    code >> ui;
    return ui;
  }

  uint32_t read_u32 ()
  {
    uint32_t ui;
    code >> ui;
    return ui;
  }

  int8_t read_s8 ()
  {
    int8_t ui;
    code >> ui;
    return ui;
  }

  int16_t read_s16 ()
  {
    int16_t ui;
    code >> ui;
    return ui;
  }

  int32_t read_s32 ()
  {
    int32_t ui;
    code >> ui;
    return ui;
  }

  float read_f32 ()
  {
    float ui;
    code >> ui;
    return ui;
  }

  std::string read_string ()
  {
    std::string s;
    code >> s;
    return s;
  }

  rio::io::nbinreader &code;
};
