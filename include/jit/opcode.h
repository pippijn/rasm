private:
static char const *mnemonics[];

public:
static uint16_t opcode (std::string const &mnemonic);
static char const *mnemonic_for (uint16_t opcode);
