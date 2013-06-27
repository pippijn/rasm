#include <rio/exception.h>

namespace rio
{
  namespace io
  {
    int
    binreader<BYTEORDER>::read (void *p, std::size_t len)
    {
      if (remain () < len)
        die (overflow, "tried to read more bytes from reader than remaining");
      std::memcpy (p, pos, len);
      pos += len;
      return len;
    }

    int
    binreader<BYTEORDER>::read_noinc (void *p, std::size_t len) const
    {
      if (remain () < len)
        die (overflow, "tried to read more bytes from reader than remaining");
      std::memcpy (p, pos, len);
      return len;
    }

    std::size_t
    binreader<BYTEORDER>::remain () const
    {
      return end - pos;
    }
  
    /**
     * Signed integrals output
     */
    binreader<BYTEORDER> &
    binreader<BYTEORDER>::operator >> (int8_t &data)
    {
      return *this >> reinterpret_cast<uint8_t &> (data);
    }

    binreader<BYTEORDER> &
    binreader<BYTEORDER>::operator >> (int16_t &data)
    {
      return *this >> reinterpret_cast<uint16_t &> (data);
    }
  
    binreader<BYTEORDER> &
    binreader<BYTEORDER>::operator >> (int32_t &data)
    {
      return *this >> reinterpret_cast<uint32_t &> (data);
    }
  
    binreader<BYTEORDER> &
    binreader<BYTEORDER>::operator >> (int64_t &data)
    {
      return *this >> reinterpret_cast<uint64_t &> (data);
    }

    /**
     * Floating point
     */
    binreader<BYTEORDER> &
    binreader<BYTEORDER>::operator >> (float &data)
    {
      return *this >> reinterpret_cast<uint32_t &> (data);
    }

    binreader<BYTEORDER> &
    binreader<BYTEORDER>::operator >> (double &data)
    {
      return *this >> reinterpret_cast<uint64_t &> (data);
    }
  
    /**
     * Character strings
     */
    binreader<BYTEORDER> &
    binreader<BYTEORDER>::operator >> (char * &data)
    {
      uint32_t len;
      *this >> len;
      data = new char[len];
      read (data, len);
      return *this;
    }

    binreader<BYTEORDER> &
    binreader<BYTEORDER>::operator >> (std::string &data)
    {
      uint32_t len;
      *this >> len;
      char *buf = new char[len];
      read (buf, len);
      data.assign (buf, len);
      delete[] buf;
      return *this;
    }
  }
}
