/**************************************************************************************************
*
* \file Pointers.cpp
* \brief C++ Training - Exercise about pointer types
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Create a pointer and assign a value to change through the pointer.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>


int main()
{
   int i = 1;

   int* j = &i;

   // Checking if a pointer points to Null
   // if not, only then edit the value being pointed to
   if(j != nullptr){
      *j = 42;
   }

   std::cout << "Result: i = " << i << "\n";

   return EXIT_SUCCESS;
}
