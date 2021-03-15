/**************************************************************************************************
*
* \file Main.cpp
* \brief C++ Training - Class Design Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Refactor the 'Book' class in the following steps:
*       1.) Extract the 'isbn_' string into the 'ISBN' class;
*       2.) Extract the 'firstname_' and 'lastname_' strings into the 'Author' class;
*       3.) Refactor the 'Price' type alias into the 'Price' class.
*
**************************************************************************************************/

#include <iostream>
#include "Author.h"
#include "Book.h"
#include "ISBN.h"


int main()
{
   Book book1( "Vom Winde verdreht", "Homer", "Simpson", "1X23456" );
   book1.setPrice( 12.5 );

   Book book2( "Vom Winde verdreht 2", "Homer", "Simpson", "1X23457" );
   book2.setPrice( 13.5 );

   Book book3( "Gone with the Lint", "O.J.", "Simpson", "2Y83746" );
   book3.setPrice( 9.99, Currency::Dollar );

   Book book4( "Hairy Potter", "J.K.", "Rowling", "1Z95857" );
   book4.setPrice( 19.99, Currency::Dollar );

   Book book5( "Lord of the Things", "J.R.R.", "Tolkien", "8Y34567" );
   book5.setPrice( 25.0, Currency::Euro );

   Book book6( "Ghost in the Dwell", "Masamune", "Shirow", "7Z35790" );
   book6.setPrice( 45.99, Currency::Yen );

   std::cout << "\n"
             << book1 << "\n"
             << book2 << "\n"
             << book3 << "\n"
             << book4 << "\n"
             << book5 << "\n"
             << book6 << "\n"
             << "\n";

   return EXIT_SUCCESS;
}
