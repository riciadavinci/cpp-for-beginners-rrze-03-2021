/**************************************************************************************************
*
* \file Multiply.cpp
* \brief C++ Training - Introduction of std::cin and std::cout
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Write a program to read in two numbers and multiply the result.
*
**************************************************************************************************/

#include <iostream>
#include <cstdlib>


int main()
{
   int num_1, num_2;
   // Read in the first integer
   std::cout << "First integer: ";

   if( !(std::cin >> num_1) ){
      std::cerr << "Invalid integral value detected\n";
      return EXIT_FAILURE;
   }

   // Read in the second integer
   std::cout << "Second integer: ";

   if( !(std::cin >> num_2) ){
      std::cerr << "Invalid integral value detected\n";
      return EXIT_FAILURE;
   }

   // Multiplying the integers
   int result = num_1 * num_2;

   // Printing the result
   std::cout << "The result of " << num_1 << " * " << num_2 << " is " << result;

   return EXIT_SUCCESS;
}
