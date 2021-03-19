#==================================================================================================
#
#  Makefile for chapter 16 of the C++ Training
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
default: Animal Command Function2 Library6 Observer Prototype Shape ShapeStrategy Strategy Visitor

Animal: Animal.cpp
	$(CXX) $(CXXFLAGS) -o Animal Animal.cpp

Command: Command.cpp
	$(CXX) $(CXXFLAGS) -o Command Command.cpp

Function2: Function2.cpp
	$(CXX) $(CXXFLAGS) -o Function2 Function2.cpp

Library6: Library6.cpp
	$(CXX) $(CXXFLAGS) -o Library6 Library6.cpp

Observer: Observer.cpp
	$(CXX) $(CXXFLAGS) -o Observer Observer.cpp

Prototype: Prototype.cpp
	$(CXX) $(CXXFLAGS) -o Prototype Prototype.cpp

Shape: Shape.cpp
	$(CXX) $(CXXFLAGS) -o Shape Shape.cpp

ShapeStrategy: ShapeStrategy.cpp
	$(CXX) $(CXXFLAGS) -o ShapeStrategy ShapeStrategy.cpp

Strategy: Strategy.cpp
	$(CXX) $(CXXFLAGS) -o Strategy Strategy.cpp

Visitor: Visitor.cpp
	$(CXX) $(CXXFLAGS) -o Visitor Visitor.cpp

clean:
	@$(RM) $(BIN)


# Setting the independent commands
.PHONY: default clean
