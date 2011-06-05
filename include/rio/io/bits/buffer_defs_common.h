namespace rio
{
  namespace io
  {
    template<typename Alloc>
    struct binbuf<Alloc, BYTEORDER> : buffer<Alloc>
    {
      friend struct binreader<BYTEORDER>;

      typedef typename buffer<Alloc>::byte byte;
  
      binbuf (std::size_t initial = buffer<Alloc>::INITIAL, std::size_t extend = buffer<Alloc>::EXTEND)
      : buffer<Alloc> (initial, extend)
      {
      }
  
      // signed input
      binbuf &operator << ( int8_t data);
      binbuf &operator << (int16_t data);
      binbuf &operator << (int32_t data);
      binbuf &operator << (int64_t data);
      
      // unsigned input
      binbuf &operator << ( uint8_t data);
      binbuf &operator << (uint16_t data);
      binbuf &operator << (uint32_t data);
      binbuf &operator << (uint64_t data);

      // floating point
      binbuf &operator << (float data);
      binbuf &operator << (double data);

      // character strings
      binbuf &operator << (char const *data);
      binbuf &operator << (std::string const &data);

      // self
      binbuf &operator << (binbuf const &data);

      // binary reader
      binbuf &operator << (binreader<BYTEORDER> const &data);
    };
  
    template<>
    struct binreader<BYTEORDER>
    {
      typedef unsigned char byte;

      template<typename T, std::size_t N>
      binreader (T const (&array)[N])
      : data ((byte *) &array), pos (data), end (data + N * sizeof (T))
      {
      }

      binreader (void const *buf, std::size_t len)
      : data ((byte *) buf), pos (data), end (data + len)
      {
      }

      template<typename Alloc>
      binreader (binbuf<Alloc, BYTEORDER> &buf)
      : data (buf.linearise ()), pos (data), end (data + buf.length ())
      {
      }

      int read           (void *p, std::size_t len);
      int read_noinc     (void *p, std::size_t len) const;
      std::size_t remain () const;

      // signed output
      binreader &operator >> ( int8_t &data);
      binreader &operator >> (int16_t &data);
      binreader &operator >> (int32_t &data);
      binreader &operator >> (int64_t &data);
  
      // unsigned output
      binreader &operator >> ( uint8_t &data);
      binreader &operator >> (uint16_t &data);
      binreader &operator >> (uint32_t &data);
      binreader &operator >> (uint64_t &data);

      // floating point
      binreader &operator >> (float &data);
      binreader &operator >> (double &data);

      // character strings
      binreader &operator >> (char * &data);
      binreader &operator >> (std::string &data);

      // binary buffer
      template<typename Alloc>
      binreader &operator >> (binbuf<Alloc, BYTEORDER> &data)
      {
        byte *buf = new byte[remain ()];
        read (buf, remain ());
        data.write (buf, remain ());
        delete[] buf;
      }

    private:
      byte const * const data;
      byte const *       pos;
      byte const * const end;
    };
  }
}
