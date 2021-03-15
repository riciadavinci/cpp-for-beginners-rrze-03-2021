/**************************************************************************************************
*
* \file AlignedAllocator.cpp
* \brief C++ Training - Allocator Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
**************************************************************************************************/

#include <cstddef>
#include <iostream>
#include <type_traits>
#include <vector>


template< typename Type >
Type* allocate( size_t size )
{
   static_assert( std::is_fundamental<Type>::value, "Invalid data type detected" );

   const size_t alignment( 32U );  // Proper alignment for AVX

   void* raw( nullptr );

#if defined(_MSC_VER)
   raw = _aligned_malloc( size*sizeof(Type), alignment );
   if( raw == nullptr ) {
#else
   if( posix_memalign( &raw, alignment, size*sizeof(Type) ) ) {
#endif
      throw std::bad_alloc();
   }

   return reinterpret_cast<Type*>( raw );
}


template< typename Type >
void deallocate( Type* address )
{
   static_assert( std::is_fundamental<Type>::value, "Invalid data type detected" );

   if( address == nullptr )
      return;

#if defined(_MSC_VER)
   _aligned_free( address );
#else
   free( address );
#endif
}




template< typename Type >
class AlignedAllocator
{
 public:
   using value_type    = Type;            //!< Type of the allocated values.
   using pointer       = Type*;           //!< Type of a pointer to the allocated values.
   using const_pointer = const Type*;     //!< Type of a pointer-to-const to the allocated values.

   template< typename Type2 >
   struct rebind
   {
      using other = AlignedAllocator<Type2>;
   };

   explicit inline AlignedAllocator();

   template< typename Type2 >
   inline AlignedAllocator( const AlignedAllocator<Type2>& );

   inline pointer allocate  ( size_t numObjects, const void* localityHint = nullptr );
   inline void    deallocate( pointer ptr, size_t numObjects ) noexcept;
};


template< typename Type >
inline AlignedAllocator<Type>::AlignedAllocator()
{}


template< typename Type >
template< typename Type2 >
inline AlignedAllocator<Type>::AlignedAllocator( const AlignedAllocator<Type2>& allocator )
{}


template< typename Type >
inline typename AlignedAllocator<Type>::pointer
   AlignedAllocator<Type>::allocate( size_t numObjects, const void* localityHint )
{
   using ::allocate;

   return allocate<Type>( numObjects*sizeof(Type) );
}


template< typename Type >
inline void AlignedAllocator<Type>::deallocate( pointer ptr, size_t numObjects ) noexcept
{
   using ::deallocate;

   if( ptr == nullptr )
      return;

   deallocate( ptr );
}


template< typename T1, typename T2 >
inline bool operator==( const AlignedAllocator<T1>& lhs, const AlignedAllocator<T2>& rhs ) noexcept
{
   return true;
}


template< typename T1, typename T2 >
inline bool operator!=( const AlignedAllocator<T1>& lhs, const AlignedAllocator<T2>& rhs ) noexcept
{
   return false;
}




int main()
{
   std::vector<int,AlignedAllocator<int>> v{ 1, 2, 3, 4, 5 };

   std::cout << " (";
   for( int i : v ) {
      std::cout << " " << i;
   }
   std::cout << " )\n";
}
