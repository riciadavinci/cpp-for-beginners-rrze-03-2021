/**************************************************************************************************
*
* \file Simpson.cpp
* \brief C++ Training - STL Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Implement the empty functions to perform the following operations on the Simpson characters:
*       1. Print all characters to the screen
*       2. Randomize their order ('r')
*       3. Find the youngest person ('y')
*       4. Order them by first name ('f')
*       5. Order them by last name while preserving the order between equal elements ('l')
*       6. Order them by age while preserving the order between equal elements ('a')
*       7. Put all Simpsons first without affecting the general order of characters ('s')
*       8. Compute the total age of all characters ('t')
*       9. Determine the third oldest character as quickly as possible ('3')
*
**************************************************************************************************/

#include <algorithm>
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

std::ostream& operator<<( std::ostream& os, Person const& person )
{
   return os << std::setw(11) << std::left  << person.firstname
             << std::setw(10) << std::left  << person.lastname
             << std::setw(3)  << std::right << person.age;
}


// --------------------------------------------------------------------------------
// Implementing a Class that replicates Lambda Function of comparing ages of 2 Persons

class IsYounger{
   public:
   // No need to write inline, since the compiler will consider it to be inline anyways
   // coz it is the best to do it here
   bool operator()(const Person& a, const Person& b ) const {
      return a.age < b.age;
   }
};





// --------------------------------------------------------------------------------


void print( const std::vector<Person>& table )
{
   // TODO: Print all characters to the screen
   for(const Person& person: table){
      std::cout << person << "\n";
   }
   std::cout << "\n";
}

// --------------------------------------------------------------------------------
// Implement the following without using for, while, do while loops or goto statements
// Just use algorithms from STL

void random_order( std::vector<Person>& table )
{
   // TODO: Randomize their order ('r')
   // mt = Mersenne Twister => Randon Number Generator
   std::random_device rd;
   std::mt19937 mt(rd());
   std::shuffle(table.begin(), table.end(), mt);
}

void find_youngest( const std::vector<Person>& table )
{
   // TODO: Find the youngest character ('y')
   const auto pos = std::min_element(table.begin(), table.end(), IsYounger{});
   std::cout << "Youngest person = " << pos->firstname << " " << pos->lastname << "\n";
}

void order_by_firstname( std::vector<Person>& table )
{
   // TODO: Order them by first name ('f')
   std::sort(table.begin(), table.end(), [](const Person& a, const Person& b){
      return a.firstname < b.firstname;
   });
}

void order_by_lastname( std::vector<Person>& table )
{
   // TODO: Order them by last name while preserving the order between equal elements ('l')
   // Stable Sort!
   std::stable_sort(table.begin(), table.end(), [](const Person& a, const Person& b){
      return a.lastname < b.lastname;
   });
}

void order_by_age( std::vector<Person>& table )
{
   // TODO: Order them by age while preserving the order between equal elements ('a')
   // Stable Sort!
   std::stable_sort(table.begin(), table.end(), IsYounger{});
}

void simpsons_first( std::vector<Person>& table )
{
   // TODO: Put all Simpsons first without affecting the general order of characters ('s')
   std::stable_partition(table.begin(), table.end(), [](const Person& p){
      return p.lastname == "Simpson";
   });

}

void compute_total_age( const std::vector<Person>& table )
{
   // TODO: Compute the total age of all characters ('t')
   // use accumulate

   // The 3rd Param here is being accumulated
   // Since we want int, we set it as 0
   // If you want to accumulate a float or double,
   // you should write 0.0F or 0.0 respectively
   // The 1st param of the Lambda is the return value of the "accumulate" function 
   const int age = std::accumulate(table.begin(), table.end(), 0,[](const int accu, const Person& p){
      return accu + p.age;
   });

   std::cout << "Total age = " << age << "\n";
}

void third_oldest( std::vector<Person>& table )
{
   // TODO: Determine the third oldest character as quickly as possible ('3')
   //       Note that you are allowed to change the order of characters.

   // This is an example of a Pruning Algorithm
   // Here, for the 3rd oldest element, the algorithm shuffles the list such that
   // This 3rd oldest Person (by Age) comes to 3rd position with older 2 above it
   // and rest of the younger that it are placed below it!

   std::nth_element(table.begin(), table.begin()+2, table.end(), [](const Person& a, const Person& b){
      return a.age > b.age;
   });
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

      case 'f':
         order_by_firstname( table );
         break;

      case 'l':
         order_by_lastname( table );
         break;

      case 'a':
         order_by_age( table );
         break;

      case 's':
         simpsons_first( table );
         break;

      case 't':
         compute_total_age( table );
         break;

      case '3':
         third_oldest( table );
         break;

      default:
         return EXIT_SUCCESS;
      }

      print( table );
   }
}
