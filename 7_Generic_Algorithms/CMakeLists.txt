#==================================================================================================
#
#  CMakeLists for chapter 7 of the C++ Training
#
#  Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
#
#  This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
#  context of the C++ training or with explicit agreement by Klaus Iglberger.
#
#==================================================================================================

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

add_executable(Simpson
   Simpson.cpp
   )

add_executable(SimpsonPro
   SimpsonPro.cpp
   )

add_executable(STLintro
   STLintro.cpp
   )

add_executable(STLpro
   STLpro.cpp
   )

set_target_properties(
   Simpson
   SimpsonPro
   STLintro
   STLpro
   PROPERTIES
   FOLDER "7_Generic_Algorithms"
   )
