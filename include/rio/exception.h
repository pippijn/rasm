// Copyright © 2008 Pippijn van Steenhoven
#ifndef RIO_EXCEPTION
#define RIO_EXCEPTION

#include <cstdarg>
#include <cstdio>
#include <cerrno>
#include <string>

#include <algorithm>
#include <exception>

#define SRCINF  ::rio::srcinf (__FILE__, __LINE__, __func__)

namespace rio
{
  struct srcinf
  {
    srcinf ()
    {
    }
  
    srcinf (char const *filename, unsigned int linenumber, char const *function)
    : info_ (info (filename, linenumber, function))
    {
    }
  
    unsigned int line () const throw () { return info_.line_; }
    char const *file () const throw ()  { return info_.file_; }
    char const *func () const throw ()  { return info_.func_; }
    
    operator bool () const
    {
      return file () != "<anonymous file>"
          && line () != 0
          && func () != "<anonymous function> ()";
    }
  
    srcinf (srcinf const &rhs)
    : info_ (rhs.info_)
    {
    }
  
  private:
    struct info
    {
      char const *file_;
      unsigned line_;
      char const *func_;
  
      info ()
      : file_ (0), line_ (0), func_ (0)
      {
      }
  
      info (char const *filename, unsigned linenumber, char const *function)
      : file_ (filename ? filename : "<anonymous file>"), line_ (linenumber), func_ (function ? function : "<anonymous function> ()")
      {
      }
    };

    info info_;
  };
   
  struct exception : std::exception
  {
    virtual char const *what () const throw ()
    {
      if (full.empty ())
        {
          char buf[BUFSIZ];
          snprintf (buf, BUFSIZ - 1, "%s(#%d) %s: %s", si.file (), si.line (), si.func (), msg.c_str ());
          full = buf;
        }
      return full.c_str ();
    }

    char const *message () const throw ()
    {
      return msg.c_str ();
    }

    int error () const
    {
      return errnum;
    }

    virtual ~exception () throw ()
    {
    }
  
  protected:
    exception ()
    : errnum (errno)
    {
    }

    exception (srcinf const &si, std::string const &fmt)
    : errnum (errno)
    {
      what (si, fmt);
    }

    exception (srcinf const &si, std::string const &fmt, va_list ap)
    : errnum (errno)
    {
      what (si, fmt, ap);
    }

    void what (srcinf const &si, std::string const &fmt)
    {
      this->si  = si;
      this->msg = fmt;
    }

    void what (srcinf const &si, std::string const &fmt, std::va_list ap)
    {
      char buf[BUFSIZ];
      vsnprintf (buf, BUFSIZ - 1, fmt.c_str (), ap);
      va_end (ap);
      this->si  = si;
      this->msg = buf;
    }

  private:
    srcinf si;
    std::string msg;
    mutable std::string full;
    int errnum;
  };
}

#define ADD_EXCEPTION(name, base)                                                       \
struct name ## _exception : base                                                        \
{                                                                                       \
  explicit name ## _exception ()                                                        \
  : base (::rio::srcinf (), #name " exception thrown")                                  \
  {                                                                                     \
  }                                                                                     \
                                                                                        \
  explicit name ## _exception (::rio::srcinf const &si)                                 \
  : base (si, #name " exception thrown")                                                \
  {                                                                                     \
  }                                                                                     \
                                                                                        \
  name ## _exception (::std::string const &fmt, va_list ap)                             \
  : base (::rio::srcinf (), fmt, ap)                                                    \
  {                                                                                     \
  }                                                                                     \
                                                                                        \
  name ## _exception (::rio::srcinf const &si, ::std::string const &fmt, va_list ap)    \
  : base (si, fmt, ap)                                                                  \
  {                                                                                     \
  }                                                                                     \
                                                                                        \
  explicit name ## _exception (::std::string const &fmt, ...)                           \
  {                                                                                     \
    va_list ap;                                                                         \
    va_start (ap, fmt);                                                                 \
    what (::rio::srcinf (), fmt, ap);                                                   \
  }                                                                                     \
                                                                                        \
  explicit name ## _exception (::rio::srcinf const &si, ::std::string const &fmt, ...)  \
  {                                                                                     \
    va_list ap;                                                                         \
    va_start (ap, fmt);                                                                 \
    what (si, fmt, ap);                                                                 \
  }                                                                                     \
}

ADD_EXCEPTION (out_of_range, rio::exception);
ADD_EXCEPTION (overflow, rio::exception);

ADD_EXCEPTION (compiler, rio::exception);
ADD_EXCEPTION (type, compiler_exception);
ADD_EXCEPTION (argument, compiler_exception);
ADD_EXCEPTION (lexer, rio::exception);
ADD_EXCEPTION (parser, rio::exception);

#define die(T, msg...)          throw T ## _exception (SRCINF, msg)
#define ensure(T, cond, msg...) do { if (!(cond)) throw T ## _exception (SRCINF, "Assertion `" #cond "' failed: " msg); } while (0)

#endif
// vim:filetype=cpp
