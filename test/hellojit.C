#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

#include <boost/lexical_cast.hpp>

#include <jit.h>

std::string const code[] = {
  "leaf 2",
  "arg_i i0",
  "getarg_i r0 i0",
  "arg_i i0",
  "getarg_i r1 i0",
  "addr_i ret r0 r1",
  "ret",
  ""
};

template<typename T, typename Alloc = std::allocator<T> >
struct variables : std::vector<T, Alloc>
{
  T &operator [] (size_t idx)
  {
    if (idx >= this->size ())
      this->resize (idx + 1);
    return std::vector<T, Alloc>::operator [] (idx);
  }

  T const &operator [] (size_t idx) const
  {
    if (idx > this->size ())
      this->resize (idx);
    return std::vector<T, Alloc>::operator [] (idx);
  }
};

class compiler : public jit
{
  struct object
  {
    object (void *entry)
    : entry (entry)
    {
    }

    template<typename T>
    operator T * ()
    {
      return union_cast<T> (entry);
    }

    void *entry;

  private:
    template<typename To, typename From>
    To *union_cast (From *from)
    {
      union
      {
        From *in;
        To *out;
      };
      in = from;
      return out;
    }
  };

public:
  void compile (std::string const &line);

  compiler ()
  : jit (buffer)
  {
    memset (buffer, 0, sizeof (buffer));
  }

  object cast ()
  {
    return entry ();
  }

  friend std::ostream &operator << (std::ostream &os, compiler const &comp)
  {
    os.write (reinterpret_cast<char const *> (comp.buffer), sizeof (comp.buffer));
  }

private: // functions
  std::vector<std::string> tokenise (std::string const &line, const char split_char = ' ');
  imm32 get_immediate (std::string const &var);
  reg32 get_register (std::string const &var);

private: // data members
  insn buffer[1024];
  variables<int> iv;
};

std::vector<std::string>
compiler::tokenise (std::string const &line, const char split_char)
{
  std::istringstream split (line);
  std::vector<std::string> tokens;
  
  for (std::string each; std::getline (split, each, split_char); tokens.push_back (each))
    ;
  
  return tokens;
}

compiler::imm32
compiler::get_immediate (std::string const &var)
{
  using boost::lexical_cast;

  switch (var[0])
    {
    case 'i':
      return iv[lexical_cast<imm32> (var.substr (1))];
    }

  return lexical_cast<imm32> (var);
}

compiler::reg32
compiler::get_register (std::string const &var)
{
  using boost::lexical_cast;

  if (var == "ret")
    return RET;

  switch (var[0])
    {
    case 'r':
      return reg32 (JIT_R (var[1]));
    case 'v':
      return reg32 (JIT_V (var[1]));
    }

  throw std::invalid_argument ("get_register: unknown register: " + var);
}

void
compiler::compile (std::string const &line)
{
  using boost::lexical_cast;
  std::vector<std::string> const &tokens = tokenise (line);

  for (int i = 0; i < tokens.size (); i++)
    {
      std::string const &tok = tokens[i];
      if (tok == "leaf")
        {
          leaf (lexical_cast<imm32> (tokens[++i]));
        }
      else if (tok == "arg_i")
        {
          std::string const &var = tokens[++i];
          switch (var[0])
            {
            case 'i':
              iv[lexical_cast<int> (var.substr (1))] = arg_i ();
              break;
            default:
              throw std::invalid_argument ("compiler: invalid argument:" + var);
            }
        }
      else if (tok == "getarg_i")
        {
          std::string const &rs = tokens[++i];
          imm32 ofs = get_immediate (tokens[++i]);
          reg32 reg = rs[0] == 'r' ? reg32 (JIT_R (rs[1])) : reg32 (JIT_V (rs[1]));
          getarg_i (reg, ofs);
        }
      else if (tok == "addr_i")
        {
          std::string const &ds = tokens[++i];
          std::string const &s1s = tokens[++i];
          std::string const &s2s = tokens[++i];

          reg32 d = get_register (ds);
          reg32 s1 = get_register (s1s);
          reg32 s2 = get_register (s2s);

          addr_i (d, s1, s2);
        }
      else if (tok == "ret")
        {
          ret ();
        }

      if (tokens.size () > i + 1)
        throw std::runtime_error ("compiler: too many tokens; current token = " + tokens[i]);
    }
}

int
main ()
{
  compiler comp;
  
  std::string const *line;
  for (int i = 0; !(line = &code[i])->empty (); i++)
    comp.compile (*line);
  comp.flush_code ();

  typedef int (*pifii) (int, int);

  pifii func = comp.cast ();

  std::cout << func (5, 4) << '\n';
}
