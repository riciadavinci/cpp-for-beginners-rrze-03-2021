/**************************************************************************************************
*
* \file LogicalOperators.cpp
* \brief C++ Training - Programming Exercise about the logical operators
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Use all of the logical operators: && (and), || (or), and ! (not).
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>


int main()
{
   bool b1 = true;
   bool b2 = false;

   // Logical and
   bool res = b1 && b2;
   std::cout << "b1 && b2 : " << res << "\n";

   // Logical or
   res = b1 || b2;
   std::cout << "b1 || b2 : " << res << "\n";

   // Logical not
   res = !b1;
   std::cout << "!b1 : " << res << "\n";

   return EXIT_SUCCESS;
}
