#include <cstdio>
#include <cstdlib>

#if defined (__i386__) || defined (__x86_64__)
# include <lightning/i386/funcs.h>
#endif

static inline int jit_fail (const char *, const char *, int, const char *) JIT_UNUSED;

int
jit_fail (const char *msg, const char *file, int line, const char *function)
{
  fprintf (stderr, "%s: In function `%s':\n", file, function);
  fprintf (stderr, "%s:%d: %s\n", file, line, msg);
  abort ();
}
