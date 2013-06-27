#ifndef ASSEMBLER_VISITORS_SERIALISER_H_INCLUDED
#define ASSEMBLER_VISITORS_SERIALISER_H_INCLUDED

namespace visitors
{
  struct serialiser : ast::const_visitor, serialisation_base
  {
    void visit (ast::code const &v);
    DECL_CONSTVISIT;

    std::string get ();

  private:
    rio::io::nbinbuf code;
  };
}

#endif /* ASSEMBLER_VISITORS_SERIALISER_H_INCLUDED */
