#ifndef ASSEMBLER_H_INCLUDED
#define ASSEMBLER_H_INCLUDED

#include <assembler/visitors/machine.h>

class assembler : jit
{
  typedef visitors::machine::instruction vmi;

public:
  struct operand;

  void assemble (map<std::string, std::vector<vmi> > const &funs);

  void disassemble (std::ostream &os);
  pointer cast () const;

private:
  void assemble (std::vector<vmi> const &insns);
  void assemble (vmi const &insn);

  static void croak (rio::srcinf const &si, vmi const &v, char const *fmt, ...);
  static void croak (rio::srcinf const &si, rio::srcinf const &origin, vmi const &v, char const *fmt, ...);

  struct variable
  {
    enum otype
    {
      NONE,
      IMM,
      FIMM,
      PTR,
      INSN,
    } type;

    union value
    {
      long   i; // integer
      double f; // floating point number
      void * p; // pointer
      insn * l; // label
    } u;

    variable ()         : type (NONE) { u.i = 0; }
    variable (int    v) : type (IMM)  { u.i = v; }
    variable (long   v) : type (IMM)  { u.i = v; }
    variable (double v) : type (FIMM) { u.f = v; }
    variable (void * v) : type (PTR)  { u.p = v; }
    variable (insn * v) : type (INSN) { u.l = v; }

    long   imm  (vmi const &i) const { type_check (SRCINF, IMM, i);  return u.i; }
    double fimm (vmi const &i) const { type_check (SRCINF, FIMM, i); return u.f; }
    void * ptr  (vmi const &i) const { type_check (SRCINF, PTR, i);  return u.p; }
    insn * ins  (vmi const &i) const { type_check (SRCINF, INSN, i); return u.l; }

    static char const *type_string (otype t);

  private:
    void type_check (rio::srcinf const &si, otype t, vmi const &i) const;
  };

  struct function
  {
    insn buffer[1024];
    map<std::string, variable> locals;
    insn *ip;
  };
  
  map<std::string, function> funcs;

  function *curfunc;
};

#endif /* ASSEMBLER_H_INCLUDED */
