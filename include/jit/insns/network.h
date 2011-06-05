// Host-to-network (big endian) order
INSN (void, hton_ui, (reg32 d, reg32 rs))
INSN (void, hton_us, (reg32 d, reg32 rs))

// Network-to-host order
INSN (void, ntoh_ui, (reg32 d, reg32 rs))
INSN (void, ntoh_us, (reg32 d, reg32 rs))
