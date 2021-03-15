/**************************************************************************************************
*
* \file Uppercase2.cpp
* \brief C++ Training - Function Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Extend the Uppercase1 exercise with a function to lowercase a string.
*
**************************************************************************************************/

#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>


bool hasUppercase( const std::string& s )
{
   for( auto c : s ) {
      if( std::isupper( c ) )
         return true;
   }

   return false;
}


// TODO: Implement a function to lowercase a string



int main()
{
   /*
   std::string s;

   while( std::cin >> s )
   {
      std::cout << " The string \"" << s << "\"";

      if( hasUppercase( s ) ) {
         std::cout << " contains uppercase characters! Lowercase version: \"";
         toLowercase( s );
         std::cout << s << "\"\n";
      }
      else {
         std::cout << " does not contain any uppercase characters!\n";
      }
   }
   */

   return EXIT_SUCCESS;
}
