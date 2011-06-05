#ifndef RIO_VECTOR_TCC
#define RIO_VECTOR_TCC

namespace rio
{
  template<typename T>
  podvector<T>::podvector ()
  : reserved (64), len (0)
  {
    data = (static_cast<T *> (std::malloc (sizeof (T) * (reserved + 1)))) + 1;
  }

  template<typename T>
  podvector<T>::podvector (std::size_t r)
  : reserved (r + 1024), len (r)
  {
    data = (static_cast<T *> (std::malloc (sizeof (T) * (reserved + 1)))) + 1;
  }

  template<typename T>
  podvector<T>::podvector (std::size_t r, std::size_t res)
  : reserved (res), len (r)
  {
    data = (static_cast<T *> (std::malloc (sizeof (T) * (reserved + 1)))) + 1;
  }
  
  template<typename T>
  podvector<T>::podvector (const podvector &f)
  : reserved (f.reserved), len (f.len)
  {
    data = (static_cast<T *> (std::malloc (sizeof (T) * (reserved + 1)))) + 1;
    std::memcpy (data, f.data, sizeof (T) * len);
  }

  template<typename T>
  podvector<T>::~podvector ()
  {
    free (data - 1);
  }

  template<typename T>
  podvector<T> &
  podvector<T>::operator = (const podvector &f)
  {
    reserved = f.reserved;
    len = f.len;
    data = (static_cast<T *> (std::realloc (data - 1, sizeof (T) * (reserved + 1)))) + 1;
    std::memcpy (data, f.data, sizeof (T) * (reserved - 1));
    return *this;
  }

  template<typename T>
  void
  podvector<T>::reserve (std::size_t r)
  {
    reserved = r;
    data = (static_cast<T *> (std::realloc (data - 1, sizeof (T) * (reserved + 1)))) + 1;
  }

  template<typename T>
  void
  podvector<T>::erase (iterator w)
  {
    iterator e = data + len;
    if (w == e)
      return;
    for (; w != e; ++w)
      *w = *(w + 1);
    
    if (len * 4 + 4096 < reserved)
      reserve (len * 2 + 2048);
    len--;
  }

  template<typename T>
  void
  podvector<T>::erase (iterator f, iterator l)
  {
    if (f == l)
      return;
    ptrdiff_t d = l - f;
    iterator e = data + len;

    for (; l != e; ++l)
      *f++ = *l;
    len -= d;
    if (len * 4 + 4096 < reserved)
      reserve (len * 2 + 2048);
  }

  template<typename T>
  void
  podvector<T>::push_back (const_reference val)
  {
    if (len >= reserved)
      reserve (len * 2 + 2048);
    data[len++] = val;
  }

  template<typename T>
  void
  podvector<T>::pop_back ()
  {
    if (len * 4 + 4096 < reserved)
      reserve (len * 2 + 2048);
    --len;
  }

  template<typename T>
  void
  podvector<T>::resize (std::size_t r)
  {
    len = r;
    if (len >= reserved)
      reserve (len * 2 + 2048);
  }

  template<typename T>
  void
  podvector<T>::clear ()
  {
    len = 0;
  }

  template<typename T>
  podvector<T>::operator pointer ()
  {
    return data;
  }

  template<typename T>
  podvector<T>::operator const_pointer () const
  {
    return data;
  }

  template<typename T>
  std::size_t
  podvector<T>::size () const
  {
    return len;
  }

  template<typename T>
  std::size_t
  podvector<T>::capacity () const
  {
    return reserved;
  }

  template<typename T>
  bool
  podvector<T>::empty () const
  {
    return len == 0;
  }

  template<typename T>
  typename podvector<T>::reference
  podvector<T>::front ()
  {
    return *data;
  }

  template<typename T>
  typename podvector<T>::const_reference
  podvector<T>::front () const
  {
    return *data;
  }

  template<typename T>
  typename podvector<T>::reference
  podvector<T>::back ()
  {
    return data[len - 1];
  }

  template<typename T>
  typename podvector<T>::const_reference
  podvector<T>::back () const
  {
    return data[len - 1];
  }

  template<typename T>
  typename podvector<T>::iterator
  podvector<T>::begin ()
  {
    return data;
  }

  template<typename T>
  typename podvector<T>::const_iterator
  podvector<T>::begin () const
  {
    return data;
  }

  template<typename T>
  typename podvector<T>::reverse_iterator
  podvector<T>::rbegin ()
  {
    return data + len - 1;
  }

  template<typename T>
  typename podvector<T>::const_reverse_iterator
  podvector<T>::rbegin () const
  {
    return data + len - 1;
  }

  template<typename T>
  typename podvector<T>::iterator
  podvector<T>::end ()
  {
    return data + len;
  }

  template<typename T>
  typename podvector<T>::const_iterator
  podvector<T>::end () const
  {
    return data + len;
  }

  template<typename T>
  typename podvector<T>::reverse_iterator
  podvector<T>::rend ()
  {
    return data - 1;
  }

  template<typename T>
  typename podvector<T>::const_reverse_iterator
  podvector<T>::rend () const
  {
    return data - 1;
  }
}

#endif
