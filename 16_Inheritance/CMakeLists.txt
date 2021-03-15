#==================================================================================================
#
#  CMakeLists for chapter 16 of the C++ Training
#
#  Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
#
#  This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
#  context of the C++ training or with explicit agreement by Klaus Iglberger.
#
#==================================================================================================

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

add_executable(Animal
   Animal.cpp
   )

add_executable(Command
   Command.cpp
   )

add_executable(Function2
   Function2.cpp
   )

add_executable(Library6
   Library6.cpp
   )

add_executable(Observer
   Observer.cpp
   )

add_executable(Prototype
   Prototype.cpp
   )

add_executable(Shape
   Shape.cpp
   )

add_executable(Strategy
   Strategy.cpp
   )

add_executable(Visitor
   Visitor.cpp
   )

set_target_properties(
   Animal
   Command
   Function2
   Library6
   Observer
   Prototype
   Shape
   Strategy
   Visitor
   PROPERTIES
   FOLDER "16_Inheritance"
   )
