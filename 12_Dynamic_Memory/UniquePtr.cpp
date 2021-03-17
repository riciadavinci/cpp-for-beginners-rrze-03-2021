/**************************************************************************************************
*
* \file UniquePtr.cpp
* \brief C++ Training - Programming Task About std::unique_ptr
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Use a 'std::unique_ptr' to handle a dynamically allocated object automatically.
*
**************************************************************************************************/

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <memory>


struct S
{
   S() { std::puts( "S()" ); }
   S( const S& ) { std::puts( "S(const S&)" ); }
   S& operator=( const S& ) { std::puts( "operator=(const S&)" ); return *this; }
   ~S() { std::puts( "~S()" ); }
};


std::unique_ptr<S> createObjectOnHeap()
{
   return std::unique_ptr<S>(new S{});
}


int main()
{
   // TODO: Use a 'std::unique_ptr' to handle a dynamically allocated object automatically
   // This "unique_ptr" is a very shallow wrapper around the "raw pointer" S*
   std::unique_ptr<S> s(createObjectOnHeap());

   return EXIT_SUCCESS;
}
