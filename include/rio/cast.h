// Copyright © 2008 Pippijn van Steenhoven
#ifndef RIO_CAST_H
#define RIO_CAST_H

#include <algorithm>
#include <cstring>

namespace rio
{
  /**
   * implicit_cast is used to show that there is actually no cast needed,
   * but we would like to emphasise that a converion happens
   *
   * Example:
   * \code
   *   struct type1
   *   {
   *   };
   *
   *   struct type2 : type1
   *   {
   *   };
   *
   *   type2 *v2 = new type2;
   *   type1 *v1 = implicit_cast<type1 *> (v2);
   * \endcode
   */
  template<typename To, typename From>
  inline To
  implicit_cast (From from)
  {
    return from;
  }

  /**
   * memory_cast provides a standards compliant way of casting between
   * function- and object pointer (e.g. between void * and void (*)().
   * Note that although we use memcpy here, this will likely be completely
   * optimised away by the compiler.
   *
   * Note that all of the below forcing casts in fact evoke unspecified
   * behaviour. Use at your own risk. Strict aliasing optimisation might
   * break it.
   */
  template<typename To, typename From>
  To memory_cast (From const &from)
  {
    char to[sizeof (To)];
    std::memcpy (to, &from, std::min (sizeof (To), sizeof (From)));
    return *reinterpret_cast<To *> (to);
  }

  /**
   * union_cast does the same as reinterpret_cast but without the compiler
   * moaning at you for casting between function and object pointers.
   */
  template<typename To, typename From>
  To union_cast (From from)
  {
    // Make sure the target type is of the same size as the source type
#ifdef __GXX_EXPERIMENTAL_CXX0X__
    static_assert (sizeof (From) == sizeof (To), "Cannot cast between differently sized objects");
#else
    typedef int sanity_check[sizeof (From) == sizeof (To) ? 1 : -1];
#endif

    union
    {
      From in;
      To   out;
    };
    in = from;
    return out;
  }

  /**
   * The bytes making up an array cast with reference_cast will be interpreted
   * as the bytes making up the returned pointer.
   */
  template<typename To, typename From>
  To reference_cast (From const &from)
  {
    return (To const &) (from);
  }

  /**
   * An array cast with forced_cast will decay into a pointer and
   * immediately returned.
   */
  template<typename To, typename From>
  To direct_cast (From const from)
  {
    // from itself is not a reference because we want arrays to decay,
    // so that direct_cast<char *> ("hello") works properly.
    From const &r = from;
    return (To const &) (r);
  }
}

#endif
