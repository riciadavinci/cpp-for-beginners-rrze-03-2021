/**************************************************************************************************
*
* \file Vector1.cpp
* \brief C++ Training - Class Template Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Rework the 'Vector' class to a class template named 'Vector'.
*
**************************************************************************************************/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>

using std::size_t;
using namespace std::string_literals;


template<typename T>
class Vector
{
 public:
   using iterator       = T*;
   using const_iterator = const T*;

   Vector() = default;
   Vector( const Vector& sv );

   Vector& operator=( const Vector& sv );

   ~Vector();

   void   push_back( const T& s );
   void   push_back( T&& s );
   size_t size() const;
   size_t capacity() const;

   iterator       begin();
   iterator       end();
   const_iterator begin() const;
   const_iterator end()   const;

   void swap( Vector& sv );

 private:
   void reallocate();
   void free();

   T* begin_{ nullptr };
   T* end_  { nullptr };
   T* final_{ nullptr };

   static std::allocator<T> alloc;
};

template<typename T>
std::allocator<T> Vector<T>::alloc;


template<typename T>
Vector<T>::Vector( const Vector& sv )
   : begin_( alloc.allocate( sv.size() ) )
   , end_  ( std::uninitialized_copy( sv.begin(), sv.end(), begin_ ) )
   , final_( end_ )
{}


template<typename T>
Vector<T>& Vector<T>::operator=( const Vector& sv )
{
   Vector tmp( sv );
   swap( tmp );
   return *this;
}


template<typename T>
Vector<T>::~Vector()
{
   free();
}


template<typename T>
void Vector<T>::push_back( const T& s )
{
   if( end_ == final_ ) {
      reallocate();
   }

   alloc.construct( end_, s );
   ++end_;
}


template<typename T>
void Vector<T>::push_back( T&& s )
{
   if( end_ == final_ ) {
      reallocate();
   }

   alloc.construct( end_, std::move( s ) );
   ++end_;
}


template<typename T>
size_t Vector<T>::size() const
{
   return end_ - begin_;
}


template<typename T>
size_t Vector<T>::capacity() const
{
   return final_ - begin_;
}


template<typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
   return begin_;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::end()
{
   return end_;
}


template<typename T>
typename Vector<T>::const_iterator Vector<T>::begin() const
{
   return begin_;
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::end() const
{
   return end_;
}


template<typename T>
void Vector<T>::swap( Vector<T>& sv )
{
   using std::swap;

   swap( begin_, sv.begin_ );
   swap( end_  , sv.end_   );
   swap( final_, sv.final_ );
}


template<typename T>
void Vector<T>::reallocate()
{
   const size_t n = ( size() ? 2*size() : 1UL );

   auto newbegin( alloc.allocate( n ) );
   auto newend  ( std::uninitialized_copy( begin_, end_, newbegin ) );

   free();

   begin_ = newbegin;
   end_   = newend;
   final_ = begin_ + n;
}


template<typename T>
void Vector<T>::free()
{
   for( auto it=begin_; it!=end_; ++it ) {
      alloc.destroy( it );
   }

   alloc.deallocate( begin_, capacity() );
}


template<typename T>
std::ostream& operator<<( std::ostream& os, const Vector<T>& sv )
{
   os << "(";
   for( const auto& s : sv ) {
      os << s << " ";
   }
   return os << " )";
}


int main()
{
   /*
   Vector<std::string> sv;
   sv.push_back( "Bjarne"s );
   sv.push_back( "Herb"s );
   sv.push_back( "Nicolai"s );

   Vector<std::string> sv2( std::move(sv) );

   std::cout << "\n" << sv2 << "\n\n";

   Vector<std::string> sv3;
   sv3.push_back( "Alexander" );
   sv3.push_back( "Andrei" );

   sv2 = std::move(sv3);

   std::cout << "\n" << sv2 << "\n\n";
   */

   return EXIT_SUCCESS;
}
