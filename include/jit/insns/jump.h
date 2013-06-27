// function call to O1
INSN (void, calli, (insn *label))
INSN (void, finish, (insn *sub))

// function call to a register
INSN (void, callr, (reg32 reg))
INSN (void, finishr, (reg32 reg))

// unconditional jump to O1
INSN (void, jmpi, (insn *label))
INSN (void, jmpr, (reg32 reg))

// return from subroutine
INSN (void, ret, ())
