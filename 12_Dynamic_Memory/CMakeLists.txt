#==================================================================================================
#
#  CMakeLists for chapter 12 of the C++ Training
#
#  Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
#
#  This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
#  context of the C++ training or with explicit agreement by Klaus Iglberger.
#
#==================================================================================================

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

add_executable(AlignedAllocator
   AlignedAllocator.cpp
   )

add_executable(ArenaAllocator
   ArenaAllocator.cpp
   )

add_executable(NewDelete
   NewDelete.cpp
   )

add_executable(SharedPtr
   SharedPtr.cpp
   )

add_executable(SharedStringPtr
   SharedStringPtr.cpp
   )

add_executable(UniquePtr
   UniquePtr.cpp
   )

add_executable(UniqueStringPtr
   UniqueStringPtr.cpp
   )

set_target_properties(
   AlignedAllocator
   ArenaAllocator
   NewDelete
   SharedPtr
   SharedStringPtr
   UniquePtr
   UniqueStringPtr
   PROPERTIES
   FOLDER "12_Dynamic_Memory"
   )
