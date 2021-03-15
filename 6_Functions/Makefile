#==================================================================================================
#
#  Makefile for chapter 6 of the C++ Training
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
default: ArgumentPassing Factorial InitializerList1 InitializerList2 \
         Overloading Prefix2 Swap1 Uppercase1 Uppercase2

ArgumentPassing: ArgumentPassing.cpp
	$(CXX) $(CXXFLAGS) -o ArgumentPassing ArgumentPassing.cpp

Factorial: Factorial.cpp
	$(CXX) $(CXXFLAGS) -o Factorial Factorial.cpp

InitializerList1: InitializerList1.cpp
	$(CXX) $(CXXFLAGS) -o InitializerList1 InitializerList1.cpp

InitializerList2: InitializerList2.cpp
	$(CXX) $(CXXFLAGS) -o InitializerList2 InitializerList2.cpp

Overloading: Overloading.cpp
	$(CXX) $(CXXFLAGS) -o Overloading Overloading.cpp

Prefix2: Prefix2.cpp
	$(CXX) $(CXXFLAGS) -o Prefix2 Prefix2.cpp

Swap1: Swap1.cpp
	$(CXX) $(CXXFLAGS) -o Swap1 Swap1.cpp

Uppercase1: Uppercase1.cpp
	$(CXX) $(CXXFLAGS) -o Uppercase1 Uppercase1.cpp

Uppercase2: Uppercase2.cpp
	$(CXX) $(CXXFLAGS) -o Uppercase2 Uppercase2.cpp

clean:
	@$(RM) $(BIN)


# Setting the independent commands
.PHONY: default clean
