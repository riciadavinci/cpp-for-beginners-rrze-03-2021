/**************************************************************************************************
*
* \file Compare.cpp
* \brief C++ Training - Function Template Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Write a generic 'compare()' function that returns -1 if the left-hand side argument is
*       smaller, 0 if both arguments are equal, and 1 if the left-hand side argument is larger.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>


// TODO: Write a generic 'compare()' function that returns -1 if the left-hand side argument is
//       smaller, 0 if both arguments are equal, and 1 if the left-hand side argument is larger.

template<typename T>
int compare(const T& a, const T& b){
   // // my solution   
   // if(a > b){
   //    return 1;
   // }
   // else if(a < b){
   //    return -1;
   // }
   // else {
   //    return 0;
   // }

   return (a > b) ? 1 : ((a < b) ? -1 : 0);
}


int main()
{
   {
      int i1 = 1;
      int i2 = 2;

      if( compare( i1, i2 ) != -1 || compare( i2, i1 ) != 1 || compare( i1, i1 ) != 0 ) {
         std::cerr << "Error during the comparison of 'int' detected!\n";
      }
      else {
         std::cout << "compare( int, int ) works!\n";
      }
   }

   {
      std::string s1( "Bjarne" );
      std::string s2( "Herb" );

      if( compare( s1, s2 ) != -1 || compare( s2, s1 ) != 1 || compare( s1, s1 ) != 0 ) {
         std::cerr << "Error during the comparison of 'std::string' detected!\n";
      }
      else {
         std::cout << "compare( std::string, std::string ) works!\n";
      }
   }

   return EXIT_SUCCESS;
}
