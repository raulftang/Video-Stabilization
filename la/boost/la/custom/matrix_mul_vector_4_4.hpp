//Copyright (c) 2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_LA_CUSTOM_MATRIX_MUL_VECTOR_4_4_HPP_INCLUDED
#define BOOST_LA_CUSTOM_MATRIX_MUL_VECTOR_4_4_HPP_INCLUDED

//This file was generated by a program. Do not edit manually.

#include <boost/la/config.hpp>
#include <boost/la/deduce_vector.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/static_assert.hpp>

namespace
boost
    {
    namespace
    la
        {
        template <class A,class B>
        BOOST_LA_INLINE_OPERATIONS
        typename lazy_enable_if_c<
            matrix_traits<A>::rows==4 && matrix_traits<A>::cols==4 &&
            vector_traits<B>::dim==4,
            deduce_vector2<A,B,4> >::type
        operator*( A const & a, B const & b )
            {
            typedef typename matrix_traits<A>::scalar_type Ta;
            typedef typename vector_traits<B>::scalar_type Tb;
            Ta const a00 = matrix_traits<A>::template r<0,0>(a);
            Ta const a01 = matrix_traits<A>::template r<0,1>(a);
            Ta const a02 = matrix_traits<A>::template r<0,2>(a);
            Ta const a03 = matrix_traits<A>::template r<0,3>(a);
            Ta const a10 = matrix_traits<A>::template r<1,0>(a);
            Ta const a11 = matrix_traits<A>::template r<1,1>(a);
            Ta const a12 = matrix_traits<A>::template r<1,2>(a);
            Ta const a13 = matrix_traits<A>::template r<1,3>(a);
            Ta const a20 = matrix_traits<A>::template r<2,0>(a);
            Ta const a21 = matrix_traits<A>::template r<2,1>(a);
            Ta const a22 = matrix_traits<A>::template r<2,2>(a);
            Ta const a23 = matrix_traits<A>::template r<2,3>(a);
            Ta const a30 = matrix_traits<A>::template r<3,0>(a);
            Ta const a31 = matrix_traits<A>::template r<3,1>(a);
            Ta const a32 = matrix_traits<A>::template r<3,2>(a);
            Ta const a33 = matrix_traits<A>::template r<3,3>(a);
            Tb const b0 = vector_traits<B>::template r<0>(b);
            Tb const b1 = vector_traits<B>::template r<1>(b);
            Tb const b2 = vector_traits<B>::template r<2>(b);
            Tb const b3 = vector_traits<B>::template r<3>(b);
            typedef typename deduce_vector2<A,B,4>::type R;
            BOOST_STATIC_ASSERT(vector_traits<R>::dim==4);
            R r;
            vector_traits<R>::template w<0>(r)=a00*b0+a01*b1+a02*b2+a03*b3;
            vector_traits<R>::template w<1>(r)=a10*b0+a11*b1+a12*b2+a13*b3;
            vector_traits<R>::template w<2>(r)=a20*b0+a21*b1+a22*b2+a23*b3;
            vector_traits<R>::template w<3>(r)=a30*b0+a31*b1+a32*b2+a33*b3;
            return r;
            }

        namespace
        la_detail
            {
            template <int M,int N>
            struct matrix_mul_vector_defined;

            template <>
            struct
            matrix_mul_vector_defined<4,4>
                {
                static bool const value=true;
                };
            }
        }
    }

#endif
