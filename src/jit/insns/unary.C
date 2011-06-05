#include <jit.h>

#define _jit this->current

#if 1
// O1 = -O2
void jit::negr_i (reg32 d, reg32 rs) { jit_negr_i (d, rs); }
void jit::negr_l (reg32 d, reg32 rs) { jit_negr_l (d, rs); }
//void jit::negr_f (reg32 rd, reg32 rs) { jit_negr_f (rd, rs); }
//void jit::negr_d (reg32 rd, reg32 rs) { jit_negr_d (rd, rs); }

// O1 = ~O2
//void jit::notr_c (reg32 d, reg32 rs) { jit_notr_c (d, rs); }
//void jit::notr_uc (reg32 d, reg32 rs) { jit_notr_uc (d, rs); }
//void jit::notr_s (reg32 d, reg32 rs) { jit_notr_s (d, rs); }
//void jit::notr_us (reg32 d, reg32 rs) { jit_notr_us (d, rs); }
void jit::notr_i (reg32 d, reg32 rs) { jit_notr_i (d, rs); }
void jit::notr_ui (reg32 d, reg32 rs) { jit_notr_ui (d, rs); }
void jit::notr_l (reg32 d, reg32 rs) { jit_notr_l (d, rs); }
void jit::notr_ul (reg32 d, reg32 rs) { jit_notr_ul (d, rs); }
#endif
