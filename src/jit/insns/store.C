#include <jit.h>

#define _jit this->current

#if 1
// *O1 = O2
void jit::str_c (reg32 rd, reg32 rs) { jit_str_c (rd, rs); }
void jit::str_s (reg32 rd, reg32 rs) { jit_str_s (rd, rs); }
void jit::str_i (reg32 rd, reg32 rs) { jit_str_i (rd, rs); }
void jit::str_l (reg32 rd, reg32 rs) { jit_str_l (rd, rs); }
void jit::str_uc (reg32 rd, reg32 rs) { jit_str_uc (rd, rs); }
void jit::str_us (reg32 rd, reg32 rs) { jit_str_us (rd, rs); }
void jit::str_ui (reg32 rd, reg32 rs) { jit_str_ui (rd, rs); }
void jit::str_ul (reg32 rd, reg32 rs) { jit_str_ul (rd, rs); }
void jit::str_p (reg32 rd, reg32 rs) { jit_str_p (rd, rs); }
void jit::str_f (reg32 rd, reg32 rs) { jit_str_f (rd, rs); }
void jit::str_d (reg32 rd, reg32 rs) { jit_str_d (rd, rs); }

// *O1 = O2
void jit::sti_c (reg32 id, imm32 is) { jit_sti_c (id, is); }
void jit::sti_s (reg32 id, imm32 is) { jit_sti_s (id, is); }
void jit::sti_i (reg32 id, imm32 is) { jit_sti_i (id, is); }
void jit::sti_l (reg32 id, imm32 is) { jit_sti_l (id, is); }
void jit::sti_uc (reg32 id, imm32 is) { jit_sti_uc (id, is); }
void jit::sti_us (reg32 id, imm32 is) { jit_sti_us (id, is); }
void jit::sti_ui (reg32 id, imm32 is) { jit_sti_ui (id, is); }
void jit::sti_ul (reg32 id, imm32 is) { jit_sti_ul (id, is); }
void jit::sti_p (reg32 id, imm32 is) { jit_sti_p (id, is); }
void jit::sti_f (reg32 id, imm32 is) { jit_sti_f (id, is); }
void jit::sti_d (reg32 id, imm32 is) { jit_sti_d (id, is); }

// *(O1 + O2) = O3
void jit::stxr_c (reg32 d1, reg32 d2, reg32 rs) { jit_stxr_c (d1, d2, rs); }
void jit::stxr_s (reg32 d1, reg32 d2, reg32 rs) { jit_stxr_s (d1, d2, rs); }
void jit::stxr_i (reg32 d1, reg32 d2, reg32 rs) { jit_stxr_i (d1, d2, rs); }
void jit::stxr_l (reg32 d1, reg32 d2, reg32 rs) { jit_stxr_l (d1, d2, rs); }
void jit::stxr_uc (reg32 d1, reg32 d2, reg32 rs) { jit_stxr_uc (d1, d2, rs); }
void jit::stxr_us (reg32 d1, reg32 d2, reg32 rs) { jit_stxr_us (d1, d2, rs); }
void jit::stxr_ui (reg32 d1, reg32 d2, reg32 rs) { jit_stxr_ui (d1, d2, rs); }
void jit::stxr_ul (reg32 d1, reg32 d2, reg32 rs) { jit_stxr_ul (d1, d2, rs); }
void jit::stxr_p (reg32 d1, reg32 d2, reg32 rs) { jit_stxr_p (d1, d2, rs); }
void jit::stxr_f (reg32 d1, reg32 d2, reg32 rs) { jit_stxr_f (d1, d2, rs); }
void jit::stxr_d (reg32 d1, reg32 d2, reg32 rs) { jit_stxr_d (d1, d2, rs); }

// *(O1 + O2) = O3
void jit::stxi_c (reg32 id, reg32 rd, imm32 is) { jit_stxi_c (id, rd, is); }
void jit::stxi_s (reg32 id, reg32 rd, imm32 is) { jit_stxi_s (id, rd, is); }
void jit::stxi_i (reg32 id, reg32 rd, imm32 is) { jit_stxi_i (id, rd, is); }
void jit::stxi_l (reg32 id, reg32 rd, imm32 is) { jit_stxi_l (id, rd, is); }
void jit::stxi_uc (reg32 id, reg32 rd, imm32 is) { jit_stxi_uc (id, rd, is); }
void jit::stxi_us (reg32 id, reg32 rd, imm32 is) { jit_stxi_us (id, rd, is); }
void jit::stxi_ui (reg32 id, reg32 rd, imm32 is) { jit_stxi_ui (id, rd, is); }
void jit::stxi_ul (reg32 id, reg32 rd, imm32 is) { jit_stxi_ul (id, rd, is); }
void jit::stxi_p (reg32 id, reg32 rd, imm32 is) { jit_stxi_p (id, rd, is); }
void jit::stxi_f (reg32 id, reg32 rd, imm32 is) { jit_stxi_f (id, rd, is); }
void jit::stxi_d (reg32 id, reg32 rd, imm32 is) { jit_stxi_d (id, rd, is); }
#endif
