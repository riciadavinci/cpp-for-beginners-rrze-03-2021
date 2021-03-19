/**************************************************************************************************
*
* \file Library5.cpp
* \brief C++ Training - Class Template Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Add a 'BookCompare' template parameter to the 'Library' class, which specifies the
*       way books are ordered within the library. Test the implementation with a least two
*       different comparators ('CompareByISBN' and 'CompareByAuthorAndTitle').
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
   explicit ISBN( string isbn )
      : isbn_( std::move(isbn) )
   {}

   const string& asString() const { return isbn_; }

 private:
   string isbn_;
};

bool operator==( const ISBN& lhs, const ISBN& rhs )
{
   return lhs.asString() == rhs.asString();
}

bool operator!=( const ISBN& lhs, const ISBN& rhs )
{
   return !( lhs == rhs );
}

bool operator<( const ISBN& lhs, const ISBN& rhs )
{
   return lhs.asString() < rhs.asString();
}

bool operator>( const ISBN& lhs, const ISBN& rhs )
{
   return ( rhs < lhs );
}

bool operator<=( const ISBN& lhs, const ISBN& rhs )
{
   return !( rhs < lhs );
}

bool operator>=( const ISBN& lhs, const ISBN& rhs )
{
   return !( lhs < rhs );
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
   explicit Author( string firstname, string lastname )
      : firstname_( std::move(firstname) )
      , lastname_ ( std::move(lastname)  )
   {}

   const string& firstname() const { return firstname_; }
   const string& lastname () const { return lastname_; }

 private:
   string firstname_;
   string lastname_;
};

bool operator==( const Author& lhs, const Author& rhs )
{
   return lhs.lastname() == rhs.lastname() && lhs.firstname() == rhs.firstname();
}

bool operator!=( const Author& lhs, const Author& rhs )
{
   return !( lhs == rhs );
}

bool operator<( const Author& lhs, const Author& rhs )
{
   return ( lhs.lastname() < rhs.lastname() ||
            ( lhs.lastname() == rhs.lastname() && lhs.firstname() < rhs.firstname() ) );
}

bool operator>( const Author& lhs, const Author& rhs )
{
   return rhs < lhs;
}

bool operator<=( const Author& lhs, const Author& rhs )
{
   return !( rhs < lhs );
}

bool operator>=( const Author& lhs, const Author& rhs )
{
   return !( lhs < rhs );
}

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

   explicit Book( string title, Author author, ISBN isbn )
      : title_ ( std::move(title) )
      , author_( std::move(author) )
      , isbn_  ( std::move(isbn) )
      , price_ ( defaultPrice_ )
   {}

   explicit Book( string title, string firstname, string lastname, ISBN isbn )
      : title_ ( std::move(title) )
      , author_( std::move(firstname), std::move(lastname) )
      , isbn_  ( std::move(isbn) )
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

bool operator==( const Book& lhs, const Book& rhs )
{
   return lhs.title() == rhs.title() && lhs.author() == rhs.author() && lhs.isbn() == rhs.isbn();
}

bool operator!=( const Book& lhs, const Book& rhs )
{
   return !( lhs == rhs );
}

bool operator<( const Book& lhs, const Book& rhs )
{
   return ( lhs.author() < rhs.author() ||
            ( lhs.author() == rhs.author() && lhs.title() < rhs.title() ) );
}

bool operator>( const Book& lhs, const Book& rhs )
{
   return ( rhs < lhs );
}

bool operator<=( const Book& lhs, const Book& rhs )
{
   return !( rhs < lhs );
}

bool operator>=( const Book& lhs, const Book& rhs )
{
   return !( lhs < rhs );
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

// TODO: Add the 'BookCompare' template parameter

template<typename BookCompare>
class Library
{
 private:
   using Books = std::map<Book,unsigned int, BookCompare>;

 public:
   using const_iterator = typename Books::const_iterator;

   void addBook( const Book& book, unsigned int count = 1U )
   {
      books_[book] += count;
   }

   void addBook( Book&& book, unsigned int count = 1U )
   {
      books_[std::move(book)] += count;
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

template<typename BookCompare>
std::ostream& operator<<( std::ostream& os, const Library<BookCompare>& library )
{
   for( const auto& book : library ) {
      os << book.first << ", Count:" << book.second << "\n";
   }

   return os;
}


//=================================================================================================
// class CompareByISBN
//=================================================================================================

// TODO: Implement the 'CompareByISBN' functors
struct CompareByISBN{
   template<typename B>
   bool operator()( const B& b1, const B& b2 ) const {
      return b1.isbn() < b2.isbn();
   }
};


//=================================================================================================
// class CompareByAuthorAndTitle
//=================================================================================================

// TODO: Implement the 'CompareByAuthorAndTitle' functors
struct CompareByAuthorAndTitle{
   template<typename B>
   bool operator()( const B& b1, const B& b2 ) const {
      // // My implementation
      // return (b1.author() == b2.author()) ? b1.title() < b2.title() : b1.author() < b2.author();
      
      // Klaus' implementation (both work)
      return (b1.author() < b2.author() ||
               (b1.author() == b2.author() && b1.title() < b2.title()));
   }
};



//=================================================================================================
// main() function
//=================================================================================================

int main()
{
   // Library<CompareByISBN> library;
   Library<CompareByAuthorAndTitle> library;

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
