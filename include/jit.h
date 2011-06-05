#ifndef JIT_H_INCLUDED
#define JIT_H_INCLUDED

#include <tr1/unordered_map>
#include <stdexcept>

#include <lightning.h>
#include <rio/exception.h>
#include <rio/cast.h>

struct jit
{
  typedef int imm32;
  typedef float fimm32;

  typedef jit_insn insn;
  typedef jit_code code;
  typedef jit_state state;

  enum reg32
  {
    R0 = JIT_R (0),
    R1 = JIT_R (1),
    R2 = JIT_R (2),
    V0 = JIT_V (0),
    V1 = JIT_V (1),
    V2 = JIT_V (2),
    RET = JIT_RET,
    FP = JIT_FP,
    SP = JIT_SP,
  };

  enum freg32
  {
    FPR0 = JIT_FPR (0),
    FPR1 = JIT_FPR (1),
    FPR2 = JIT_FPR (2),
    FPR3 = JIT_FPR (3),
    FPR4 = JIT_FPR (4),
    FPR5 = JIT_FPR (5),
  };

  static reg32 reg_for (int reg);
  static freg32 freg_for (int freg);

  static int const R_NUM = JIT_R_NUM;
  static int const V_NUM = JIT_V_NUM;
  static int const FPR_NUM = JIT_FPR_NUM;

  template<typename KeyT, typename ValueT>
  struct map : std::tr1::unordered_map<KeyT, ValueT>
  {
    typedef typename std::tr1::unordered_map<KeyT, ValueT>::iterator iterator;
    typedef typename std::tr1::unordered_map<KeyT, ValueT>::const_iterator const_iterator;

    ValueT &at (KeyT const &key)
    {
      iterator it = this->find (key);
      if (it == this->end ())
        throw std::out_of_range ("Key not found: `" + key + '\'');
      return it->second;
    }

    ValueT const &at (KeyT const &key) const
    {
      const_iterator it = this->find (key);
      if (it == this->end ())
        throw std::out_of_range ("Key not found: `" + key + '\'');
      return it->second;
    }
  };

#define INSN(R, name, args) R name args;
#include <jit/insns.h>
#undef INSN

#include <jit/opcode.h>

  jit ();
  jit (insn *ptr);

  code &set_ip (insn *ptr);
  code &get_ip ();

  void flush_code ();
  void flush_code (void *start, void *end);

  void disassemble (std::ostream &os);

  static bool can (std::string const &mnemonic);

protected:
  struct functor;
  static map<std::string, functor> &functors ();
  static map<std::string, void *> &functions ();

  std::size_t length ();
  static void disassemble (std::ostream &os, insn const *ptr, std::size_t len);

  struct pointer
  {
    pointer (insn const *begin)
    : entry (begin)
    {
    }

    template<typename T>
    operator T * ()
    {
      return rio::direct_cast<T *> (entry);
    }

  private:
    insn const *entry;
  };

private:
  template<typename Sig> struct registry;

  static bool initialised;
  static bool initialise ();

  static void init_functors ();
  static void init_functions ();

  void finalise ();

  insn *begin;
  state current;

public:
  pointer cast ()
  {
    return pointer (entry ());
  }
};

#endif /* JIT_H_INCLUDED */
