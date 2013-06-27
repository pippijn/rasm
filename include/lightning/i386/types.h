typedef _uc		jit_insn;

#if defined (__i386__)
# include <lightning/i386/x86/types.h>
#else
# include <lightning/i386/x86_64/types.h>
#endif
