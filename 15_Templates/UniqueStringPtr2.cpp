/**************************************************************************************************
*
* \file UniqueStringPtr.cpp
* \brief C++ Training - Class Template Programming Task
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
            UniqueStringPtr() = default;
   explicit UniqueStringPtr( std::string* ptr );
            UniqueStringPtr( UniqueStringPtr const& ) = delete;

   ~UniqueStringPtr();

   UniqueStringPtr& operator=( UniqueStringPtr const& ) = delete;

   std::string& operator* () const;
   std::string* operator->() const;

 private:
   std::string* ptr_{ nullptr };
};


UniqueStringPtr::UniqueStringPtr( std::string* ptr )
   : ptr_( ptr )
{}


UniqueStringPtr::~UniqueStringPtr()
{
   delete ptr_;
}


std::string& UniqueStringPtr::operator*() const
{
   return *ptr_;
}


std::string* UniqueStringPtr::operator->() const
{
   return ptr_;
}


int main()
{
   UniqueStringPtr usptr( new std::string( "Bjarne"s ) );

   std::cout << "\n *usptr = \"" << *usptr << "\"\n\n";

   return EXIT_SUCCESS;
}
