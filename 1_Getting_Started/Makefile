#==================================================================================================
#
#  Makefile for chapter 1 of the C++ Training
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
default: Add Count FlowControl Multiply

Add: Add.cpp
	$(CXX) $(CXXFLAGS) -o Add Add.cpp

Count: Count.cpp
	$(CXX) $(CXXFLAGS) -o Count Count.cpp

FlowControl: FlowControl.cpp
	$(CXX) $(CXXFLAGS) -o FlowControl FlowControl.cpp

Multiply: Multiply.cpp
	$(CXX) $(CXXFLAGS) -o Multiply Multiply.cpp

clean:
	@$(RM) $(BIN)


# Setting the independent commands
.PHONY: default clean
