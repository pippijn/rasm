#include <jit.h>

#define _jit this->current

#if 1
// O1 = O2 + O3
void jit::addr_ui (reg32 d, reg32 s1, reg32 s2) { jit_addr_ui (d, s1, s2); }
void jit::addr_ul (reg32 d, reg32 s1, reg32 s2) { jit_addr_ul (d, s1, s2); }
void jit::addr_p (reg32 d, reg32 s1, reg32 s2) { jit_addr_p (d, s1, s2); }
void jit::addr_l (reg32 d, reg32 s1, reg32 s2) { jit_addr_l (d, s1, s2); }
void jit::addr_i (reg32 d, reg32 s1, reg32 s2) { jit_addr_i (d, s1, s2); }
void jit::addr_d (reg32 rd, reg32 s1, reg32 s2) { jit_addr_d (rd, s1, s2); }
void jit::addr_f (reg32 rd, reg32 s1, reg32 s2) { jit_addr_f (rd, s1, s2); }

// O1 = O2 + O3
void jit::addi_ui (reg32 d, reg32 rs, imm32 is) { jit_addi_ui (d, rs, is); }
void jit::addi_ul (reg32 d, reg32 rs, imm32 is) { jit_addi_ul (d, rs, is); }
void jit::addi_p (reg32 d, reg32 rs, imm32 is) { jit_addi_p (d, rs, is); }
void jit::addi_l (reg32 d, reg32 rs, imm32 is) { jit_addi_l (d, rs, is); }
void jit::addi_i (reg32 d, reg32 rs, imm32 is) { jit_addi_i (d, rs, is); }

// O1 = O2 + (O3 + carry)
void jit::addxr_ui (reg32 d, reg32 s1, reg32 s2) { jit_addxr_ui (d, s1, s2); }
//void jit::addxr_ul (reg32 d, reg32 s1, reg32 s2) { jit_addxr_ul (d, s1, s2); }
//void jit::addxr_l (reg32 d, reg32 s1, reg32 s2) { jit_addxr_l (d, s1, s2); }
void jit::addxr_i (reg32 d, reg32 s1, reg32 s2) { jit_addxr_i (d, s1, s2); }

// O1 = O2 + (O3 + carry)
void jit::addxi_ui (reg32 d, reg32 s1, reg32 s2) { jit_addxi_ui (d, s1, s2); }
//void jit::addxi_ul (reg32 d, reg32 s1, reg32 s2) { jit_addxi_ul (d, s1, s2); }
//void jit::addxi_l (reg32 d, reg32 s1, reg32 s2) { jit_addxi_l (d, s1, s2); }
void jit::addxi_i (reg32 d, reg32 s1, reg32 s2) { jit_addxi_i (d, s1, s2); }

// O1 = O2 + O3, set carry
void jit::addcr_ui (reg32 d, reg32 rs, imm32 is) { jit_addcr_ui (d, rs, is); }
//void jit::addcr_ul (reg32 d, reg32 rs, imm32 is) { jit_addcr_ul (d, rs, is); }
//void jit::addcr_l (reg32 d, reg32 rs, imm32 is) { jit_addcr_l (d, rs, is); }
void jit::addcr_i (reg32 d, reg32 rs, imm32 is) { jit_addcr_i (d, rs, is); }

// O1 = O2 + O3, set carry
void jit::addci_ui (reg32 d, reg32 rs, imm32 is) { jit_addci_ui (d, rs, is); }
//void jit::addci_ul (reg32 d, reg32 rs, imm32 is) { jit_addci_ul (d, rs, is); }
//void jit::addci_l (reg32 d, reg32 rs, imm32 is) { jit_addci_l (d, rs, is); }
void jit::addci_i (reg32 d, reg32 rs, imm32 is) { jit_addci_i (d, rs, is); }

// O1 = O2 - O3
void jit::subr_ui (reg32 d, reg32 s1, reg32 s2) { jit_subr_ui (d, s1, s2); }
void jit::subr_ul (reg32 d, reg32 s1, reg32 s2) { jit_subr_ul (d, s1, s2); }
void jit::subr_p (reg32 d, reg32 s1, reg32 s2) { jit_subr_p (d, s1, s2); }
void jit::subr_l (reg32 d, reg32 s1, reg32 s2) { jit_subr_l (d, s1, s2); }
void jit::subr_i (reg32 d, reg32 s1, reg32 s2) { jit_subr_i (d, s1, s2); }
void jit::subr_d (reg32 rd, reg32 s1, reg32 s2) { jit_subr_d (rd, s1, s2); }
void jit::subr_f (reg32 rd, reg32 s1, reg32 s2) { jit_subr_f (rd, s1, s2); }

// O1 = O2 - O3
void jit::subi_ui (reg32 d, reg32 rs, imm32 is) { jit_subi_ui (d, rs, is); }
void jit::subi_ul (reg32 d, reg32 rs, imm32 is) { jit_subi_ul (d, rs, is); }
void jit::subi_p (reg32 d, reg32 rs, imm32 is) { jit_subi_p (d, rs, is); }
void jit::subi_l (reg32 d, reg32 rs, imm32 is) { jit_subi_l (d, rs, is); }
void jit::subi_i (reg32 d, reg32 rs, imm32 is) { jit_subi_i (d, rs, is); }

// O1 = O2 - (O3 - carry)
void jit::subxr_ui (reg32 d, reg32 s1, reg32 s2) { jit_subxr_ui (d, s1, s2); }
void jit::subxr_ul (reg32 d, reg32 s1, reg32 s2) { jit_subxr_ul (d, s1, s2); }
//void jit::subxr_l (reg32 d, reg32 s1, reg32 s2) { jit_subxr_l (d, s1, s2); }
void jit::subxr_i (reg32 d, reg32 s1, reg32 s2) { jit_subxr_i (d, s1, s2); }

// O1 = O2 - (O3 - carry)
void jit::subxi_ui (reg32 d, reg32 s1, reg32 s2) { jit_subxi_ui (d, s1, s2); }
//void jit::subxi_ul (reg32 d, reg32 s1, reg32 s2) { jit_subxi_ul (d, s1, s2); }
//void jit::subxi_l (reg32 d, reg32 s1, reg32 s2) { jit_subxi_l (d, s1, s2); }
void jit::subxi_i (reg32 d, reg32 s1, reg32 s2) { jit_subxi_i (d, s1, s2); }

// O1 = O2 - O3, set carry
void jit::subcr_ui (reg32 d, reg32 rs, imm32 is) { jit_subcr_ui (d, rs, is); }
//void jit::subcr_ul (reg32 d, reg32 rs, imm32 is) { jit_subcr_ul (d, rs, is); }
//void jit::subcr_l (reg32 d, reg32 rs, imm32 is) { jit_subcr_l (d, rs, is); }
void jit::subcr_i (reg32 d, reg32 rs, imm32 is) { jit_subcr_i (d, rs, is); }

// O1 = O2 - O3, set carry
void jit::subci_ui (reg32 d, reg32 rs, imm32 is) { jit_subci_ui (d, rs, is); }
//void jit::subci_ul (reg32 d, reg32 rs, imm32 is) { jit_subci_ul (d, rs, is); }
//void jit::subci_l (reg32 d, reg32 rs, imm32 is) { jit_subci_l (d, rs, is); }
void jit::subci_i (reg32 d, reg32 rs, imm32 is) { jit_subci_i (d, rs, is); }

// O1 = O3 - O2
void jit::rsbr_ui (reg32 d, reg32 s1, reg32 s2) { jit_rsbr_ui (d, s1, s2); }
void jit::rsbr_ul (reg32 d, reg32 s1, reg32 s2) { jit_rsbr_ul (d, s1, s2); }
void jit::rsbr_f (reg32 rd, reg32 s1, reg32 s2) { jit_rsbr_f (rd, s1, s2); }
void jit::rsbr_d (reg32 rd, reg32 s1, reg32 s2) { jit_rsbr_d (rd, s1, s2); }
void jit::rsbr_i (reg32 d, reg32 s1, reg32 s2) { jit_rsbr_i (d, s1, s2); }
void jit::rsbr_l (reg32 d, reg32 s1, reg32 s2) { jit_rsbr_l (d, s1, s2); }
void jit::rsbr_p (reg32 d, reg32 s1, reg32 s2) { jit_rsbr_p (d, s1, s2); }

// O1 = O3 - O2
void jit::rsbi_ui (reg32 d, reg32 rs, imm32 is) { jit_rsbi_ui (d, rs, is); }
void jit::rsbi_ul (reg32 d, reg32 rs, imm32 is) { jit_rsbi_ul (d, rs, is); }
void jit::rsbi_p (reg32 d, reg32 rs, imm32 is) { jit_rsbi_p (d, rs, is); }
void jit::rsbi_i (reg32 d, reg32 rs, imm32 is) { jit_rsbi_i (d, rs, is); }
void jit::rsbi_l (reg32 d, reg32 rs, imm32 is) { jit_rsbi_l (d, rs, is); }

// O1 = O2 * O3
//void jit::mulr_l (reg32 d, reg32 s1, reg32 s2) { jit_mulr_l (d, s1, s2); }
//void jit::mulr_ul (reg32 d, reg32 s1, reg32 s2) { jit_mulr_ul (d, s1, s2); }
void jit::mulr_i (reg32 d, reg32 s1, reg32 s2) { jit_mulr_i (d, s1, s2); }
void jit::mulr_ui (reg32 d, reg32 s1, reg32 s2) { jit_mulr_ui (d, s1, s2); }
void jit::mulr_f (reg32 rd, reg32 s1, reg32 s2) { jit_mulr_f (rd, s1, s2); }
void jit::mulr_d (reg32 rd, reg32 s1, reg32 s2) { jit_mulr_d (rd, s1, s2); }

// O1 = O2 * O3
//void jit::muli_l (reg32 d, reg32 rs, imm32 is) { jit_muli_l (d, rs, is); }
//void jit::muli_ul (reg32 d, reg32 rs, imm32 is) { jit_muli_ul (d, rs, is); }
void jit::muli_i (reg32 d, reg32 rs, imm32 is) { jit_muli_i (d, rs, is); }
void jit::muli_ui (reg32 d, reg32 rs, imm32 is) { jit_muli_ui (d, rs, is); }

// O1 = high bits of O2 * O3
//void jit::hmulr_l (reg32 d, reg32 s1, reg32 s2) { jit_hmulr_l (d, s1, s2); }
//void jit::hmulr_ul (reg32 d, reg32 s1, reg32 s2) { jit_hmulr_ul (d, s1, s2); }
void jit::hmulr_i (reg32 d, reg32 s1, reg32 s2) { jit_hmulr_i (d, s1, s2); }
void jit::hmulr_ui (reg32 d, reg32 s1, reg32 s2) { jit_hmulr_ui (d, s1, s2); }

// O1 = high bits of O2 * O3
//void jit::hmuli_l (reg32 d, reg32 rs, imm32 is) { jit_hmuli_l (d, rs, is); }
//void jit::hmuli_ul (reg32 d, reg32 rs, imm32 is) { jit_hmuli_ul (d, rs, is); }
void jit::hmuli_i (reg32 d, reg32 rs, imm32 is) { jit_hmuli_i (d, rs, is); }
void jit::hmuli_ui (reg32 d, reg32 rs, imm32 is) { jit_hmuli_ui (d, rs, is); }

// O1 = O2 / O3
//void jit::divr_l (reg32 d, reg32 s1, reg32 s2) { jit_divr_l (d, s1, s2); }
//void jit::divr_ul (reg32 d, reg32 s1, reg32 s2) { jit_divr_ul (d, s1, s2); }
void jit::divr_i (reg32 d, reg32 s1, reg32 s2) { jit_divr_i (d, s1, s2); }
void jit::divr_ui (reg32 d, reg32 s1, reg32 s2) { jit_divr_ui (d, s1, s2); }
void jit::divr_f (reg32 rd, reg32 s1, reg32 s2) { jit_divr_f (rd, s1, s2); }
void jit::divr_d (reg32 rd, reg32 s1, reg32 s2) { jit_divr_d (rd, s1, s2); }

// O1 = O2 / O3
//void jit::divi_l (reg32 d, reg32 rs, imm32 is) { jit_divi_l (d, rs, is); }
//void jit::divi_ul (reg32 d, reg32 rs, imm32 is) { jit_divi_ul (d, rs, is); }
void jit::divi_i (reg32 d, reg32 rs, imm32 is) { jit_divi_i (d, rs, is); }
void jit::divi_ui (reg32 d, reg32 rs, imm32 is) { jit_divi_ui (d, rs, is); }

// O1 = O2 % O3
//void jit::modr_l (reg32 d, reg32 s1, reg32 s2) { jit_modr_l (d, s1, s2); }
//void jit::modr_ul (reg32 d, reg32 s1, reg32 s2) { jit_modr_ul (d, s1, s2); }
void jit::modr_i (reg32 d, reg32 s1, reg32 s2) { jit_modr_i (d, s1, s2); }
void jit::modr_ui (reg32 d, reg32 s1, reg32 s2) { jit_modr_ui (d, s1, s2); }

// O1 = O2 % O3
//void jit::modi_l (reg32 d, reg32 rs, imm32 is) { jit_modi_l (d, rs, is); }
//void jit::modi_ul (reg32 d, reg32 rs, imm32 is) { jit_modi_ul (d, rs, is); }
void jit::modi_i (reg32 d, reg32 rs, imm32 is) { jit_modi_i (d, rs, is); }
void jit::modi_ui (reg32 d, reg32 rs, imm32 is) { jit_modi_ui (d, rs, is); }

// O1 = O2 & O3
void jit::andr_l (reg32 d, reg32 s1, reg32 s2) { jit_andr_l (d, s1, s2); }
void jit::andr_ul (reg32 d, reg32 s1, reg32 s2) { jit_andr_ul (d, s1, s2); }
void jit::andr_i (reg32 d, reg32 s1, reg32 s2) { jit_andr_i (d, s1, s2); }
void jit::andr_ui (reg32 d, reg32 s1, reg32 s2) { jit_andr_ui (d, s1, s2); }

// O1 = O2 & O3
void jit::andi_l (reg32 d, reg32 rs, imm32 is) { jit_andi_l (d, rs, is); }
void jit::andi_ul (reg32 d, reg32 rs, imm32 is) { jit_andi_ul (d, rs, is); }
void jit::andi_i (reg32 d, reg32 rs, imm32 is) { jit_andi_i (d, rs, is); }
void jit::andi_ui (reg32 d, reg32 rs, imm32 is) { jit_andi_ui (d, rs, is); }

// O1 = O2 | O3
void jit::orr_l (reg32 d, reg32 s1, reg32 s2) { jit_orr_l (d, s1, s2); }
void jit::orr_ul (reg32 d, reg32 s1, reg32 s2) { jit_orr_ul (d, s1, s2); }
void jit::orr_i (reg32 d, reg32 s1, reg32 s2) { jit_orr_i (d, s1, s2); }
void jit::orr_ui (reg32 d, reg32 s1, reg32 s2) { jit_orr_ui (d, s1, s2); }

// O1 = O2 | O3
//void jit::ori_l (reg32 d, reg32 rs, imm32 is) { jit_ori_l (d, rs, is); }
//void jit::ori_ul (reg32 d, reg32 rs, imm32 is) { jit_ori_ul (d, rs, is); }
void jit::ori_i (reg32 d, reg32 rs, imm32 is) { jit_ori_i (d, rs, is); }
void jit::ori_ui (reg32 d, reg32 rs, imm32 is) { jit_ori_ui (d, rs, is); }

// O1 = O2 ^ O3
void jit::xorr_l (reg32 d, reg32 s1, reg32 s2) { jit_xorr_l (d, s1, s2); }
void jit::xorr_ul (reg32 d, reg32 s1, reg32 s2) { jit_xorr_ul (d, s1, s2); }
void jit::xorr_i (reg32 d, reg32 s1, reg32 s2) { jit_xorr_i (d, s1, s2); }
void jit::xorr_ui (reg32 d, reg32 s1, reg32 s2) { jit_xorr_ui (d, s1, s2); }

// O1 = O2 ^ O3
//void jit::xori_l (reg32 d, reg32 rs, imm32 is) { jit_xori_l (d, rs, is); }
//void jit::xori_ul (reg32 d, reg32 rs, imm32 is) { jit_xori_ul (d, rs, is); }
void jit::xori_i (reg32 d, reg32 rs, imm32 is) { jit_xori_i (d, rs, is); }
void jit::xori_ui (reg32 d, reg32 rs, imm32 is) { jit_xori_ui (d, rs, is); }

// O1 = O2 << O3
//void jit::lshr_l (reg32 d, reg32 s1, reg32 s2) { jit_lshr_l (d, s1, s2); }
//void jit::lshr_ul (reg32 d, reg32 s1, reg32 s2) { jit_lshr_ul (d, s1, s2); }
void jit::lshr_i (reg32 d, reg32 s1, reg32 s2) { jit_lshr_i (d, s1, s2); }
void jit::lshr_ui (reg32 d, reg32 s1, reg32 s2) { jit_lshr_ui (d, s1, s2); }

// O1 = O2 << O3
void jit::lshi_l (reg32 d, reg32 rs, imm32 is) { jit_lshi_l (d, rs, is); }
void jit::lshi_ul (reg32 d, reg32 rs, imm32 is) { jit_lshi_ul (d, rs, is); }
void jit::lshi_i (reg32 d, reg32 rs, imm32 is) { jit_lshi_i (d, rs, is); }
void jit::lshi_ui (reg32 d, reg32 rs, imm32 is) { jit_lshi_ui (d, rs, is); }

// O1 = O2 >> O3
//void jit::rshr_l (reg32 d, reg32 s1, reg32 s2) { jit_rshr_l (d, s1, s2); }
//void jit::rshr_ul (reg32 d, reg32 s1, reg32 s2) { jit_rshr_ul (d, s1, s2); }
void jit::rshr_i (reg32 d, reg32 s1, reg32 s2) { jit_rshr_i (d, s1, s2); }
void jit::rshr_ui (reg32 d, reg32 s1, reg32 s2) { jit_rshr_ui (d, s1, s2); }

// O1 = O2 >> O3
void jit::rshi_l (reg32 d, reg32 rs, imm32 is) { jit_rshi_l (d, rs, is); }
void jit::rshi_ul (reg32 d, reg32 rs, imm32 is) { jit_rshi_ul (d, rs, is); }
void jit::rshi_i (reg32 d, reg32 rs, imm32 is) { jit_rshi_i (d, rs, is); }
void jit::rshi_ui (reg32 d, reg32 rs, imm32 is) { jit_rshi_ui (d, rs, is); }
#endif
