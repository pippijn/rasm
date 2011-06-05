#include <jit.h>
#include <rio/singleton.h>

#include <jit/functor.h>

template<typename R, R (jit::*func) ()>
static R thunk (jit &self)
{
  return (self.*func) ();
}

template<typename R, typename A1, R (jit::*func) (A1)>
static R thunk (jit &self, A1 a1)
{
  return (self.*func) (a1);
}

template<typename R, typename A1, typename A2, R (jit::*func) (A1, A2)>
static R thunk (jit &self, A1 a1, A2 a2)
{
  return (self.*func) (a1, a2);
}

template<typename R, typename A1, typename A2, typename A3, R (jit::*func) (A1, A2, A3)>
static R thunk (jit &self, A1 a1, A2 a2, A3 a3)
{
  return (self.*func) (a1, a2, a3);
}

#define TYPE0(AC, R, RT, T)             \
template<>                              \
struct jit::registry<RT ()>             \
{                                       \
  template<RT (jit::*func) ()>          \
  static void regfun (char const *name) \
  {                                     \
    functor f;                          \
    f.type = functor::ftype::T;         \
    f.u.T = thunk<RT, func>;            \
    functors ()[name] = f;              \
  }                                     \
};

#define TYPE(AC, R, RT, T, args...)     \
template<>                              \
struct jit::registry<RT (args)>         \
{                                       \
  template<RT (jit::*func) (args)>      \
  static void regfun (char const *name) \
  {                                     \
    functor f;                          \
    f.type = functor::ftype::T;         \
    f.u.T = thunk<RT, args, func>;      \
    functors ()[name] = f;              \
  }                                     \
};

#include <jit/types.h>

#undef TYPE
#undef TYPE0

jit::map<std::string, jit::functor> &
jit::functors ()
{
  return rio::singleton<map<std::string, functor> >::instance ();
}

void
jit::init_functors ()
{
#define INSN(R, name, args) registry<R args>::regfun<&jit::name> (#name);
#include <jit/insns.h>
#undef INSN
}

bool
jit::can (std::string const &mnemonic)
{
  return functors ().find (mnemonic) != functors ().end ();
}

std::string
jit::functor::ftype::describe (type t)
{
  char const * const s = string (t);
  char const *p = s;
  size_t len = std::strlen (s);
  
  if (len == 2 && s[1] == 'v')
    return std::string ("nullary function returning") + chartype (s[0]);

  std::string description = "function taking";
  description.reserve (100);
  
  --len;
  while (--len)
    {
      description += chartype (*++p);
      description += ",";
    }
  description += " and";
  description += chartype (*++p);
  description += " and returning";
  description += chartype (*s);
  
  return description;
}

char const *
jit::functor::ftype::chartype (char t)
{
  switch (t)
    {
    case 'i': return " an immediate";
    case 'l': return " a label";
    case 'r': return " a register";
    case 'p': return " a pointer";
    case 'v': return " nothing";
    }
  return " an <unknown>";
}

char const *
jit::functor::ftype::string (type t)
{
  static char const *types[] = {
#define TYPE0(AC, R, RT, T) #T,
#define TYPE(AC, R, RT, T, ...) #T,
#include <jit/types.h>
#undef TYPE
#undef TYPE0
  };
  return types[t];
}
