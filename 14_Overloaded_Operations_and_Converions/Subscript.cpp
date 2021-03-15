/**************************************************************************************************
*
* \file Subscript.cpp
* \brief C++ Training - Operator Overloading Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Add the subscript operator to the 'StringVector' class template to provide single
*       element access.
*
**************************************************************************************************/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>

using std::size_t;
using namespace std::string_literals;


class StringVector
{
 public:
   using iterator       = std::string*;
   using const_iterator = const std::string*;

   StringVector() = default;
   StringVector( const StringVector& sv );
   StringVector( StringVector&& sv );

   StringVector& operator=( const StringVector& sv );
   StringVector& operator=( StringVector&& sv );
   StringVector& operator=( std::initializer_list<std::string> list );

   ~StringVector();

   void   push_back( const std::string& s );
   void   push_back( std::string&& s );
   size_t size() const;
   size_t capacity() const;

   // TODO: Add the subscript operator (i.e. 'operator[])

   iterator       begin();
   iterator       end();
   const_iterator begin() const;
   const_iterator end()   const;

   void swap( StringVector& sv );

 private:
   void reallocate();
   void free();

   std::string* begin_{ nullptr };
   std::string* end_  { nullptr };
   std::string* final_{ nullptr };

   static std::allocator<std::string> alloc;
};

std::allocator<std::string> StringVector::alloc;


StringVector::StringVector( const StringVector& sv )
   : begin_( alloc.allocate( sv.size() ) )
   , end_  ( std::uninitialized_copy( sv.begin(), sv.end(), begin_ ) )
   , final_( end_ )
{}


StringVector::StringVector( StringVector&& sv )
   : begin_( sv.begin_ )
   , end_  ( sv.end_   )
   , final_( sv.final_ )
{
   sv.begin_ = nullptr;
   sv.end_   = nullptr;
   sv.final_ = nullptr;
}


StringVector& StringVector::operator=( const StringVector& sv )
{
   StringVector tmp( sv );
   swap( tmp );
   return *this;
}


StringVector& StringVector::operator=( StringVector&& sv )
{
   free();

   begin_ = sv.begin_;
   end_   = sv.end_;
   final_ = sv.final_;

   sv.begin_ = nullptr;
   sv.end_   = nullptr;
   sv.final_ = nullptr;

   return *this;
}


StringVector& StringVector::operator=( std::initializer_list<std::string> list )
{
   StringVector tmp;
   for( const std::string& s : list ) {
      tmp.push_back( s );
   }
   swap( tmp );
   return *this;
}


StringVector::~StringVector()
{
   free();
}


void StringVector::push_back( const std::string& s )
{
   if( end_ == final_ ) {
      reallocate();
   }

   alloc.construct( end_, s );
   ++end_;
}


void StringVector::push_back( std::string&& s )
{
   if( end_ == final_ ) {
      reallocate();
   }

   alloc.construct( end_, std::move( s ) );
   ++end_;
}


size_t StringVector::size() const
{
   return end_ - begin_;
}


size_t StringVector::capacity() const
{
   return final_ - begin_;
}


StringVector::iterator StringVector::begin()
{
   return begin_;
}

StringVector::iterator StringVector::end()
{
   return end_;
}

StringVector::const_iterator StringVector::begin() const
{
   return begin_;
}

StringVector::const_iterator StringVector::end() const
{
   return end_;
}


void StringVector::swap( StringVector& sv )
{
   using std::swap;

   swap( begin_, sv.begin_ );
   swap( end_  , sv.end_   );
   swap( final_, sv.final_ );
}


void StringVector::reallocate()
{
   const size_t n = ( size() ? 2*size() : 1UL );

   auto newbegin( alloc.allocate( n ) );
   auto newend  ( std::uninitialized_copy( begin_, end_, newbegin ) );

   free();

   begin_ = newbegin;
   end_   = newend;
   final_ = begin_ + n;
}


void StringVector::free()
{
   for( auto it=begin_; it!=end_; ++it ) {
      alloc.destroy( it );
   }

   alloc.deallocate( begin_, capacity() );
}


std::ostream& operator<<( std::ostream& os, const StringVector& sv )
{
   os << "(";
   for( const auto& s : sv ) {
      os << " \"" << s << "\"";
   }
   return os << " )";
}


int main()
{
   StringVector sv;

   sv = { "Bjarne"s, "Herb"s, "Nicolai"s };

   for( size_t i=0UL; i<sv.size(); ++i ) {
      //std::cout << sv[i] << "\n";  // TODO: Add the subscript operator (i.e. 'operator[])
   }

   return EXIT_SUCCESS;
}
