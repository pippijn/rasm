// O1 = O2
INSN (void, movr_i, (reg32 d, reg32 rs))
INSN (void, movr_ui, (reg32 d, reg32 rs))
INSN (void, movr_l, (reg32 d, reg32 rs))
INSN (void, movr_ul, (reg32 d, reg32 rs))
INSN (void, movr_p, (reg32 d, reg32 rs))
INSN (void, movr_f, (reg32 rd, reg32 rs))
INSN (void, movr_d, (reg32 rd, reg32 rs))

// O1 = O2
INSN (void, movi_i, (reg32 d, imm32 is))
INSN (void, movi_ui, (reg32 d, imm32 is))
INSN (void, movi_l, (reg32 d, imm32 is))
INSN (void, movi_ul, (reg32 d, imm32 is))
INSN (insn *, movi_p, (reg32 d, insn *rs))
INSN (void, movi_f, (reg32 rd, imm32 is))
INSN (void, movi_d, (reg32 rd, imm32 is))

// O1 = O2 (Sign/Zero extension)
INSN (void, extr_c_ui, (reg32 d, reg32 rs))
INSN (void, extr_s_ui, (reg32 d, reg32 rs))
INSN (void, extr_c_i, (reg32 d, reg32 rs))
INSN (void, extr_s_i, (reg32 d, reg32 rs))

INSN (void, extr_c_ul, (reg32 d, reg32 rs))
INSN (void, extr_s_ul, (reg32 d, reg32 rs))
INSN (void, extr_i_ul, (reg32 d, reg32 rs))
INSN (void, extr_c_l, (reg32 d, reg32 rs))
INSN (void, extr_s_l, (reg32 d, reg32 rs))
INSN (void, extr_i_l, (reg32 d, reg32 rs))

INSN (void, extr_c_s, (reg32 d, reg32 rs))
INSN (void, extr_c_us, (reg32 d, reg32 rs))
INSN (void, extr_uc_s, (reg32 d, reg32 rs))
INSN (void, extr_uc_us, (reg32 d, reg32 rs))
INSN (void, extr_uc_i, (reg32 d, reg32 rs))
INSN (void, extr_uc_ui, (reg32 d, reg32 rs))
INSN (void, extr_us_i, (reg32 d, reg32 rs))
INSN (void, extr_us_ui, (reg32 d, reg32 rs))
INSN (void, extr_uc_l, (reg32 d, reg32 rs))
INSN (void, extr_uc_ul, (reg32 d, reg32 rs))
INSN (void, extr_us_l, (reg32 d, reg32 rs))
INSN (void, extr_us_ul, (reg32 d, reg32 rs))
INSN (void, extr_ui_l, (reg32 d, reg32 rs))
INSN (void, extr_ui_ul, (reg32 d, reg32 rs))

INSN (void, extr_f_d, (reg32 rs, reg32 rd))
INSN (void, extr_d_f, (reg32 rs, reg32 rd))
INSN (void, extr_i_f, (reg32 rd, reg32 rs))
INSN (void, extr_i_d, (reg32 rd, reg32 rs))

// O1 = round (O2)
INSN (void, roundr_f_i, (reg32 rd, reg32 rs))
INSN (void, roundr_d_i, (reg32 rd, reg32 rs))
INSN (void, roundr_f_l, (reg32 rd, reg32 rs))
INSN (void, roundr_d_l, (reg32 rd, reg32 rs))

// O1 = trunc (O2)
INSN (void, truncr_f_i, (reg32 rd, reg32 rs))
INSN (void, truncr_d_i, (reg32 rd, reg32 rs))
INSN (void, truncr_f_l, (reg32 rd, reg32 rs))
INSN (void, truncr_d_l, (reg32 rd, reg32 rs))

// O1 = floor (O2)
INSN (void, floorr_f_i, (reg32 rd, reg32 rs))
INSN (void, floorr_d_i, (reg32 rd, reg32 rs))
INSN (void, floorr_f_l, (reg32 rd, reg32 rs))
INSN (void, floorr_d_l, (reg32 rd, reg32 rs))

// O1 = ceil (O2)
INSN (void, ceilr_f_i, (reg32 rd, reg32 rs))
INSN (void, ceilr_d_i, (reg32 rd, reg32 rs))
INSN (void, ceilr_f_l, (reg32 rd, reg32 rs))
INSN (void, ceilr_d_l, (reg32 rd, reg32 rs))
