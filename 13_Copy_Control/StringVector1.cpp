/**************************************************************************************************
*
* \file StringVector1.cpp
* \brief C++ Training - Copy Control Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Implement the following 'StringVector' class. Define the member functions outside the
*       class body.
*
**************************************************************************************************/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>

using std::size_t;
using namespace std::string_literals;


class StringVector
{
 public:
   using iterator       = std::string*;
   using const_iterator = const std::string*;

   StringVector();
   StringVector( const StringVector& sv );

   StringVector& operator=( const StringVector& sv );

   ~StringVector();

   void   push_back( const std::string& s );
   size_t size() const;
   size_t capacity() const;

   iterator       begin();
   iterator       end();
   const_iterator begin() const;
   const_iterator end()   const;

   void swap( StringVector& sv );

 private:
   void reallocate();
   void free();

   std::string* begin_{ nullptr };
   std::string* end_  { nullptr };
   std::string* final_{ nullptr };

   static std::allocator<std::string> alloc;
};

std::allocator<std::string> StringVector::alloc;


// TODO: Implement the 'StringVector' class. Define the member functions outside the class body.


std::ostream& operator<<( std::ostream& os, const StringVector& sv )
{
   /*
   os << "(";
   for( const auto& s : sv ) {
      os << " \"" << s << "\"";
   }
   */
   return os << " )";
}


int main()
{
   /*
   StringVector sv;
   sv.push_back( "Bjarne"s );
   sv.push_back( "Herb"s );
   sv.push_back( "Nicolai"s );

   StringVector sv2( sv );

   std::cout << "\n" << sv2 << "\n\n";

   StringVector sv3;
   sv3.push_back( "Alexander"s );
   sv3.push_back( "Andrei"s );

   sv2 = sv3;

   std::cout << "\n" << sv2 << "\n\n";
   */

   return EXIT_SUCCESS;
}
