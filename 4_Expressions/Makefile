#==================================================================================================
#
#  Makefile for chapter 4 of the C++ Training
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
default: ArithmeticOperators BitwiseOperators Conversions LogicalOperators \
         Odd RelationalOperators Size2

ArithmeticOperators: ArithmeticOperators.cpp
	$(CXX) $(CXXFLAGS) -o ArithmeticOperators ArithmeticOperators.cpp

BitwiseOperators: BitwiseOperators.cpp
	$(CXX) $(CXXFLAGS) -o BitwiseOperators BitwiseOperators.cpp

Conversions: Conversions.cpp
	$(CXX) $(CXXFLAGS) -o Conversions Conversions.cpp

LogicalOperators: LogicalOperators.cpp
	$(CXX) $(CXXFLAGS) -o LogicalOperators LogicalOperators.cpp

Odd: Odd.cpp
	$(CXX) $(CXXFLAGS) -o Odd Odd.cpp

RelationalOperators: RelationalOperators.cpp
	$(CXX) $(CXXFLAGS) -o RelationalOperators RelationalOperators.cpp

Size2: Size2.cpp
	$(CXX) $(CXXFLAGS) -o Size2 Size2.cpp

clean:
	@$(RM) $(BIN)


# Setting the independent commands
.PHONY: default clean
