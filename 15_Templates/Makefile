#==================================================================================================
#
#  Makefile for chapter 15 of the C++ Training
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
default: ArraySize Compare Find Library5 Max Print Specialization1 \
         Specialization2 UniqueStringPtr2 Vector1 Vector2

ArraySize: ArraySize.cpp
	$(CXX) $(CXXFLAGS) -o ArraySize ArraySize.cpp

Compare: Compare.cpp
	$(CXX) $(CXXFLAGS) -o Compare Compare.cpp

Find: Find.cpp
	$(CXX) $(CXXFLAGS) -o Find Find.cpp

Library5: Library5.cpp
	$(CXX) $(CXXFLAGS) -o Library5 Library5.cpp

Max: Max.cpp
	$(CXX) $(CXXFLAGS) -o Max Max.cpp

Print: Print.cpp
	$(CXX) $(CXXFLAGS) -o Print Print.cpp

Specialization1: Specialization1.cpp
	$(CXX) $(CXXFLAGS) -o Specialization1 Specialization1.cpp

Specialization2: Specialization2.cpp
	$(CXX) $(CXXFLAGS) -o Specialization2 Specialization2.cpp

UniqueStringPtr2: UniqueStringPtr2.cpp
	$(CXX) $(CXXFLAGS) -o UniqueStringPtr2 UniqueStringPtr2.cpp

Vector1: Vector1.cpp
	$(CXX) $(CXXFLAGS) -o Vector1 Vector1.cpp

Vector2: Vector2.cpp
	$(CXX) $(CXXFLAGS) -o Vector2 Vector2.cpp

clean:
	@$(RM) $(BIN)


# Setting the independent commands
.PHONY: default clean
