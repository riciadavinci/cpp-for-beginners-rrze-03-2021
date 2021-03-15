/**************************************************************************************************
*
* \file ReadStrings.cpp
* \brief C++ Training - Introduction of std::string
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Write a program to read two strings and report wether the first string is equal,
*       less-than or greater-than the second string.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>


int main()
{
   std::string str_1, str_2;
   
   while(std::cin >> str_1 >> str_2){
      if(str_1 > str_2){
         std::cout   << "String 1 \"" << str_1 
                     << "\" is greater than String 2 \"" 
                     << str_2 << "\".\n";
      }
      else if(str_1 < str_2){
         std::cout   << "String 1 \"" << str_1 
                     << "\" is less than than String 2 \"" 
                     << str_2 << "\".\n";
      } else {
         std::cout   << "String 1 \"" << str_1 
                     << "\" and String 2 \"" 
                     << str_2 << "\" are equal.\n";
      }
   }

   return EXIT_SUCCESS;
}
