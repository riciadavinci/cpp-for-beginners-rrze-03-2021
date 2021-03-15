#==================================================================================================
#
#  Makefile for the C++ Training
#
#  Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
#
#  This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
#  context of the C++ training or with explicit agreement by Klaus Iglberger.
#
#==================================================================================================

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(Tasks CXX)

# use solution folders in Visual Studio
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

enable_testing()

add_subdirectory(1_Getting_Started)
add_subdirectory(2_Variables_and_Basic_Types)
add_subdirectory(3_Library_Types)
add_subdirectory(4_Expressions)
add_subdirectory(5_Statements)
add_subdirectory(6_Functions)
add_subdirectory(7_Generic_Algorithms)
add_subdirectory(8_Classes)
add_subdirectory(9_Sequence_Containers)
add_subdirectory(10_Associative_Containers)
add_subdirectory(11_Selecting_a_Container)
add_subdirectory(12_Dynamic_Memory)
add_subdirectory(13_Copy_Control)
add_subdirectory(14_Overloaded_Operations_and_Converions)
add_subdirectory(15_Templates)
add_subdirectory(16_Inheritance)
