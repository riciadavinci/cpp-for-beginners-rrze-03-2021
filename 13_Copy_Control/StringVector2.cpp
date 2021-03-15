/**************************************************************************************************
*
* \file StringVector2.cpp
* \brief C++ Training - Copy Control Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Add the move operations to the following 'StringVector' class.
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
   // TODO: Add the declaration of the move constructor

   StringVector& operator=( const StringVector& sv );
   // TODO: Add the declaration of the move assignment operator

   ~StringVector();

   void   push_back( const std::string& s );
   size_t size() const;
   size_t capacity() const;

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


// TODO: Add the definition of the move constructor


StringVector::~StringVector()
{
   free();
}


StringVector& StringVector::operator=( const StringVector& sv )
{
   StringVector tmp( sv );
   swap( tmp );
   return *this;
}


// TODO: Add the definition of the move assignment operator


void StringVector::push_back( const std::string& s )
{
   if( end_ == final_ ) {
      reallocate();
   }

   alloc.construct( end_, s );
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
   sv.push_back( "Bjarne"s );
   sv.push_back( "Herb"s );
   sv.push_back( "Nicolai"s );

   StringVector sv2( std::move(sv) );

   std::cout << "\n" << sv2 << "\n\n";

   StringVector sv3;
   sv3.push_back( "Alexander"s );
   sv3.push_back( "Andrei"s );

   sv2 = std::move(sv3);

   std::cout << "\n" << sv2 << "\n\n";

   return EXIT_SUCCESS;
}
