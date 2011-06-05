#ifndef INTERNAL_INSTRUCTION_H
#define INTERNAL_INSTRUCTION_H

#include <assembler/visitors/machine.h>

namespace visitors
{
  struct machine::instruction
  {
    class operand
    {
      std::string str;
      long imm;
      double dec;

    public:
      enum otype
      {
        NONE,           // nothing
        IVARIABLE,      // an integer variable
        FVARIABLE,      // a floating point variable
        PVARIABLE,      // instruction pointer
        ENTRY,          // function entry point
        COMPCALL,       // compile-time function call
        FUNCTION,       // function reference
        REG_R,          // R-register
        REG_V,          // V-register
        REG_FPR,        // floating point register
        REG_RET,        // return value register
        REG_FP,         // frame pointer
        REG_SP,         // stack pointer
        IIMMEDIATE,     // immediate integer
        FIMMEDIATE,     // immediate floating point number
        MNEMONIC,       // mnemonic
      } typ;

      static char const *type_string (otype t);

      operand (std::string const &v, otype t);
      operand (long v, otype t);
      operand ();

      void operator () (std::string const &v, otype t);
      void operator () (long v, otype t);

      void reset ();
      bool is_string () const;
      bool is_integral () const;
      void type_check (otype t) const;

      std::string const &string () const { return str; }
      long              integer () const { return imm; }
      double            decimal () const { return dec; }

      otype type () const { return typ; }

      std::string const &mnemonic () const { type_check (MNEMONIC); return str; }
      std::string const &compcall () const { type_check (COMPCALL); return str; }
      jit:: reg32 reg_r   () const { type_check (REG_R);   return jit:: reg_for (integer ()); }
      jit:: reg32 reg_v   () const { type_check (REG_V);   return jit:: reg_for (integer ()); }
      jit::freg32 reg_fpr () const { type_check (REG_FPR); return jit::freg_for (integer ()); }
    };

    operand mne;
    operand op[3];
    operand ret;

    std::string file;
    int line;

    instruction (std::string const &filename, int row, std::string const &mnemonic = "<invalid>")
    : mne (mnemonic, operand::MNEMONIC), file (filename), line (row)
    {
    }

    void reset ()
    {
      mne.reset ();
      op[0].reset ();
      op[1].reset ();
      op[2].reset ();
      ret.reset ();
    }

    std::string const &mnemonic () const
    {
      return mne.mnemonic ();
    }
  };
}

#endif
