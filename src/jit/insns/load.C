#include <jit.h>

#define _jit this->current

#if 1
// O1 = *O2
void jit::ldr_c (reg32 rd, reg32 rs) { jit_ldr_c (rd, rs); }
void jit::ldr_s (reg32 rd, reg32 rs) { jit_ldr_s (rd, rs); }
void jit::ldr_i (reg32 rd, reg32 rs) { jit_ldr_i (rd, rs); }
void jit::ldr_l (reg32 rd, reg32 rs) { jit_ldr_l (rd, rs); }
void jit::ldr_uc (reg32 rd, reg32 rs) { jit_ldr_uc (rd, rs); }
void jit::ldr_us (reg32 rd, reg32 rs) { jit_ldr_us (rd, rs); }
void jit::ldr_ui (reg32 rd, reg32 rs) { jit_ldr_ui (rd, rs); }
void jit::ldr_ul (reg32 rd, reg32 rs) { jit_ldr_ul (rd, rs); }
void jit::ldr_p (reg32 rd, reg32 rs) { jit_ldr_p (rd, rs); }
void jit::ldr_f (reg32 rd, reg32 rs) { jit_ldr_f (rd, rs); }
void jit::ldr_d (reg32 rd, reg32 rs) { jit_ldr_d (rd, rs); }

// O1 = *O2
void jit::ldi_c (reg32 rd, imm32 is) { jit_ldi_c (rd, is); }
void jit::ldi_s (reg32 rd, imm32 is) { jit_ldi_s (rd, is); }
void jit::ldi_i (reg32 rd, imm32 is) { jit_ldi_i (rd, is); }
void jit::ldi_l (reg32 rd, imm32 is) { jit_ldi_l (rd, is); }
void jit::ldi_uc (reg32 rd, imm32 is) { jit_ldi_uc (rd, is); }
void jit::ldi_us (reg32 rd, imm32 is) { jit_ldi_us (rd, is); }
void jit::ldi_ui (reg32 rd, imm32 is) { jit_ldi_ui (rd, is); }
void jit::ldi_ul (reg32 rd, imm32 is) { jit_ldi_ul (rd, is); }
void jit::ldi_p (reg32 rd, imm32 is) { jit_ldi_p (rd, is); }
void jit::ldi_f (reg32 rd, imm32 is) { jit_ldi_f (rd, is); }
void jit::ldi_d (reg32 rd, imm32 is) { jit_ldi_d (rd, is); }

// O1 = *(O2 + O3)
void jit::ldxr_c (reg32 rd, reg32 s1, reg32 s2) { jit_ldxr_c (rd, s1, s2); }
void jit::ldxr_s (reg32 rd, reg32 s1, reg32 s2) { jit_ldxr_s (rd, s1, s2); }
void jit::ldxr_i (reg32 rd, reg32 s1, reg32 s2) { jit_ldxr_i (rd, s1, s2); }
void jit::ldxr_l (reg32 rd, reg32 s1, reg32 s2) { jit_ldxr_l (rd, s1, s2); }
void jit::ldxr_uc (reg32 rd, reg32 s1, reg32 s2) { jit_ldxr_uc (rd, s1, s2); }
void jit::ldxr_us (reg32 rd, reg32 s1, reg32 s2) { jit_ldxr_us (rd, s1, s2); }
void jit::ldxr_ui (reg32 rd, reg32 s1, reg32 s2) { jit_ldxr_ui (rd, s1, s2); }
void jit::ldxr_ul (reg32 rd, reg32 s1, reg32 s2) { jit_ldxr_ul (rd, s1, s2); }
void jit::ldxr_p (reg32 rd, reg32 s1, reg32 s2) { jit_ldxr_p (rd, s1, s2); }
void jit::ldxr_f (reg32 rd, reg32 s1, reg32 s2) { jit_ldxr_f (rd, s1, s2); }
void jit::ldxr_d (reg32 rd, reg32 s1, reg32 s2) { jit_ldxr_d (rd, s1, s2); }

// O1 = *(O2 + O3)
void jit::ldxi_c (reg32 rd, reg32 rs, imm32 is) { jit_ldxi_c (rd, rs, is); }
void jit::ldxi_s (reg32 rd, reg32 rs, imm32 is) { jit_ldxi_s (rd, rs, is); }
void jit::ldxi_i (reg32 rd, reg32 rs, imm32 is) { jit_ldxi_i (rd, rs, is); }
void jit::ldxi_l (reg32 rd, reg32 rs, imm32 is) { jit_ldxi_l (rd, rs, is); }
void jit::ldxi_uc (reg32 rd, reg32 rs, imm32 is) { jit_ldxi_uc (rd, rs, is); }
void jit::ldxi_us (reg32 rd, reg32 rs, imm32 is) { jit_ldxi_us (rd, rs, is); }
void jit::ldxi_ui (reg32 rd, reg32 rs, imm32 is) { jit_ldxi_ui (rd, rs, is); }
void jit::ldxi_ul (reg32 rd, reg32 rs, imm32 is) { jit_ldxi_ul (rd, rs, is); }
void jit::ldxi_p (reg32 rd, reg32 rs, imm32 is) { jit_ldxi_p (rd, rs, is); }
void jit::ldxi_f (reg32 rd, reg32 rs, imm32 is) { jit_ldxi_f (rd, rs, is); }
void jit::ldxi_d (reg32 rd, reg32 rs, imm32 is) { jit_ldxi_d (rd, rs, is); }
#endif
