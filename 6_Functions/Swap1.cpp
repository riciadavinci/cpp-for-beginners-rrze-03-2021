/**************************************************************************************************
*
* \file Swap1.cpp
* \brief C++ Training - Function Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Write a function to swap two integers
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>


// TODO: Implement the 'swap()' function

void swap(int& a, int& b){
   int temp = a;
   a = b;
   b = temp;
}

int main()
{

   int a = 3;
   int b = 5;

   std::cout << "Before Swapping: ";
   std::cout << "\n"
             << " a = " << a << "\n"
             << " b = " << b << "\n"
             << "\n";

   swap( a, b );

   std::cout << "After Swapping: ";
   std::cout << "\n"
             << " a = " << a << "\n"
             << " b = " << b << "\n"
             << "\n";

   return EXIT_SUCCESS;
}
