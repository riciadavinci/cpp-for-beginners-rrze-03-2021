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

// Just for convenience here!
using std::string;


//=================================================================================================
// class ISBN
//=================================================================================================

// Step 1: Extract the 'isbn_' string into the 'ISBN' class.

class ISBN{
private:
   string isbn_;

public:
   // We don't need a default constructor here,
   // because we don't 
   // ISBN() = default;    // default constructor

   // Member initializer list constructor
   ISBN(const string& isbn)
      : isbn_{ isbn }
   {}

   // getters
   // const std::string& isbn() const { return isbn_; }     // my implementation

   // Klaus' implementation
   string asString() const { return isbn_; }       // We return here as a string
                                                   // since we want to store the
                                                   // the ISBN differently (and 
                                                   // not as a string)
   
   // setters
   void isbn(const string& isbn) { isbn_ = isbn; }

};

std::ostream& operator<< (std::ostream& out, const ISBN& i){
   out << i.asString();
   return out;
}


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

class Author{
private:
   string firstname_;
   string lastname_;

public:
   // Again, we don't have a Default author name,
   // so no need to define a default constructor
   // Author() = default;     // default constructor

   // Member initialization list constructor
   Author(const string& firstname, const string& lastname)
      : firstname_ { firstname }
      , lastname_  { lastname  }
   {}

   // getters
   const string& firstname() const { return firstname_; }
   const string& lastname () const { return lastname_; }
   // const string  name() const { return firstname_ + " " + lastname_; } 

   // setters
   void firstname(string const& firstname) { firstname_ = firstname; }
   void lastname (string const& lastname ) { lastname_ = lastname; }

};

std::ostream& operator<< (std::ostream& out, const Author& a){
   out << a.firstname()  << " " << a.lastname();
   return out; 
}


//=================================================================================================
// class Price
//=================================================================================================

// Step 3: Refactor the 'Price' type alias into the 'Price' class.

class Price{
private:
   double value_;// = 10.0;
   Currency currency_;// = Currency::Euro;

public:
   // default constructor
   Price() = default;

   // Member initializer list constructor
   Price(const double price, const Currency& currency = Currency::Euro)
      : value_    {price}
      , currency_ { currency }
   {}

   double price() const { return value_; }
   Currency currency() const { return currency_; } 

};

std::ostream& operator<< (std::ostream& out, const Price& price){
   out << price.price() << " " << price.currency();
   return out;

}


//=================================================================================================
// class Book
//=================================================================================================

class Book
{
 public:
   explicit Book( const string& title, const Author& author, const ISBN& isbn )
      : title_    ( title )
      , author_   ( author )
      , isbn_     ( isbn )
      , price_    ( defaultPrice_ )
   {}

   const string& title() const { return title_; }
   const Author& author() const { return author_; }
   const ISBN&   isbn() const { return isbn_; }
   Price         price() const { return price_; }

   void setPrice( Price price ) { price_ = price; }
   void setPrice( double price, Currency currency = Currency::Euro ) { price_ = Price( price, currency ); }

   static void setDefaultPrice( Price price ) { defaultPrice_ = price; }
   static void setDefaultPrice( double price, Currency currency = Currency::Euro ) { defaultPrice_ = Price( price, currency ); }

 private:
   string title_;
   Author author_;
   ISBN isbn_;
   Price  price_;

   static Price defaultPrice_;
};

Price Book::defaultPrice_( 10.0, Currency::Euro );

std::ostream& operator<<( std::ostream& os, const Book& book )
{
   os << "Title: \"" << book.title()
      << "\", Author: \"" << book.author()
      << "\", ISBN: " << book.isbn()
      << std::setprecision( 2 ) << std::fixed
      << ", Price: " << book.price();

   return os;
}


//=================================================================================================
// main() function
//=================================================================================================

int main()
{
   Book book1( "Vom Winde verdreht", Author("Homer", "Simpson"), ISBN("1X23456") );
   book1.setPrice( 12.5 );

   Book book2( "Vom Winde verdreht 2", Author("Homer", "Simpson"), ISBN("1X23457") );
   book2.setPrice( 13.5 );

   Book book3( "Gone with the Lint", Author("O.J.", "Simpson"), ISBN("2Y83746") );
   book3.setPrice( 9.99, Currency::Dollar );

   Book book4( "Hairy Potter", Author("J.K.", "Rowling"), ISBN("1Z95857") );
   book4.setPrice( 19.99, Currency::Dollar );

   Book book5( "Lord of the Things", Author("J.R.R.", "Tolkien"), ISBN("8Y34567") );
   book5.setPrice( 25.0, Currency::Euro );

   Book book6( "Ghost in the Dwell", Author("Masamune", "Shirow"), ISBN("7Z35790") );
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
