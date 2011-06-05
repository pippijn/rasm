#include <rio/io/buffer.h>

#include <rio/io/bits/byteswap.h>
#include <arpa/inet.h>

#define BYTEORDER NETWORK
#include "binreader_common.h"
#undef BYTEORDER

namespace rio
{
  namespace io
  {
    /**
     * Unsigned integrals output
     */
    binreader<NETWORK> &
    binreader<NETWORK>::operator >> (uint8_t &data)
    {
      read (&data, sizeof (data));
  
      return *this;
    }
  
    binreader<NETWORK> &
    binreader<NETWORK>::operator >> (uint16_t &data)
    {
      uint16_t netdata;
      read (&netdata, sizeof (netdata));
      data = ntohs (netdata);
  
      return *this;
    }
  
    binreader<NETWORK> &
    binreader<NETWORK>::operator >> (uint32_t &data)
    {
      uint32_t netdata;
      read (&netdata, sizeof (netdata));
      data = ntohl (netdata);
  
      return *this;
    }
  
    binreader<NETWORK> &
    binreader<NETWORK>::operator >> (uint64_t &data)
    {
      union
      {
        uint32_t parts[2];
        uint64_t netdata;
      };

      read (&netdata, sizeof (netdata));
  
#ifdef HAVE_HTONLL
      data = htonll (netdata);
#else
      uint32_t *data_high = reinterpret_cast<uint32_t *> (&data) + 1;
      uint32_t *data_low  = reinterpret_cast<uint32_t *> (&data);
      *data_high = ntohl (parts[0]);
      *data_low  = ntohl (parts[1]);
#endif
  
      return *this;
    }
  }
}
