#include <jit.h>
#include <disasm.h>
#include <rio/initially.h>

#define _jit this->current

jit::jit ()
: begin (NULL)
{
}

jit::jit (insn *ptr)
{
  set_ip (ptr);
}

jit::code &
jit::set_ip (insn *ptr)
{
  begin = ptr;
  return jit_set_ip (ptr);
}

jit::code &
jit::get_ip ()
{
  return jit_get_ip ();
}

void
jit::flush_code ()
{
  flush_code (begin, get_ip ().ptr);
}

void
jit::flush_code (void *start, void *end)
{
  jit_flush_code (start, end);
}

void
jit::finalise ()
{
  initially
    {
      flush_code ();
    }
}

jit::reg32
jit::reg_for (int reg)
{
  if (reg32 (reg) == R0) return R0;
  if (reg32 (reg) == R1) return R1;
  if (reg32 (reg) == R2) return R2;
  if (reg32 (reg) == V0) return V0;
  if (reg32 (reg) == V1) return V1;
  if (reg32 (reg) == V2) return V2;

  if (reg32 (reg) == RET) return RET;
  if (reg32 (reg) == FP) return FP;
  if (reg32 (reg) == SP) return SP;

  die (argument, "got invalid register: %d", reg);
}

jit::freg32
jit::freg_for (int reg)
{
  switch (freg32 (reg))
    {
    case FPR0: return FPR0;
    case FPR1: return FPR1;
    case FPR2: return FPR2;
    case FPR3: return FPR3;
    case FPR4: return FPR4;
    case FPR5: return FPR5;
    }
  die (argument, "got invalid floating point register: %d", reg);
}

std::size_t
jit::length ()
{
  return reinterpret_cast<insn *> (get_ip ().ptr) - entry ();
}

bool
jit::initialise ()
{
  init_functors ();
  init_functions ();

  return true;
}

bool jit::initialised = jit::initialise ();

void
jit::disassemble (std::ostream &os)
{
  disassemble (os, entry (), length ());
}

void
jit::disassemble (std::ostream &os, insn const *ptr, std::size_t len)
{
  ud_t ud;
  ud_init (&ud);
  ud_set_mode (&ud, 64);
  ud_set_syntax (&ud, UD_SYN_ATT);
  ud_set_vendor (&ud, UD_VENDOR_INTEL);
  ud_set_input_buffer (&ud, const_cast<insn *> (ptr), len);

  while (ud_disassemble (&ud))
    {
      printf ("%016lx ", ud_insn_off (&ud));
      char *h1 = ud_insn_hex (&ud);
      std::string in (h1, std::min (std::strlen (h1), 16lu));
      std::string out;
      out.reserve (16);
      bool flag = false;
      for (std::string::iterator i = in.begin (); i != in.end (); i++)
        {
          out += *i;
          if (flag)
            out += ' ';
          flag = !flag;
        }
      printf ("%-24s %s", out.c_str (), ud_insn_asm (&ud));
      if (std::strlen (h1) > 16) 
        {
          os << '\n';
          std::printf ("%15s- ", "");
          out.clear ();
          in = h1 + 16;;
          bool flag = false;
          for (std::string::iterator i = in.begin (); i != in.end (); i++)
            {
              out += *i;
              if (flag)
                out += ' ';
              flag = !flag;
            }
          printf ("%s", out.c_str ());
        }
      
      os << '\n';
    }
}
