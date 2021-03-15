/**************************************************************************************************
*
* \file SharedStringPtr.cpp
* \brief C++ Training - RAII Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Implement the 'SharedStringPtr' class to manage a dynamically allocated 'std::string'.
*       The 'SharedStringPtr' should implement shared ownership of a std::string.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std::string_literals;


class SharedStringPtr
{
 public:
   SharedStringPtr();
   SharedStringPtr( std::string* ptr );
   SharedStringPtr( SharedStringPtr const& s );

   ~SharedStringPtr();

   SharedStringPtr& operator=( SharedStringPtr const& s );

   std::string& operator* () const;
   std::string* operator->() const;

 private:
   std::string* ptr_;
   std::size_t* uses_;
};


// TODO: Implement all member functions of the 'SharedStringPtr' class


int main()
{
   /*
   SharedStringPtr ssptr1( new std::string( "Bjarne"s ) );
   SharedStringPtr ssptr2( ssptr1 );

   std::cout << "\n"
             << " *ssptr1 = \"" << *ssptr1 << "\"\n"
             << " *ssptr2 = \"" << *ssptr2 << "\"\n"
             << "\n";
   */

   return EXIT_SUCCESS;
}
