/**************************************************************************************************
*
* \file Strategy.cpp
* \brief C++ Training - Example for the Strategy Design Pattern
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Discuss the advantages and disadvantages of the given implementation of the classical
*       strategy design pattern.
*
**************************************************************************************************/

#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>


//--Strategy.h-------------------------------------------------------------------------------------

class Strategy
{
 public:
   explicit Strategy() = default;
   virtual ~Strategy() = default;

   void algorithm( int i );

 private:
   virtual void doAlgorithm( int i ) = 0;
};


//--Strategy.cpp-----------------------------------------------------------------------------------

void Strategy::algorithm( int i )
{
   std::cout << " Applying strategy for value " << i << "\n";
   doAlgorithm( i );
}


//--Subject.h--------------------------------------------------------------------------------------

class Subject
{
 public:
   explicit Subject() = default;

   void setStrategy( Strategy* strategy );

   void context( int i );

 private:
   Strategy* strategy_ = nullptr;
};


//--Subject.cpp------------------------------------------------------------------------------------

void Subject::setStrategy( Strategy* strategy )
{
   strategy_ = strategy;
}

void Subject::context( int i )
{
   strategy_->algorithm( i );
}


//--ConcreteStrategy.h-----------------------------------------------------------------------------

class ConcreteStrategy : public Strategy
{
 public:
   explicit ConcreteStrategy() = default;

 private:
   void doAlgorithm( int i ) override;
};


//--ConcreteStrategy.cpp---------------------------------------------------------------------------

void ConcreteStrategy::doAlgorithm( int i )
{
   std::cout << " Applying concrete strategy for value " << i << "...\n";
}


//--Main.cpp---------------------------------------------------------------------------------------

int main()
{
   ConcreteStrategy strategy;

   Subject subject;
   subject.setStrategy( &strategy );

   subject.context( 1 );

   return EXIT_SUCCESS;
}
