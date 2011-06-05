#ifndef LIGHTNING_TYPES_H
#define LIGHTNING_TYPES_H

typedef signed char	_sc;
typedef unsigned char	_uc;
typedef signed short	_ss;
typedef unsigned short	_us;
typedef signed int	_si;
typedef unsigned int	_ui;
typedef signed long	_sl;
typedef unsigned long	_ul;

#if defined (__i386__) || defined (__x86_64__)
# include <lightning/i386/types.h>
#endif

struct jit_state {
  jit_state ()
  : fp (0)
  {
  }

  union {
    jit_insn             *pc;
    _uc                  *uc_pc;
    _us                  *us_pc;
    _ui                  *ui_pc;
    _ul                  *ul_pc;
  }                       x;
  struct jit_fp		 *fp;
  struct jit_local_state jitl;
};

/* jit_code: union of many possible function pointer types.  Returned
 * by jit_get_ip().
 */
typedef union jit_code {	
  char		 *ptr;
  void		 (*vptr)(void);
  char		 (*cptr)(void);
  unsigned char	 (*ucptr)(void);
  short		 (*sptr)(void);
  unsigned short (*usptr)(void);
  int		 (*iptr)(void);
  unsigned int	 (*uiptr)(void);
  long		 (*lptr)(void);
  unsigned long	 (*ulptr)(void);
  void *	 (*pptr)(void);
  float		 (*fptr)(void);
  double	 (*dptr)(void);
} jit_code;

#endif
