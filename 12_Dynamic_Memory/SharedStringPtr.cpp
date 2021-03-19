/**************************************************************************************************
*
* \file SharedStringPtr.cpp
* \brief C++ Training - RAII Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Implement the 'SharedStringPtr' class to manage a dynamically allocated 'std::string'.
*       The 'SharedStringPtr' should implement shared ownership of a std::string.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std::string_literals;


class SharedStringPtr
{
public:
    // default constructor
    SharedStringPtr() = default;

    // Resource constructor
    explicit SharedStringPtr( std::string* ptr )
      : ptr_ { ptr }
    {
      // if(ptr_) is short for if(ptr_ != nullptr)
      if(ptr_){
        uses_ = new std::size_t(1);
      }
    }


    // copy constructor
    SharedStringPtr( const SharedStringPtr& s )
      : ptr_  ( s.ptr_  )
      , uses_ ( s.uses_ )
    {
      // if s does not manage any resource, 
      // this object will also have null values and uses_ (reference count)
      // will be zero
      increment();
    }

    // destructor
    ~SharedStringPtr(){
      decrement();
    }

    SharedStringPtr& operator=( const SharedStringPtr& s ){
      decrement();

      ptr_ = s.ptr_;
      uses_ = s.uses_;

      increment();

      return *this;
    }


    std::string& operator* () const { return *ptr_; }
    std::string* operator->() const { return  ptr_; }

private:
    std::string* ptr_ { nullptr };    // Resource
    std::size_t* uses_ { nullptr };   // Reference count
    
    // Helper function
    void decrement(){
      if( uses_ && --(*uses_) == 0U){
        delete uses_;
        delete ptr_; 
      }
    }

    void increment(){
      if(uses_){
        ++(*uses_);
      }
    }
};


// TODO: Implement all member functions of the 'SharedStringPtr' class


int main()
{
   
    SharedStringPtr ssptr1( new std::string( "Bjarne"s ) );
    // SharedStringPtr ssptr2( ssptr1 );

    std::cout << "\n"
              << " *ssptr1 = \"" << *ssptr1 << "\"\n"
              << " *ssptr2 = \"" << *ssptr1 << "\"\n"
              << "\n";


    return EXIT_SUCCESS;
}
