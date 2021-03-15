#==================================================================================================
#
#  CMakeLists for chapter 10 of the C++ Training
#
#  Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
#
#  This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
#  context of the C++ training or with explicit agreement by Klaus Iglberger.
#
#==================================================================================================

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

add_executable(AssociativeContainers
   AssociativeContainers.cpp
   )

add_executable(Count2
   Count2.cpp
   )

add_executable(Library2
   Library2.cpp
   )

add_executable(Set
   Set.cpp
   )

set_target_properties(
   AssociativeContainers
   Count2
   Library2
   Set
   PROPERTIES
   FOLDER "10_Associative_Containers"
   )
