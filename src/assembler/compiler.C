#include <assembler/parser.h>
#include <assembler/visitors.h>
#include <assembler.h>

#include "deserialiser.h"

void
compiler::take (ast::program &prog)
{
  jit::map<std::string, std::tr1::shared_ptr<ast::code> >::iterator it = prog.functions.begin ();
  jit::map<std::string, std::tr1::shared_ptr<ast::code> >::iterator et = prog.functions.end ();

  while (it != et)
    {
      std::tr1::shared_ptr<ast::code> &code = program.functions[it->first];
      if (code == NULL)
        code = it->second;
      else
        {
          code->statements.insert (code->statements.end (),
                                   it->second->statements.begin (),
                                   it->second->statements.end ());
          it->second->statements.clear ();
        }
      ++it;
    }
}

void
compiler::compile_file (char const *file)
{
  take (parser::parse_file (file));
}

void
compiler::compile_string (std::string const &str)
{
  take (parser::parse_string (str));
}

void
compiler::check ()
{
  visitors::checks::mnemonics mnecheck;
  program.invite (mnecheck);
}

void
compiler::print (std::ostream &os)
{
  visitors::rasm rasm (os);
  program.invite (rasm);
}

void
compiler::assemble (assembler &as)
{
  visitors::machine mach;
  program.invite (mach);
  as.assemble (mach.functions);
}

std::string
compiler::store ()
{
  visitors::serialiser serialiser;
  program.invite (serialiser);
  return serialiser.get ();
}

void
compiler::load (std::string const &codestr)
{
#if 0
  rio::io::nbinreader code (codestr.data (), codestr.length ());
  deserialiser reader (code);
  program.code = reader.read ();
  check ();
#endif
}

#undef croak

void
compiler::croak (rio::srcinf const &si, ast::node const &v, char const *fmt, ...)
{
  char buf[BUFSIZ];
  std::va_list ap;

  va_start (ap, fmt);
  std::vsnprintf (buf, BUFSIZ - 1, fmt, ap);
  va_end (ap);

  throw compiler_exception (si, "%s:%d:%d: %s", v.file ().c_str (), v.line (), v.column (), buf);
}
