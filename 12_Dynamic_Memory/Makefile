#==================================================================================================
#
#  Makefile for chapter 12 of the C++ Training
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
default: AlignedAllocator ArenaAllocator NewDelete SharedPtr SharedStringPtr \
         UniquePtr UniqueStringPtr

AlignedAllocator: AlignedAllocator.cpp
	$(CXX) $(CXXFLAGS) -o AlignedAllocator AlignedAllocator.cpp

ArenaAllocator: ArenaAllocator.cpp
	$(CXX) $(CXXFLAGS) -o ArenaAllocator ArenaAllocator.cpp

NewDelete: NewDelete.cpp
	$(CXX) $(CXXFLAGS) -o NewDelete NewDelete.cpp

SharedPtr: SharedPtr.cpp
	$(CXX) $(CXXFLAGS) -o SharedPtr SharedPtr.cpp

SharedStringPtr: SharedStringPtr.cpp
	$(CXX) $(CXXFLAGS) -o SharedStringPtr SharedStringPtr.cpp

UniquePtr: UniquePtr.cpp
	$(CXX) $(CXXFLAGS) -o UniquePtr UniquePtr.cpp

UniqueStringPtr: UniqueStringPtr.cpp
	$(CXX) $(CXXFLAGS) -o UniqueStringPtr UniqueStringPtr.cpp

clean:
	@$(RM) $(BIN)


# Setting the independent commands
.PHONY: default clean
