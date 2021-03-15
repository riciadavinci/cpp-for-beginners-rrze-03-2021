/**************************************************************************************************
*
* \file Grades.cpp
* \brief C++ Training - Exercise about statements
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Write a program to transform a grade from 0 to 100 into a lettergrade (F through A++):
*         -   0 - 59  ->  F
*         -  60 - 69  ->  D
*         -  70 - 79  ->  C
*         -  80 - 89  ->  B
*         -  90 - 99  ->  A
*         - 100       ->  A++
*       Grades ending in 8 or 9 should receive an additional '+', grades ending in 0, 1 or 2
*       should receive an additional '-'.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>


int main()
{
   std::vector<std::string> scores{ "F", "D", "C", "B", "A", "A++" };
   int grade = 0;

   std::cout << "Please enter a grade (0-100): ";

   if( !(std::cin >> grade) || grade > 100 ) {
      std::cerr << "\nInvalid grade detected\n";
      return EXIT_FAILURE;
   }

   std::string lettergrade;

   // TODO: Transform the given grade into a letter

   std::cout << " Transformed grade = '" << lettergrade << "'\n";

   return EXIT_SUCCESS;
}
