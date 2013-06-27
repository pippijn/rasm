#include <jit.h>
#include "assembler/compiler.h"
#include "assembler.h"

assembler &
jitcomp (std::string const &str)
{
  static assembler as;
  compiler comp;

  comp.compile_string ("#function start\n\n" + str);
  comp.check ();
  comp.assemble (as);

  return as;
}

void jit::rshr_l(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::xori_ul(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::addxi_ul(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::bosubr_ui(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::negr_f(jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::subxr_l(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::ori_l(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::hmulr_ul(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::mulr_l(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::divr_ul(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::subci_l(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::addxr_ul(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::bosubr_ul(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::rshr_ul(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::addci_ul(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::notr_uc(jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::hmuli_l(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::subcr_ul(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::subcr_l(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::lshr_l(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::muli_l(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::divr_l(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::extr_f_d(jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::boaddi_ui(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::hmuli_ul(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::addci_l(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::divi_ul(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::xori_l(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::boaddr_ul(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::bosubi_ui(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::bosubi_ul(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::notr_us(jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::addcr_l(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::boaddi_ul(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::subxi_ul(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::hmulr_l(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::modr_l(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::modr_ul(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::muli_ul(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::notr_s(jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::negr_d(jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::addcr_ul(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::subci_ul(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::lshr_ul(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::ori_ul(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::mulr_ul(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::extr_d_f(jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::addxi_l(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::notr_c(jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::modi_ul(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::addxr_l(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::divi_l(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
void jit::subxi_l(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::boaddr_ui(jit::reg32, jit::reg32, jit::reg32) { throw std::runtime_error ("not implemented"); }
void jit::modi_l(jit::reg32, jit::reg32, int) { throw std::runtime_error ("not implemented"); }
