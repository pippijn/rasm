#include <jit.h>

#define _jit this->current

#if 1
void jit::prepare_i (imm32 ni) { jit_prepare_i (ni); }
void jit::prepare_f (imm32 nf) { jit_prepare_f (nf); }
void jit::prepare_d (imm32 nd) { jit_prepare_d (nd); }

void jit::pusharg_c (reg32 rs) { jit_pusharg_c (rs); }
void jit::pusharg_s (reg32 rs) { jit_pusharg_s (rs); }
void jit::pusharg_uc (reg32 rs) { jit_pusharg_uc (rs); }
void jit::pusharg_us (reg32 rs) { jit_pusharg_us (rs); }
void jit::pusharg_ui (reg32 rs) { jit_pusharg_ui (rs); }
void jit::pusharg_ul (reg32 rs) { jit_pusharg_ul (rs); }
void jit::pusharg_l (reg32 rs) { jit_pusharg_l (rs); }
void jit::pusharg_i (reg32 rs) { jit_pusharg_i (rs); }
void jit::pusharg_p (reg32 rs) { jit_pusharg_p (rs); }
void jit::pusharg_f (reg32 rs) { jit_pusharg_f (rs); }
void jit::pusharg_d (reg32 rs) { jit_pusharg_d (rs); }

void jit::getarg_c (reg32 reg, imm32 ofs) { jit_getarg_c (reg, ofs); }
void jit::getarg_i (reg32 reg, imm32 ofs) { jit_getarg_i (reg, ofs); }
void jit::getarg_l (reg32 reg, imm32 ofs) { jit_getarg_l (reg, ofs); }
void jit::getarg_p (reg32 reg, imm32 ofs) { jit_getarg_p (reg, ofs); }
void jit::getarg_s (reg32 reg, imm32 ofs) { jit_getarg_s (reg, ofs); }
void jit::getarg_uc (reg32 reg, imm32 ofs) { jit_getarg_uc (reg, ofs); }
void jit::getarg_ui (reg32 reg, imm32 ofs) { jit_getarg_ui (reg, ofs); }
void jit::getarg_ul (reg32 reg, imm32 ofs) { jit_getarg_ul (reg, ofs); }
void jit::getarg_us (reg32 reg, imm32 ofs) { jit_getarg_us (reg, ofs); }
void jit::getarg_f (reg32 reg, imm32 ofs) { jit_getarg_f (reg, ofs); }
void jit::getarg_d (reg32 reg, imm32 ofs) { jit_getarg_d (reg, ofs); }

jit::imm32 jit::arg_c () { return jit_arg_c (); }
jit::imm32 jit::arg_uc () { return jit_arg_uc (); }
jit::imm32 jit::arg_s () { return jit_arg_s (); }
jit::imm32 jit::arg_us () { return jit_arg_us (); }
jit::imm32 jit::arg_i () { return jit_arg_i (); }
jit::imm32 jit::arg_ui () { return jit_arg_ui (); }
jit::imm32 jit::arg_l () { return jit_arg_l (); }
jit::imm32 jit::arg_ul () { return jit_arg_ul (); }
jit::imm32 jit::arg_p () { return jit_arg_p (); }
jit::imm32 jit::arg_f () { return jit_arg_f (); }
jit::imm32 jit::arg_d () { return jit_arg_d (); }

void jit::retval_ui (reg32 rd) { jit_retval_ui (rd); }
void jit::retval_uc (reg32 rd) { jit_retval_uc (rd); }
void jit::retval_us (reg32 rd) { jit_retval_us (rd); }
void jit::retval_ul (reg32 rd) { jit_retval_ul (rd); }
void jit::retval_i (reg32 rd) { jit_retval_i (rd); }
void jit::retval_l (reg32 rd) { jit_retval_l (rd); }
void jit::retval_p (reg32 rd) { jit_retval_p (rd); }
void jit::retval_c (reg32 rd) { jit_retval_c (rd); }
void jit::retval_s (reg32 rd) { jit_retval_s (rd); }
void jit::retval_f (reg32 rs) { jit_retval_f (rs); }
void jit::retval_d (reg32 rs) { jit_retval_d (rs); }
#endif
