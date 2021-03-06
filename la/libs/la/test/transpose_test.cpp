//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/transpose.hpp>
#include <boost/la/array_matrix_traits.hpp>
#include <boost/la/matrix_assign.hpp>
#include <boost/la/matrix_mul_eq_scalar.hpp>
#include "test_la_matrix.hpp"
#include "gold.hpp"

namespace
	{
	template <int Rows,int Cols>
	void
	test()
		{
		using namespace boost::la;
		test_la::matrix<M1,Rows,Cols> x(42,1);
		float r1[Cols][Rows];
		for( int i=0; i!=Rows; ++i )
			for( int j=0; j!=Cols; ++j )
				r1[j][i]=x.a[i][j];
		float r2[Cols][Rows];
		assign(r2,x|transpose);
		BOOST_TEST_LA_EQ(r1,r2);
		test_la::scalar_multiply_m(x.b,x.a,2.0f);
		x|transpose *= 2;
		BOOST_TEST_LA_EQ(x.a,x.b);
		}
	}

int
main()
	{
	test<1,2>();
	test<2,1>();
	test<2,2>();
	test<1,3>();
	test<3,1>();
	test<3,3>();
	test<1,4>();
	test<4,1>();
	test<4,4>();
	test<1,5>();
	test<5,1>();
	test<5,5>();
	return boost::report_errors();
	}
