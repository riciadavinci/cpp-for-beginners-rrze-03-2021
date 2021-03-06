/**************************************************************************************************
*
* \file SharedPtr.cpp
* \brief C++ Training - Programming Task About std::shared_ptr
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Use a 'std::shared_ptr' to handle a dynamically allocated object automatically.
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


S* createObjectOnHeap()
{
   S* s = new S{};
   return s;
}


int main()
{
   // TODO: Use a 'std::shared_ptr' to handle a dynamically allocated object automatically

   return EXIT_SUCCESS;
}
