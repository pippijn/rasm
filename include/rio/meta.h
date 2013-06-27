#ifndef META_H_INCLUDED
#define META_H_INCLUDED

namespace rio
{
  template<typename T, std::size_t N>
  static inline std::size_t
  array_size (T const (&)[N])
  {
    return N;
  }
}

#endif /* META_H_INCLUDED */
