/**************************************************************************************************
*
* \file SimpsonPro.cpp
* \brief C++ Training - STL Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Implement the empty functions to perform the following operations on the Simpson characters:
*       1. Print all characters to the screen
*       2. Randomize the order of characters ('r')
*       3. Find the youngest character ('y')
*       4. Order them by last name while preserving the order between equal elements ('l')
*       5. Put all children first ('c')
*       6. Check if any of the characters has a certain age ('h')
*       7. Check if two adjacent characters have the same age ('s')
*       8. Compute the maximum age difference between two adjacent characters ('d')
*       9. Determine the median age of all characters ('m')
*
**************************************************************************************************/

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <numeric>
#include <random>
#include <string>
#include <vector>


struct Person
{
   std::string firstname;
   std::string lastname;
   int age;
};

bool isChildren( const Person& p )
{
   return p.age < 21;
}

std::ostream& operator<<( std::ostream& os, Person const& person )
{
   return os << std::setw(11) << std::left  << person.firstname
             << std::setw(11) << std::left  << person.lastname
             << std::setw(3)  << std::right << person.age;
}




void print( const std::vector<Person>& table )
{
   // TODO: Print all characters to the screen
}

void random_order( std::vector<Person>& table )
{
   // TODO: Randomize their order ('r')
}

void find_youngest( const std::vector<Person>& table )
{
   // TODO: Find the youngest character ('y')

   //const auto pos = ...;

   //std::cout << "Youngest person = " << pos->firstname << " " << pos->lastname << "\n";
}

void order_by_lastname( std::vector<Person>& table )
{
   // TODO: Order them by last name while preserving the order between equal elements ('l')
}

void children_first( std::vector<Person>& table )
{
   // TODO: Put all children first ('c')
}

void has_age( std::vector<Person>& table )
{
   int age{};

   std::cout << "Enter age: ";
   std::cin >> age;

   // TODO: Check if any of the characters has a certain age ('h')

   //if( res ) {
   //   std::cout << "There is at least one person with the specified age!\n";
   //}
   //else {
   //   std::cout << "No person with the specified age found!\n";
   //}
}

void same_age( std::vector<Person>& table )
{
   // TODO: Check if two adjacent characters have the same age ('s')

   // const auto pos = ...;

   //if( pos != table.end() ) {
   //   std::cout << pos->firstname << " and " << (pos+1)->firstname << " have the same age!\n";
   //}
   //else {
   //   std::cout << "No consecutive persons with the same age found!\n";
   //}
}

void maximum_age_difference( const std::vector<Person>& table )
{
   // TODO: Compute the maximum age difference between two adjacent characters ('d')

   // const int diff = ...;

   //std::cout << " Maximum age different = " << diff << "\n";
}

void median_age( std::vector<Person>& table )
{
   // TODO: Determine the median age of all characters ('m')
}




int main()
{
   std::vector<Person> table =
      { Person{ "Homer",      "Simpson",    38 }
      , Person{ "Marge",      "Simpson",    34 }
      , Person{ "Bart",       "Simpson",    10 }
      , Person{ "Lisa",       "Simpson",     8 }
      , Person{ "Maggie",     "Simpson",     1 }
      , Person{ "Hans",       "Moleman",    33 }
      , Person{ "Ralph",      "Wiggum",      8 }
      , Person{ "Milhouse",   "Van Houten", 10 }
      , Person{ "Ned",        "Flanders",   60 }
      , Person{ "Jeff",       "Albertson",  45 }
      , Person{ "Montgomery", "Burns",     104 } };

   char command;

   while( std::cout << "Enter command: " && std::cin >> command )
   {
      switch( command )
      {
      case 'r':
         random_order( table );
         break;

      case 'y':
         find_youngest( table );
         break;

      case 'l':
         order_by_lastname( table );
         break;

      case 'c':
         children_first( table );
         break;

      case 'h':
         has_age( table );
         break;

      case 's':
         same_age( table );
         break;

      case 'd':
         maximum_age_difference( table );
         break;

      case 'm':
         median_age( table );
         break;

      default:
         return EXIT_SUCCESS;
      }

      print( table );
   }
}
