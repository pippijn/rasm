// if (O2 <  O3) goto O1
INSN (void, bltr_p, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bltr_l, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bltr_ul, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bltr_i, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bltr_ui, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bltr_f, (reg32 d, reg32 s1, reg32 s2))
INSN (void, bltr_d, (reg32 d, reg32 s1, reg32 s2))

// if (O2 <  O3) goto O1
INSN (insn *, blti_p, (insn *label, reg32 s1, imm32 s2))
INSN (insn *, blti_l, (insn *label, reg32 s1, imm32 s2))
INSN (insn *, blti_ul, (insn *label, reg32 s1, imm32 s2))
INSN (insn *, blti_i, (insn *label, reg32 s1, imm32 s2))
INSN (insn *, blti_ui, (insn *label, reg32 s1, imm32 s2))

// if (O2 <= O3) goto O1
INSN (void, bler_p, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bler_l, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bler_ul, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bler_i, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bler_ui, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bler_f, (reg32 d, reg32 s1, reg32 s2))
INSN (void, bler_d, (reg32 d, reg32 s1, reg32 s2))

// if (O2 <= O3) goto O1
INSN (void, blei_p, (reg32 label, reg32 s1, reg32 s2))
INSN (void, blei_l, (reg32 label, reg32 s1, reg32 s2))
INSN (void, blei_ul, (reg32 label, reg32 s1, reg32 s2))
INSN (void, blei_i, (reg32 label, reg32 s1, reg32 s2))
INSN (void, blei_ui, (reg32 label, reg32 s1, reg32 s2))

// if (O2 >  O3) goto O1
INSN (void, bgtr_p, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bgtr_l, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bgtr_ul, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bgtr_i, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bgtr_ui, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bgtr_f, (reg32 d, reg32 s1, reg32 s2))
INSN (void, bgtr_d, (reg32 d, reg32 s1, reg32 s2))

// if (O2 >  O3) goto O1
INSN (void, bgti_p, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bgti_l, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bgti_ul, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bgti_i, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bgti_ui, (reg32 label, reg32 s1, reg32 s2))

// if (O2 >= O3) goto O1
INSN (void, bger_p, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bger_l, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bger_ul, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bger_i, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bger_ui, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bger_f, (reg32 d, reg32 s1, reg32 s2))
INSN (void, bger_d, (reg32 d, reg32 s1, reg32 s2))

// if (O2 >= O3) goto O1
INSN (void, bgei_p, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bgei_l, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bgei_ul, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bgei_i, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bgei_ui, (reg32 label, reg32 s1, reg32 s2))

// if (O2 == O3) goto O1
INSN (void, beqr_p, (reg32 label, reg32 s1, reg32 s2))
INSN (void, beqr_l, (reg32 label, reg32 s1, reg32 s2))
INSN (void, beqr_ul, (reg32 label, reg32 s1, reg32 s2))
INSN (void, beqr_i, (reg32 label, reg32 s1, reg32 s2))
INSN (void, beqr_ui, (reg32 label, reg32 s1, reg32 s2))
INSN (void, beqr_f, (reg32 d, reg32 s1, reg32 s2))
INSN (void, beqr_d, (reg32 d, reg32 s1, reg32 s2))

// if (O2 == O3) goto O1
INSN (void, beqi_p, (reg32 label, reg32 s1, reg32 s2))
INSN (void, beqi_l, (reg32 label, reg32 s1, reg32 s2))
INSN (void, beqi_ul, (reg32 label, reg32 s1, reg32 s2))
INSN (void, beqi_i, (reg32 label, reg32 s1, reg32 s2))
INSN (void, beqi_ui, (reg32 label, reg32 s1, reg32 s2))

// if (O2 != O3) goto O1
INSN (void, bner_p, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bner_l, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bner_ul, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bner_i, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bner_ui, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bner_f, (reg32 d, reg32 s1, reg32 s2))
INSN (void, bner_d, (reg32 d, reg32 s1, reg32 s2))

// if (O2 != O3) goto O1
INSN (void, bnei_p, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bnei_l, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bnei_ul, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bnei_i, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bnei_ui, (reg32 label, reg32 s1, reg32 s2))

// if !(O2 >= O3) goto O1
INSN (void, bunltr_f, (reg32 d, reg32 s1, reg32 s2))
INSN (void, bunltr_d, (reg32 d, reg32 s1, reg32 s2))

// if !(O2 >  O3) goto O1
INSN (void, bunler_f, (reg32 d, reg32 s1, reg32 s2))
INSN (void, bunler_d, (reg32 d, reg32 s1, reg32 s2))

// if !(O2 <= O3) goto O1
INSN (void, bungtr_f, (reg32 d, reg32 s1, reg32 s2))
INSN (void, bungtr_d, (reg32 d, reg32 s1, reg32 s2))

// if !(O2 <  O3) goto O1
INSN (void, bunger_f, (reg32 d, reg32 s1, reg32 s2))
INSN (void, bunger_d, (reg32 d, reg32 s1, reg32 s2))

// if !(O2 <  O3) && !(O2 >  O3) goto O1
INSN (void, buneqr_f, (reg32 d, reg32 s1, reg32 s2))
INSN (void, buneqr_d, (reg32 d, reg32 s1, reg32 s2))

// if !(O2 >= O3) || !(O2 <= O3) goto O1
INSN (void, bltgtr_f, (reg32 d, reg32 s1, reg32 s2))
INSN (void, bltgtr_d, (reg32 d, reg32 s1, reg32 s2))

// if  (O2 == O2) &&  (O3 == O3) goto O1
INSN (void, bordr_f, (reg32 d, reg32 s1, reg32 s2))
INSN (void, bordr_d, (reg32 d, reg32 s1, reg32 s2))

// if  (O2 != O2) ||  (O3 != O3) goto O1
INSN (void, bunordr_f, (reg32 d, reg32 s1, reg32 s2))
INSN (void, bunordr_d, (reg32 d, reg32 s1, reg32 s2))

// if O2 &  O3 goto O1 (Branch if mask set)
INSN (void, bmsr_i, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bmsr_ui, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bmsr_l, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bmsr_ul, (reg32 label, reg32 s1, reg32 s2))

// if O2 &  O3 goto O1 (Branch if mask set)
INSN (void, bmsi_i, (reg32 label, reg32 rs, imm32 is))
INSN (void, bmsi_ui, (reg32 label, reg32 rs, imm32 is))
INSN (void, bmsi_l, (reg32 label, reg32 rs, imm32 is))
INSN (void, bmsi_ul, (reg32 label, reg32 rs, imm32 is))

// if !(O2 & O3) goto O1 (Branch if mask cleared)
INSN (void, bmcr_i, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bmcr_ui, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bmcr_l, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bmcr_ul, (reg32 label, reg32 s1, reg32 s2))

// if !(O2 & O3) goto O1 (Branch if mask cleared)
INSN (void, bmci_i, (reg32 label, reg32 rs, imm32 is))
INSN (void, bmci_ui, (reg32 label, reg32 rs, imm32 is))
INSN (void, bmci_l, (reg32 label, reg32 rs, imm32 is))
INSN (void, bmci_ul, (reg32 label, reg32 rs, imm32 is))

// O2 += O3, goto O1 on overflow
INSN (void, boaddr_i, (reg32 label, reg32 s1, reg32 s2))
INSN (void, boaddr_ui, (reg32 label, reg32 s1, reg32 s2))
INSN (void, boaddr_l, (reg32 label, reg32 s1, reg32 s2))
INSN (void, boaddr_ul, (reg32 label, reg32 s1, reg32 s2))

// O2 += O3, goto O1 on overflow
INSN (void, boaddi_i, (reg32 label, reg32 rs, imm32 is))
INSN (void, boaddi_ui, (reg32 label, reg32 rs, imm32 is))
INSN (void, boaddi_l, (reg32 label, reg32 rs, imm32 is))
INSN (void, boaddi_ul, (reg32 label, reg32 rs, imm32 is))

// O2 -= O3, goto O1 on overflow
INSN (void, bosubr_i, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bosubr_ui, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bosubr_l, (reg32 label, reg32 s1, reg32 s2))
INSN (void, bosubr_ul, (reg32 label, reg32 s1, reg32 s2))

// O2 -= O3, goto O1 on overflow
INSN (void, bosubi_i, (reg32 label, reg32 rs, imm32 is))
INSN (void, bosubi_ui, (reg32 label, reg32 rs, imm32 is))
INSN (void, bosubi_l, (reg32 label, reg32 rs, imm32 is))
INSN (void, bosubi_ul, (reg32 label, reg32 rs, imm32 is))
