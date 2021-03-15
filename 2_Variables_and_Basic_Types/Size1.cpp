/**************************************************************************************************
*
* \file Size1.cpp
* \brief C++ Training - Exercise about fundamental types
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Print the size of the following types: 'char', 'short', 'int', 'long', 'float',
*       'float', 'double', 'long double'.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <limits>

int main()
{
   // Types to check: char, short, int, long, float, double, long double

   std::cout << "Size of bool is " << sizeof(bool) << " bytes.\n";
   std::cout << "Size of char is " << sizeof(char) << " bytes.\n";
   std::cout << "Size of short is " << sizeof(short) << " bytes.\n";
   std::cout << "Size of int is " << sizeof(int) << " bytes.\n";
   std::cout << "Size of long is " << sizeof(long) << " bytes.\n";
   std::cout << "Size of long long is " << sizeof(long long) << " bytes.\n";
   std::cout << "Size of float is " << sizeof(float) << " bytes.\n";
   std::cout << "Size of double is " << sizeof(double) << " bytes.\n";
   std::cout << "Size of long double is " << sizeof(long double) << " bytes.\n";

   // TODO: try above stuff with unsigned stuff


   // Special Stuff:
   long long l = std::numeric_limits<long long>::max();
   std::cout << "Largest positive number that can be stored on this system is: " << l << "\n\n";

   return EXIT_SUCCESS;
}
