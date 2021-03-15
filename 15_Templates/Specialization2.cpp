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
