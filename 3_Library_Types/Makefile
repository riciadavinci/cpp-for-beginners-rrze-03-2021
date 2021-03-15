#==================================================================================================
#
#  Makefile for chapter 3 of the C++ Training
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
default: ArrayToVector CompareStrings Hexadecimal MinMax PointerToArray ReadStrings SortWords

ArrayToVector: ArrayToVector.cpp
	$(CXX) $(CXXFLAGS) -o ArrayToVector ArrayToVector.cpp

CompareStrings: CompareStrings.cpp
	$(CXX) $(CXXFLAGS) -o CompareStrings CompareStrings.cpp

Hexadecimal: Hexadecimal.cpp
	$(CXX) $(CXXFLAGS) -o Hexadecimal Hexadecimal.cpp

MinMax: MinMax.cpp
	$(CXX) $(CXXFLAGS) -o MinMax MinMax.cpp

PointerToArray: PointerToArray.cpp
	$(CXX) $(CXXFLAGS) -o PointerToArray PointerToArray.cpp

ReadStrings: ReadStrings.cpp
	$(CXX) $(CXXFLAGS) -o ReadStrings ReadStrings.cpp

SortWords: SortWords.cpp
	$(CXX) $(CXXFLAGS) -o SortWords SortWords.cpp

clean:
	@$(RM) $(BIN)


# Setting the independent commands
.PHONY: default clean
