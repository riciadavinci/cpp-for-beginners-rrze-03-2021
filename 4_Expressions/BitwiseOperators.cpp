/**************************************************************************************************
*
* \file BitwiseOperators.cpp
* \brief C++ Training - Programming Exercise about the bitwise operators
*
* Copyright (C) 2015-2021 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Use all of the bitwise operators: Bitwise NOT, left-shift, right-shift, bitwise AND,
*       bitwise OR, and bitwise XOR.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>


// Hexadecimal | Decimal | Binary
//     0       |    0    |  0000
//     1       |    1    |  0001
//     2       |    2    |  0010
//     3       |    3    |  0011
//     4       |    4    |  0100
//     5       |    5    |  0101
//     6       |    6    |  0110
//     7       |    7    |  0111
//     8       |    8    |  1000
//     9       |    9    |  1001
//     A       |   10    |  1010
//     B       |   11    |  1011
//     C       |   12    |  1100
//     D       |   13    |  1101
//     E       |   14    |  1110
//     F       |   15    |  1111


int main()
{
   unsigned int i = 0b01100101;  // or 101 (decimal) or 0x65 (hexadecimal)
   unsigned int j = 0b10101111;  // or 175 (decimal) or 0xAF (hexadecimal)

   // Bitwise NOT
   unsigned int k = ~i;
   std::cout << "~i : " << std::hex << k << "\n";

   // Left-shift
   k = (i << 1);
   std::cout << "i << 1 : " << std::hex << k << "\n";

   // Right-shift
   k = (i >> 1);
   std::cout << "i >> 1 : " << std::hex << k << "\n";

   // Bitwise AND
   k = (i & j);
   std::cout << "i & j : " << std::hex << k << "\n";

   // Bitwise OR
   k = (i | j);
   std::cout << "i | j : " << std::hex << k << "\n";

   // Bitwise XOR
   k = (i ^ j);
   std::cout << "i ^ j : " << std::hex << k << "\n";

   return EXIT_SUCCESS;
}

