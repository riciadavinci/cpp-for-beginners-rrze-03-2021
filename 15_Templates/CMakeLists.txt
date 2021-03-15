#==================================================================================================
#
#  CMakeLists for chapter 15 of the C++ Training
#
#  Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
#
#  This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
#  context of the C++ training or with explicit agreement by Klaus Iglberger.
#
#==================================================================================================

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

add_executable(ArraySize
   ArraySize.cpp
   )

add_executable(Compare
   Compare.cpp
   )

add_executable(Find
   Find.cpp
   )

add_executable(Library5
   Library5.cpp
   )

add_executable(Max
   Max.cpp
   )

add_executable(Print
   Print.cpp
   )

add_executable(Specialization1
   Specialization1.cpp
   )

add_executable(Specialization2
   Specialization2.cpp
   )

add_executable(UniqueStringPtr2
   UniqueStringPtr2.cpp
   )

add_executable(Vector1
   Vector1.cpp
   )

add_executable(Vector2
   Vector2.cpp
   )

set_target_properties(
   ArraySize
   Compare
   Find
   Library5
   Max
   Print
   Specialization1
   Specialization2
   UniqueStringPtr2
   Vector1
   Vector2
   PROPERTIES
   FOLDER "15_Templates"
   )
