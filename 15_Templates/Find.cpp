/**************************************************************************************************
*
* \file Find.cpp
* \brief C++ Training - Function Template Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Write a function template that acts like the standard library 'find()' algorithm. The
*       function needs two template type parameters: One represents the function's iterator
*       parameters, one represents the type of the value to find. Use your function to find a
*       given value in a 'std::vector<int>' and a 'std::list<std::string>'.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std::string_literals;


// TODO: Write a function template that acts like the standard library 'find()' algorithm. The
//       function needs two template type parameters: One represents the function's iterator
//       parameters, one represents the type of the value to find. Use your function to find a
//       given value in a 'std::vector<int>' and a 'std::list<std::string>'.

// Don't want const for the first iterator since we need to increment it
// But it is okay to keep the last iterator as const qualified
template<typename InputIterator, typename Type>
InputIterator find(InputIterator first, const InputIterator last, const Type& value){
   for( ; first != last; ++first){
      if(*first == value){
         return first;
      }
   }
   return last;
}

int main()
{
   // Find a value in a std::vector<int>
   {
      std::vector<int> v{ 3, 5, 2, 7, 5, 4, 3 };
      auto it = ::find( v.begin(), v.end(), 5 );

      if( it != v.end() ) {
         std::cout << "Found the value in the vector!\n";
      }
      else {
         std::cout << "Didn't find it in the vector!\n";
      }
   }

   /*
   // Find a value in a std::list<std::string>
   {
      std::list<std::string> l{ "Herb"s, "Bjarne"s, "Alex"s, "Nicolai"s };
      auto it = ::find( begin(l), end(l), "Bjarne"s );

      if( it != end(l) ) {
         std::cout << "Found 'Bjarne' in the list!\n";
      }
   }
   */

   return EXIT_SUCCESS;
}
