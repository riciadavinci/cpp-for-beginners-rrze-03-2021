/**************************************************************************************************
*
* \file NewDelete.cpp
* \brief C++ Training - Programming Task About New and Delete
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Experiment with the 'createObjectOnStack()' and 'createObjectOnHeap()' functions.
*
**************************************************************************************************/

#include <cstddef>
#include <cstdlib>
#include <iostream>


struct S
{
   S() { std::puts( "S()" ); }
   S( const S& ) { std::puts( "S(const S&)" ); }
   S& operator=( const S& ) { std::puts( "operator=(const S&)" ); return *this; }
   ~S() { std::puts( "~S()" ); }
};


S createObjectOnStack()
{
   S s{};
   return s;
}


S* createObjectOnHeap()
{
   S* s = new S{};
   return s;
}


int main()
{
   // TODO: Experiment with the 'createObjectOnStack()' and 'createObjectOnHeap()' functions.

   std::cout << "Start of main() function...\n";

   S* s = createObjectOnHeap();

   delete s;

   std::cout << "End of main() function...\n";

   return EXIT_SUCCESS;
}
