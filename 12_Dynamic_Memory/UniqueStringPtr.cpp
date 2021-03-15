/**************************************************************************************************
*
* \file UniqueStringPtr.cpp
* \brief C++ Training - RAII Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Implement the 'UniqueStringPtr' class to manage a dynamically allocated 'std::string'.
*       The 'UniqueStringPtr' should implement unique ownership of a std::string.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std::string_literals;


class UniqueStringPtr
{
 public:
   UniqueStringPtr();
   UniqueStringPtr( std::string* ptr );
   UniqueStringPtr( UniqueStringPtr const& );

   ~UniqueStringPtr();

   UniqueStringPtr& operator=( UniqueStringPtr const& );

   std::string& operator* () const;
   std::string* operator->() const;

 private:
   std::string* ptr_;
};


// TODO: Implement all member functions of the 'UniqueStringPtr' class


int main()
{
   /*
   UniqueStringPtr usptr( new std::string( "Bjarne"s ) );

   std::cout << "\n *usptr = \"" << *usptr << "\"\n\n";
   */

   return EXIT_SUCCESS;
}
