#==================================================================================================
#
#  Makefile for chapter 5 of the C++ Training
#
#  Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
#
#  This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
#  context of the C++ training or with explicit agreement by Klaus Iglberger.
#
#==================================================================================================


# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17


# Setting the source and binary files
SRC = $(wildcard *.cpp)
BIN = $(SRC:.cpp=)


# Rules
default: Grades Prefix1

Grades: Grades.cpp
	$(CXX) $(CXXFLAGS) -o Grades Grades.cpp

Prefix1: Prefix1.cpp
	$(CXX) $(CXXFLAGS) -o Prefix1 Prefix1.cpp

clean:
	@$(RM) $(BIN)


# Setting the independent commands
.PHONY: default clean
