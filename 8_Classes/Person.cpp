/**************************************************************************************************
*
* \file Person.cpp
* \brief C++ Training - Class Design Programming Task
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Write a 'Person' class to represent a person with a firstname, a lastname and an age.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>


//--Person.h---------------------------------------------------------------------------------------

// TODO: Implement the 'Person' class

class Person{
public:
   // Default constructor (that the compiler gives us)
   // Person() = default; 
   
   // Member initializer list constructor (here, we define this as default)
   Person()
      : firstname_{"John"}
      , lastname_{"Doe"}
      , age_{35}
   {}

   // Member initializer list constructor (self-defined)
   // The implementation details are in the Person.cpp source file
   Person(const std::string& firstname, const std::string& lastname, int age);

   // destructor
   ~Person() = default;

   // copy constructor
   Person( const Person& ) = default;

   // assignment operator overload
   Person& operator=( const Person& ) = default;

   // Getter Functions
   // Help us get data members which may be private
   const std::string& firstname() const {return firstname_;}
   const std::string& lastname() const {return lastname_;}
   int age() const { return age_; }

   // Setter Functions
   // Help is set/update data member values
   // It returns void
   // Note that this function is not const (after function signature),
   // this is because it does mutate/change the data-members of this class
   void firstname(const std::string& name); // Defined within the Person.cpp file
   void lastname(const std::string& name){ lastname_ = name; }

   static void defaultFirstname(const std::string& firstname) { defaultFirstname_ = firstname; }
   static void defaultLastname (const std::string& lastname ) { defaultFirstname_ = lastname; }

private:
   std::string firstname_;
   std::string lastname_;
   int age_;

   static std::string defaultFirstname_;
   static std::string defaultLastname_;

/*
// In-class initializer:
// Used when default constructor is called, or even in the case when it is 
// not defined at all. Thus avoid using default values within multiple constructors
// and just set it where the data-members are defined. They will work even the 
// compiler uses it's own default constructor.
// Thus, you can just write: Person() = default;
// This will help to have a constructor with no/default arguments, like when you create an
// an array of this class.
Person(){}
private:
   std::string firstname_ = "John";
   std::string lastname_ = "Doe";
   int age_ = 35;
public:
   Person() = default;
};
*/

};


std::ostream& operator<<(std::ostream& os, const Person& p){
   os << p.firstname() << " " << p.lastname() << ", age: " << p.age();
   return os;
}




//--Person.cpp-------------------------------------------------------------------------------------

// Static data members of a class need to defined only once in a source file
std::string Person::defaultFirstname_ {"John"};
std::string Person::defaultLastname_ {"Doe"};

// This is the definition of the class constructor in say a Person.cpp file
// The "Person::" tells the compiler that this function belongs to the Person class 
Person::Person(const std::string& firstname, const std::string& lastname, int age)
   : firstname_ {firstname}
   , lastname_ {lastname}
   , age_ {age}
{}

void Person::firstname(const std::string& name){ lastname_ = name; }

//--Main.cpp---------------------------------------------------------------------------------------

int main()
{
   Person bjarne("Bjarne", "Stroustrup", 71);

   const std::string firstname = bjarne.firstname();

   std::cout << bjarne << "\n";

   // This will call the copy constructor
   Person cloneOfBjarne(bjarne);

   Person clone2OfBjarne;
   clone2OfBjarne = bjarne;   // This will call the copy assignment operator

   return EXIT_SUCCESS;
}
