/**************************************************************************************************
*
* \file RelationalOperators.cpp
* \brief C++ Training - Programming Exercise about the relational operators
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Use all of the relational operators: Less-than, less-than-or-equal, greater-than,
*       greater-than-or-equal, equality, and inequality.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>


int main()
{
   int i = 1;
   int j = 2;

   // Less-than
   std::cout << "i < j : " << bool(i < j) << "\n";

   // Less-than-or-equal
   std::cout << "i <= j : " << bool(i <= j) << "\n";

   // Greater-than
   std::cout << "i > j : " << bool(i > j) << "\n";

   // Greater-than-or-equal
   std::cout << "i >= j : " << bool(i >= j) << "\n";

   // Equality
   std::cout << "i == j : " << bool(i == j) << "\n";

   // Inequality
   std::cout << "i != j : " << bool(i != j) << "\n";

   return EXIT_SUCCESS;
}
