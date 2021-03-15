#==================================================================================================
#
#  CMakeLists for chapter 3 of the C++ Training
#
#  Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
#
#  This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
#  context of the C++ training or with explicit agreement by Klaus Iglberger.
#
#==================================================================================================

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

add_executable(ArrayToVector
   ArrayToVector.cpp
   )

add_executable(CompareStrings
   CompareStrings.cpp
   )

add_executable(Hexadecimal
   Hexadecimal.cpp
   )

add_executable(MinMax
   MinMax.cpp
   )

add_executable(PointerToArray
   PointerToArray.cpp
   )

add_executable(ReadStrings
   ReadStrings.cpp
   )

add_executable(SortWords
   SortWords.cpp
   )

set_target_properties(
   ArrayToVector
   CompareStrings
   Hexadecimal
   MinMax
   PointerToArray
   ReadStrings
   SortWords
   PROPERTIES
   FOLDER "3_Library_Types"
   )
