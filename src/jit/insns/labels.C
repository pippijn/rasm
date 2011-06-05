#include <jit.h>

#define _jit this->current

#if 1
jit::insn *jit::get_label () { return jit_get_label (); }
jit::insn *jit::forward () { return jit_forward (); }
jit::insn *jit::entry () { return begin; }

void jit::patch (insn *pv) { jit_patch (pv); }
void jit::patch_at (insn *delay_pc, insn *pv) { jit_patch_at (delay_pc, pv); }
void jit::patch_movi (insn *pa, insn *pv) { jit_patch_movi (pa, pv); }
#endif
