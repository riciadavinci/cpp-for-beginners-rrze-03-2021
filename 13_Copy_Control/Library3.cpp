/**************************************************************************************************
*
* \file Library3.cpp
* \brief C++ Training - Copy Control Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Rework the Library exercise by means of the following items:
*       1.) Think about which of the existing classes requires copy or move operations;
*       2.) Rework the constructor of the 'ISBN' class;
*       3.) Rework the constructor of the 'Author' class;
*       4.) Rework the constructor(s) of the 'Book' class;
*       5.) Rework the 'addBook()' and 'removeBook()' function of the 'Library' class.
*
**************************************************************************************************/

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using std::string;


//=================================================================================================
// class ISBN
//=================================================================================================

class ISBN
{
 public:
   // TODO: Rework the constructor of the 'ISBN' class.
   explicit ISBN( const string& isbn )
      : isbn_( isbn )
   {}

   const string& asString() const { return isbn_; }

 private:
   string isbn_;
};

bool operator<( const ISBN& lhs, const ISBN& rhs )
{
   return lhs.asString() < rhs.asString();
}

std::ostream& operator<<( std::ostream& os, const ISBN& isbn )
{
   return os << isbn.asString();
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

class Author
{
 public:
   // TODO: Rework the constructor of the 'Author' class.
   explicit Author( const string& firstname, const string& lastname )
      : firstname_( firstname )
      , lastname_ ( lastname  )
   {}

   const string& firstname() const { return firstname_; }
   const string& lastname () const { return lastname_; }

 private:
   string firstname_;
   string lastname_;
};

std::ostream& operator<<( std::ostream& os, const Author& author )
{
   os << author.firstname() << " " << author.lastname();

   return os;
}


//=================================================================================================
// class Price
//=================================================================================================

class Price
{
 public:
   explicit Price( double price, Currency currency = Currency::Euro )
      : price_   ( price )
      , currency_( currency )
   {}

   double   price() const { return price_; }
   Currency currency() const { return currency_; }

 private:
   double   price_;
   Currency currency_;
};

std::ostream& operator<<( std::ostream& os, const Price& price )
{
   return os << price.price() << " " << price.currency();
}


//=================================================================================================
// class Book
//=================================================================================================

class Book
{
 public:
   using Title = string;

   // TODO: Rework the constructor(s) of the 'Book' class.
   explicit Book( const string& title, const Author& author, const ISBN& isbn )
      : title_ ( title )
      , author_( author )
      , isbn_  ( isbn )
      , price_ ( defaultPrice_ )
   {}

   explicit Book( const string& title, const string& firstname
                , const string& lastname, const ISBN& isbn )
      : title_ ( title )
      , author_( firstname, lastname )
      , isbn_  ( isbn )
      , price_ ( defaultPrice_ )
   {}

   const Title&  title() const { return title_; }
   const Author& author() const { return author_; }
   const ISBN&   isbn() const { return isbn_; }
   Price         price() const { return price_; }

   void setPrice( Price price ) { price_ = price; }
   void setPrice( double price, Currency currency = Currency::Euro );

   static void setDefaultPrice( Price price ) { defaultPrice_ = price; };
   static void setDefaultPrice( double price, Currency currency = Currency::Euro );

 private:
   Title  title_;
   Author author_;
   ISBN   isbn_;
   Price  price_;

   static Price defaultPrice_;
};

Price Book::defaultPrice_( 10.0, Currency::Euro );

void Book::setPrice( double price, Currency currency )
{
   price_ = Price( price, currency );
}

void Book::setDefaultPrice( double price, Currency currency )
{
   defaultPrice_ = Price( price, currency );
}

bool operator<( const Book& lhs, const Book& rhs )
{
   return lhs.isbn() < rhs.isbn();
}

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
// class Library
//=================================================================================================

class Library
{
 private:
   using Books = std::map<Book,unsigned int>;

 public:
   using const_iterator = Books::const_iterator;

   // TODO: Rework the 'addBook()' and 'removeBook()' function of the 'Library' class.
   void addBook( const Book& book, unsigned int count = 1U )
   {
      books_[book] += count;
   }

   void removeBook( const Book& book )
   {
      const auto pos = books_.find( book );
      if( pos != books_.end() )
         --(pos->second);
   }

   const_iterator begin() const { return books_.cbegin(); }
   const_iterator end() const { return books_.cend(); }

 private:
   Books books_;
};

std::ostream& operator<<( std::ostream& os, const Library& library )
{
   for( const auto& book : library ) {
      os << book.first << ", Count:" << book.second << "\n";
   }

   return os;
}


//=================================================================================================
// main() function
//=================================================================================================

int main()
{
   Library library;

   Book book1( "Vom Winde verdreht", Author( "Homer", "Simpson" ), ISBN( "1X23456" ) );
   book1.setPrice( 12.5 );
   library.addBook( book1 );

   Book book2( "Vom Winde verdreht 2", Author( "Homer", "Simpson" ), ISBN( "1X23457" ) );
   book2.setPrice( 13.5 );
   library.addBook( book2, 3 );

   Book book3( "Gone with the Lint", Author( "O.J.", "Simpson" ), ISBN( "2Y83746" ) );
   book3.setPrice( 9.99, Currency::Dollar );
   library.addBook( book3, 2 );

   Book book4( "Hairy Potter", Author( "J.K.", "Rowling" ), ISBN( "1Z95857" ) );
   book4.setPrice( 19.99, Currency::Dollar );
   library.addBook( book4, 5 );

   Book book5( "Lord of the Things", Author( "J.R.R.", "Tolkien" ), ISBN( "8Y34567" ) );
   book5.setPrice( 25.0, Currency::Euro );
   library.addBook( book5, 4 );

   Book book6( "Ghost in the Dwell", Author( "Masamune", "Shirow" ), ISBN( "7Z35790" ) );
   book6.setPrice( 45.99, Currency::Yen );
   library.addBook( book6 );

   std::cout << "\n" << library << "\n\n";

   library.removeBook( book5 );

   std::cout << "\n" << library << "\n\n";

   return EXIT_SUCCESS;
}
