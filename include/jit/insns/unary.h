// O1 = -O2
INSN (void, negr_i, (reg32 d, reg32 rs))
INSN (void, negr_l, (reg32 d, reg32 rs))
INSN (void, negr_f, (reg32 rd, reg32 rs))
INSN (void, negr_d, (reg32 rd, reg32 rs))

// O1 = ~O2
INSN (void, notr_c, (reg32 d, reg32 rs))
INSN (void, notr_uc, (reg32 d, reg32 rs))
INSN (void, notr_s, (reg32 d, reg32 rs))
INSN (void, notr_us, (reg32 d, reg32 rs))
INSN (void, notr_i, (reg32 d, reg32 rs))
INSN (void, notr_ui, (reg32 d, reg32 rs))
INSN (void, notr_l, (reg32 d, reg32 rs))
INSN (void, notr_ul, (reg32 d, reg32 rs))
