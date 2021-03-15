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
* Task: Write a program to read an unknown number of strings from std::cin.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>


int main()
{
   // Read in an arbitrary number of strings
   std::string str;
   
   std::cout << "Enter a String: ";
   while(std::getline(std::cin, str)){
      std::cout << "You entered: \"" << str << "\"\n";
      std::cout << "Enter a String: ";
   }

   return EXIT_SUCCESS;
}
