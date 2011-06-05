#include <jit.h>

#define _jit this->current

#if 1
jit::imm32 jit::assign_i (imm32 i) { return i; }
jit::reg32 jit::assign_r (reg32 r) { return r; }
jit::insn *jit::assign_l (insn *l) { return l; }
#endif
