INSN (void, prepare_i, (imm32 ni))
INSN (void, prepare_f, (imm32 nf))
INSN (void, prepare_d, (imm32 nd))

INSN (void, pusharg_c, (reg32 rs))
INSN (void, pusharg_s, (reg32 rs))
INSN (void, pusharg_uc, (reg32 rs))
INSN (void, pusharg_us, (reg32 rs))
INSN (void, pusharg_ui, (reg32 rs))
INSN (void, pusharg_ul, (reg32 rs))
INSN (void, pusharg_l, (reg32 rs))
INSN (void, pusharg_i, (reg32 rs))
INSN (void, pusharg_p, (reg32 rs))
INSN (void, pusharg_f, (reg32 rs))
INSN (void, pusharg_d, (reg32 rs))

INSN (void, getarg_c, (reg32 reg, imm32 ofs))
INSN (void, getarg_i, (reg32 reg, imm32 ofs))
INSN (void, getarg_l, (reg32 reg, imm32 ofs))
INSN (void, getarg_p, (reg32 reg, imm32 ofs))
INSN (void, getarg_s, (reg32 reg, imm32 ofs))
INSN (void, getarg_uc, (reg32 reg, imm32 ofs))
INSN (void, getarg_ui, (reg32 reg, imm32 ofs))
INSN (void, getarg_ul, (reg32 reg, imm32 ofs))
INSN (void, getarg_us, (reg32 reg, imm32 ofs))
INSN (void, getarg_f, (reg32 reg, imm32 ofs))
INSN (void, getarg_d, (reg32 reg, imm32 ofs))

INSN (imm32, arg_c, ())
INSN (imm32, arg_uc, ())
INSN (imm32, arg_s, ())
INSN (imm32, arg_us, ())
INSN (imm32, arg_i, ())
INSN (imm32, arg_ui, ())
INSN (imm32, arg_l, ())
INSN (imm32, arg_ul, ())
INSN (imm32, arg_p, ())
INSN (imm32, arg_f, ())
INSN (imm32, arg_d, ())

INSN (void, retval_ui, (reg32 rd))
INSN (void, retval_uc, (reg32 rd))
INSN (void, retval_us, (reg32 rd))
INSN (void, retval_ul, (reg32 rd))
INSN (void, retval_i, (reg32 rd))
INSN (void, retval_l, (reg32 rd))
INSN (void, retval_p, (reg32 rd))
INSN (void, retval_c, (reg32 rd))
INSN (void, retval_s, (reg32 rd))
INSN (void, retval_f, (reg32 rs))
INSN (void, retval_d, (reg32 rs))
