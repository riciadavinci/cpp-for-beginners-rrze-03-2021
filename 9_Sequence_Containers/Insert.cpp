/**************************************************************************************************
*
* \file Equal.cpp
* \brief C++ Training - Sequence Containers Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Write a program to read in two strings at a time. Find the first string in a
*       list<string> and insert the second string immediately after the first one. If the first
*       string isn't found, insert the second string at the end of the list. Finally, copy the
*       final list<string> into a vector<string>. Now sort both the list and the vector and
*       assert that their content is equal.
*
**************************************************************************************************/

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>


int main()
{
   std::list<std::string> lwords;
   std::string s1, s2;

   while(std::cin >> s1 >> s2){
      // TODO: Insert strings into the list
      const auto pos = std::find(lwords.begin(), lwords.end(), s1);
      if(pos == lwords.end()){
         lwords.push_back(s2);
      }
      else {
         // If you didn't use const, you could also do
         // (++pos) instead of std::next(pos) to get
         // the next iterator
         lwords.insert(std::next(pos), s2);
      }
   }
   for(const auto& element: lwords){
      std::cout << "\"" << element << "\" ";
   }
   std::cout << "\n";

   // TODO: Copy the list into a vector
   std::vector<std::string> vwords(lwords.size());
   std::copy(lwords.begin(),lwords.end(), vwords.begin());
   
   // TODO: Compare the list and the vector
   if(std::equal(lwords.begin(), lwords.end(), vwords.begin(), vwords.end())){
      std::cout << "Success: Vector and list are equal!\n";
   }
   else {
      std::cout << "Failure: Vector and list are NOT equal!\n";
   }
   

   return EXIT_SUCCESS;
}
