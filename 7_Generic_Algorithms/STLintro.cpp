/**************************************************************************************************
*
* \file STLintro.cpp
* \brief C++ Training - STL Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Solve the following tasks on a vector of integers by means of STL algorithms:
*       - Print the contents of the vector to the screen
*       - Reverse the order of elements in the vector
*       - Find the first element with the value 5
*       - Count the elements with the value 5
*       - Replace all 5s by 2s
*       - Sort the vector
*       - Determine the range of 2s
*
**************************************************************************************************/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>


using Ints = std::vector<int>;


void printToScreen( Ints const& ints )
{
   for(const auto i : ints){
      std::cout << " " << i;
   }
   std::cout << "\n";
}


void reverseOrder( Ints& ints )
{
   std::reverse(ints.begin(), ints.end());
   printToScreen(ints);
}


void findFirstFive( Ints const& ints )
{
   auto pos = std::find(ints.begin(), ints.end(), 5);
   // If iterator did not find the value, pos will take "end" value,
   // which is not valid. Hence, we need the following check
   if(pos != ints.end()){
      // Manually:
      // const auto dist = pos - ints.begin();

      // from Standard Library
      const auto dist = std::distance(ints.begin(), pos);
      
      // Here, the type of dist is ptrdiff_t: pointer difference
      // sort of similar to size_t

      std::cout << "Found the value " << *pos 
                << " at index: " << dist << "\n";
   } else {
      std::cout << "Did not find it!\n";
   }
   
}


void countNumberOfFives( Ints const& ints )
{
   const auto fives = std::count(ints.begin(), ints.end(), 5);
   // Here fives will be of type size_t
   std::cout << "Number of fives: " << fives << "\n";
}


void replaceAllFivesWithTwos( Ints& ints )
{
   std::replace(ints.begin(), ints.end(), 5, 2);
   printToScreen(ints);
}


void sortInts( Ints& ints )
{
   std::sort(ints.begin(), ints.end());
   printToScreen(ints);
}


void findAllTwos( Ints const& ints )
{
   // TODO
   // The functions "lower_bounds" and "upper_bounds"
   // they are combined into a function "equal_range"
   const auto range =  std::equal_range(ints.begin(), ints.end(), 2);
   // here, range of type pairs
   // the "first" will point to the first "2" and
   // the "second" will point to the element after last "2"
   // So, it returns both the "upper bound" and "lower bound" 

   std::cout << "First element: " << *(range.first) << "\n"
             << "Second element: " << *(range.second) << "\n";
}




int main()
{
   Ints ints{ 3, 6, 27, 5, 1, 8, 5, 4 };

   printToScreen( ints );
   reverseOrder( ints );
   findFirstFive( ints );
   countNumberOfFives( ints );
   replaceAllFivesWithTwos( ints );
   sortInts( ints );
   findAllTwos( ints );
}

