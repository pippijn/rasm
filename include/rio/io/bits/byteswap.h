// Copyright © 2008 Pippijn van Steenhoven
#ifndef RIO_IO_BITS_BYTESWAP_H
#define RIO_IO_BITS_BYTESWAP_H

#include <arpa/inet.h>

namespace rio
{
  namespace io
  {
    enum byte_order
    {
      NETWORK,
      HOST
    };
  }
}
  
#if defined (__GNUC__) && !defined (__STRICT_ANSI__)
#  include <endian.h>
#  include <byteswap.h>
#  if __BYTE_ORDER == __BIG_ENDIAN
#    define htonll(x)       (x)
#    define ntohll(x)       (x)
#  else // Little endian
#    define htonll(x)       bswap_64 (x)
#    define ntohll(x)       bswap_64 (x)
#  endif
#endif

#ifdef htonll
#  define HAVE_HTONLL 1
#endif

#endif
// vim:filetype=cpp
