/**************************************************************************************************
*
* \file Print.cpp
* \brief C++ Training - Variadic Template Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Extend the given 'print()' function by variadic templates to enable an arbitrary
*       number of function arguments.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>


template< typename T >
std::ostream& print( std::ostream& os, const T& value )
{
   return os << value;
}


// TODO: Extend the given 'print()' function by variadic templates to enable an arbitrary
//       number of function arguments.


int main()
{
   //print( std::cout, 1, ' ', 1.2, ' ', "String", '\n' );

   return EXIT_SUCCESS;
}
