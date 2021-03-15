#==================================================================================================
#
#  CMakeLists for chapter 13 of the C++ Training
#
#  Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
#
#  This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
#  context of the C++ training or with explicit agreement by Klaus Iglberger.
#
#==================================================================================================

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

add_executable(Library3
   Library3.cpp
   )

add_executable(String
   String.cpp
   )

add_executable(StringVector1
   StringVector1.cpp
   )

add_executable(StringVector2
   StringVector2.cpp
   )

add_executable(StringVector3
   StringVector3.cpp
   )

add_executable(Swap2
   Swap2.cpp
   )

set_target_properties(
   Library3
   String
   StringVector1
   StringVector2
   StringVector3
   Swap2
   PROPERTIES
   FOLDER "13_Copy_Control"
   )
