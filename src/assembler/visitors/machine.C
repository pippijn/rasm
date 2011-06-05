#include <iostream>

#include <assembler/visitors.h>
#include <jit/functor.h>

#include "instruction.h"

namespace visitors
{
  struct machine::mstate
  {
    mstate (machine &that)
    : returning (false), self (that), op (0)
    {
    }

    instruction::operand &nextop ()
    {
      return returning ? insns->back ().ret : insns->back ().op[op++];
    }

    void reset ()
    {
      returning = false;
      op = 0;
    }

    bool returning;
    std::vector<instruction> *insns;
    std::string const *func;

  private:
    machine &self;
    uint8_t op;
  };

  machine::machine ()
  : state (new mstate (*this))
  {
  }

  machine::~machine ()
  {
    delete state;
  }

  void
  machine::visit (ast::code const &v)
  {
    std::vector<std::tr1::shared_ptr<ast::statement> >::const_iterator it = v.statements.begin ();
    std::vector<std::tr1::shared_ptr<ast::statement> >::const_iterator et = v.statements.end ();

    state->func = v.func;
    state->insns = &functions[*state->func];

    while (it != et)
      {
        (*it)->invite (*this);
        ++it;
      }
  }

  void
  machine::visit (ast::instruction const &v)
  {
    //puts (__PRETTY_FUNCTION__);
    v.mnemonic ().invite (*this);
    if (v.argc () >= 1) v.operand1 ().invite (*this);
    if (v.argc () >= 2) v.operand2 ().invite (*this);
    if (v.argc () >= 3) v.operand3 ().invite (*this);
    state->reset ();
  }

  void
  machine::visit (ast::assignment const &v)
  {
    //puts (__PRETTY_FUNCTION__);
    v.lhs ().invite (*this);
    state->returning = true;
    v.rhs ().invite (*this);
    state->returning = false;
  }

  void
  machine::visit (ast::imm_flt const &v)
  {
    //puts (__PRETTY_FUNCTION__);
    state->nextop () (v.value (), instruction::operand::FIMMEDIATE);
  }

  void
  machine::visit (ast::imm_int const &v)
  {
    //puts (__PRETTY_FUNCTION__);
    state->nextop () (v.value (), instruction::operand::IIMMEDIATE);
  }

  void
  machine::visit (ast::compcall const &v)
  {
    //puts (__PRETTY_FUNCTION__);
    state->nextop () (v.name (), instruction::operand::COMPCALL);
  }

  void
  machine::visit (ast::function const &v)
  {
    //puts (__PRETTY_FUNCTION__);
    state->nextop () (v.name (), instruction::operand::FUNCTION);
  }

  void
  machine::visit (ast::reg_r const &v)
  {
    //puts (__PRETTY_FUNCTION__);
    state->nextop () (v.value (), instruction::operand::REG_R);
  }

  void
  machine::visit (ast::reg_v const &v)
  {
    //puts (__PRETTY_FUNCTION__);
    state->nextop () (v.value (), instruction::operand::REG_V);
  }

  void
  machine::visit (ast::reg_fpr const &v)
  {
    //puts (__PRETTY_FUNCTION__);
    state->nextop () (v.value (), instruction::operand::REG_FPR);
  }

  void
  machine::visit (ast::reg_sp const &v)
  {
    //puts (__PRETTY_FUNCTION__);
    state->nextop () (-1, instruction::operand::REG_SP);
  }

  void
  machine::visit (ast::reg_fp const &v)
  {
    //puts (__PRETTY_FUNCTION__);
    state->nextop () (-1, instruction::operand::REG_FP);
  }

  void
  machine::visit (ast::reg_ret const &v)
  {
    //puts (__PRETTY_FUNCTION__);
    state->nextop () (-1, instruction::operand::REG_RET);
  }

  void
  machine::visit (ast::mnemonic const &v)
  {
    //puts (__PRETTY_FUNCTION__);
    state->insns->push_back (instruction (v.file (), v.line (), v.name ()));
  }

  void
  machine::visit (ast::entry const &v)
  {
    //puts (__PRETTY_FUNCTION__);
    state->nextop () (v.name (), instruction::operand::ENTRY);
  }

  void
  machine::visit (ast::ptrvar const &v)
  {
    //puts (__PRETTY_FUNCTION__);
    state->nextop () (v.name (), instruction::operand::PVARIABLE);
  }

  void
  machine::visit (ast::intvar const &v)
  {
    //puts (__PRETTY_FUNCTION__);
    state->nextop () (v.name (), instruction::operand::IVARIABLE);
  }

  void
  machine::visit (ast::fltvar const &v)
  {
    //puts (__PRETTY_FUNCTION__);
    state->nextop () (v.name (), instruction::operand::FVARIABLE);
  }
}
