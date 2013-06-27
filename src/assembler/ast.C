#include <assembler/ast.h>

namespace ast
{
  void
  program::invite (const_visitor &v) const
  {
    jit::map<std::string, std::tr1::shared_ptr<ast::code> >::const_iterator it = functions.begin ();
    jit::map<std::string, std::tr1::shared_ptr<ast::code> >::const_iterator et = functions.end ();

    while (it != et)
      {
        it->second->invite (v);
        ++it;
      }
  }

  void
  program::invite (visitor &v)
  {
    jit::map<std::string, std::tr1::shared_ptr<ast::code> >::iterator it = functions.begin ();
    jit::map<std::string, std::tr1::shared_ptr<ast::code> >::iterator et = functions.end ();

    while (it != et)
      {
        it->second->invite (v);
        ++it;
      }
  }

  node::~node () { }

  void code       ::invite (visitor &v) { v.visit (*this); }
  void instruction::invite (visitor &v) { v.visit (*this); }
  void imm_flt    ::invite (visitor &v) { v.visit (*this); }
  void reg_v      ::invite (visitor &v) { v.visit (*this); }
  void reg_r      ::invite (visitor &v) { v.visit (*this); }
  void imm_int    ::invite (visitor &v) { v.visit (*this); }
  void assignment ::invite (visitor &v) { v.visit (*this); }
  void compcall   ::invite (visitor &v) { v.visit (*this); }
  void function   ::invite (visitor &v) { v.visit (*this); }
  void entry      ::invite (visitor &v) { v.visit (*this); }
  void ptrvar     ::invite (visitor &v) { v.visit (*this); }
  void reg_sp     ::invite (visitor &v) { v.visit (*this); }
  void reg_fp     ::invite (visitor &v) { v.visit (*this); }
  void mnemonic   ::invite (visitor &v) { v.visit (*this); }
  void intvar     ::invite (visitor &v) { v.visit (*this); }
  void reg_fpr    ::invite (visitor &v) { v.visit (*this); }
  void fltvar     ::invite (visitor &v) { v.visit (*this); }
  void reg_ret    ::invite (visitor &v) { v.visit (*this); }

  void code       ::invite (const_visitor &v) const { v.visit (*this); }
  void instruction::invite (const_visitor &v) const { v.visit (*this); }
  void imm_flt    ::invite (const_visitor &v) const { v.visit (*this); }
  void reg_v      ::invite (const_visitor &v) const { v.visit (*this); }
  void reg_r      ::invite (const_visitor &v) const { v.visit (*this); }
  void imm_int    ::invite (const_visitor &v) const { v.visit (*this); }
  void assignment ::invite (const_visitor &v) const { v.visit (*this); }
  void compcall   ::invite (const_visitor &v) const { v.visit (*this); }
  void function   ::invite (const_visitor &v) const { v.visit (*this); }
  void entry      ::invite (const_visitor &v) const { v.visit (*this); }
  void ptrvar     ::invite (const_visitor &v) const { v.visit (*this); }
  void reg_sp     ::invite (const_visitor &v) const { v.visit (*this); }
  void reg_fp     ::invite (const_visitor &v) const { v.visit (*this); }
  void mnemonic   ::invite (const_visitor &v) const { v.visit (*this); }
  void intvar     ::invite (const_visitor &v) const { v.visit (*this); }
  void reg_fpr    ::invite (const_visitor &v) const { v.visit (*this); }
  void fltvar     ::invite (const_visitor &v) const { v.visit (*this); }
  void reg_ret    ::invite (const_visitor &v) const { v.visit (*this); }

  void
  visitor::visit (code &v)
  {
    std::vector<std::tr1::shared_ptr<statement> >::iterator it = v.statements.begin ();
    std::vector<std::tr1::shared_ptr<statement> >::iterator et = v.statements.end ();

    while (it != et)
      {
        (*it)->invite (*this);
        ++it;
      }
  }

  void
  const_visitor::visit (code const &v)
  {
    std::vector<std::tr1::shared_ptr<statement> >::const_iterator it = v.statements.begin ();
    std::vector<std::tr1::shared_ptr<statement> >::const_iterator et = v.statements.end ();

    while (it != et)
      {
        (*it)->invite (*this);
        ++it;
      }
  }
}
