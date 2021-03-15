/**************************************************************************************************
*
* \file FlowControl.cpp
* \brief C++ Training - Introduction of std::cin and std::cout
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Step 1: Sum up the values from 1 to 10.
*
* Step 2: Read in an unknown number of inputs via while and std::cin.
*
* Step 3: Sum up the values from 1 to 10.
*
* Step 4: Read in a range of integers and sum them up (but don't forget to check the input!)
*
**************************************************************************************************/

#include <iostream>
#include <cstdlib>


int main()
{
   
   // Step 1: Sum up the values from 1 to 10 by means of a while loop
   {
      int i = 1;
      int sum = 0;
      while(i <= 10){
         sum += i;   // sum = sum + i;
         ++i;        // i = i + 1;
      }

      std::cout << "The sum from 1 to 10 is " << sum << "\n";
   }

   // Step 2: Read in an unknown number of inputs via while and std::cin
   /*
   {
      int i;
      int sum = 0;
      while(std::cin >> i){
         sum += i;
      }

      std::cout << "The sum is " << sum << "\n";
   }
   */

   // Step 3: Sum up the values from 1 to 10 by means of a for loop
   {
      int sum = 0;

      for(int i = 1; i<= 10; ++i){
         sum += i;
      }

      std::cout << "The sum from 1 to 10 is " << sum << "\n";
   }

   // Step 4: Read in a range of integers and sum them up (but don't forget to check the input!)
   {
      int sum = 0;

      for(int i = 0; i < 10; ++i){
         int input;
         std::cin >> input;
         if(std::cin){
            sum += input;
         }
         else{
            break;
         }
      }

      std::cout << "The sum is " << sum << "\n";
   }

   return EXIT_SUCCESS;
}
