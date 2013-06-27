  switch (f.type)
    {
    case functor::ftype::iv:
      curfunc->locals[insn.ret.string ()] = f.u.iv (*this);
      return;
    case functor::ftype::ii:
      curfunc->locals[insn.ret.string ()] = f.u.ii (*this, op1.imm (insn));
      return;
    case functor::ftype::rr:
      f.u.rr (*this, op1.reg (insn));
      return;
    case functor::ftype::lv:
      curfunc->locals[insn.ret.string ()] = f.u.lv (*this);
      return;
    case functor::ftype::ll:
      curfunc->locals[insn.ret.string ()] = f.u.ll (*this, op1.ins (insn));
      return;
    case functor::ftype::lr:
      curfunc->locals[insn.ret.string ()] = f.u.lr (*this, op1.reg (insn));
      return;
    case functor::ftype::lrr:
      curfunc->locals[insn.ret.string ()] = f.u.lrr (*this, op1.reg (insn), op2.reg (insn));
      return;
    case functor::ftype::lrrr:
      curfunc->locals[insn.ret.string ()] = f.u.lrrr (*this, op1.reg (insn), op2.reg (insn), op3.reg (insn));
      return;
    case functor::ftype::llri:
      curfunc->locals[insn.ret.string ()] = f.u.llri (*this, op1.ins (insn), op2.reg (insn), op3.imm (insn));
      return;
    case functor::ftype::lrl:
      curfunc->locals[insn.ret.string ()] = f.u.lrl (*this, op1.reg (insn), op2.ins (insn));
      return;
    case functor::ftype::vv:
      f.u.vv (*this);
      return;
    case functor::ftype::vrl:
      f.u.vrl (*this, op1.reg (insn), op2.ins (insn));
      return;
    case functor::ftype::vr:
      f.u.vr (*this, op1.reg (insn));
      return;
    case functor::ftype::vrr:
      f.u.vrr (*this, op1.reg (insn), op2.reg (insn));
      return;
    case functor::ftype::vrrr:
      f.u.vrrr (*this, op1.reg (insn), op2.reg (insn), op3.reg (insn));
      return;
    case functor::ftype::vl:
      f.u.vl (*this, op1.ins (insn));
      return;
    case functor::ftype::vll:
      f.u.vll (*this, op1.ins (insn), op2.ins (insn));
      return;
    case functor::ftype::vlll:
      f.u.vlll (*this, op1.ins (insn), op2.ins (insn), op3.ins (insn));
      return;
    case functor::ftype::vi:
      f.u.vi (*this, op1.imm (insn));
      return;
    case functor::ftype::vri:
      f.u.vri (*this, op1.reg (insn), op2.imm (insn));
      return;
    case functor::ftype::vrri:
      f.u.vrri (*this, op1.reg (insn), op2.reg (insn), op3.imm (insn));
      return;
    }
