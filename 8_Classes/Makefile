#==================================================================================================
#
#  Makefile for chapter 8 of the C++ Training
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
OBJ = $(SRC:.cpp=.o)
BIN = $(SRC:.cpp=)


# Rules
default: Library1 Main ConstCorrectness Person

Library1: Library1.cpp
	$(CXX) $(CXXFLAGS) -o Library1 Library1.cpp

Main: Main.cpp Author.o Book.o Currency.o ISBN.o Price.o

ConstCorrectness: ConstCorrectness.cpp
	$(CXX) $(CXXFLAGS) -o ConstCorrectness ConstCorrectness.cpp

Person: Person.cpp
	$(CXX) $(CXXFLAGS) -o Person Person.cpp

clean:
	@$(RM) $(OBJ) $(BIN)


# Setting the independent commands
.PHONY: default clean
