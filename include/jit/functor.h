struct jit::functor
{
  union function
  {
#define TYPE0(AC, R, RT, T) RT (*T) (jit &);
#define TYPE(AC, R, RT, T, args...) RT (*T) (jit &, args);
#include <jit/types.h>
#undef TYPE
#undef TYPE0
  } u;

  struct ftype
  {
    enum type
    {
#define TYPE0(AC, R, RT, T) T,
#define TYPE(AC, R, RT, T, ...) T,
#include <jit/types.h>
#undef TYPE
#undef TYPE0
      NUMTYPES
    };

    static char const *string (type t);
    static std::string describe (type t);

  private:
    static char const *chartype (char t);
  };

  ftype::type type;
};
