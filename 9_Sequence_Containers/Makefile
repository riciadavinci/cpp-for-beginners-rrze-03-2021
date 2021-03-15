#==================================================================================================
#
#  Makefile for chapter 9 of the C++ Training
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
default: Equal Insert SequenceContainers

Equal: Equal.cpp
	$(CXX) $(CXXFLAGS) -o Equal Equal.cpp

Insert: Insert.cpp
	$(CXX) $(CXXFLAGS) -o Insert Insert.cpp

SequenceContainers: SequenceContainers.cpp
	$(CXX) $(CXXFLAGS) -o SequenceContainers SequenceContainers.cpp

clean:
	@$(RM) $(BIN)


# Setting the independent commands
.PHONY: default clean
