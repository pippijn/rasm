struct jit_local_state {
  jit_local_state ()
  : framesize (0), argssize (0), alloca_offset (0), alloca_slack (0)
  {
  }

  int	framesize;
  int	argssize;
  int	alloca_offset;
  int	alloca_slack;
};
