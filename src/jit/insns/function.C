#include <jit.h>

#define _jit this->current

#if 1
// function prolog for O1 args
void jit::prolog (imm32 n) { jit_prolog (n); }

// the same for leaf functions
void jit::leaf (imm32 numargs) { jit_leaf (numargs); }

// reserve space on the stack
jit::imm32 jit::allocai (imm32 n) { return jit_allocai (n); }
#endif
