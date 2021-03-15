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
*       visitor design pattern.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <utility>


//--Visitor.h--------------------------------------------------------------------------------------

class ElementA;
class ElementB;

class Visitor
{
 public:
   virtual ~Visitor() = default;

   virtual void visit( const ElementA& ) const = 0;
   virtual void visit( const ElementB& ) const = 0;
};


//--ActionA.h--------------------------------------------------------------------------------------

class ActionA : public Visitor
{
 public:
   void visit( const ElementA& ) const override;
   void visit( const ElementB& ) const override;
};


//--ActionA.cpp------------------------------------------------------------------------------------

void ActionA::visit( const ElementA& ) const
{
   std::cout << " ActionA::visit( ElementA )\n";
}

void ActionA::visit( const ElementB& ) const
{
   std::cout << " ActionA::visit( ElementB )\n";
}


//--ActionB.h--------------------------------------------------------------------------------------

class ActionB : public Visitor
{
 public:
   void visit( const ElementA& ) const override;
   void visit( const ElementB& ) const override;
};


//--ActionB.cpp-----------------------------------------------------------------------------------

void ActionB::visit( const ElementA& ) const
{
   std::cout << " ActionB::visit( ElementA )\n";
}

void ActionB::visit( const ElementB& ) const
{
   std::cout << " ActionB::visit( ElementB )\n";
}


//--ElementA.h-------------------------------------------------------------------------------------

class ElementA
{
 public:
   void accept( const Visitor& v ) const;
};


//--ElementA.cpp-----------------------------------------------------------------------------------

void ElementA::accept( const Visitor& v ) const
{
   v.visit( *this );
}


//--ElementB.h-------------------------------------------------------------------------------------

class ElementB
{
 public:
   void accept( const Visitor& v ) const;
};


//--ElementB.cpp-----------------------------------------------------------------------------------

void ElementB::accept( const Visitor& v ) const
{
   v.visit( *this );
}


//--Main.cpp---------------------------------------------------------------------------------------

int main()
{
   ActionA vA;
   ActionB vB;

   ElementA eA;
   ElementB eB;

   eA.accept( vA );
   eA.accept( vB );
   eB.accept( vA );
   eB.accept( vB );

   return EXIT_SUCCESS;
}
