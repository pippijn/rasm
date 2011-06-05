#include <rio/io/bits/byteswap.h>
#include <arpa/inet.h>

#define BYTEORDER HOST
#include <rio/io/bits/buffer_defs_common.h>
#include <rio/io/bits/binbuf_common.tcc>
#undef BYTEORDER

#undef BYTEORDER

namespace rio
{
  namespace io
  {
    /**
     * Unsigned integrals input
     */
    template<typename Alloc>
    binbuf<Alloc, HOST> &
    binbuf<Alloc, HOST>::operator << (uint8_t data)
    {
      this->write (&data, sizeof (data));
  
      return *this;
    }
  
    template<typename Alloc>
    binbuf<Alloc, HOST> &
    binbuf<Alloc, HOST>::operator << (uint16_t data)
    {
      this->write (&data, sizeof (data));
  
      return *this;
    }
  
    template<typename Alloc>
    binbuf<Alloc, HOST> &
    binbuf<Alloc, HOST>::operator << (uint32_t data)
    {
      this->write (&data, sizeof (data));
  
      return *this;
    }
  
    template<typename Alloc>
    binbuf<Alloc, HOST> &
    binbuf<Alloc, HOST>::operator << (uint64_t data)
    {
      this->write (&data, sizeof (data));
      
      return *this;
    }
  }
}
