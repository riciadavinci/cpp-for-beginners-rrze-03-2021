/**************************************************************************************************
*
* \file ArenaAllocator.cpp
* \brief C++ Training - Allocator Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
**************************************************************************************************/

#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>


class Arena
{
 public:
   static constexpr size_t N = 100UL;

   explicit Arena() noexcept
      : ptr_( buf_ )
   {}

   char* allocate( size_t n ) noexcept {
      assert( ptr_ + n <= buf_ + N );
      const auto tmp( ptr_ );
      ptr_ += n;
      return tmp;
   }

   void deallocate( char* p, std::size_t n ) noexcept {
      if( p + n == ptr_ )
         ptr_ = p;
   }

 private:
   char buf_[N];
   char* ptr_;
};


template< typename Type >
class ArenaAllocator
{
 public:
   using value_type    = Type;            //!< Type of the allocated values.
   using pointer       = Type*;           //!< Type of a pointer to the allocated values.
   using const_pointer = const Type*;     //!< Type of a pointer-to-const to the allocated values.

   template< typename Type2 >
   struct rebind
   {
      using other = ArenaAllocator<Type2>;
   };

   explicit ArenaAllocator( Arena& arena )
      : arena_( arena )
   {}

   ArenaAllocator( const ArenaAllocator& ) = default;

   pointer allocate( size_t numObjects, const void* localityHint = nullptr )
   {
      return reinterpret_cast<pointer>( arena_.allocate( numObjects*sizeof(Type) ) );
   }

   void deallocate( pointer ptr, size_t numObjects ) noexcept
   {
      arena_.deallocate( reinterpret_cast<char*>( ptr ), numObjects*sizeof(Type) );
   }

 private:
   Arena& arena_;

   template< typename T1, typename T2 >
   friend bool operator==( const ArenaAllocator<T1>& lhs, const ArenaAllocator<T2>& rhs ) noexcept;
};

template< typename T1, typename T2 >
inline bool operator==( const ArenaAllocator<T1>& lhs, const ArenaAllocator<T2>& rhs ) noexcept
{
   return &lhs.arena_ == &rhs.arena_;
}

template< typename T1, typename T2 >
inline bool operator!=( const ArenaAllocator<T1>& lhs, const ArenaAllocator<T2>& rhs ) noexcept
{
   return !( lhs == rhs );
}




int main()
{
   Arena arena;

   std::vector<int,ArenaAllocator<int>> v{ ArenaAllocator<int>( arena ) };
   v.push_back( 1 );
   v.push_back( 2 );
   v.push_back( 3 );
   v.push_back( 4 );
   v.push_back( 5 );

   std::cout << " (";
   for( int i : v ) {
      std::cout << " " << i;
   }
   std::cout << " )\n";
}
