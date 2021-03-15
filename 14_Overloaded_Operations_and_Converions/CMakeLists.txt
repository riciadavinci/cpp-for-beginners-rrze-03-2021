#==================================================================================================
#
#  CMakeLists for chapter 14 of the C++ Training
#
#  Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
#
#  This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
#  context of the C++ training or with explicit agreement by Klaus Iglberger.
#
#==================================================================================================

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

add_executable(Assignment
   Assignment.cpp
   )

add_executable(Library4
   Library4.cpp
   )

add_executable(Function1
   Function1.cpp
   )

add_executable(Subscript
   Subscript.cpp
   )

set_target_properties(
   Assignment
   Function1
   Library4
   Subscript
   PROPERTIES
   FOLDER "14_Overloaded_Operations_and_Converions"
   )
