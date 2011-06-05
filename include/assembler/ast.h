#ifndef ASSEMBLER_AST_H_INCLUDED
#define ASSEMBLER_AST_H_INCLUDED

#include <cassert>

#include <vector>
#include <string>
#include <memory>
#include <tr1/memory>

#include <jit.h>

#include <assembler/lexer.h>

namespace ast
{
  struct visitor;
  struct const_visitor;
  
  struct node
  {
    virtual ~node () = 0;
    virtual void invite (visitor &v) = 0;
    virtual void invite (const_visitor &v) const = 0;

    std::string const &func () const { return function; }
    std::string const &file () const { return filename; }
    int line () const { return row; }
    int column () const { return col; }

  protected:
    node ()
    : function (lexer::function ()), filename (lexer::file ()), row (lexer::row ()), col (lexer::col ())
    {
    }

  private:
    std::string const function;
    std::string const filename;
    int const row;
    int const col;
  };
  
  struct operand : node
  {
    std::string const &type ()
    {
      return otype;
    }

  protected:
    operand (std::string const &t)
    : otype (t)
    {
    }

  private:
    std::string otype;
  };
  
  struct statement : node
  {
  protected:
    statement ()
    {
    }
  };
  
  struct code
  {
    std::string const *func;

    std::vector<std::tr1::shared_ptr<statement> > statements;
    void invite (visitor &v);
    void invite (const_visitor &v) const;
  };
  
  struct program
  {
    jit::map<std::string, std::tr1::shared_ptr<struct code> > functions;
    void invite (visitor &v);
    void invite (const_visitor &v) const;
  };
  
  struct mnemonic : node
  {
    void invite (visitor &v);
    void invite (const_visitor &v) const;

    std::string const &name () const
    {
      return n;
    }

    void name (std::string const &name)
    {
      n = name;
    }

    mnemonic (std::string const &v)
    : n (v)
    {
    }

    mnemonic (char const *v)
    : n (v)
    {
    }

  private:
    std::string n;
  };
  
  struct instruction : statement, operand
  {
    void invite (visitor &v);
    void invite (const_visitor &v) const;

    struct mnemonic const &mnemonic () const
    {
      return *mne;
    }

    struct operand const &operand1 () const { return *op1; }
    struct operand const &operand2 () const { return *op2; }
    struct operand const &operand3 () const { return *op3; }

    uint8_t argc () const JIT_CONST
    {
      return bool (op3.get ()) + bool (op2.get ()) + bool (op1.get ());
    }
  
    instruction (struct mnemonic *m, struct operand *o1 = NULL, struct operand *o2 = NULL, struct operand *o3 = NULL)
    : operand ("<insn>"), mne (m), op1 (o1), op2 (o2), op3 (o3)
    {
      assert (bool (o3) <= bool (o2) || bool (o2) <= bool (o1)); // TODO: check this when I'm no longer a zombie
    }

  private:
    std::auto_ptr<struct mnemonic> const mne;
    std::auto_ptr<struct operand> const op1;
    std::auto_ptr<struct operand> const op2;
    std::auto_ptr<struct operand> const op3;
  };
  
  struct variable : operand
  {
    std::string const &name () const
    {
      return n;
    }

    void name (std::string const &name)
    {
      n = name;
    }

  protected:
    variable (std::string const &t, std::string const &v)
    : operand (t), n (v)
    {
    }

    variable (std::string const &t, char const *v)
    : operand (t), n (v)
    {
    }

  private:
    std::string n;
  };
  
  struct entry : variable
  {
    void invite (visitor &v);
    void invite (const_visitor &v) const;

    entry (std::string const &name)
    : variable ("e", name)
    {
    }

    entry (char const *name)
    : variable ("e", name)
    {
    }
  };
  
  struct intvar : variable
  {
    void invite (visitor &v);
    void invite (const_visitor &v) const;

    intvar (std::string const &name)
    : variable ("i", name)
    {
    }

    intvar (char const *name)
    : variable ("i", name)
    {
    }
  };
  
  struct ptrvar : variable
  {
    void invite (visitor &v);
    void invite (const_visitor &v) const;

    ptrvar (std::string const &name)
    : variable ("l", name)
    {
    }

    ptrvar (char const *name)
    : variable ("l", name)
    {
    }
  };
  
  struct fltvar : variable
  {
    void invite (visitor &v);
    void invite (const_visitor &v) const;

    fltvar (std::string const &name)
    : variable ("f", name)
    {
    }

    fltvar (char const *name)
    : variable ("f", name)
    {
    }
  };
  
  struct compcall : operand
  {
    void invite (visitor &v);
    void invite (const_visitor &v) const;

    std::string const &name () const
    {
      return n;
    }

    void name (std::string const &name)
    {
      n = name;
    }

    compcall (std::string const &v)
    : operand ("<invalid>"), n (v)
    {
    }

    compcall (char const *v)
    : operand ("<invalid>"), n (v)
    {
    }

  private:
    std::string n;
  };
  
  struct function : operand
  {
    void invite (visitor &v);
    void invite (const_visitor &v) const;

    std::string const &name () const
    {
      return n;
    }

    void name (std::string const &name)
    {
      n = name;
    }

    function (std::string const &v)
    : operand ("<invalid>"), n (v)
    {
    }

    function (char const *v)
    : operand ("<invalid>"), n (v)
    {
    }

  private:
    std::string n;
  };
  
  struct assignment : statement
  {
    void invite (visitor &v);
    void invite (const_visitor &v) const;
  
    operand const &lhs () const
    {
      return *left;
    }
  
    variable const &rhs () const
    {
      return *right;
    }

    assignment (operand *l, variable *r)
    : left (l), right (r)
    {
    }

  private:
    std::auto_ptr<operand> const left;
    std::auto_ptr<variable> const right;
  };
  
  struct immediate : operand
  {
  protected:
    immediate (std::string const &t)
    : operand (t)
    {
    }
  };
  
  struct imm_int : immediate
  {
    void invite (visitor &v);
    void invite (const_visitor &v) const;

    long value () const
    {
      return val;
    }
  
    imm_int (long v)
    : immediate ("i"), val (v)
    {
    }

  private:
    long val;
  };
  
  struct imm_flt : immediate
  {
    void invite (visitor &v);
    void invite (const_visitor &v) const;

    double value () const
    {
      return val;
    }
  
    imm_flt (double v)
    : immediate ("d"), val (v)
    {
    }

  private:
    double val;
  };
  
  struct registr : operand
  {
  protected:
    registr (std::string const &t)
    : operand (t)
    {
    }
  };
  
  struct reg_r : registr
  {
    void invite (visitor &v);
    void invite (const_visitor &v) const;

    jit::reg32 value () const
    {
      return reg;
    }

    reg_r (jit::reg32 r)
    : registr ("r"), reg (r)
    {
    }

  private:
    jit::reg32 reg;
  };
  
  struct reg_v : registr
  {
    void invite (visitor &v);
    void invite (const_visitor &v) const;

    jit::reg32 value () const
    {
      return reg;
    }

    reg_v (jit::reg32 r)
    : registr ("r"), reg (r)
    {
    }

  private:
    jit::reg32 reg;
  };
  
  struct reg_fpr : registr
  {
    void invite (visitor &v);
    void invite (const_visitor &v) const;

    jit::freg32 value () const
    {
      return reg;
    }
  
    reg_fpr (jit::freg32 r)
    : registr ("fr"), reg (r)
    {
    }

  private:
    jit::freg32 reg;
  };
  
  struct reg_ret : reg_r
  {
    void invite (visitor &v);
    void invite (const_visitor &v) const;

    reg_ret ()
    : reg_r (jit::RET)
    {
    }
  };
  
  struct reg_sp : reg_r
  {
    void invite (visitor &v);
    void invite (const_visitor &v) const;

    reg_sp ()
    : reg_r (jit::SP)
    {
    }
  };
  
  struct reg_fp : reg_r
  {
    void invite (visitor &v);
    void invite (const_visitor &v) const;

    reg_fp ()
    : reg_r (jit::SP)
    {
    }
  };

  struct visitor
  {
    virtual void visit (code &v);

    virtual void visit (instruction &v) { }
    virtual void visit (assignment &v) { }
    virtual void visit (mnemonic &v) { }
    virtual void visit (imm_flt &v) { }
    virtual void visit (imm_int &v) { }
    virtual void visit (reg_r &v) { }
    virtual void visit (reg_v &v) { }
    virtual void visit (reg_fpr &v) { }
    virtual void visit (reg_sp &v) { }
    virtual void visit (reg_fp &v) { }
    virtual void visit (reg_ret &v) { }
    virtual void visit (entry &v) { }
    virtual void visit (ptrvar &v) { }
    virtual void visit (intvar &v) { }
    virtual void visit (fltvar &v) { }
    virtual void visit (compcall &v) { }
    virtual void visit (function &v) { }
  };

  struct const_visitor
  {
    virtual void visit (code const &v);

    virtual void visit (instruction const &v) { }
    virtual void visit (assignment const &v) { }
    virtual void visit (mnemonic const &v) { }
    virtual void visit (imm_flt const &v) { }
    virtual void visit (imm_int const &v) { }
    virtual void visit (reg_r const &v) { }
    virtual void visit (reg_v const &v) { }
    virtual void visit (reg_fpr const &v) { }
    virtual void visit (reg_sp const &v) { }
    virtual void visit (reg_fp const &v) { }
    virtual void visit (reg_ret const &v) { }
    virtual void visit (entry const &v) { }
    virtual void visit (ptrvar const &v) { }
    virtual void visit (intvar const &v) { }
    virtual void visit (fltvar const &v) { }
    virtual void visit (compcall const &v) { }
    virtual void visit (function const &v) { }
  };
} // namespace ast

#define DECL_CONSTVISIT                        \
  void visit (::ast::instruction const &v);    \
  void visit (::ast::assignment const &v);     \
  void visit (::ast::mnemonic const &v);       \
  void visit (::ast::imm_flt const &v);        \
  void visit (::ast::imm_int const &v);        \
  void visit (::ast::reg_r const &v);          \
  void visit (::ast::reg_v const &v);          \
  void visit (::ast::reg_fpr const &v);        \
  void visit (::ast::reg_sp const &v);         \
  void visit (::ast::reg_fp const &v);         \
  void visit (::ast::reg_ret const &v);        \
  void visit (::ast::entry const &v);          \
  void visit (::ast::ptrvar const &v);         \
  void visit (::ast::intvar const &v);         \
  void visit (::ast::fltvar const &v);         \
  void visit (::ast::compcall const &v);       \
  void visit (::ast::function const &v)

#define DECL_VISIT                     \
  void visit (::ast::instruction &v);  \
  void visit (::ast::assignment &v);   \
  void visit (::ast::mnemonic &v);     \
  void visit (::ast::imm_flt &v);      \
  void visit (::ast::imm_int &v);      \
  void visit (::ast::reg_r &v);        \
  void visit (::ast::reg_v &v);        \
  void visit (::ast::reg_fpr &v);      \
  void visit (::ast::reg_sp &v);       \
  void visit (::ast::reg_fp &v);       \
  void visit (::ast::reg_ret &v);      \
  void visit (::ast::entry &v);        \
  void visit (::ast::ptrvar &v);       \
  void visit (::ast::intvar &v);       \
  void visit (::ast::fltvar &v);       \
  void visit (::ast::function &v);     \
  void visit (::ast::compcall &v)
    
#endif /* ASSEMBLER_AST_H_INCLUDED */
