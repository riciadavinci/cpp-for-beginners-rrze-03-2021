#==================================================================================================
#
#  Makefile for chapter 10 of the C++ Training
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
default: AssociativeContainers Count2 Library2 Set

AssociativeContainers: AssociativeContainers.cpp
	$(CXX) $(CXXFLAGS) -o AssociativeContainers AssociativeContainers.cpp

Count2: Count2.cpp
	$(CXX) $(CXXFLAGS) -o Count2 Count2.cpp

Library2: Library2.cpp
	$(CXX) $(CXXFLAGS) -o Library2 Library2.cpp

Set: Set.cpp
	$(CXX) $(CXXFLAGS) -o Set Set.cpp

clean:
	@$(RM) $(BIN)


# Setting the independent commands
.PHONY: default clean
