/**************************************************************************************************
*
* \file Function1.cpp
* \brief C++ Training - std::function Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Implement the 'configure()' function of the given 'WordProcessor' class. Note that it
*       should be possible to pass function pointers, functors as well as lambdas.
*
**************************************************************************************************/

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using namespace std::string_literals;


void toUpper( string& word )
{
   std::for_each( begin(word), end(word), []( char& c ){ c = std::toupper( c ); } );
}

void toLower( string& word )
{
   std::for_each( begin(word), end(word), []( char& c ){ c = std::tolower( c ); } );
}


class WordProcessor
{
 public:
   void process( string& word )
   {
      //strategy_( word );
   }

   // TODO: Implement the 'configure()' function

 private:
   //Strategy strategy_;  // TODO: Think about a suitable implementation for 'Strategy'
};


int main()
{
   /*
   WordProcessor processor;
   char c;

   std::cout << "How do you want your words to be printed (lowercase/uppercase)? ";
   std::cin >> c;

   if( std::isupper( c ) ) {
      processor.configure( toUpper );
   }
   else if( std::islower( c ) ) {
      processor.configure( []( string& word ){ toLower( word ); } );
   }
   else {
      std::cerr << "Invalid character!\n";
      return EXIT_FAILURE;
   }

   std::string word;

   while( std::cin >> word )
   {
      processor.process( word );
      std::cout << word << "\n";
   }
   */

   return EXIT_SUCCESS;
}
