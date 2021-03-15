#==================================================================================================
#
#  Makefile for chapter 13 of the C++ Training
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
default: Library3 String StringVector1 StringVector2 StringVector3 Swap2

Library3: Library3.cpp
	$(CXX) $(CXXFLAGS) -o Library3 Library3.cpp

String: String.cpp
	$(CXX) $(CXXFLAGS) -o String String.cpp

StringVector1: StringVector1.cpp
	$(CXX) $(CXXFLAGS) -o StringVector1 StringVector1.cpp

StringVector2: StringVector2.cpp
	$(CXX) $(CXXFLAGS) -o StringVector2 StringVector2.cpp

StringVector3: StringVector3.cpp
	$(CXX) $(CXXFLAGS) -o StringVector3 StringVector3.cpp

Swap2: Swap2.cpp
	$(CXX) $(CXXFLAGS) -o Swap2 Swap2.cpp

clean:
	@$(RM) $(BIN)


# Setting the independent commands
.PHONY: default clean
