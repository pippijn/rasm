#include <jit.h>
#include <rio/initially.h>
#include <rio/meta.h>

uint16_t
jit::opcode (std::string const &mnemonic)
{
  static jit::map<std::string, uint16_t> opcodes;
  initially
    {
      uint16_t code = 0;
#define INSN(R, name, args) opcodes[#name] = code++;
#include <jit/insns.h>
#undef INSN
    }

  //puts (mnemonic.c_str ());
  return opcodes.at (mnemonic);
}

char const *jit::mnemonics[] = {
#define INSN(R, name, args) #name,
#include <jit/insns.h>
#undef INSN
};

char const *
jit::mnemonic_for (uint16_t opcode)
{
  if (opcode > rio::array_size (mnemonics))
    die (out_of_range, "no mnemonic for opcode: %d", opcode);
  return mnemonics[opcode];
}
