#==================================================================================================
#
#  Makefile for chapter 14 of the C++ Training
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
default: Assignment Function1 Library4 Subscript

Assignment: Assignment.cpp
	$(CXX) $(CXXFLAGS) -o Assignment Assignment.cpp

Function1: Function1.cpp
	$(CXX) $(CXXFLAGS) -o Function1 Function1.cpp

Library4: Library4.cpp
	$(CXX) $(CXXFLAGS) -o Library4 Library4.cpp

Subscript: Subscript.cpp
	$(CXX) $(CXXFLAGS) -o Subscript Subscript.cpp

clean:
	@$(RM) $(BIN)


# Setting the independent commands
.PHONY: default clean
