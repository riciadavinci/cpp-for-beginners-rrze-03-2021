#==================================================================================================
#
#  Makefile for chapter 2 of the C++ Training
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
default: Integrals Pointers References Size1

Integrals: Integrals.cpp
	$(CXX) $(CXXFLAGS) -o Integrals Integrals.cpp

Pointers: Pointers.cpp
	$(CXX) $(CXXFLAGS) -o Pointers Pointers.cpp

References: References.cpp
	$(CXX) $(CXXFLAGS) -o References References.cpp

Size1: Size1.cpp
	$(CXX) $(CXXFLAGS) -o Size1 Size1.cpp

clean:
	@$(RM) $(BIN)


# Setting the independent commands
.PHONY: default clean
