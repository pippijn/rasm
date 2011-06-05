#include <iostream>

#include <assembler/visitors.h>

namespace visitors
{
  rasm::rasm (std::ostream &o)
  : os (o)
  {
  }

  void
  rasm::visit (ast::code const &v)
  {
    os << "\n#function " << *v.func << "\n\n";
    std::vector<std::tr1::shared_ptr<ast::statement> >::const_iterator it = v.statements.begin ();
    std::vector<std::tr1::shared_ptr<ast::statement> >::const_iterator et = v.statements.end ();

    while (it != et)
      {
        (*it)->invite (*this);
        os << '\n';
        ++it;
      }
  }

  void
  rasm::visit (ast::instruction const &v)
  {
    v.mnemonic ().invite (*this);
    if (v.argc () >= 1)
      {
        os << ' ';
        v.operand1 ().invite (*this);
        if (v.argc () >= 2)
          os << ", ";
      }
    if (v.argc () >= 2)
      {
        v.operand2 ().invite (*this);
        if (v.argc () >= 3)
          os << ", ";
      }
    if (v.argc () >= 3)
      {
        v.operand3 ().invite (*this);
      }
  }

  void
  rasm::visit (ast::assignment const &v)
  {
    v.lhs ().invite (*this);
    os << " => ";
    v.rhs ().invite (*this);
  }

  void
  rasm::visit (ast::imm_flt const &v)
  {
    os << v.value ();
  }

  void
  rasm::visit (ast::imm_int const &v)
  {
    os << v.value ();
  }

  void
  rasm::visit (ast::compcall const &v)
  {
    os << '!' << v.name ();
  }

  void
  rasm::visit (ast::function const &v)
  {
    os << '*' << v.name ();
  }

  void
  rasm::visit (ast::reg_r const &v)
  {
    switch (v.value ())
      {
      case jit::R0: os << "%r0"; break;
      case jit::R1: os << "%r1"; break;
      case jit::R2: os << "%r2"; break;
      }
  }

  void
  rasm::visit (ast::reg_v const &v)
  {
    switch (v.value ())
      {
      case jit::V0: os << "%v0"; break;
      case jit::V1: os << "%v1"; break;
      case jit::V2: os << "%v2"; break;
      }
  }

  void
  rasm::visit (ast::reg_sp const &v)
  {
    os << "%sp";
  }

  void
  rasm::visit (ast::reg_fp const &v)
  {
    os << "%fp";
  }

  void
  rasm::visit (ast::mnemonic const &v)
  {
    os << v.name ();
  }

  void
  rasm::visit (ast::reg_fpr const &v)
  {
    switch (v.value ())
      {
      case jit::FPR0: os << "%fpr0"; break;
      case jit::FPR1: os << "%fpr1"; break;
      case jit::FPR2: os << "%fpr2"; break;
      case jit::FPR3: os << "%fpr3"; break;
      case jit::FPR4: os << "%fpr4"; break;
      case jit::FPR5: os << "%fpr5"; break;
      }
  }

  void
  rasm::visit (ast::entry const &v)
  {
    os << '=' << v.name ();
  }

  void
  rasm::visit (ast::ptrvar const &v)
  {
    os << '@' << v.name ();
  }

  void
  rasm::visit (ast::intvar const &v)
  {
    os << '$' << v.name ();
  }

  void
  rasm::visit (ast::fltvar const &v)
  {
    os << '&' << v.name ();
  }

  void
  rasm::visit (ast::reg_ret const &v)
  {
    os << "%ret";
  }
}
