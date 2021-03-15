/**************************************************************************************************
*
* \file Currency.h
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

#ifndef CURRENCY_H
#define CURRENCY_H

#include <ostream>


enum class Currency
{
   Euro,
   Dollar,
   Yen
};


std::ostream& operator<<( std::ostream& os, Currency currency );

#endif
