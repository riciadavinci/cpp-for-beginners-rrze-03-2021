/**************************************************************************************************
*
* \file String.cpp
* \brief C++ Training - Copy Control Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Implement the special member functions of the given 'String' class:
*       1.) Implement the destructor;
*       2.) Implement the copy constructor;
*       3.) Implement the copy assignment operator.
*       4.) Implement the default constructor;
*
**************************************************************************************************/

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <utility>


class String
{
 public:
   using iterator = char*;
   using const_iterator = const char*;

   // Step 4: Implement the default constructor
   // TODO

   String( const char* array );

   // Step 2: Implement the copy constructor
   // TODO

   // Step 1: Implement the destructor
   // TODO

   // Step 3: Implement the copy assignment operator
   // TODO

   size_t size() const { return end_ - begin_; }

   char&       operator[]( size_t index )       { return begin_[index]; }
   const char& operator[]( size_t index ) const { return begin_[index]; }

   iterator       begin()       { return begin_; }
   const_iterator begin() const { return begin_; }
   iterator       end()         { return end_; }
   const_iterator end()   const { return end_; }

 private:
   char* begin_{};
   char* end_{};
};

String::String( const char* array )
{
   const size_t size( strlen(array) );
   begin_ = new char[size];
   end_   = std::copy_n( array, size, begin_ );
}


std::ostream& operator<<( std::ostream& os, const String& string )
{
   for( auto c : string ) {
      os << c;
   }
   return os;
}


//=================================================================================================
// main() function
//=================================================================================================

int main()
{
   // Creating a string
   String s1{ "Teststring" };
   std::cout << "\n" << s1 << "\n\n";

   // Copying a string via the copy constructor
   String s2( s1 );
   std::cout << "\n" << s2 << "\n\n";

   // Copying a string via the copy assignment operator
   s2 = s1;
   std::cout << "\n" << s2 << "\n\n";

   return EXIT_SUCCESS;
}
