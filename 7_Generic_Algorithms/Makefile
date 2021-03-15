#==================================================================================================
#
#  Makefile for chapter 7 of the C++ Training
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
default: Simpson SimpsonPro STLintro STLpro

Simpson: Simpson.cpp
	$(CXX) $(CXXFLAGS) -o Simpson Simpson.cpp

SimpsonPro: SimpsonPro.cpp
	$(CXX) $(CXXFLAGS) -o SimpsonPro SimpsonPro.cpp

STLintro: STLintro.cpp
	$(CXX) $(CXXFLAGS) -o STLintro STLintro.cpp

clean:
	@$(RM) $(BIN)


# Setting the independent commands
.PHONY: default clean
