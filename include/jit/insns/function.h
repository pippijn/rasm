// function prolog for O1 args
INSN (void, prolog, (imm32 n))

// the same for leaf functions
INSN (void, leaf, (imm32 numargs))

// reserve space on the stack
INSN (imm32, allocai, (imm32 n))
