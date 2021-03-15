/**************************************************************************************************
*
* \file Add.cpp
* \brief C++ Training - Introduction of std::cin and std::cout
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Read in two numbers via std::cin, add them and print the result.
*
**************************************************************************************************/

#include <iostream>
#include <cstdlib>


int main()
{
   int i, j;
   // Read in the first integer
   std::cout << "First integer: ";
   
   std::cin >> i;
   
   if( !std::cin ){
      std::cerr << "Invalid integral value detected\n";
      return EXIT_FAILURE;
   }

   // Read in the second integer
   std::cout << "Second integer: ";
   
   if( !(std::cin >> j) ){
      std::cerr << "Invalid integral value detected\n";
      return EXIT_FAILURE;
   }

   // Add the integers
   int k = i + j;

   // Printing the result
   std::cout << "The result of " << i << " + " << j << " is " << k << "\n"; 

   return EXIT_SUCCESS;
}
