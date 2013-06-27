#include <iostream>

#include <assembler/compiler.h>
#include <assembler.h>

struct adder : jit
{
  adder ()
  : jit (buffer)
  {
    leaf (2);                   // initialise function entry with 2 arguments
    int ofs = arg_i ();         // get the stack offset for the first argument
    getarg_i (R0, ofs);         // put first argument into %r0
    ofs = arg_i ();             // get the stack offset for the second argument
    getarg_i (R1, ofs);         // put the second argument into %r1
    addr_i (RET, R0, R1);       // %ret = %r0 + %r1
    ret ();                     // clean up and leave
  }

private:
  insn buffer[100]; // 100 bytes of memory for this function
};

int
main (int argc, char *argv[])
{
  compiler comp;
  try
  {
    comp.compile_file (argc > 1 ? argv[1] : "-");
    //comp.compile_string ("#function start\n\nleaf 0\nmovi_i %ret, 20\nret\n");
    //comp.compile_string ("leaf 0\nmovi_i %ret, 20\nret\n");
  }
  catch (parser_exception const &e)
  {
    std::puts (e.message ());
    return 0;
  }
  comp.check ();
  comp.load (comp.store ());
  comp.print (std::cout);

  assembler as;
  comp.assemble (as);
  as.disassemble (std::cout);

  int (*func) (int) = as.cast ();
  std::cout << func (32) << '\n';

  return 0;
}
