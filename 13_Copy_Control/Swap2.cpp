/**************************************************************************************************
*
* \file Swap2.cpp
* \brief C++ Training - Swap Programming Exercise
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Implement a 'swap()' function for the given 'StringPtr' class.
*
**************************************************************************************************/

#include <iostream>
#include <string>


struct StringPtr
{
 public:
   StringPtr( std::string* ptr ) : ptr_( ptr ) {}
   ~StringPtr() { delete ptr_; }

   StringPtr( const StringPtr& ) = delete;
   StringPtr& operator=( const StringPtr& ptr ) = delete;

   const std::string* data() const { return ptr_; }

 private:
   std::string* ptr_;
};


// TODO: Implement a 'swap()' function for the given 'StringPtr' class.


std::ostream& operator<<( std::ostream& os, const StringPtr& sptr )
{
   return os << *sptr.data();
}


int main()
{
   StringPtr sptr1( new std::string( "Hello" ) );
   StringPtr sptr2( new std::string( "World" ) );

   //swap( sptr1, sptr2 );

   std::cout << "\n"
             << " sptr1 = " << sptr1 << "\n"
             << " sptr2 = " << sptr2 << "\n"
             << "\n";

   return EXIT_SUCCESS;
}
