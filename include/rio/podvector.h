#include <cstdlib>
#include <cstddef>

namespace rio
{
  template<typename T>
  struct reverse_iterator
  {
    T *ptr_;

    reverse_iterator (T *p = 0)
    : ptr_ (p)
    {
    }

    reverse_iterator &operator = (T *p)
    {
      ptr_ = p;
      return *this;
    }

    T &operator * ()
    {
      return *ptr_;
    }

    T const &operator * () const
    {
      return *ptr_;
    }

    T *operator -> ()
    {
      return ptr_;
    }

    T const *operator -> () const
    {
      return ptr_;
    }

    reverse_iterator &operator -- ()
    {
      ++ptr_;
      return *this;
    }

    reverse_iterator &operator ++ ()
    {
      --ptr_;
      return *this;
    }

    reverse_iterator operator -- (int)
    {
      reverse_iterator<T> p = *this;
      ++ptr_;
      return p;
    }

    reverse_iterator operator ++ (int)
    {
      reverse_iterator<T> p = *this;
      --ptr_;
      return p;
    }

    reverse_iterator &operator -= (ptrdiff_t d)
    {
      ptr_ += d;
      return *this;
    }

    reverse_iterator &operator += (ptrdiff_t d)
    {
      ptr_ -= d;
      return *this;
    }

    ptrdiff_t operator - (reverse_iterator &p)
    {
      return p.ptr_ - ptr_;
    }

    bool operator <  (reverse_iterator const &p) { return p.ptr_ <  ptr_; }
    bool operator <= (reverse_iterator const &p) { return p.ptr_ <= ptr_; }
    bool operator >  (reverse_iterator const &p) { return p.ptr_ >  ptr_; }
    bool operator >= (reverse_iterator const &p) { return p.ptr_ >= ptr_; }
    bool operator == (reverse_iterator const &p) { return p.ptr_ == ptr_; }
    bool operator != (reverse_iterator const &p) { return p.ptr_ != ptr_; }
    bool operator == (T *p) { return p == ptr_; }
    bool operator != (T *p) { return p != ptr_; }
  };

  template<typename T>
  inline reverse_iterator<T>
  operator + (reverse_iterator<T> const &p, ptrdiff_t d)
  {
    return reverse_iterator<T> (p.ptr_ - d);
  }

  template<typename T>
  inline reverse_iterator<T>
  operator + (ptrdiff_t d, reverse_iterator<T> const &p)
  {
    return reverse_iterator<T> (d - p.ptr_);
  }

  template<typename T>
  inline reverse_iterator<T>
  operator - (reverse_iterator<T> const &p, ptrdiff_t d)
  {
    return reverse_iterator<T> (p.ptr_ + d);
  }

  template<typename T>
  inline reverse_iterator<T>
  operator - (ptrdiff_t d, reverse_iterator<T> const &p)
  {
    return reverse_iterator<T> (d + p.ptr_);
  }

  template<typename T>
  inline bool
  operator == (T *l, reverse_iterator<T> const &p)
  {
    return p.ptr_ == l;
  }

  template<typename T>
  inline bool
  operator != (T *l, reverse_iterator<T> const &p)
  {
    return p.ptr_ != l;
  }


  /**
   * \brief Fast version of std::podvector
   *
   * This podvector class may not be completely standards compliant, but it is
   * mostly. It does not take an allocator parameter.
   */
  template<typename T>
  struct podvector
  {
    typedef T &                               reference;
    typedef T const &                         const_reference;
    typedef T *                               pointer;
    typedef T const *                         const_pointer;
    typedef T                                 value_type;
    typedef std::size_t                       size_type;
    typedef ptrdiff_t                         difference_type;
    typedef T *                               iterator;
    typedef T const *                         const_iterator;
    typedef rio::reverse_iterator<T>          reverse_iterator;
    typedef rio::reverse_iterator<T const>    const_reverse_iterator;

    podvector ();
    podvector (std::size_t r);
    podvector (std::size_t r, std::size_t res);
    podvector (const podvector &f);
    virtual ~podvector ();

    podvector &operator = (const podvector &f);

    void reserve (std::size_t r);
    void erase (iterator w);
    void erase (iterator f, iterator l);
    void push_back (const_reference val);
    void pop_back ();
    void resize (std::size_t r);
    void clear ();

    operator pointer ();
    operator const_pointer () const;

    std::size_t size () const;
    std::size_t capacity () const;
    bool empty () const;

    reference front ();
    const_reference front () const;
    reference back ();
    const_reference back () const;
    iterator begin ();
    const_iterator begin () const;
    reverse_iterator rbegin ();
    const_reverse_iterator rbegin () const;
    iterator end ();
    const_iterator end () const;
    reverse_iterator rend ();
    const_reverse_iterator rend () const;

  private:
    std::size_t reserved;
    std::size_t len;
    pointer data;
  };
}
