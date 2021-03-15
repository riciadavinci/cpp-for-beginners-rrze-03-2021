#==================================================================================================
#
#  CMakeLists for chapter 1 of the C++ Training
#
#  Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
#
#  This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
#  context of the C++ training or with explicit agreement by Klaus Iglberger.
#
#==================================================================================================

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

add_executable(Add
   Add.cpp
   )

add_executable(Count
   Count.cpp
   )

add_executable(FlowControl
   FlowControl.cpp
   )

add_executable(Multiply
   Multiply.cpp
   )

set_target_properties(
   Add
   Count
   FlowControl
   Multiply
   PROPERTIES
   FOLDER "1_Getting_Started"
   )
