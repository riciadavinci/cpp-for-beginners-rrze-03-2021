/**************************************************************************************************
*
* \file InitializerList.cpp
* \brief C++ Training - Function Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Rework the 'sum()' function to enable compile time computations.
*
**************************************************************************************************/

#include <cstdlib>
#include <initializer_list>
#include <iostream>


int sum( std::initializer_list<int> list )
{
   int result = 0;
   for( int i : list )
      result += i;
   return result;
}


int main()
{
   const int s = sum( { 1, 2, 3, 4, 5 } );

   std::cout << "\n sum = " << s << "\n\n";

   return EXIT_SUCCESS;
}
