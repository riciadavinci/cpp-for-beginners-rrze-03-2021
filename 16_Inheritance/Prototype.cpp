/**************************************************************************************************
*
* \file Visitor.cpp
* \brief C++ Training - Example for the Visitor Design Pattern
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Discuss the advantages and disadvantages of the given implementation of the classical
*       prototype design pattern.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>


//--Prototype.h------------------------------------------------------------------------------------

class Prototype
{
 public:
   virtual ~Prototype() = default;
   virtual Prototype* clone() const = 0;
};


//--ConcretePrototype1.h---------------------------------------------------------------------------

class ConcretePrototype1 : public Prototype
{
 public:
   ConcretePrototype1* clone() const override;
};


//--ConcretePrototype1.cpp-------------------------------------------------------------------------

ConcretePrototype1* ConcretePrototype1::clone() const
{
   std::cout << " ConcretePrototype1::clone()\n";
   return new ConcretePrototype1{};
}


//--ConcretePrototype2.h---------------------------------------------------------------------------

class ConcretePrototype2 : public Prototype
{
 public:
   ConcretePrototype2* clone() const override;
};


//--ConcretePrototype2.cpp-------------------------------------------------------------------------

ConcretePrototype2* ConcretePrototype2::clone() const
{
   std::cout << " ConcretePrototype2::clone()\n";
   return new ConcretePrototype2{};
}


//--Main.cpp---------------------------------------------------------------------------------------

int main()
{
   Prototype* pp1( new ConcretePrototype1{} );
   Prototype* pp2( new ConcretePrototype2{} );

   Prototype* pp3( pp1->clone() );
   Prototype* pp4( pp2->clone() );

   delete pp1;
   delete pp2;
   delete pp3;
   delete pp4;

   return EXIT_SUCCESS;
}
