/**************************************************************************************************
*
* \file Currency.cpp
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

#include "Currency.h"


std::ostream& operator<<( std::ostream& os, Currency currency )
{
   switch( currency ) {
      case Currency::Euro:
         os << "Euro";
         break;
      case Currency::Dollar:
         os << "Dollar";
         break;
      case Currency::Yen:
         os << "Yen";
         break;
      default:
         os << "Unknown currency";
   }

   return os;
}
