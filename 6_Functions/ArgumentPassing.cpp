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

   // s = "Changed string"; // This will not work!
}

// Write a function that takes its argument by pointer
// TODO

// Write a function that takes its argument by pointer-to-const
// TODO


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
      // TODO
   }

   // Pass-by-pointer-to-const
   {
      // TODO
   }

   return EXIT_SUCCESS;
}
