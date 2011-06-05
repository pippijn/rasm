// AC:   Argument count
// R:    Whether or not this instruction returns
// RT:   Return type of the instruction
// T:    The function signature, mangled
// args: Any number of arguments passed to the instruction
//     AC     R           RT      T  args...
TYPE0 (0,  true,  jit::imm32,    iv)
TYPE  (1,  true,  jit::imm32,    ii, jit::imm32)
TYPE  (1,  true,  jit::reg32,    rr, jit::reg32)
TYPE0 (0,  true, jit::insn *,    lv)
TYPE  (1,  true, jit::insn *,    ll, jit::insn *)
TYPE  (1,  true, jit::insn *,    lr, jit::reg32)
TYPE  (2,  true, jit::insn *,   lrr, jit::reg32, jit::reg32)
TYPE  (3,  true, jit::insn *,  lrrr, jit::reg32, jit::reg32, jit::reg32)
TYPE  (3,  true, jit::insn *,  llri, jit::insn *, jit::reg32, jit::imm32)
TYPE  (2,  true, jit::insn *,   lrl, jit::reg32, jit::insn *)
TYPE0 (0, false,        void,    vv)
TYPE  (2, false,        void,   vrl, jit::reg32, jit::insn *)
TYPE  (1, false,        void,    vr, jit::reg32)
TYPE  (2, false,        void,   vrr, jit::reg32, jit::reg32)
TYPE  (3, false,        void,  vrrr, jit::reg32, jit::reg32, jit::reg32)
TYPE  (1, false,        void,    vl, jit::insn *)
TYPE  (2, false,        void,   vll, jit::insn *, jit::insn *)
TYPE  (3, false,        void,  vlll, jit::insn *, jit::insn *, jit::insn *)
TYPE  (1, false,        void,    vi, jit::imm32)
TYPE  (2, false,        void,   vri, jit::reg32, jit::imm32)
TYPE  (3, false,        void,  vrri, jit::reg32, jit::reg32, jit::imm32)
