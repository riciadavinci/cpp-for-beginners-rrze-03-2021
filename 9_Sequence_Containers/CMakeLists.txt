#==================================================================================================
#
#  CMakeLists for chapter 9 of the C++ Training
#
#  Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
#
#  This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
#  context of the C++ training or with explicit agreement by Klaus Iglberger.
#
#==================================================================================================

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

add_executable(Equal
   Equal.cpp
   )

add_executable(Insert
   Insert.cpp
   )

add_executable(SequenceContainers
   SequenceContainers.cpp
   )

set_target_properties(
   Equal
   Insert
   SequenceContainers
   PROPERTIES
   FOLDER "9_Sequence_Containers"
   )
