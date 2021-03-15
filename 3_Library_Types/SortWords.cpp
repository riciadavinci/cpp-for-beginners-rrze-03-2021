/**************************************************************************************************
*
* \file SortWords.cpp
* \brief C++ Training - Exercise for the std::vector library class
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Read in a vector of words via std::cin, sort them, and print them in lines of 4 words.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>


int main()
{
   std::vector<std::string> words;

   {
      // Keeping this string within this scope to compartmentalize the code
      std::string input;
      // Reading in an arbitrary number of words
      while(std::cin >> input){
         words.push_back(input);
      }
   }

   // Sorting the vector of words
   // my implementation:
   /*
   for(int i = 0; i < words.size()-1; ++i){
      for(int j = 0; j < words.size()-1; ++j){
         if(words[j] > words[j+1]){
            std::string temp = words[j];
            words[j] = words[j+1];
            words[j+1] = temp; 
         }
      }
   }
   */

   // Implementation by Klaus Iglberger
   // Again using Scope to compartmentalize the code
   {
      const size_t size(words.size());
      for(size_t i = 0U; i < size; ++i){
         for(size_t j = i + 1U; j < size; ++j){
            // Swap Algorithm
            if(words[j] < words[i]){
               std::string tmp(words[j]);
               words[j] = words[i];
               words[i] = tmp;

               // Alternatively you could also use: std::swap(words[i], words[j]);
            }
         }
      }
   }

   // Printing the vector of words
   {
      std::cout << "The sorted \"words\" vector: \n";
      
      // C-Style Indexing Syntax:
      for(int i = 0; i < words.size(); ++i){
         std::cout << words[i] << "\n";
      }
      
      // Using iterator to loop over the sorted vector
      for(auto it = words.begin(); it != words.end(); ++it){
         std::cout << *it << "\n";
      }

      // List Syntax
      // (You can also use auto& instead of std::string& here)
      for(const std::string& word: words){
         std::cout << word << "\n";
      }

   }

   return EXIT_SUCCESS;
}
