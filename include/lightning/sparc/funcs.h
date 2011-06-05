#if !defined(__GNUC__) && !defined(__GNUG__)
#error Go get GNU C, I do not know how to flush the cache
#error with this compiler.
#else
/* Why doesn't this compile?!?
 * static void
 * jit_flush_code(start, end)
 *      void 	*start;
 *      void	*end;
 */

static inline void
jit_flush_code(void* start, void* end)
{
#ifndef LIGHTNING_CROSS
  register char *dest;

  __asm__ __volatile__ ("stbar");
  for (dest = (char *)start; dest <= (char *)end; dest += 4) {
    __asm__ __volatile__ ("flush %0"::"r"(dest));
  }

  /* [SPARC Architecture Manual v8, page 139, implementation note #5] */
  __asm__ __volatile__ ("nop; nop; nop; nop; nop");
#endif
}
#endif
