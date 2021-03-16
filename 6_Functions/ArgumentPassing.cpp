/**************************************************************************************************
*
* \file ArgumentPassing.cpp
* \brief C++ Training - Programming Task about the different forms of argument passing
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Try out the different kinds of argument passing: Pass-by-value, pass-by-reference,
*       pass-by-reference-to-const, pass-by-pointer, and pass-by-pointer-to-const.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>


// Write a function that takes its argument by value
void passByValue(std::string s){
   // This is SLOWER since we copy whole object
   // But it is SAFER since we CANNOT EDIT the original object
   s = "Changed string";
}

// Write a function that takes its argument by reference
void passByReference(std::string& s){
   // This is FASTER since we pass the reference of the object
   // But it is LESS SAFER since we CAN EDIT the original object
   s = "Changed string";
}

// Write a function that takes its argument by reference-to-const
void passByReferenceToConst(const std::string& s){
   // This is best of both worlds!
   // It is not only FAST, but also PREVENTS us from EDITING
   // the original object
   // This can be done 90% of the time

   // s = "Changed string"; // This will not work!
}

// The above function can also be written as:
void passByReference(const std::string& s){/* ... */}

// Write a function that takes its argument by pointer
void passByPointer(std::string* s){
   if(s != nullptr){
      // Then do stuff!
      // ex:
      *s = "Changed string";
   }
}

// Write a function that takes its argument by pointer-to-const
void passByPointerToConst(const std::string* s){
   if(s != nullptr){
      // even if pointer to obj is not null, we cannot change it
      // since it is a pointer to const object (immutable object)
      // Ex.:
      // *s = "Changed String";     // This won't work!
   }
}


int main()
{
   // Pass-by-value
   {
      std::string s("Original String");
      passByValue(s);
      std::cout << "s = " << s << "\n";
   }

   // Pass-by-reference
   {
      std::string s("Original String");
      passByReference(s);
      std::cout << "s = " << s << "\n";
   }

   // Pass-by-reference-to-const
   {
      std::string s("Original String");
      passByReferenceToConst(s);
      std::cout << "s = " << s << "\n";
   }

   // Pass-by-pointer
   {
      std::string s("Original String");
      passByPointer(&s);
      std::cout << "s = " << s << "\n";
   }

   // Pass-by-pointer-to-const
   {
      std::string s("Original String");
      passByPointerToConst(&s);
      std::cout << "s = " << s << "\n";
   }

   return EXIT_SUCCESS;
}
