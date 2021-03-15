#==================================================================================================
#
#  CMakeLists for chapter 4 of the C++ Training
#
#  Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
#
#  This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
#  context of the C++ training or with explicit agreement by Klaus Iglberger.
#
#==================================================================================================

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

add_executable(ArithmeticOperators
   ArithmeticOperators.cpp
   )

add_executable(BitwiseOperators
   BitwiseOperators.cpp
   )

add_executable(Conversions
   Conversions.cpp
   )

add_executable(LogicalOperators
   LogicalOperators.cpp
   )

add_executable(Odd
   Odd.cpp
   )

add_executable(RelationalOperators
   RelationalOperators.cpp
   )

add_executable(Size2
   Size2.cpp
   )

set_target_properties(
   ArithmeticOperators
   BitwiseOperators
   Conversions
   LogicalOperators
   Odd
   RelationalOperators
   Size2
   PROPERTIES
   FOLDER "4_Expressions"
   )
