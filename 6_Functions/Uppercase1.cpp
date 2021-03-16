/**************************************************************************************************
*
* \file Uppercase1.cpp
* \brief C++ Training - Function Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Write a function to check if a string contains any uppercase characters.
*
**************************************************************************************************/

#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>


// TODO: Implement the 'hasUppercase()' function
// using std::isupper(char)

bool hasUppercase(const std::string& s){
   // Index Based Solution:
   /*
   const size_t str_size = s.size();
   for(size_t i = 0U; i < str_size; ++i){
      if(std::isupper(s[i])){
         return true;
      }
   }
   */

   // Iterator Based Solution:
   /*
   for(auto it = s.begin(); it != s.end() ; ++it){
      if(std::isupper(*it)){
         return true;
      }
   }
   */

   // Range Based Solution:
   // const added since we don't want to modify the character!!
   for(const auto ch : s){
      if(std::isupper(ch)){
         return true;
      }
   }

   return false;
}

int main()
{
   
   std::string s;

   while( std::cin >> s )
   {
      std::cout << " The string \"" << s << "\"";

      if( hasUppercase( s ) ) {
         std::cout << " contains uppercase characters!\n";
      }
      else {
         std::cout << " does not contain any uppercase characters!\n";
      }
   }
   

   return EXIT_SUCCESS;
}
