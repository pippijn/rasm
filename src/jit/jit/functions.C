#include <jit.h>
#include <rio/singleton.h>

jit::map<std::string, void *> &
jit::functions ()
{
  return rio::singleton<map<std::string, void *> >::instance ();
}

void
jit::init_functions ()
{
#define DECLFUNC(func)  functions ()[#func] = reinterpret_cast<void *> (func)
#include "functions.h"
#undef DECLFUNC
}
