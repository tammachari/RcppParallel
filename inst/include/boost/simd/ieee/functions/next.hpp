//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_IEEE_FUNCTIONS_NEXT_HPP_INCLUDED
#define BOOST_SIMD_IEEE_FUNCTIONS_NEXT_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>


namespace boost { namespace simd { namespace tag
  {
   /*!
     @brief next generic tag

     Represents the next function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct next_ : ext::elementwise_<next_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<next_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_next_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
   template<class Site, class... Ts>
   BOOST_FORCEINLINE generic_dispatcher<tag::next_, Site> dispatching_next_(adl_helper, boost::dispatch::meta::unknown_<Site>, boost::dispatch::meta::unknown_<Ts>...)
   {
     return generic_dispatcher<tag::next_, Site>();
   }
   template<class... Args>
   struct impl_next_;
  }
  /*!
    Returns the smallest element strictly greater than the parameter

    @par Semantic:

    @code
    T r = next(a0);
    @endcode

    computes the smallest value strictly greater than a0 in type T

    @param a0

    @return a value of same type as the input
  **/
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::next_, next, 1)
} }

#endif
