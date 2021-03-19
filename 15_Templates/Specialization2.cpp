/**************************************************************************************************
*
* \file Specialization2.cpp
* \brief C++ Training - Template Specialization Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Implement all necessary specializations for the IsConst type trait.
*
**************************************************************************************************/

#include <complex>
#include <cstdlib>
#include <iostream>
#include <type_traits>


template< typename T >
struct IsConst
   : public std::false_type
{};


// This is a specialization of the above class template
// <> / angle brackets after the struct/class name creates
// the class specialization.
// If a class T is passed to IsConst, and it const qualified,
// then it will return true. Else, it will return false
template< typename T >
struct IsConst<const T>
   : public std::true_type
{};


// Another advantage is that the above code to check is for `const` qualified
// or not at compile time. In comparison, if else statements to implement this
// will be run-time, since if else is a run-time construct
// Similarly, for pattern matching, we can do the following:
/*
// for reference
template< typename T >
struct IsConst<T&>

// for pointer
template< typename T >
struct IsConst<T*>
*/


// Also, we can check if a certain variable is of a certain type
// eg: IsIntegral
/*

template< typename T >
struct IsIntegral
   : public std::false_type
{}

template< typename T >
struct IsIntegral<int>
   : public std::true_type
{}

*/

// Here, the above struct will return true only if the variable is an int,
// else it will return false. But you will also need to implement it for 
// short, long, long long , unsigned, etc. to cover all integrals


// TODO: Implement all necessary specializations for the IsConst type trait.


template< typename T >
constexpr bool IsConst_v = IsConst<T>::value;


int main()
{
   using Type1 = int;
   using Type2 = const int;
   using Type3 = std::complex<float>;
   using Type4 = std::complex<float> const;

   constexpr bool res1 = IsConst_v<Type1>;
   constexpr bool res2 = IsConst_v<Type2>;
   constexpr bool res3 = IsConst_v<Type3>;
   constexpr bool res4 = IsConst_v<Type4>;

   std::cout << "\n"
             << " res1 = " << res1 << "\n"
             << " res2 = " << res2 << "\n"
             << " res3 = " << res3 << "\n"
             << " res4 = " << res4 << "\n"
             << "\n";

   return EXIT_SUCCESS;
}
