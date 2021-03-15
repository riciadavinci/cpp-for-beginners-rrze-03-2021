/**************************************************************************************************
*
* \file Library1.cpp
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

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

using std::string;


//=================================================================================================
// class ISBN
//=================================================================================================

// Step 1: Extract the 'isbn_' string into the 'ISBN' class.


//=================================================================================================
// Currency enumeration
//=================================================================================================

enum class Currency
{
   Euro,
   Dollar,
   Yen
};

std::ostream& operator<<( std::ostream& os, Currency currency )
{
   switch( currency ) {
      case Currency::Euro:
         os << "Euro";
         break;
      case Currency::Dollar:
         os << "Dollar";
         break;
      case Currency::Yen:
         os << "Yen";
         break;
      default:
         os << "Unknown currency";
   }

   return os;
}


//=================================================================================================
// class Author
//=================================================================================================

// Step 2: Extract the 'firstname_' and 'lastname_' strings into the 'Author' class.


//=================================================================================================
// class Price
//=================================================================================================

// Step 3: Refactor the 'Price' type alias into the 'Price' class.


//=================================================================================================
// class Book
//=================================================================================================

class Book
{
 public:
   using Price = std::pair<double,Currency>;

   explicit Book( const string& title, const string& firstname
                , const string& lastname, const string& isbn )
      : title_    ( title )
      , firstname_( firstname )
      , lastname_ ( lastname )
      , isbn_     ( isbn )
      , price_    ( defaultPrice_ )
   {}

   const string& title() const { return title_; }
   const string& firstname() const { return firstname_; }
   const string& lastname() const { return lastname_; }
   const string& isbn() const { return isbn_; }
   Price         price() const { return price_; }

   void setPrice( Price price ) { price_ = price; }
   void setPrice( double price, Currency currency = Currency::Euro ) { price_ = Price( price, currency ); }

   static void setDefaultPrice( Price price ) { defaultPrice_ = price; }
   static void setDefaultPrice( double price, Currency currency = Currency::Euro ) { defaultPrice_ = Price( price, currency ); }

 private:
   string title_;
   string firstname_;
   string lastname_;
   string isbn_;
   Price  price_;

   static Price defaultPrice_;
};

Book::Price Book::defaultPrice_( 10.0, Currency::Euro );

std::ostream& operator<<( std::ostream& os, const Book& book )
{
   os << "Title: \"" << book.title()
      << "\", Author: \"" << book.firstname() << " " << book.lastname()
      << "\", ISBN: " << book.isbn()
      << std::setprecision( 2 ) << std::fixed
      << ", Price: " << book.price().first << " " << book.price().second;

   return os;
}


//=================================================================================================
// main() function
//=================================================================================================

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
