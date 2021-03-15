/**************************************************************************************************
*
* \file Book.cpp
* \brief C++ Training - Class Design Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: For instructions, see the 'Main.cpp' file.
*
**************************************************************************************************/

#include <iomanip>

#include "Book.h"

using std::string;


Book::Price Book::defaultPrice_( 10.0, Currency::Euro );


Book::Book( const string& title, const string& firstname
          , const string& lastname, const string& isbn )
   : title_ ( title )
   , firstname_( firstname )
   , lastname_( lastname )
   , isbn_  ( isbn )
   , price_ ( defaultPrice_ )
{}


const std::string& Book::title() const
{
   return title_;
}


const std::string& Book::firstname() const
{
   return firstname_;
}


const std::string& Book::lastname() const
{
   return lastname_;
}


const std::string& Book::isbn() const
{
   return isbn_;
}


Book::Price Book::price() const
{
   return price_;
}


void Book::setPrice( Price price )
{
   price_ = price;
}


void Book::setPrice( double price, Currency currency )
{
   price_ = Price( price, currency );
}


void Book::setDefaultPrice( Price price )
{
   defaultPrice_ = price;
}


void Book::setDefaultPrice( double price, Currency currency )
{
   defaultPrice_ = Price( price, currency );
}


std::ostream& operator<<( std::ostream& os, const Book& book )
{
   os << "Title: \"" << book.title()
      << "\", Author: \"" << book.firstname() << " " << book.lastname()
      << "\", ISBN: " << book.isbn()
      << std::setprecision( 2 ) << std::fixed
      << ", Price: " << book.price().first << " " << book.price().second;

   return os;
}
