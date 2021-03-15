/**************************************************************************************************
*
* \file Sort.cpp
* \brief C++ Training - Performance Evaluation of Data Structures
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Benchmark the insertion of N elements of type 'Type' into different containers.
*       Explain the time differences based on the implementation details of the underlying
*       data structures.
*
**************************************************************************************************/

#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <set>
#include <unordered_set>
#include <vector>

using std::size_t;


//=================================================================================================
// Benchmark configuration
//=================================================================================================

constexpr size_t N = 1000000U;

using Type = int;


//=================================================================================================
// benchmarkVector()
//=================================================================================================

void benchmarkVector( const std::vector<Type>& values )
{
   std::vector<Type> v;

   std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
   start = std::chrono::high_resolution_clock::now();

   const size_t N( values.size() );

   for( size_t i=0U; i<N; ++i ) {
      v.push_back( values[i] );
   }

   std::sort( std::begin(v), std::end(v) );

   end = std::chrono::high_resolution_clock::now();
   const std::chrono::duration<double> elapsedTime( end - start );
   const double seconds( elapsedTime.count() );

   std::cout << " Vector runtime       : " << seconds << "s\n";
}


//=================================================================================================
// benchmarkDeque()
//=================================================================================================

void benchmarkDeque( const std::vector<Type>& values )
{
   // TODO: Implement the benchmark for a 'std::deque'.
}


//=================================================================================================
// benchmarkList()
//=================================================================================================

void benchmarkList( const std::vector<Type>& values )
{
   // TODO: Implement the benchmark for a 'std::list'.
}


//=================================================================================================
// benchmarkSet()
//=================================================================================================

void benchmarkSet( const std::vector<Type>& values )
{
   // TODO: Implement the benchmark for a 'std::set'.
}


//=================================================================================================
// benchmarkUnorderedSet()
//=================================================================================================

void benchmarkUnorderedSet( const std::vector<Type>& values )
{
   // TODO: Implement the benchmark for a 'std::unordered_set'.
}


//=================================================================================================
// main() function
//=================================================================================================

int main()
{
   std::vector<Type> values( N );

   std::iota( begin(values), end(values), Type{} );
   std::random_device rd{};
   std::mt19937 mt{ rd() };
   std::shuffle( begin(values), end(values), mt );

   benchmarkVector( values );
   benchmarkDeque( values );
   benchmarkList( values );
   benchmarkSet( values );
   benchmarkUnorderedSet( values );

   return EXIT_SUCCESS;
}
