#include <rio/io/bits/byteswap.h>

#define BYTEORDER NETWORK
#include <rio/io/bits/buffer_defs_common.h>
#include <rio/io/bits/binbuf_common.tcc>
#undef BYTEORDER

namespace rio
{
  namespace io
  {
    /**
     * Unsigned integrals input
     */
    template<typename Alloc>
    binbuf<Alloc, NETWORK> &
    binbuf<Alloc, NETWORK>::operator << (uint8_t data)
    {
      this->write (&data, sizeof (data));
  
      return *this;
    }
  
    template<typename Alloc>
    binbuf<Alloc, NETWORK> &
    binbuf<Alloc, NETWORK>::operator << (uint16_t data)
    {
      uint16_t netdata = htons (data);
      this->write (&netdata, sizeof (netdata));
  
      return *this;
    }
  
    template<typename Alloc>
    binbuf<Alloc, NETWORK> &
    binbuf<Alloc, NETWORK>::operator << (uint32_t data)
    {
      uint32_t netdata = htonl (data);
      this->write (&netdata, sizeof (netdata));
  
      return *this;
    }
  
    template<typename Alloc>
    binbuf<Alloc, NETWORK> &
    binbuf<Alloc, NETWORK>::operator << (uint64_t data)
    {
#ifdef HAVE_HTONLL
      uint64_t netdata = htonll (data);
      this->write (&netdata, sizeof (netdata));
#else
      uint32_t netdata_high = htonl (data >> 32);
      this->write (&netdata_high, sizeof (netdata_high));
      
      uint32_t netdata_low = htonl (data & 0xffffffff);
      this->write (&netdata_low, sizeof (netdata_low));
#endif
      
      return *this;
    }
  }
}
