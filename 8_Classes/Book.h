/**************************************************************************************************
*
* \file Book.h
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

#ifndef BOOK_H
#define BOOK_H

#include <istream>
#include <ostream>
#include <string>

#include "Author.h"
#include "Currency.h"
#include "ISBN.h"
#include "Price.h"


class Book
{
 public:
   using Price = std::pair<double,Currency>;

   explicit Book( const std::string& title, const std::string& firstname
                , const std::string& lastname, const std::string& isbn );

   const std::string& title() const;
   const std::string& firstname() const;
   const std::string& lastname() const;
   const std::string& isbn() const;
   Price              price() const;

   void setPrice( Price price );
   void setPrice( double price, Currency currency = Currency::Euro );

   static void setDefaultPrice( Price price );
   static void setDefaultPrice( double price, Currency currency = Currency::Euro );

 private:
   std::string title_;
   std::string firstname_;
   std::string lastname_;
   std::string isbn_;
   Price       price_;

   static Price defaultPrice_;
};


std::ostream& operator<<( std::ostream& os, const Book& book );

#endif
