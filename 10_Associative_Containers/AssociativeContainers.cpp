/**************************************************************************************************
*
* \file AssociativeContainers.cpp
* \brief C++ Training - Associative Containers Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Investigate the different operations available on the associative containers.
*
**************************************************************************************************/

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>

// Here, you can also use std::unordered_map here
using Container = std::map<int,std::string>;


void print( const Container& container )
{
   // Accessing elements via iterator
   {
      for(const auto& element: container){
         std::cout << "(" << element.first << " : " << element.second << ")\n";
      }
      std::cout << "\n";
   }
}


int main()
{
   Container container{};

   // Adding elements to the container
   {
      // for both map and unordered_map, you will need to use make_pair
      // to make a pair of key and value
      container.insert(std::make_pair(2, "two"));
      container.insert(std::make_pair(1, "one"));
      container.insert(std::make_pair(3, "three"));

      // We can also use the sub-script operator to insert/access values in a map
      // The input to this sub-script is the key
      // But please use insert() to add elements since it is more conservative
      // than the sub-script notation
      container[4] = "four";

      print(container);
   }

   // Erasing elements from the container
   {
      // Use the member function find instead of using the one 
      // from "algorithm" header
      // "erase" takes iterator for the element
      container.erase(container.find(1));
      print(container);
   }

   // Assignment
   {
      Container container2;

      container2 = container;

      if(container != container2){
         std::cerr << "Invalid assignment!\n";
      }
   }

   // Swapping containers
   {
      Container container2;
      container2.insert(std::make_pair(4, "four"));
      container2.insert(std::make_pair(5, "five"));
      container2.insert(std::make_pair(6, "six"));

      std::swap(container, container2);
      std::cout << "Container: \n";
      print(container);

      std::cout << "\nContainer2 : \n";
      print(container2);
   }

   return EXIT_SUCCESS;
}
