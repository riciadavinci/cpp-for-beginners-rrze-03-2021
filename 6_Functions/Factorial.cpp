/**************************************************************************************************
*
* \file Factorial.cpp
* \brief C++ Training - Function Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Write a function to compute the factorial of a given integer.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>


// TODO: Implement the 'factorial()' function
int factorial(int value){
   if(value == 0){
      return 1;
   }
   
   int fact = 1;

   for(int i = 1; i < value; ++i){
      fact *= i;
   }

   return fact;
}


int main()
{
   const int fact0 = factorial(0);
   std::cout << "fact0 = " << fact0 << "\n";

   const int fact3 = factorial(3);
   std::cout << "fact0 = " << fact3 << "\n";

   return EXIT_SUCCESS;
}

