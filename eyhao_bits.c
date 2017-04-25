/* 
 * CS:APP Data Lab 
 * 
 * Emily Hao, user id: eyhao 
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void) {
  int odd = ( 0xAA << 8) | 0xAA; 
  odd = odd + (odd << 16); 
  return (odd); 
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
  // if x = tmin, x+x = 0, !0 = 1, (!!(x)) = 1; and 1 & 1 = 1; 
  // if x != tmin, !(x+x) = 0; !!(x) = 1; and 1 & 0 = 0; 
  return !(x+x) & !!(x); 
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  // ~(x &y) shows the similarity 
  // ~(~x) & (~y) shows the differences 
  // & joins them together and works as XOR 
  return (~(x & y)) & ( ~((~x) & (~y)));
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
   //
int conditional(int x, int y, int z) {
  // setting x to either 1 or 0;
  x = !!x; 
  // setting x to either all 1 or all 0; 
  x = ~x + 1; 
  // choose either y or z; 
  return (x & y) | (~x & z); 
}
/* 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */
int greatestBitPos(int x) {
  // shift 32 bits 
  int a = x | (x>>1); 
  int b = a | (a>>2); 
  int c = b | (b>>4); 
  int d = c | (c>>8); 
  int e = d | (d>>16); 
  // the one with 1 will be show itself 
  int f = e ^ (e>>1); 
  // special case 
  int mask = ~0; 
  // two cases 
  return (((!f + mask) &f) | ((!!f + mask) & (1 << 31))) & e;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    // the sign 
    int sign = x >> 31;
    //create a mask that is contains n 0's and rest are 1's  
    int mask = ( 1 << n) + ~0;  
    // and sign and mask 
    int y = sign & mask; 
    return (x+y) >> n ;
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
  // either 1 or 0 base on the sign of the integer
  return !(x >> 31);
}
/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x60000000) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x) {
  // set tmin; 
  int tmin = 0x1 << 31; 
  // get the sign 
  int sign = x >> 31; 
  // normal answer 
  int twox = x + x ; 
  // too big 
  int toobig = (x ^ twox) >> 31;
  
  int sat2 = toobig & (sign ^ ~tmin);
  // either normal answer
  return (sat2) | (~toobig & twox);
}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
  // masking using two's completement 
  int mask = x + (~y + 1) ;
  // case 1 
  int case1 = x & (~y); 
  // case 2 
  int case2 = (~(x ^ y)) & mask; 
  //combine together shift either 0 or 1 
  return (case1 | case2) >> 31 & 1; 
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // get the sign 
  int sign = 1 << 31;  
  // set the upper bound 
  int upper = ~(sign | 0x39);  
  //set the lower bound 
  int lower = ~ 0x30; 
  // if x > 0x39, upeer set to negative
  upper = sign & (upper + x);
  // if x < 0x30, lower set to negative
  lower = sign & (lower + 1 + x);
  // if either is negative, it is not in the range
  return !(upper | lower); 
}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x){
  // part1 represent the integer part of the result
  int part1 = (x>>1) + (x>>2); 
  // part 2 represent the fractional part of the result 
  int part2 = ((((x&1) <<1) + ( x&3)) &7); 
   // combine the two parts with some adjustments by shifting and anding 
   // if it is a integer answer, it will just return part 1 
   // if not, it will return the answer that is close to 0
  return part1+ ((part2>>2) &1) + ((!!( part2 &3)) &(part1>>31)); 
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  //something similar to  binary search 
  // try to find the most significant 1
  int result = 0; 

  int counter = (!!(x>>16))<<31>>31; //if most sig is in right, counter is false; if most sig is in left, counter is true
  result += counter & 16;
  x = x >> (counter & 16); 

  counter = (!!(x>>8))<<31>>31;
  result += counter & 8;  
  x = x >> (counter & 8); 

  counter = (!!( x >> 4)) <<31>>31; 
  result += counter & 4;  
  x = x >> (counter & 4);   

  counter = (!!( x >> 2)) <<31>>31; 
  result += counter & 2;  
  x = x >> (counter & 2); 

  counter = (!!( x >> 1)) <<31>>31; 
  result += counter & 1;  

  // repeat until got to the last bit, then return the answer
  return result;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  int isExplan = (uf >> 23) & 0xFF; 
  int mantissa = uf & 0x7FFFFF; 
  if( (isExplan == 0xFF)&& (mantissa !=0)){
     return uf; 
  }else {
     return uf ^ 0x80000000; 
  }
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  // i give up
  int sign = x << 31; 
  if(x==0) return 0; 
  
  if(x<0) {
	sign = 0x80000000; 
 	
  }else {
   return sign; 
  }
  return 2; 
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  //get the sign, exponent and fraction 
  unsigned sign= uf & 0x80000000; 
  unsigned exp = (uf>>23) & 0xFF; 
  unsigned frac = (uf & 0x7FFFFF); 

  //if NAN or 0 just return argument (special case) 
  if (( exp ==0 && frac == 0) || (exp == 255)){
    return uf; 
  } 

  if (exp) {  // case1: normalized 
	exp++; 
  }else if( frac == 0x7FFFFF) { // case2: frac is on the edge value
	frac--; 
	exp++; 
  }else{ // case3:  denormalized 
	frac <<=1; 
  }
  return sign | (exp <<23) | frac; 
}
