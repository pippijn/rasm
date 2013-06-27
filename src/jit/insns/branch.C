#include <jit.h>

#define _jit this->current

#if 1
// if (O2 <  O3) goto O1
void jit::bltr_p (reg32 label, reg32 s1, reg32 s2) { jit_bltr_p (label, s1, s2); }
void jit::bltr_l (reg32 label, reg32 s1, reg32 s2) { jit_bltr_l (label, s1, s2); }
void jit::bltr_ul (reg32 label, reg32 s1, reg32 s2) { jit_bltr_ul (label, s1, s2); }
void jit::bltr_i (reg32 label, reg32 s1, reg32 s2) { jit_bltr_i (label, s1, s2); }
void jit::bltr_ui (reg32 label, reg32 s1, reg32 s2) { jit_bltr_ui (label, s1, s2); }
void jit::bltr_f (reg32 d, reg32 s1, reg32 s2) { jit_bltr_f (d, s1, s2); }
void jit::bltr_d (reg32 d, reg32 s1, reg32 s2) { jit_bltr_d (d, s1, s2); }

// if (O2 <  O3) goto O1
jit::insn *jit::blti_p (insn *label, reg32 s1, imm32 s2) { return jit_blti_p (label, s1, s2); }
jit::insn *jit::blti_l (insn *label, reg32 s1, imm32 s2) { return jit_blti_l (label, s1, s2); }
jit::insn *jit::blti_ul (insn *label, reg32 s1, imm32 s2) { return jit_blti_ul (label, s1, s2); }
jit::insn *jit::blti_i (insn *label, reg32 s1, imm32 s2) { return jit_blti_i (label, s1, s2); }
jit::insn *jit::blti_ui (insn *label, reg32 s1, imm32 s2) { return jit_blti_ui (label, s1, s2); }

// if (O2 <= O3) goto O1
void jit::bler_p (reg32 label, reg32 s1, reg32 s2) { jit_bler_p (label, s1, s2); }
void jit::bler_l (reg32 label, reg32 s1, reg32 s2) { jit_bler_l (label, s1, s2); }
void jit::bler_ul (reg32 label, reg32 s1, reg32 s2) { jit_bler_ul (label, s1, s2); }
void jit::bler_i (reg32 label, reg32 s1, reg32 s2) { jit_bler_i (label, s1, s2); }
void jit::bler_ui (reg32 label, reg32 s1, reg32 s2) { jit_bler_ui (label, s1, s2); }
void jit::bler_f (reg32 d, reg32 s1, reg32 s2) { jit_bler_f (d, s1, s2); }
void jit::bler_d (reg32 d, reg32 s1, reg32 s2) { jit_bler_d (d, s1, s2); }

// if (O2 <= O3) goto O1
void jit::blei_p (reg32 label, reg32 s1, reg32 s2) { jit_blei_p (label, s1, s2); }
void jit::blei_l (reg32 label, reg32 s1, reg32 s2) { jit_blei_l (label, s1, s2); }
void jit::blei_ul (reg32 label, reg32 s1, reg32 s2) { jit_blei_ul (label, s1, s2); }
void jit::blei_i (reg32 label, reg32 s1, reg32 s2) { jit_blei_i (label, s1, s2); }
void jit::blei_ui (reg32 label, reg32 s1, reg32 s2) { jit_blei_ui (label, s1, s2); }

// if (O2 >  O3) goto O1
void jit::bgtr_p (reg32 label, reg32 s1, reg32 s2) { jit_bgtr_p (label, s1, s2); }
void jit::bgtr_l (reg32 label, reg32 s1, reg32 s2) { jit_bgtr_l (label, s1, s2); }
void jit::bgtr_ul (reg32 label, reg32 s1, reg32 s2) { jit_bgtr_ul (label, s1, s2); }
void jit::bgtr_i (reg32 label, reg32 s1, reg32 s2) { jit_bgtr_i (label, s1, s2); }
void jit::bgtr_ui (reg32 label, reg32 s1, reg32 s2) { jit_bgtr_ui (label, s1, s2); }
void jit::bgtr_f (reg32 d, reg32 s1, reg32 s2) { jit_bgtr_f (d, s1, s2); }
void jit::bgtr_d (reg32 d, reg32 s1, reg32 s2) { jit_bgtr_d (d, s1, s2); }

// if (O2 >  O3) goto O1
void jit::bgti_p (reg32 label, reg32 s1, reg32 s2) { jit_bgti_p (label, s1, s2); }
void jit::bgti_l (reg32 label, reg32 s1, reg32 s2) { jit_bgti_l (label, s1, s2); }
void jit::bgti_ul (reg32 label, reg32 s1, reg32 s2) { jit_bgti_ul (label, s1, s2); }
void jit::bgti_i (reg32 label, reg32 s1, reg32 s2) { jit_bgti_i (label, s1, s2); }
void jit::bgti_ui (reg32 label, reg32 s1, reg32 s2) { jit_bgti_ui (label, s1, s2); }

// if (O2 >= O3) goto O1
void jit::bger_p (reg32 label, reg32 s1, reg32 s2) { jit_bger_p (label, s1, s2); }
void jit::bger_l (reg32 label, reg32 s1, reg32 s2) { jit_bger_l (label, s1, s2); }
void jit::bger_ul (reg32 label, reg32 s1, reg32 s2) { jit_bger_ul (label, s1, s2); }
void jit::bger_i (reg32 label, reg32 s1, reg32 s2) { jit_bger_i (label, s1, s2); }
void jit::bger_ui (reg32 label, reg32 s1, reg32 s2) { jit_bger_ui (label, s1, s2); }
void jit::bger_f (reg32 d, reg32 s1, reg32 s2) { jit_bger_f (d, s1, s2); }
void jit::bger_d (reg32 d, reg32 s1, reg32 s2) { jit_bger_d (d, s1, s2); }

// if (O2 >= O3) goto O1
void jit::bgei_p (reg32 label, reg32 s1, reg32 s2) { jit_bgei_p (label, s1, s2); }
void jit::bgei_l (reg32 label, reg32 s1, reg32 s2) { jit_bgei_l (label, s1, s2); }
void jit::bgei_ul (reg32 label, reg32 s1, reg32 s2) { jit_bgei_ul (label, s1, s2); }
void jit::bgei_i (reg32 label, reg32 s1, reg32 s2) { jit_bgei_i (label, s1, s2); }
void jit::bgei_ui (reg32 label, reg32 s1, reg32 s2) { jit_bgei_ui (label, s1, s2); }

// if (O2 == O3) goto O1
void jit::beqr_p (reg32 label, reg32 s1, reg32 s2) { jit_beqr_p (label, s1, s2); }
void jit::beqr_l (reg32 label, reg32 s1, reg32 s2) { jit_beqr_l (label, s1, s2); }
void jit::beqr_ul (reg32 label, reg32 s1, reg32 s2) { jit_beqr_ul (label, s1, s2); }
void jit::beqr_i (reg32 label, reg32 s1, reg32 s2) { jit_beqr_i (label, s1, s2); }
void jit::beqr_ui (reg32 label, reg32 s1, reg32 s2) { jit_beqr_ui (label, s1, s2); }
void jit::beqr_f (reg32 d, reg32 s1, reg32 s2) { jit_beqr_f (d, s1, s2); }
void jit::beqr_d (reg32 d, reg32 s1, reg32 s2) { jit_beqr_d (d, s1, s2); }

// if (O2 == O3) goto O1
void jit::beqi_p (reg32 label, reg32 s1, reg32 s2) { jit_beqi_p (label, s1, s2); }
void jit::beqi_l (reg32 label, reg32 s1, reg32 s2) { jit_beqi_l (label, s1, s2); }
void jit::beqi_ul (reg32 label, reg32 s1, reg32 s2) { jit_beqi_ul (label, s1, s2); }
void jit::beqi_i (reg32 label, reg32 s1, reg32 s2) { jit_beqi_i (label, s1, s2); }
void jit::beqi_ui (reg32 label, reg32 s1, reg32 s2) { jit_beqi_ui (label, s1, s2); }

// if (O2 != O3) goto O1
void jit::bner_p (reg32 label, reg32 s1, reg32 s2) { jit_bner_p (label, s1, s2); }
void jit::bner_l (reg32 label, reg32 s1, reg32 s2) { jit_bner_l (label, s1, s2); }
void jit::bner_ul (reg32 label, reg32 s1, reg32 s2) { jit_bner_ul (label, s1, s2); }
void jit::bner_i (reg32 label, reg32 s1, reg32 s2) { jit_bner_i (label, s1, s2); }
void jit::bner_ui (reg32 label, reg32 s1, reg32 s2) { jit_bner_ui (label, s1, s2); }
void jit::bner_f (reg32 d, reg32 s1, reg32 s2) { jit_bner_f (d, s1, s2); }
void jit::bner_d (reg32 d, reg32 s1, reg32 s2) { jit_bner_d (d, s1, s2); }

// if (O2 != O3) goto O1
void jit::bnei_p (reg32 label, reg32 s1, reg32 s2) { jit_bnei_p (label, s1, s2); }
void jit::bnei_l (reg32 label, reg32 s1, reg32 s2) { jit_bnei_l (label, s1, s2); }
void jit::bnei_ul (reg32 label, reg32 s1, reg32 s2) { jit_bnei_ul (label, s1, s2); }
void jit::bnei_i (reg32 label, reg32 s1, reg32 s2) { jit_bnei_i (label, s1, s2); }
void jit::bnei_ui (reg32 label, reg32 s1, reg32 s2) { jit_bnei_ui (label, s1, s2); }

// if !(O2 >= O3) goto O1
void jit::bunltr_f (reg32 d, reg32 s1, reg32 s2) { jit_bunltr_f (d, s1, s2); }
void jit::bunltr_d (reg32 d, reg32 s1, reg32 s2) { jit_bunltr_d (d, s1, s2); }

// if !(O2 >  O3) goto O1
void jit::bunler_f (reg32 d, reg32 s1, reg32 s2) { jit_bunler_f (d, s1, s2); }
void jit::bunler_d (reg32 d, reg32 s1, reg32 s2) { jit_bunler_d (d, s1, s2); }

// if !(O2 <= O3) goto O1
void jit::bungtr_f (reg32 d, reg32 s1, reg32 s2) { jit_bungtr_f (d, s1, s2); }
void jit::bungtr_d (reg32 d, reg32 s1, reg32 s2) { jit_bungtr_d (d, s1, s2); }

// if !(O2 <  O3) goto O1
void jit::bunger_f (reg32 d, reg32 s1, reg32 s2) { jit_bunger_f (d, s1, s2); }
void jit::bunger_d (reg32 d, reg32 s1, reg32 s2) { jit_bunger_d (d, s1, s2); }

// if !(O2 <  O3) && !(O2 >  O3) goto O1
void jit::buneqr_f (reg32 d, reg32 s1, reg32 s2) { jit_buneqr_f (d, s1, s2); }
void jit::buneqr_d (reg32 d, reg32 s1, reg32 s2) { jit_buneqr_d (d, s1, s2); }

// if !(O2 >= O3) || !(O2 <= O3) goto O1
void jit::bltgtr_f (reg32 d, reg32 s1, reg32 s2) { jit_bltgtr_f (d, s1, s2); }
void jit::bltgtr_d (reg32 d, reg32 s1, reg32 s2) { jit_bltgtr_d (d, s1, s2); }

// if  (O2 == O2) &&  (O3 == O3) goto O1
void jit::bordr_f (reg32 d, reg32 s1, reg32 s2) { jit_bordr_f (d, s1, s2); }
void jit::bordr_d (reg32 d, reg32 s1, reg32 s2) { jit_bordr_d (d, s1, s2); }

// if  (O2 != O2) ||  (O3 != O3) goto O1
void jit::bunordr_f (reg32 d, reg32 s1, reg32 s2) { jit_bunordr_f (d, s1, s2); }
void jit::bunordr_d (reg32 d, reg32 s1, reg32 s2) { jit_bunordr_d (d, s1, s2); }

// if O2 &  O3 goto O1 (Branch if mask set)
void jit::bmsr_i (reg32 label, reg32 s1, reg32 s2) { jit_bmsr_i (label, s1, s2); }
void jit::bmsr_ui (reg32 label, reg32 s1, reg32 s2) { jit_bmsr_ui (label, s1, s2); }
void jit::bmsr_l (reg32 label, reg32 s1, reg32 s2) { jit_bmsr_l (label, s1, s2); }
void jit::bmsr_ul (reg32 label, reg32 s1, reg32 s2) { jit_bmsr_ul (label, s1, s2); }

// if O2 &  O3 goto O1 (Branch if mask set)
void jit::bmsi_i (reg32 label, reg32 rs, imm32 is) { jit_bmsi_i (label, rs, is); }
void jit::bmsi_ui (reg32 label, reg32 rs, imm32 is) { jit_bmsi_ui (label, rs, is); }
void jit::bmsi_l (reg32 label, reg32 rs, imm32 is) { jit_bmsi_l (label, rs, is); }
void jit::bmsi_ul (reg32 label, reg32 rs, imm32 is) { jit_bmsi_ul (label, rs, is); }

// if !(O2 & O3) goto O1 (Branch if mask cleared)
void jit::bmcr_i (reg32 label, reg32 s1, reg32 s2) { jit_bmcr_i (label, s1, s2); }
void jit::bmcr_ui (reg32 label, reg32 s1, reg32 s2) { jit_bmcr_ui (label, s1, s2); }
void jit::bmcr_l (reg32 label, reg32 s1, reg32 s2) { jit_bmcr_l (label, s1, s2); }
void jit::bmcr_ul (reg32 label, reg32 s1, reg32 s2) { jit_bmcr_ul (label, s1, s2); }

// if !(O2 & O3) goto O1 (Branch if mask cleared)
void jit::bmci_i (reg32 label, reg32 rs, imm32 is) { jit_bmci_i (label, rs, is); }
void jit::bmci_ui (reg32 label, reg32 rs, imm32 is) { jit_bmci_ui (label, rs, is); }
void jit::bmci_l (reg32 label, reg32 rs, imm32 is) { jit_bmci_l (label, rs, is); }
void jit::bmci_ul (reg32 label, reg32 rs, imm32 is) { jit_bmci_ul (label, rs, is); }

// O2 += O3, goto O1 on overflow
void jit::boaddr_i (reg32 label, reg32 s1, reg32 s2) { jit_boaddr_i (label, s1, s2); }
//void jit::boaddr_ui (reg32 label, reg32 s1, reg32 s2) { jit_boaddr_ui (label, s1, s2); }
void jit::boaddr_l (reg32 label, reg32 s1, reg32 s2) { jit_boaddr_l (label, s1, s2); }
//void jit::boaddr_ul (reg32 label, reg32 s1, reg32 s2) { jit_boaddr_ul (label, s1, s2); }

// O2 += O3, goto O1 on overflow
void jit::boaddi_i (reg32 label, reg32 rs, imm32 is) { jit_boaddi_i (label, rs, is); }
//void jit::boaddi_ui (reg32 label, reg32 rs, imm32 is) { jit_boaddi_ui (label, rs, is); }
void jit::boaddi_l (reg32 label, reg32 rs, imm32 is) { jit_boaddi_l (label, rs, is); }
//void jit::boaddi_ul (reg32 label, reg32 rs, imm32 is) { jit_boaddi_ul (label, rs, is); }

// O2 -= O3, goto O1 on overflow
void jit::bosubr_i (reg32 label, reg32 s1, reg32 s2) { jit_bosubr_i (label, s1, s2); }
//void jit::bosubr_ui (reg32 label, reg32 s1, reg32 s2) { jit_bosubr_ui (label, s1, s2); }
void jit::bosubr_l (reg32 label, reg32 s1, reg32 s2) { jit_bosubr_l (label, s1, s2); }
//void jit::bosubr_ul (reg32 label, reg32 s1, reg32 s2) { jit_bosubr_ul (label, s1, s2); }

// O2 -= O3, goto O1 on overflow
void jit::bosubi_i (reg32 label, reg32 rs, imm32 is) { jit_bosubi_i (label, rs, is); }
//void jit::bosubi_ui (reg32 label, reg32 rs, imm32 is) { jit_bosubi_ui (label, rs, is); }
void jit::bosubi_l (reg32 label, reg32 rs, imm32 is) { jit_bosubi_l (label, rs, is); }
//void jit::bosubi_ul (reg32 label, reg32 rs, imm32 is) { jit_bosubi_ul (label, rs, is); }
#endif
