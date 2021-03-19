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

#include <algorithm>
#include <cstring>
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
   String() = default;

   String( const char* array );

   // Rule of Three: If you implement one of these functions, you very likely
   // have to implement all three (destructor, copy constructor, 
   // copy assignment operator)

   // Step 2: Implement the copy constructor
   String(const String& other)
      : begin_ { new char[other.size()] }
      , end_ { std::copy(other.begin_, other.end_, begin_) }
   {
      std::cout << "Copy constructor\n";
   }

   // Step 1: Implement the destructor
   ~String(){
      delete_string();
   }

   // Step 3: Implement the copy assignment operator
   String& operator=(const String& other){
      // Temporary swap idiom:
      // Create a temp string as a copy of the string
      String tmp(other);
      std::swap(begin_, tmp.begin_);
      std::swap(end_, tmp.end_);

      // Thus, at the end, we get all the data and 
      // at the end of the copy assignment, this stack
      // allocated tmp will be deleted, so no need to 
      // explicitly call delete;

      return *this;
   }

   size_t size() const { return end_ - begin_; }

   // This version for mutable strings
   char&       operator[]( size_t index )       { return begin_[index]; }

   // This version for const strings
   const char& operator[]( size_t index ) const { return begin_[index]; }

   iterator       begin()       { return begin_; }    // start iterator for non-const string
   const_iterator begin() const { return begin_; }    // start iterator for const string
   iterator       end()         { return end_; }      // end+1 iterator for non-const string
   const_iterator end()   const { return end_; }      // end+1 iterator for const string

 private:
   char* begin_{ nullptr };
   char* end_{ nullptr };

   // helper functions
   void delete_string(){
      if(begin_){
         delete[] begin_;
         begin_ = nullptr;
         end_ = nullptr;
      }
      std::cout << "Deleted!\n";
   }
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
