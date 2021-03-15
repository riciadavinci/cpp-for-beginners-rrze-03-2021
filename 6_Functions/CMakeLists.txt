#==================================================================================================
#
#  CMakeLists for chapter 6 of the C++ Training
#
#  Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
#
#  This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
#  context of the C++ training or with explicit agreement by Klaus Iglberger.
#
#==================================================================================================

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

add_executable(ArgumentPassing
   ArgumentPassing.cpp
   )

add_executable(Factorial
   Factorial.cpp
   )

add_executable(InitializerList1
   InitializerList1.cpp
   )

add_executable(InitializerList2
   InitializerList2.cpp
   )

add_executable(Overloading
   Overloading.cpp
   )

add_executable(Prefix2
   Prefix2.cpp
   )

add_executable(Swap1
   Swap1.cpp
   )

add_executable(Uppercase1
   Uppercase1.cpp
   )

add_executable(Uppercase2
   Uppercase2.cpp
   )

set_target_properties(
   ArgumentPassing
   Factorial
   InitializerList1
   InitializerList2
   Overloading
   Prefix2
   Swap1
   Uppercase1
   Uppercase2
   PROPERTIES
   FOLDER "6_Functions"
   )
