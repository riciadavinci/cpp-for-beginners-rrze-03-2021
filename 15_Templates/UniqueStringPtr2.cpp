/**************************************************************************************************
*
* \file UniquePtr.cpp
* \brief C++ Training - Class Template Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Implement the 'UniquePtr' class to manage a dynamically allocated 'std::string'.
*       The 'UniquePtr' should implement unique ownership of a std::string.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std::string_literals;

template<typename T>
class UniquePtr
{
 public:
            UniquePtr() = default;
   explicit UniquePtr( T* ptr );
            UniquePtr( UniquePtr const& ) = delete;

   ~UniquePtr();

   UniquePtr& operator=( UniquePtr const& ) = delete;

   T& operator* () const;
   T* operator->() const;

 private:
   T* ptr_{ nullptr };
};


template<typename T>
UniquePtr<T>::UniquePtr( T* ptr )
   : ptr_( ptr )
{}


template<typename T>
UniquePtr<T>::~UniquePtr()
{
   delete ptr_;
}


template<typename T>
T& UniquePtr<T>::operator*() const
{
   return *ptr_;
}


template<typename T>
T* UniquePtr<T>::operator->() const
{
   return ptr_;
}


int main()
{
   UniquePtr<std::string> usptr( new std::string( "Bjarne"s ) );

   std::cout << "\n *usptr = \"" << *usptr << "\"\n\n";

   return EXIT_SUCCESS;
}
