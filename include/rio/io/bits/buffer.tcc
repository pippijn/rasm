namespace rio
{
  namespace io
  {
    template<typename Alloc>
    buffer<Alloc>::~buffer ()
    {
      destroy (first);
    }

    template<typename Alloc>
    bool
    buffer<Alloc>::empty () const
    {
      return !length ();
    }

    template<typename Alloc>
    std::size_t
    buffer<Alloc>::length () const
    {
      return size + (ptr - last->data);
    }
    
    template<typename Alloc>
    std::size_t
    buffer<Alloc>::capacity () const
    {
      return end - ptr;
    }

    template<typename Alloc>
    typename buffer<Alloc>::byte *
    buffer<Alloc>::need (std::size_t bytes)
    {
      if (ptr + bytes >= end)
        reserve (bytes);
    
      return ptr;
    }
    
    template<typename Alloc>
    typename buffer<Alloc>::byte *
    buffer<Alloc>::advance (std::size_t bytes)
    {
      byte *res = ptr;
      ptr += bytes;
      return res;
    }
    
    template<typename Alloc>
    typename buffer<Alloc>::byte *
    buffer<Alloc>::alloc (std::size_t bytes)
    {
      need (bytes);
      return advance (bytes);
    }
  
    template<typename Alloc>
    void
    buffer<Alloc>::fwrite (byte c)
    {
      *ptr++ = c;
    }
      
    template<typename Alloc>
    void
    buffer<Alloc>::fwrite (void const *p, std::size_t len)
    {
      memcpy (advance (len), p, len);
    }

    template<typename Alloc>
    void
    buffer<Alloc>::write (void const *p, std::size_t len)
    {
      memcpy (alloc (len), p, len);
    }

    template<typename Alloc>
    template<typename T, std::size_t N>
    void
    buffer<Alloc>::write (T const (&array)[N])
    {
      write (array, N * sizeof (T));
    }

    template<typename Alloc>
    buffer<Alloc>::operator std::string ()
    {
      return std::string ((char *) linearise (), length ());
    }

    template<typename Alloc>
    buffer<Alloc>::buffer (std::size_t initial, std::size_t extend)
    : extend (extend)
    {
      size = 0;
    
      first = last = (chunk *) Alloc::allocate (sizeof (chunk) + initial);
      first->alloc = sizeof (chunk) + initial;
      first->next = 0;
    
      ptr = first->data;
      end = ptr + initial;
    }
    
    template<typename Alloc>
    void
    buffer<Alloc>::destroy (chunk *&chain)
    {
      while (chain)
        {
          chunk *next = chain->next;
    
          Alloc::deallocate (chain, chain->alloc);
          chain = next;
        }
    }
    
    template<typename Alloc>
    void
    buffer<Alloc>::clear ()
    {
      destroy (first->next);
    
      size = 0;
      ptr = first->data;
      end = ptr + first->alloc - sizeof (chunk);
    }
    
    template<typename Alloc>
    void
    buffer<Alloc>::finalise ()
    {
      size += last->size = ptr - last->data;
    }
    
    template<typename Alloc>
    void
    buffer<Alloc>::reserve (std::size_t bytes)
    {
      finalise ();
    
      do
        {
          extend += extend >> 1;
          extend = (extend + 15) & ~15;
        }
      while (extend < bytes);
    
      chunk *add = (chunk *) Alloc::allocate (sizeof (chunk) + extend);
      add->alloc = sizeof (chunk) + extend;
      add->next = 0;
    
      last->next = add;
      last = add;
    
      ptr = last->data;
      end = ptr + extend;
    }
    
    template<typename Alloc>
    void
    buffer<Alloc>::linearise (void *data)
    {
      last->size = ptr - last->data;
    
      for (chunk *c = first; c; c = c->next)
        {
          memcpy (data, c->data, c->size);
          data = (((byte *)data) + c->size);
        }
    }
    
    template<typename Alloc>
    typename buffer<Alloc>::byte *
    buffer<Alloc>::linearise ()
    {
      finalise ();
    
      chunk *add = (chunk *) Alloc::allocate (sizeof (chunk) + size);
      add->alloc = sizeof (chunk) + size;
      add->next = 0;
    
      linearise (add->data);
      destroy (first);
    
      first = last = add;
      ptr = last->data + size;
      end = ptr;
      size = 0;
    
      return first->data;
    }
  }
}
