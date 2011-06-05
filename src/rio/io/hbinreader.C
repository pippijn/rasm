#include <rio/io/buffer.h>

#include <rio/io/bits/byteswap.h>
#include <arpa/inet.h>

#define BYTEORDER HOST
#include "binreader_common.h"
#undef BYTEORDER

namespace rio
{
  namespace io
  {
    /**
     * Unsigned integrals output
     */
    binreader<HOST> &
    binreader<HOST>::operator >> (uint8_t &data)
    {
      read (&data, sizeof (data));
  
      return *this;
    }
  
    binreader<HOST> &
    binreader<HOST>::operator >> (uint16_t &data)
    {
      read (&data, sizeof (data));
  
      return *this;
    }
  
    binreader<HOST> &
    binreader<HOST>::operator >> (uint32_t &data)
    {
      read (&data, sizeof (data));
  
      return *this;
    }
  
    binreader<HOST> &
    binreader<HOST>::operator >> (uint64_t &data)
    {
      read (&data, sizeof (data));
  
      return *this;
    }
  }
}
