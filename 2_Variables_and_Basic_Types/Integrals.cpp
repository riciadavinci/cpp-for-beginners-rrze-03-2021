/**************************************************************************************************
*
* \file Size.cpp
* \brief C++ Training - Exercise about fundamental types
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Predict the output of the six given integral computations.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <vector>


int main()
{
   // First predict the output of the following integral computations, then confirm you
   // predictions by running the program!

   const auto u1 = 10U;
   const auto u2 = 42U;

   std::cout << "u2 - u1 = " << ( u2 - u1 ) << "\n";
   std::cout << "u1 - u2 = " << ( u1 - u2 ) << "\n";

   const auto i1 = 10;
   const auto i2 = 42;

   std::cout << "i2 - i1 = " << ( i2 - i1 ) << "\n";
   std::cout << "i1 - i2 = " << ( i1 - i2 ) << "\n";

   const auto r1 = i1 - u2;
   const auto r2 = u2 - i1;

   std::cout << "i1 - u2 = " << r1 << "\n";
   std::cout << "u2 - i1 = " << r2 << "\n";

   return EXIT_SUCCESS;
}
