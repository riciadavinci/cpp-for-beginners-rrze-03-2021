/**************************************************************************************************
*
* \file Specialization1.cpp
* \brief C++ Training - Template Specialization Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Specialize the given 'compare()' function for pointers to char.
*
**************************************************************************************************/

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>


template< typename T >
int compare( const T* pa, const T* pb )
{
   if( *pa < *pb )
      return -1;
   else if( *pb < *pa )
      return 1;
   else
      return 0;
}


// TODO: Specialize the given 'compare()' function for pointers to char.


int main()
{
   {
      int i = 2;
      int j = 1;

      const int res = compare( &i, &j );

      std::cout << "\n res = " << res << "\n\n";
   }

   {
      const char* a = "Hello";
      const char* b = "House";

      const int res = compare( a, b );

      std::cout << "\n res = " << res << "\n\n";
   }

   return EXIT_SUCCESS;
}
