// O1 = O2 + O3
INSN (void, addr_ui, (reg32 d, reg32 s1, reg32 s2))
INSN (void, addr_ul, (reg32 d, reg32 s1, reg32 s2))
INSN (void, addr_p, (reg32 d, reg32 s1, reg32 s2))
INSN (void, addr_l, (reg32 d, reg32 s1, reg32 s2))
INSN (void, addr_i, (reg32 d, reg32 s1, reg32 s2))
INSN (void, addr_d, (reg32 rd, reg32 s1, reg32 s2))
INSN (void, addr_f, (reg32 rd, reg32 s1, reg32 s2))

// O1 = O2 + O3
INSN (void, addi_ui, (reg32 d, reg32 rs, imm32 is))
INSN (void, addi_ul, (reg32 d, reg32 rs, imm32 is))
INSN (void, addi_p, (reg32 d, reg32 rs, imm32 is))
INSN (void, addi_l, (reg32 d, reg32 rs, imm32 is))
INSN (void, addi_i, (reg32 d, reg32 rs, imm32 is))

// O1 = O2 + (O3 + carry)
INSN (void, addxr_ui, (reg32 d, reg32 s1, reg32 s2))
INSN (void, addxr_ul, (reg32 d, reg32 s1, reg32 s2))
INSN (void, addxr_l, (reg32 d, reg32 s1, reg32 s2))
INSN (void, addxr_i, (reg32 d, reg32 s1, reg32 s2))

// O1 = O2 + (O3 + carry)
INSN (void, addxi_ui, (reg32 d, reg32 s1, reg32 s2))
INSN (void, addxi_ul, (reg32 d, reg32 s1, reg32 s2))
INSN (void, addxi_l, (reg32 d, reg32 s1, reg32 s2))
INSN (void, addxi_i, (reg32 d, reg32 s1, reg32 s2))

// O1 = O2 + O3, set carry
INSN (void, addcr_ui, (reg32 d, reg32 rs, imm32 is))
INSN (void, addcr_ul, (reg32 d, reg32 rs, imm32 is))
INSN (void, addcr_l, (reg32 d, reg32 rs, imm32 is))
INSN (void, addcr_i, (reg32 d, reg32 rs, imm32 is))

// O1 = O2 + O3, set carry
INSN (void, addci_ui, (reg32 d, reg32 rs, imm32 is))
INSN (void, addci_ul, (reg32 d, reg32 rs, imm32 is))
INSN (void, addci_l, (reg32 d, reg32 rs, imm32 is))
INSN (void, addci_i, (reg32 d, reg32 rs, imm32 is))

// O1 = O2 - O3
INSN (void, subr_ui, (reg32 d, reg32 s1, reg32 s2))
INSN (void, subr_ul, (reg32 d, reg32 s1, reg32 s2))
INSN (void, subr_p, (reg32 d, reg32 s1, reg32 s2))
INSN (void, subr_l, (reg32 d, reg32 s1, reg32 s2))
INSN (void, subr_i, (reg32 d, reg32 s1, reg32 s2))
INSN (void, subr_d, (reg32 rd, reg32 s1, reg32 s2))
INSN (void, subr_f, (reg32 rd, reg32 s1, reg32 s2))

// O1 = O2 - O3
INSN (void, subi_ui, (reg32 d, reg32 rs, imm32 is))
INSN (void, subi_ul, (reg32 d, reg32 rs, imm32 is))
INSN (void, subi_p, (reg32 d, reg32 rs, imm32 is))
INSN (void, subi_l, (reg32 d, reg32 rs, imm32 is))
INSN (void, subi_i, (reg32 d, reg32 rs, imm32 is))

// O1 = O2 - (O3 - carry)
INSN (void, subxr_ui, (reg32 d, reg32 s1, reg32 s2))
INSN (void, subxr_ul, (reg32 d, reg32 s1, reg32 s2))
INSN (void, subxr_l, (reg32 d, reg32 s1, reg32 s2))
INSN (void, subxr_i, (reg32 d, reg32 s1, reg32 s2))

// O1 = O2 - (O3 - carry)
INSN (void, subxi_ui, (reg32 d, reg32 s1, reg32 s2))
INSN (void, subxi_ul, (reg32 d, reg32 s1, reg32 s2))
INSN (void, subxi_l, (reg32 d, reg32 s1, reg32 s2))
INSN (void, subxi_i, (reg32 d, reg32 s1, reg32 s2))

// O1 = O2 - O3, set carry
INSN (void, subcr_ui, (reg32 d, reg32 rs, imm32 is))
INSN (void, subcr_ul, (reg32 d, reg32 rs, imm32 is))
INSN (void, subcr_l, (reg32 d, reg32 rs, imm32 is))
INSN (void, subcr_i, (reg32 d, reg32 rs, imm32 is))

// O1 = O2 - O3, set carry
INSN (void, subci_ui, (reg32 d, reg32 rs, imm32 is))
INSN (void, subci_ul, (reg32 d, reg32 rs, imm32 is))
INSN (void, subci_l, (reg32 d, reg32 rs, imm32 is))
INSN (void, subci_i, (reg32 d, reg32 rs, imm32 is))

// O1 = O3 - O2
INSN (void, rsbr_ui, (reg32 d, reg32 s1, reg32 s2))
INSN (void, rsbr_ul, (reg32 d, reg32 s1, reg32 s2))
INSN (void, rsbr_f, (reg32 rd, reg32 s1, reg32 s2))
INSN (void, rsbr_d, (reg32 rd, reg32 s1, reg32 s2))
INSN (void, rsbr_i, (reg32 d, reg32 s1, reg32 s2))
INSN (void, rsbr_l, (reg32 d, reg32 s1, reg32 s2))
INSN (void, rsbr_p, (reg32 d, reg32 s1, reg32 s2))

// O1 = O3 - O2
INSN (void, rsbi_ui, (reg32 d, reg32 rs, imm32 is))
INSN (void, rsbi_ul, (reg32 d, reg32 rs, imm32 is))
INSN (void, rsbi_p, (reg32 d, reg32 rs, imm32 is))
INSN (void, rsbi_i, (reg32 d, reg32 rs, imm32 is))
INSN (void, rsbi_l, (reg32 d, reg32 rs, imm32 is))

// O1 = O2 * O3
INSN (void, mulr_l, (reg32 d, reg32 s1, reg32 s2))
INSN (void, mulr_ul, (reg32 d, reg32 s1, reg32 s2))
INSN (void, mulr_i, (reg32 d, reg32 s1, reg32 s2))
INSN (void, mulr_ui, (reg32 d, reg32 s1, reg32 s2))
INSN (void, mulr_f, (reg32 rd, reg32 s1, reg32 s2))
INSN (void, mulr_d, (reg32 rd, reg32 s1, reg32 s2))

// O1 = O2 * O3
INSN (void, muli_l, (reg32 d, reg32 rs, imm32 is))
INSN (void, muli_ul, (reg32 d, reg32 rs, imm32 is))
INSN (void, muli_i, (reg32 d, reg32 rs, imm32 is))
INSN (void, muli_ui, (reg32 d, reg32 rs, imm32 is))

// O1 = high bits of O2 * O3
INSN (void, hmulr_l, (reg32 d, reg32 s1, reg32 s2))
INSN (void, hmulr_ul, (reg32 d, reg32 s1, reg32 s2))
INSN (void, hmulr_i, (reg32 d, reg32 s1, reg32 s2))
INSN (void, hmulr_ui, (reg32 d, reg32 s1, reg32 s2))

// O1 = high bits of O2 * O3
INSN (void, hmuli_l, (reg32 d, reg32 rs, imm32 is))
INSN (void, hmuli_ul, (reg32 d, reg32 rs, imm32 is))
INSN (void, hmuli_i, (reg32 d, reg32 rs, imm32 is))
INSN (void, hmuli_ui, (reg32 d, reg32 rs, imm32 is))

// O1 = O2 / O3
INSN (void, divr_l, (reg32 d, reg32 s1, reg32 s2))
INSN (void, divr_ul, (reg32 d, reg32 s1, reg32 s2))
INSN (void, divr_i, (reg32 d, reg32 s1, reg32 s2))
INSN (void, divr_ui, (reg32 d, reg32 s1, reg32 s2))
INSN (void, divr_f, (reg32 rd, reg32 s1, reg32 s2))
INSN (void, divr_d, (reg32 rd, reg32 s1, reg32 s2))

// O1 = O2 / O3
INSN (void, divi_l, (reg32 d, reg32 rs, imm32 is))
INSN (void, divi_ul, (reg32 d, reg32 rs, imm32 is))
INSN (void, divi_i, (reg32 d, reg32 rs, imm32 is))
INSN (void, divi_ui, (reg32 d, reg32 rs, imm32 is))

// O1 = O2 % O3
INSN (void, modr_l, (reg32 d, reg32 s1, reg32 s2))
INSN (void, modr_ul, (reg32 d, reg32 s1, reg32 s2))
INSN (void, modr_i, (reg32 d, reg32 s1, reg32 s2))
INSN (void, modr_ui, (reg32 d, reg32 s1, reg32 s2))

// O1 = O2 % O3
INSN (void, modi_l, (reg32 d, reg32 rs, imm32 is))
INSN (void, modi_ul, (reg32 d, reg32 rs, imm32 is))
INSN (void, modi_i, (reg32 d, reg32 rs, imm32 is))
INSN (void, modi_ui, (reg32 d, reg32 rs, imm32 is))

// O1 = O2 & O3
INSN (void, andr_l, (reg32 d, reg32 s1, reg32 s2))
INSN (void, andr_ul, (reg32 d, reg32 s1, reg32 s2))
INSN (void, andr_i, (reg32 d, reg32 s1, reg32 s2))
INSN (void, andr_ui, (reg32 d, reg32 s1, reg32 s2))

// O1 = O2 & O3
INSN (void, andi_l, (reg32 d, reg32 rs, imm32 is))
INSN (void, andi_ul, (reg32 d, reg32 rs, imm32 is))
INSN (void, andi_i, (reg32 d, reg32 rs, imm32 is))
INSN (void, andi_ui, (reg32 d, reg32 rs, imm32 is))

// O1 = O2 | O3
INSN (void, orr_l, (reg32 d, reg32 s1, reg32 s2))
INSN (void, orr_ul, (reg32 d, reg32 s1, reg32 s2))
INSN (void, orr_i, (reg32 d, reg32 s1, reg32 s2))
INSN (void, orr_ui, (reg32 d, reg32 s1, reg32 s2))

// O1 = O2 | O3
INSN (void, ori_l, (reg32 d, reg32 rs, imm32 is))
INSN (void, ori_ul, (reg32 d, reg32 rs, imm32 is))
INSN (void, ori_i, (reg32 d, reg32 rs, imm32 is))
INSN (void, ori_ui, (reg32 d, reg32 rs, imm32 is))

// O1 = O2 ^ O3
INSN (void, xorr_l, (reg32 d, reg32 s1, reg32 s2))
INSN (void, xorr_ul, (reg32 d, reg32 s1, reg32 s2))
INSN (void, xorr_i, (reg32 d, reg32 s1, reg32 s2))
INSN (void, xorr_ui, (reg32 d, reg32 s1, reg32 s2))

// O1 = O2 ^ O3
INSN (void, xori_l, (reg32 d, reg32 rs, imm32 is))
INSN (void, xori_ul, (reg32 d, reg32 rs, imm32 is))
INSN (void, xori_i, (reg32 d, reg32 rs, imm32 is))
INSN (void, xori_ui, (reg32 d, reg32 rs, imm32 is))

// O1 = O2 << O3
INSN (void, lshr_l, (reg32 d, reg32 s1, reg32 s2))
INSN (void, lshr_ul, (reg32 d, reg32 s1, reg32 s2))
INSN (void, lshr_i, (reg32 d, reg32 s1, reg32 s2))
INSN (void, lshr_ui, (reg32 d, reg32 s1, reg32 s2))

// O1 = O2 << O3
INSN (void, lshi_l, (reg32 d, reg32 rs, imm32 is))
INSN (void, lshi_ul, (reg32 d, reg32 rs, imm32 is))
INSN (void, lshi_i, (reg32 d, reg32 rs, imm32 is))
INSN (void, lshi_ui, (reg32 d, reg32 rs, imm32 is))

// O1 = O2 >> O3
INSN (void, rshr_l, (reg32 d, reg32 s1, reg32 s2))
INSN (void, rshr_ul, (reg32 d, reg32 s1, reg32 s2))
INSN (void, rshr_i, (reg32 d, reg32 s1, reg32 s2))
INSN (void, rshr_ui, (reg32 d, reg32 s1, reg32 s2))

// O1 = O2 >> O3
INSN (void, rshi_l, (reg32 d, reg32 rs, imm32 is))
INSN (void, rshi_ul, (reg32 d, reg32 rs, imm32 is))
INSN (void, rshi_i, (reg32 d, reg32 rs, imm32 is))
INSN (void, rshi_ui, (reg32 d, reg32 rs, imm32 is))
