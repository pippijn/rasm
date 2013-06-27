// Copyright © 2008 Pippijn van Steenhoven
#ifndef RIO_SINGLETON_H
#define RIO_SINGLETON_H

#include <cstdlib>

namespace rio
{
  namespace detail
  {
    struct empty_singleton_initialiser
    {
      template<typename T>
      void operator () (T &)
      {
      }
    };
  }

  template<typename Base, typename Context = Base, typename Initialiser = detail::empty_singleton_initialiser>
  struct singleton : Base
  {
    typedef Base                base_type;
    typedef Context             context_type;
    typedef Initialiser         initialiser_type;

    static base_type &instance ()
    {
      static singleton object;
      static bool donethat = false;
      
      if (singleton::destroyed_)
        {
          donethat = false;
          new (&object) singleton;
          atexit (singleton::destroy);
        }

      if (!donethat)
        {
          donethat = true;
          initialiser_type () (object);
        }
      
      return object;
    }

  private: // types
    typedef singleton<base_type, context_type, initialiser_type> this_type;

  private: // functions
    singleton () throw ()
    {
      destroyed_ = false;
    }

    virtual ~singleton () throw ()
    {
      destroyed_ = true;
    }

    static void destroy ()
    {
      if (destroyed_)
        return;
      static_cast<singleton &> (instance ()).~singleton ();
    }

  private: // variables
    static bool destroyed_;
  };

  template<typename BaseType, typename ContextType, typename InitialiserType>
  bool singleton<BaseType, ContextType, InitialiserType>::destroyed_ = false;
}

#endif
// vim:filetype=cpp
