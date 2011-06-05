struct jit_local_state {
  jit_local_state ()
  : long_jumps (0), nextarg_getfp (0), nextarg_putfp (0), nextarg_geti (0),
    argssize (0), alloca_offset (0), alloca_slack (0)
  {
  }

  int   long_jumps;
  int   nextarg_getfp;
  int   nextarg_putfp;
  int   nextarg_geti;
  int	argssize;
  int   alloca_offset;
  int   alloca_slack;
};
