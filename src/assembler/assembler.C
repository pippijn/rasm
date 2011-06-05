#include <jit.h>
#include <jit/functor.h>
#include <assembler.h>

#include "visitors/instruction.h"

#define croak(insn, msg...) ::assembler::croak (SRCINF, insn, msg)

char const *
assembler::variable::type_string (otype t)
{
  switch (t)
    {
    case NONE: return "<invalid>";
    case IMM:  return "immediate integer";
    case FIMM: return "immediate floating point number";
    case PTR:  return "pointer";
    case INSN: return "instruction pointer";
    }
  die (type, "got invalid type: %d", t);
}

void
assembler::variable::type_check (rio::srcinf const &si, otype t, vmi const &i) const
{
  if (t != type)
    croak (si, i, "expected `%s', got `%s'", type_string (t), type_string (type));
}

struct assembler::operand
{
  union value
  {
    imm32 imm;
    fimm32 fimm;
    reg32 reg;
    freg32 freg;
    std::string const *var;
    insn *ins;

    value (void *v)              : ins (static_cast<insn *> (v)) { }
    value (insn *v)              : ins (v) { }
    value (int v)                : imm (v) { }
    value (long v)               : imm (v) { }
    value (double v)             : fimm (v) { }
    value (reg32 v)              : reg (v) { }
    value (freg32 v)             : freg (v) { }
    value (std::string const *v) : var (v) { }
  } u;

  enum otype
  {
    IMM,
    FIMM,
    REG,
    FREG,
    VAR,
    INS
  } type;

  operand (void *v)              : u (v),  type (INS) { }
  operand (insn *v)              : u (v),  type (INS) { }
  operand (int v)                : u (v),  type (IMM) { }
  operand (long v)               : u (v),  type (IMM) { }
  operand (double v)             : u (v),  type (FIMM) { }
  operand (reg32 v)              : u (v),  type (REG) { }
  operand (freg32 v)             : u (v),  type (FREG) { }
  operand (std::string const &v) : u (&v), type (VAR) { }

  insn *ins (vmi const &insn)
  {
    type_check (SRCINF, INS, insn);
    return u.ins;
  }

  imm32 imm (vmi const &insn)
  {
    type_check (SRCINF, IMM, insn);
    return u.imm;
  }

  fimm32 fimm (vmi const &insn)
  {
    type_check (SRCINF, FIMM, insn);
    return u.fimm;
  }

  reg32 reg (vmi const &insn)
  {
    type_check (SRCINF, REG, insn);
    return u.reg;
  }

  freg32 freg (vmi const &insn)
  {
    type_check (SRCINF, FREG, insn);
    return u.freg;
  }

  std::string const &var (vmi const &insn)
  {
    type_check (SRCINF, VAR, insn);
    return *u.var;
  }

  static char const *type_string (otype t)
  {
    switch (t)
      {
      case IMM:  return "immediate integer";
      case FIMM: return "immediate floating point number";
      case REG:  return "register";
      case FREG: return "floating point register";
      case VAR:  return "variable";
      case INS:  return "instruction pointer";
      }
    die (type, "got invalid type");
  }

  void type_check (rio::srcinf const &si, otype t, vmi const &insn)
  {
    if (type != t)
      throw type_exception (si, "%s:%d: `%s' operand expected, got `%s'", insn.file.c_str (), insn.line, type_string (t), type_string (type));
  }

  static operand asm_op (vmi::operand const &op, assembler &as, vmi const &i);
};

assembler::operand
assembler::operand::asm_op (vmi::operand const &op, assembler &as, vmi const &i)
{
  typedef vmi::operand o;
  switch (op.type ())
    {
    case o::NONE:
      return 0;
    case o::IVARIABLE:
      return as.curfunc->locals.at (op.string ()).imm (i);
    case o::FVARIABLE:
      return as.curfunc->locals.at (op.string ()).fimm (i);
    case o::PVARIABLE:
      return as.curfunc->locals.at (op.string ()).ins (i);
    case o::ENTRY:
      return as.funcs.at (op.string ()).buffer;
    case o::COMPCALL:
      {
        functor const &f = functors ().at (op.compcall ());
        switch (f.type)
          {
          case functor::ftype::iv: return f.u.iv (as);
          case functor::ftype::lv: return f.u.lv (as);
          }
        croak (i, "%s has unhandled function type: %s", op.compcall ().c_str (), functor::ftype::string (f.type));
      }
    case o::FUNCTION:
      return functions ().at (op.string ());
    case o::REG_R:
      return op.reg_r ();
    case o::REG_V:
      return op.reg_v ();
    case o::REG_FPR:
      return op.reg_fpr ();
    case o::REG_RET:
      return RET;
    case o::REG_FP:
      return FP;
    case o::REG_SP:
      return SP;
    case o::IIMMEDIATE:
      return op.integer ();
    case o::FIMMEDIATE:
      return op.decimal ();
    case o::MNEMONIC:
      croak (i, "trying to use mnemonic as operand");
    }
  die (argument, "invalid operand type: %d", op.type ());
}

void
assembler::assemble (map<std::string, std::vector<vmi> > const &funs)
{
  // Forward declarations
  {
    map<std::string, std::vector<vmi> >::const_iterator it = funs.begin ();
    map<std::string, std::vector<vmi> >::const_iterator et = funs.end ();
    
    while (it != et)
      {
        curfunc = &this->funcs[it->first];
        set_ip (curfunc->buffer);
        ++it;
      }
  }
  // Iterate again, but with assembly
  {
    map<std::string, std::vector<vmi> >::const_iterator it = funs.begin ();
    map<std::string, std::vector<vmi> >::const_iterator et = funs.end ();
    
    while (it != et)
      {
        curfunc = &this->funcs[it->first];
        set_ip (curfunc->buffer);
        assemble (it->second);
        curfunc->ip = entry () + length ();
        flush_code ();
        ++it;
      }
  }
}

void
assembler::disassemble (std::ostream &os)
{
  map<std::string, function>::const_iterator it = funcs.begin ();
  map<std::string, function>::const_iterator et = funcs.end ();

  while (it != et)
    {
      std::printf ("\nFunction `%s':\n", it->first.c_str ());
      jit::disassemble (os, it->second.buffer, it->second.ip - it->second.buffer);
      ++it;
    }
}

void
assembler::assemble (std::vector<vmi> const &insns)
{
  std::vector<vmi>::const_iterator it = insns.begin ();
  std::vector<vmi>::const_iterator et = insns.end ();

  while (it != et)
    {
      assemble (*it);
      ++it;
    }
}

void
assembler::assemble (vmi const &insn)
{
  functor const &f = functors ().at (insn.mne.mnemonic ());
  //puts (insn.mne.string ().c_str ());

  operand op1 = operand::asm_op (insn.op[0], *this, insn);
  operand op2 = operand::asm_op (insn.op[1], *this, insn);
  operand op3 = operand::asm_op (insn.op[2], *this, insn);

#include <jit/type_switch.h>
  
  croak (insn, "`%s' has unhandled function type: `%s'", insn.mne.mnemonic ().c_str (), functor::ftype::string (f.type));
}

jit::pointer
assembler::cast () const
{
  return funcs.at ("start").buffer;
}

#undef croak

void
assembler::croak (rio::srcinf const &si, rio::srcinf const &origin, visitors::machine::instruction const &insn, char const *fmt, ...)
{
  char buf[BUFSIZ];
  std::va_list ap;

  va_start (ap, fmt);
  std::vsnprintf (buf, BUFSIZ - 1, fmt, ap);
  va_end (ap);

  throw type_exception (origin, "%s:%d: %s", insn.file.c_str (), insn.line, buf);
}

void
assembler::croak (rio::srcinf const &si, visitors::machine::instruction const &insn, char const *fmt, ...)
{
  char buf[BUFSIZ];
  std::va_list ap;

  va_start (ap, fmt);
  std::vsnprintf (buf, BUFSIZ - 1, fmt, ap);
  va_end (ap);

  throw type_exception (si, "%s:%d: %s", insn.file.c_str (), insn.line, buf);
}
