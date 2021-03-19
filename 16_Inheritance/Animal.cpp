/**************************************************************************************************
*
* \file Animal.cpp
* \brief C++ Training - Example for an Inheritance Hierarchy
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Implement an 'Animal' hierarchy. Provide the following function in the 'Animal' base class:
*         - a virtual destructor
*         - a non-virtual 'name()' function returning the name of the animal as string
*         - a virtual 'feet()' function returning the number of feet of the animal
*         - a pure virtual 'noise()' function printing the characteristic animal noise
*       Implement at least two different derived classes that implement the 'Animal' base class
*       and create instances of them in the 'main()' function.
*
**************************************************************************************************/

#include <iostream>
#include <memory>
#include <string>
#include <vector>


// TODO: Implement the 'Animal base class and at least two deriving classes
class Animal {
private:
   std::string name_;

public:
   explicit Animal(const std::string& name)
      : name_ { name }
   {}

   Animal(const std::string&& name)
      : name_ { name }
   {}

   virtual ~Animal() = default;

   const std::string& name() const { return name_; }
   virtual unsigned int feet() const { return 4; }
   virtual void noise() = 0;
};


class Dog: public Animal {

public:
   Dog()
      : Animal("Dog")
   {}

   ~Dog(){}

   void noise() override {std::cout << "woof woof!\n"; }
   void wag_tail() {std::cout << "wag wag\n"; }
};


class Snake: public Animal {

public:
   Snake()
      : Animal("Snake")
   {}

   unsigned int feet() const override { return 0; }
   void noise() override {std::cout << "Hisssssssssssssss!\n"; }
};


class Spider: public Animal {

public:
   Spider()
      : Animal("Spider")
   {}

   unsigned int feet() const override { return 8; }
   void noise() override {std::cout << "Kchhhh!\n"; }
};


int main()
{
   std::vector<std::unique_ptr<Animal>> animals;

   animals.push_back(std::unique_ptr<Animal>(new Dog()));
   animals.push_back(std::unique_ptr<Animal>(new Snake()));
   animals.push_back(std::unique_ptr<Animal>(new Spider()));

   for (const auto& animal : animals){
      animal->noise();
   }

   return EXIT_SUCCESS;
}
