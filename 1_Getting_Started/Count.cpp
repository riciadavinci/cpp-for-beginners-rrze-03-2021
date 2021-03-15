/**************************************************************************************************
*
* \file Count.cpp
* \brief C++ Training - Exercise for Flow Control
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Write a program to read at maximum 10 integers from std::cin and count the number of
*       odd and even numbers. Print the final result.
*
**************************************************************************************************/

#include <iostream>
#include <cstdlib>


int main()
{
   int odd_count = 0, even_count = 0;
   // Reading at maximum 10 integers
   for(int i = 1; i <= 10; ++i){
      int num;
      std::cout << "Enter " << i << ". number: ";
      if(std::cin >> num){
         if(num % 2 == 0){
            ++even_count;
         } 
         else{
            ++odd_count;
         }
      }
      else {
         // std::cin.clear();
         std::cerr << "Invalid integer detected!\n";
         break;
      }
   }

   // Printing the result
   std::cout << "Count of Odd Numbers entered: " << odd_count << "\n"
             << "Count of Even Numbers entered: " << even_count << "\n";

   // int a;
   // std::cin >> a;

   return EXIT_SUCCESS;
}
