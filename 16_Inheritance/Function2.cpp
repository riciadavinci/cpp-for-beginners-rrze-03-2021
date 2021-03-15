/**************************************************************************************************
*
* \file Function2.cpp
* \brief C++ Training - Programming Task for Type Erasure
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Reimplement the 'std::function' class template.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>


//--Function.h-------------------------------------------------------------------------------------

template< typename Fn >
class Function;

// TODO


//--Main.cpp---------------------------------------------------------------------------------------


int foo()
{
   return 1;
}

struct Foo {
   int operator()() const {
      return 2;
   }
};


int main()
{
   /*
   {
      Function<int(void)> f( foo );
      auto const res = f();
      std::cout << "\n res = " << res << "\n\n";
   }

   {
      Function<int(void)> f( Foo{} );
      auto const res = f();
      std::cout << "\n res = " << res << "\n\n";
   }

   {
      Function<int(void)> f( [](){ return 3; } );
      auto const res = f();
      std::cout << "\n res = " << res << "\n\n";
   }
   */

   return EXIT_SUCCESS;
}
