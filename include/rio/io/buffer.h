// Copyright © 2008 Pippijn van Steenhoven
#ifndef RIO_IO_BUFFER
#define RIO_IO_BUFFER

#include <cstddef>
#include <cstring>
#include <string>
#include <ostream>

#include <sys/mman.h>

#include <rio/io/bits/allocators.h>
#include <rio/io/bits/byteswap.h>

namespace rio
{
  namespace io
  {
    template<typename Alloc>
    struct buffer
    {
    protected:
      typedef unsigned char byte;

      static int const INITIAL = 4096;
      static int const EXTEND  = 16384;
  
      struct chunk
      {
        chunk *next;
        int32_t alloc;
        int32_t size;
        byte data[0];
      };
    
      byte *ptr;
      byte *end;

      std::size_t size;
      std::size_t extend;

      chunk *first;
      chunk *last;
    
      void reserve (std::size_t bytes);
      void destroy (chunk *&chain);
      byte *linearise ();
      void linearise (void *data);
      void finalise ();
    
    public:
      buffer (std::size_t initial = INITIAL, std::size_t extend = EXTEND);
    
      virtual ~buffer ();
    
      void clear ();
      
      bool empty () const;
      
      std::size_t length () const;
      std::size_t capacity () const;
    
      byte *need (std::size_t bytes);
      byte *advance (std::size_t bytes);
      byte *alloc (std::size_t bytes);
    
      void fwrite (byte c);
      void fwrite (void const *p, std::size_t len);
      void write (void const *p, std::size_t len);
      template<typename T, std::size_t N>
      void write (T const (&array)[N]);

      operator std::string ();
  
      friend std::ostream &operator << (std::ostream &os, buffer &buf)
      {
        os.write (reinterpret_cast<char const *> (buf.linearise ()), buf.length ());
        return os;
      }
    };

    template<byte_order bo>                     struct binreader;
    template<typename Alloc, byte_order bo>     struct binbuf;
  
    typedef buffer<allocators::system>          membuf;

    typedef binbuf<allocators::system, NETWORK> nbinbuf;
    typedef binbuf<allocators::system, HOST>    hbinbuf;

    typedef binreader<NETWORK>                  nbinreader;
    typedef binreader<HOST>                     hbinreader;
  }
}

#include <rio/io/bits/buffer.tcc>
#include <rio/io/bits/nbinbuf.tcc>
#include <rio/io/bits/hbinbuf.tcc>

#endif
// vim:filetype=cpp
