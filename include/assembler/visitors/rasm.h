#ifndef ASSEMBLER_VISITORS_RASM_H_INCLUDED
#define ASSEMBLER_VISITORS_RASM_H_INCLUDED

namespace visitors
{
  struct rasm : ast::const_visitor
  {
    void visit (ast::code const &v);
    DECL_CONSTVISIT;

    rasm (std::ostream &o);

  private:
    std::ostream &os;
  };
}

#endif /* ASSEMBLER_VISITORS_RASM_H_INCLUDED */
