/**************************************************************************************************
*
* \file SequenceContainers.cpp
* \brief C++ Training - Sequence Containers Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Investigate the different operations available on the sequence containers.
*
**************************************************************************************************/

#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <vector>


// Here, you can replace "vector" with "list" or "deque" as well
using Container = std::vector<int>;


void print( const Container& container )
{
   // Accessing elements via iterator
   {
      std::cout << "(";
      for( const auto& element : container){
         std::cout << element << ", ";
      }
      std::cout << ")\n";
   }

   // Accessing elements via subscript operator
   {
      // TODO
   }
}


int main()
{
   Container container{};

   // Adding elements to the container
   {
      // available on all sequence containers
      container.push_back(1);                

      // It is available only on "list" and "deque"
      // container.push_front(2);            
      
      // 1st argument is iterator, 2nd argument is the value
      // available on all containers
      // Cheap for list. Expensive for vector and deque
      container.insert(container.end(), 3);
   }

   // Erasing elements from the container
   {
      // available on all
      // It returns iterator to the last element
      // For empty containers, it causes undefined behaviour
      int back = container.back();

      // removes element at end/back
      container.pop_back();

      // removes element at front/start
      // available only in list & deque
      // container.pop_front();

      // available for all
      // removes element at the given container
      container.erase(container.begin());
   }

   // Resizing a container
   {  
      // available for all
      // changes the size of container
      container.resize(10);

      // available only for vector
      // It does not change the size of the vector, 
      // just changes the capacity of the vector
      container.reserve(100);

      // gives size of the container (How many elements does the container have)
      std::cout << container.size() << "\n";

      // gives capacity of the container 
      // (How many elements can the container have without needing to be reallocated)
      std::cout << container.capacity() << "\n";
   }

   // Assignment
   {
      // Copy constructor
      Container copied_container( container );

      // Copy assignment operator
      copied_container = container;

      if(copied_container == container){
         std::cout << "Assignment worked!\n";
      }
   }

   // Swapping containers
   {
      Container container2 {6, 7, 8};
      std::swap( container, container2);

      // afterwards, container will have {6, 7, 8}
      // and container2 will have elements of container
      // from before the swap!
   }

   return EXIT_SUCCESS;
}
