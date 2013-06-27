#include <jit.h>

#define _jit this->current

#if 1

// O1 = O2
void jit::movr_i (reg32 d, reg32 rs) { jit_movr_i (d, rs); }
void jit::movr_ui (reg32 d, reg32 rs) { jit_movr_ui (d, rs); }
void jit::movr_l (reg32 d, reg32 rs) { jit_movr_l (d, rs); }
void jit::movr_ul (reg32 d, reg32 rs) { jit_movr_ul (d, rs); }
void jit::movr_p (reg32 d, reg32 rs) { jit_movr_p (d, rs); }
void jit::movr_f (reg32 rd, reg32 rs) { jit_movr_f (rd, rs); }
void jit::movr_d (reg32 rd, reg32 rs) { jit_movr_d (rd, rs); }

// O1 = O2
void jit::movi_i (reg32 d, imm32 is) { jit_movi_i (d, is); }
void jit::movi_ui (reg32 d, imm32 is) { jit_movi_ui (d, is); }
void jit::movi_l (reg32 d, imm32 is) { jit_movi_l (d, is); }
void jit::movi_ul (reg32 d, imm32 is) { jit_movi_ul (d, is); }
jit::insn *jit::movi_p (reg32 d, insn *is) { return jit_movi_p (d, is); }
void jit::movi_f (reg32 rd, imm32 is) { jit_movi_f (rd, is); }
void jit::movi_d (reg32 rd, imm32 is) { jit_movi_d (rd, is); }

// O1 = O2 (Sign/Zero extension)
void jit::extr_c_ui (reg32 d, reg32 rs) { jit_extr_c_ui (d, rs); }
void jit::extr_s_ui (reg32 d, reg32 rs) { jit_extr_s_ui (d, rs); }
void jit::extr_c_i (reg32 d, reg32 rs) { jit_extr_c_i (d, rs); }
void jit::extr_s_i (reg32 d, reg32 rs) { jit_extr_s_i (d, rs); }

void jit::extr_c_ul (reg32 d, reg32 rs) { jit_extr_c_ul (d, rs); }
void jit::extr_s_ul (reg32 d, reg32 rs) { jit_extr_s_ul (d, rs); }
void jit::extr_i_ul (reg32 d, reg32 rs) { jit_extr_i_ul (d, rs); }
void jit::extr_c_l (reg32 d, reg32 rs) { jit_extr_c_l (d, rs); }
void jit::extr_s_l (reg32 d, reg32 rs) { jit_extr_s_l (d, rs); }
void jit::extr_i_l (reg32 d, reg32 rs) { jit_extr_i_l (d, rs); }

void jit::extr_c_s (reg32 d, reg32 rs) { jit_extr_c_s (d, rs); }
void jit::extr_c_us (reg32 d, reg32 rs) { jit_extr_c_us (d, rs); }
void jit::extr_uc_s (reg32 d, reg32 rs) { jit_extr_uc_s (d, rs); }
void jit::extr_uc_us (reg32 d, reg32 rs) { jit_extr_uc_us (d, rs); }
void jit::extr_uc_i (reg32 d, reg32 rs) { jit_extr_uc_i (d, rs); }
void jit::extr_uc_ui (reg32 d, reg32 rs) { jit_extr_uc_ui (d, rs); }
void jit::extr_us_i (reg32 d, reg32 rs) { jit_extr_us_i (d, rs); }
void jit::extr_us_ui (reg32 d, reg32 rs) { jit_extr_us_ui (d, rs); }
void jit::extr_uc_l (reg32 d, reg32 rs) { jit_extr_uc_l (d, rs); }
void jit::extr_uc_ul (reg32 d, reg32 rs) { jit_extr_uc_ul (d, rs); }
void jit::extr_us_l (reg32 d, reg32 rs) { jit_extr_us_l (d, rs); }
void jit::extr_us_ul (reg32 d, reg32 rs) { jit_extr_us_ul (d, rs); }
void jit::extr_ui_l (reg32 d, reg32 rs) { jit_extr_ui_l (d, rs); }
void jit::extr_ui_ul (reg32 d, reg32 rs) { jit_extr_ui_ul (d, rs); }

//void jit::extr_f_d (reg32 rs, reg32 rd) { jit_extr_f_d (rs, rd); }
//void jit::extr_d_f (reg32 rs, reg32 rd) { jit_extr_d_f (rs, rd); }
void jit::extr_i_f (reg32 rd, reg32 rs) { jit_extr_i_f (rd, rs); }
void jit::extr_i_d (reg32 rd, reg32 rs) { jit_extr_i_d (rd, rs); }

// O1 = round (O2)
void jit::roundr_f_i (reg32 rd, reg32 rs) { jit_roundr_f_i (rd, rs); }
void jit::roundr_d_i (reg32 rd, reg32 rs) { jit_roundr_d_i (rd, rs); }
void jit::roundr_f_l (reg32 rd, reg32 rs) { jit_roundr_f_l (rd, rs); }
void jit::roundr_d_l (reg32 rd, reg32 rs) { jit_roundr_d_l (rd, rs); }

// O1 = trunc (O2)
void jit::truncr_f_i (reg32 rd, reg32 rs) { jit_truncr_f_i (rd, rs); }
void jit::truncr_d_i (reg32 rd, reg32 rs) { jit_truncr_d_i (rd, rs); }
void jit::truncr_f_l (reg32 rd, reg32 rs) { jit_truncr_f_l (rd, rs); }
void jit::truncr_d_l (reg32 rd, reg32 rs) { jit_truncr_d_l (rd, rs); }

// O1 = floor (O2)
void jit::floorr_f_i (reg32 rd, reg32 rs) { jit_floorr_f_i (rd, rs); }
void jit::floorr_d_i (reg32 rd, reg32 rs) { jit_floorr_d_i (rd, rs); }
void jit::floorr_f_l (reg32 rd, reg32 rs) { jit_floorr_f_l (rd, rs); }
void jit::floorr_d_l (reg32 rd, reg32 rs) { jit_floorr_d_l (rd, rs); }

// O1 = ceil (O2)
void jit::ceilr_f_i (reg32 rd, reg32 rs) { jit_ceilr_f_i (rd, rs); }
void jit::ceilr_d_i (reg32 rd, reg32 rs) { jit_ceilr_d_i (rd, rs); }
void jit::ceilr_f_l (reg32 rd, reg32 rs) { jit_ceilr_f_l (rd, rs); }
void jit::ceilr_d_l (reg32 rd, reg32 rs) { jit_ceilr_d_l (rd, rs); }

#endif
