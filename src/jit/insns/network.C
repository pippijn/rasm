#include <jit.h>

#define _jit this->current

#if 1
// Host-to-network (big endian) order
void jit::hton_ui (reg32 d, reg32 rs) { jit_hton_ui (d, rs); }
void jit::hton_us (reg32 d, reg32 rs) { jit_hton_us (d, rs); }

// Network-to-host order
void jit::ntoh_ui (reg32 d, reg32 rs) { jit_ntoh_ui (d, rs); }
void jit::ntoh_us (reg32 d, reg32 rs) { jit_ntoh_us (d, rs); }
#endif
