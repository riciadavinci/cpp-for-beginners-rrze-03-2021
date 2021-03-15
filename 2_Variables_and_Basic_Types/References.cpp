/**************************************************************************************************
*
* \file References.cpp
* \brief C++ Training - Exercise about reference types
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Create a reference and assign a value to change through the reference.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>


int main()
{
   int i = 1;

   // TODO: Create a reference and assign a value to change through the reference.
   int j = i;     // This is a copy (just the value)
   
   int& k = i;    // This is a reference (alias of the other variable, so now, both I and J mean the same thing)

   k = 42;

   std::cout << "Result: i = " << i << "\n";
   std::cout << "Result: j = " << j << "\n";
   std::cout << "Result: k = " << k << "\n";

   return EXIT_SUCCESS;
}
