namespace rio
{
  namespace io
  {
    /**
     * Signed integrals input
     */
    template<typename Alloc>
    binbuf<Alloc, BYTEORDER> &
    binbuf<Alloc, BYTEORDER>::operator << (int8_t data)
    {
      return *this << uint8_t (data);
    }
  
    template<typename Alloc>
    binbuf<Alloc, BYTEORDER> &
    binbuf<Alloc, BYTEORDER>::operator << (int16_t data)
    {
      return *this << uint16_t (data);
    }
  
    template<typename Alloc>
    binbuf<Alloc, BYTEORDER> &
    binbuf<Alloc, BYTEORDER>::operator << (int32_t data)
    {
      return *this << uint32_t (data);
    }
  
    template<typename Alloc>
    binbuf<Alloc, BYTEORDER> &
    binbuf<Alloc, BYTEORDER>::operator << (int64_t data)
    {
      return *this << uint64_t (data);
    }
  
    /**
     * Floating point
     */
    template<typename Alloc>
    binbuf<Alloc, BYTEORDER> &
    binbuf<Alloc, BYTEORDER>::operator << (float data)
    {
      return *this << reinterpret_cast<uint32_t &> (data);
    }
  
    template<typename Alloc>
    binbuf<Alloc, BYTEORDER> &
    binbuf<Alloc, BYTEORDER>::operator << (double data)
    {
      return *this << reinterpret_cast<uint64_t &> (data);
    }
  
    /**
     * Character strings
     */
    template<typename Alloc>
    binbuf<Alloc, BYTEORDER> &
    binbuf<Alloc, BYTEORDER>::operator << (char const *data)
    {
      uint32_t len = std::strlen (data);
      *this << len;
      this->write (data, len);
  
      return *this;
    }

    template<typename Alloc>
    binbuf<Alloc, BYTEORDER> &
    binbuf<Alloc, BYTEORDER>::operator << (std::string const &data)
    {
      uint32_t len = data.length ();
      *this << len;
      this->write (data.data (), len);
  
      return *this;
    }
  }
}
