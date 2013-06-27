#ifdef __linux__
# include <unistd.h>
# include <sys/mman.h>
#endif

static inline void
jit_flush_code (void *dest, void *end)
{
  /* On the x86, the PROT_EXEC bits are not handled by the MMU.
     However, the kernel can emulate this by setting the code
     segment's limit to the end address of the highest page
     whose PROT_EXEC bit is set.

     Linux kernels that do so and that disable by default the
     execution of the data and stack segment are becoming more
     and more common (Fedora, for example), so we implement our
     jit_flush_code as an mprotect.  */
#ifdef __linux__
  static unsigned long prev_page = 0, prev_length = 0;
  long page, length;
#ifdef PAGESIZE
  const int page_size = PAGESIZE;
#else
  static int page_size = -1;
  if (page_size == -1)
    page_size = sysconf (_SC_PAGESIZE);
#endif

  page = (long) dest & ~(page_size - 1);
  length = ((char *) end - (char *) page + page_size - 1) & ~(page_size - 1);

  /* Simple-minded attempt at optimizing the common case where a single
     chunk of memory is used to compile multiple functions.  */
  if (page >= prev_page && page + length <= prev_page + prev_length)
    return;

  mprotect ((void *) page, length, PROT_READ | PROT_WRITE | PROT_EXEC);

  /* See if we can extend the previously mprotect'ed memory area towards
     higher addresses: the starting address remains the same as before.  */
  if (page >= prev_page && page <= prev_page + prev_length)
    prev_length = page + length - prev_page;

  /* See if we can extend the previously mprotect'ed memory area towards
     lower addresses: the highest address remains the same as before.  */
  else if (page < prev_page && page + length >= prev_page
          && page + length <= prev_page + prev_length)
    prev_length += prev_page - page, prev_page = page;

  /* Nothing to do, replace the area.  */
  else
    prev_page = page, prev_length = length;
#endif
}
