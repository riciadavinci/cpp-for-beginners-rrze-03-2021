/**************************************************************************************************
*
* \file Overloading.cpp
* \brief C++ Training - Programming task about function overloading
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Implement the following 'print()' functions:
*        - void print(const char* array);
*        - void print(const std::string& s);
*        - void print(const int* begin, const int* end);
*        - void print(const int* ia, size_t size);
*
**************************************************************************************************/

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>


// TODO: Implement the following 'print()' functions:
//        - void print(const char* array);
//        - void print(const std::string& s);
//        - void print(const int* begin, const int* end);
//        - void print(const int* ia, size_t size);


// void print(const char* array) same as void print(const char array[])
void print(const char* array){
   std::cout << array << "\n";
}


//void print(const std::string& s)
void print(const std::string& s){
   // Option 1: self implementation (built-in cout overload)
   // std::cout << s << "\n";

   // Option 2: wrapper to above function: void print (const char* array);
   print(s.c_str());
}


// void print(const int* begin, const int* end)
void print(const int* begin, const int* end){
   for( ; begin != end; ++begin){
      std::cout << " " << *begin;
   }
   std::cout << "\n";
}


// void print(const int* ia, size_t size)
// This implementation also includes default argument
void print(const int* ia, size_t size = 0){
   // Option 1:
   // It acts as a convenient wrapper
   print(ia, ia+size);

   // Option 2: self implementation
   // ...
}


int main()
{
   {
      const char array[] = "Some interesting string";
      print(array);

      std::string s("Some other string");
      print(s);
   }

   {
      const int array[] = {1, 2, 3, 4, 5};
      print(array, array+5);
      print(array, 5);
   }


   return EXIT_SUCCESS;
}
