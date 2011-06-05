#ifndef AD_META_TYPES_H
#define AD_META_TYPES_H

#include <tr1/type_traits>

namespace rio
{
  /**
   * \brief C++ template meta-programming tools.
   *
   * This namespace provides some commonly used utilities that aid in
   * template meta-programming.
   */
  namespace meta
  {
    // We import some of tr1's type_traits for uniformity
    using std::tr1::is_same;
    using std::tr1::is_convertible;
    using std::tr1::is_integral;
    using std::tr1::remove_reference;
    using std::tr1::remove_const;
    using std::tr1::is_unsigned;

    struct null_type;
    struct empty_type
    {
    };

    /**
     * \brief SFINAE meta-program to decide whether or not overload resolution
     * ought to pick a function or not.
     *
     * type_if will allow the compiler to pick the function if \a cond is true.
     * \c type_if<T, true>::type will be \a T. \c type_if<T, false>::type is
     * undefined but using it anyways will not cause a compile error. The
     * function will simply not be seen due to the way the SFINAE (Substitution
     * Failure Is Not An Error) idiom works.
     */
    template<typename T, bool cond>
    struct type_if
    {
      //! This type is only available if \a cond is true.
      typedef T type;
    };
  
    //! If \a cond is false, \c type is not defined.
    template<typename T>
    struct type_if<T, false>
    {
    };
  
    /**
     * \brief Same as type_if but works the other way around.
     *
     * type_if enables a function as overload resolution candidate, type_unless
     * disables it.
     */
    template<typename T, bool cond>
    struct type_unless
    {
      //! This type is only available if \a cond is false.
      typedef T type;
    };
  
    //! If \a cond is true, \c type is not defined.
    template<typename T>
    struct type_unless<T, true>
    {
    };

    template<bool cond, typename T>
    struct enable_if : type_if<T, cond>
    {
    };
  
    template<bool cond, typename T>
    struct disable_if : type_if<T, !cond>
    {
    };
  
    /**
     * \brief Identity type wrapper used in template metaprogramming to be able to
     * inherit from any type, including builtin types.
     */
    template<typename T>
    struct identity
    {
      //! Accessor typedef to get T.
      typedef T type;
    };
    
    /**
     * \brief A type-if implementation. If \a cond is \a true, this template provides
     * \a then_t as \c if_t::ret.
     */
    template<bool cond, typename then_t, typename else_t>
    struct if_t
    {
      //! then_t is used if cond is true.
      typedef then_t ret;
    };
    
    /**
     * If \c cond is \c false, then this template provides \c else_t as \c ret.
     */
    template<typename then_t, typename else_t>
    struct if_t<false, then_t, else_t>
    {
      //! else_t is used if cond is false.
      typedef else_t ret;
    };
    
    /**
     * \brief This is merely a convenience template that inherits from if_t so we
     * don't have to type \c typename so often.
     */
    template<bool cond, typename then_t, typename else_t>
    struct type_or
    : if_t<cond, identity<then_t>, else_t>::ret
    {
    };
  
    template<typename T>
    struct is_float
    {
      static bool const value = false;
    };

    template<>
    struct is_float<float>
    {
      static bool const value = true;
    };
    template<>
    struct is_float<double>
    {
      static bool const value = true;
    };
    template<>
    struct is_float<long double>
    {
      static bool const value = true;
    };

    template<typename T>
    struct is_numeric
    {
      static bool const value = false;
    };

    template<>
    struct is_numeric<float>
    {
      static bool const value = true;
    };
    template<>
    struct is_numeric<double>
    {
      static bool const value = true;
    };
    template<>
    struct is_numeric<long double>
    {
      static bool const value = true;
    };
    template<>
    struct is_numeric<bool>
    {
      static bool const value = true;
    };
    template<>
    struct is_numeric<signed char>
    {
      static bool const value = true;
    };
    template<>
    struct is_numeric<unsigned char>
    {
      static bool const value = true;
    };
    template<>
    struct is_numeric<signed short>
    {
      static bool const value = true;
    };
    template<>
    struct is_numeric<unsigned short>
    {
      static bool const value = true;
    };
    template<>
    struct is_numeric<signed int>
    {
      static bool const value = true;
    };
    template<>
    struct is_numeric<unsigned int>
    {
      static bool const value = true;
    };
    template<>
    struct is_numeric<signed long>
    {
      static bool const value = true;
    };
    template<>
    struct is_numeric<unsigned long>
    {
      static bool const value = true;
    };

    /**
     * \brief Meta-program returning true if \a T is of class type.
     */
    template<typename T>
    struct is_class
    {
      //! This is true if \a T is a class type.
      static bool const value = true;
    };
  
    //! Pointers are non-class types.
    template<typename T>
    struct is_class<T *>
    {
      //! False if \a T is of non-class type.
      static bool const value = false;
    };
  
    template<>
    struct is_class<void>
    {
      static bool const value = false;
    };
    template<>
    struct is_class<float>
    {
      static bool const value = false;
    };
    template<>
    struct is_class<double>
    {
      static bool const value = false;
    };
    template<>
    struct is_class<long double>
    {
      static bool const value = false;
    };
    template<>
    struct is_class<bool>
    {
      static bool const value = false;
    };
    template<>
    struct is_class<signed char>
    {
      static bool const value = false;
    };
    template<>
    struct is_class<unsigned char>
    {
      static bool const value = false;
    };
    template<>
    struct is_class<signed short>
    {
      static bool const value = false;
    };
    template<>
    struct is_class<unsigned short>
    {
      static bool const value = false;
    };
    template<>
    struct is_class<signed int>
    {
      static bool const value = false;
    };
    template<>
    struct is_class<unsigned int>
    {
      static bool const value = false;
    };
    template<>
    struct is_class<signed long>
    {
      static bool const value = false;
    };
    template<>
    struct is_class<unsigned long>
    {
      static bool const value = false;
    };

    template<typename T>
    struct is_const
    {
      static const bool value = false;
    };

    template<typename T>
    struct is_const<T const>
    {
      static const bool value = true;
    };
    
    template<typename T>
    struct is_pointer
    {
      static const bool value = false;
    };
    
    template<typename T>
    struct is_pointer<T *>
    {
      static const bool value = true;
      static const bool constant = false;
    };
    
    template<typename T>
    struct is_pointer<const T *>
    {
      static const bool value = true;
      static const bool constant = true;
    };
  
    template<typename T>
    struct is_reference
    {
      static const bool value = false;
    };
    
    template<typename T>
    struct is_reference<T &>
    {
      static const bool value = true;
      static const bool constant = false;
    };
  
    template<typename T>
    struct is_reference<const T &>
    {
      static const bool value = true;
      static const bool constant = true;
    };
  
    template<typename T1, typename T2>
    struct is_equiv
    {
      static const bool value = false;
    };		
    
    template<typename T>
    struct is_equiv<T, T>
    {
      static const bool value = true;
    };		
    
    template<typename T>
    struct is_equiv<T &, T>
    {
      static const bool value = true;
    };

    template<typename T>
    struct is_equiv<T, T &>
    {
      static const bool value = true;
    };

    template<typename T>
    struct is_equiv<T, const T &>
    {
      static const bool value = true;
    };

    template<typename T>
    struct is_equiv<const T &, T &>
    {
      static const bool value = true;
    };

    template<typename Signature>
    struct is_compatible;

    template<typename T, typename T1>
    struct is_compatible<T (T1)>
    {
      static const bool value = is_convertible<T, T1>::value;
    };

    template<typename T, typename T1, typename T2>
    struct is_compatible<T (T1, T2)>
    {
      static const bool value = is_compatible<T (T2)>::value
                             || is_compatible<T (T1)>::value;
    };
    template<typename T, typename T1, typename T2, typename T3>
    struct is_compatible<T (T1, T2, T3)>
    {
      static const bool value = is_compatible<T (T2, T3)>::value
                             || is_compatible<T (T1)>::value;
    };
    template<typename T, typename T1, typename T2, typename T3, typename T4>
    struct is_compatible<T (T1, T2, T3, T4)>
    {
      static const bool value = is_compatible<T (T2, T3, T4)>::value
                             || is_compatible<T (T1)>::value;
    };
    template<typename T, typename T1, typename T2, typename T3, typename T4, typename T5>
    struct is_compatible<T (T1, T2, T3, T4, T5)>
    {
      static const bool value = is_compatible<T (T2, T3, T4, T5)>::value
                             || is_compatible<T (T1)>::value;
    };

    template<typename Signature>
    struct is_one_of;

    template<typename T, typename T1>
    struct is_one_of<T (T1)>
    {
      static const bool value = is_same<T, T1>::value;
    };

    template<typename T, typename T1, typename T2>
    struct is_one_of<T (T1, T2)>
    {
      static const bool value = is_one_of<T (T2)>::value
                             || is_one_of<T (T1)>::value;
    };
    template<typename T, typename T1, typename T2, typename T3>
    struct is_one_of<T (T1, T2, T3)>
    {
      static const bool value = is_one_of<T (T2, T3)>::value
                             || is_one_of<T (T1)>::value;
    };
    template<typename T, typename T1, typename T2, typename T3, typename T4>
    struct is_one_of<T (T1, T2, T3, T4)>
    {
      static const bool value = is_one_of<T (T2, T3, T4)>::value
                             || is_one_of<T (T1)>::value;
    };
    template<typename T, typename T1, typename T2, typename T3, typename T4, typename T5>
    struct is_one_of<T (T1, T2, T3, T4, T5)>
    {
      static const bool value = is_one_of<T (T2, T3, T4, T5)>::value
                             || is_one_of<T (T1)>::value;
    };

    template<typename T>
    struct remove_constref
    : remove_const<typename remove_reference<T>::type>
    {
    };
  }
}

#endif
