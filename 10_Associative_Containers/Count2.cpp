/**************************************************************************************************
*
* \file Count2.cpp
* \brief C++ Training - Associative Containers Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Write a program to read at maximum 10 integers from std::cin and count the number of
*       integer values. Print the final result.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <map>


int main()
{
   // using unsigned int for the associated value (count)
   // since the count cannot be negative
   std::map<int,unsigned int> occurances;
   const int MAX_NO_ITER = 10;
   int input;
   for(int i = 0; i < MAX_NO_ITER && std::cin; ++i){


      
      if(std::cin >> input){
         // Clearner Algo:
         // If the key exists, it will have the given value
         // But if it is not present, the value will be initialized with
         // a default value, in this case the "int" is initialized with '0'
         ++occurances[input];


         // My algo and Klaus' first algo:
         /*
         const auto it = occurances.find(input);
         if(it == occurances.end()){
            occurances.insert(std::make_pair(input, 1));
         } else {
            ++(it->second);
         }
         */
      }
   }

   for( const auto& element: occurances){
      std::cout << "Key: "<<element.first << ", Value: " << element.second << "\n";
   }
   std::cout << "\n";

   return EXIT_SUCCESS;
}
