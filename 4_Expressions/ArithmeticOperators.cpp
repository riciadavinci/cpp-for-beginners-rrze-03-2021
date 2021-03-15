/**************************************************************************************************
*
* \file ArithmeticOperators.cpp
* \brief C++ Training - Programming Exercise about the arithmetic operators
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Use all of the arithmetic operators: Unary addition, unary minus, addition, subtraction,
*       multiplication, division, and remainder.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>


int main()
{
   int i = 1;
   int j = 2;
   int k;

   // Unary plus
   k = +i;
   std::cout << "k = " << k << "\n";

   // Unary minus
   k = -i;
   std::cout << "k = " << k << "\n";

   // Addition
   k = i + j;
   std::cout << "k = " << k << "\n";

   // Subtraction
   k = i - j;
   std::cout << "k = " << k << "\n";

   // Multiplication
   k = i * j;
   std::cout << "k = " << k << "\n";

   // Division
   k = i / j;
   std::cout << "k = " << k << "\n";

   // Remainder
   k = i % j;
   std::cout << "k = " << k << "\n";

   return EXIT_SUCCESS;
}
