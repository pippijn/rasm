#include <jit.h>

#define _jit this->current

#if 1
// function call to O1
void jit::calli (insn *label) { jit_calli (label); }
void jit::finish (insn *sub) { jit_finish (sub); }

// function call to a register
void jit::callr (reg32 reg) { jit_callr (reg); }
void jit::finishr (reg32 reg) { jit_finishr (reg); }

// unconditional jump to O1
void jit::jmpi (insn *label) { jit_jmpi (label); }
void jit::jmpr (reg32 reg) { jit_jmpr (reg); }

// return from subroutine
void jit::ret () { jit_ret (); }
#endif
