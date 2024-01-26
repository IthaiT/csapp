/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
/*
 * 按位异或（数字逻辑推导）
 * */ 
 return (~((~x)&(~y)))&(~(x&y));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
/*
 * a可以是任意数，将a或上非a（位操作）之后所有位都是1
 * 再将a左移31位，得到最高位为1，其余位为0的tmin
 */
  int a = 2;
  return (a|(~a))<<31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x){
/*
 * x&&y == !!x&!!y
 * x==y的写法：!(x^y)
 * 依赖的公式：
 * ~(Tmax+1) == Tmax  --> !(~(x+1)^x)，但是111...1情况也成立
 * Tmax+1 != 0 --> 111...1+1溢出为0，加两个!!因为Tmax+1 == 1000...0，加！！得到000...0
 */
  return !(~(x+1)^x)&!!(x+1);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int y;
  int z;
  y = 170;
  z = (y<<24)+(y<<16)+(y<<8)+y;
  y = z;  
 return !((z&x)^y);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
//补码  
  return ~x+1;
}
//3
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
/*
 * 48 --> 0011 0000
 * (x+6)&48判断最低四位是不是0-9
 * x右移四位判断高四位是不是0011
 * */
  return !!((x+6)&48)&!((x>>4)^3);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
/* int flag = !x;
  flag = flag + (flag<<1);
  flag = flag + (flag<<2);
  flag = flag + (flag<<4);
  flag = flag + (flag<<8);
  flag = flag + (flag<<16);
  return (~flag&y)|(flag&z);
*/
  return ((~(!x)+1)&z)+((~(!!x)+1)&y);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int z = ~x + 1; //得到x的补码
  int t = y + z; //y+x的补码相当于y-x
  int yh = y>>31; //y的最高位
  int zh = z>>31; //z的最高位
  int th = t>>31; //t的最高位，表示y-x为正数还是负数，如果是正数，th为0，如果是负数，th为1
  int flag = (yh&zh&!th) + (!yh&!zh&th); //判断z+y是否溢出 1 1 0 和 0 0 1（负数相加结果为正数，正数相加结果为负数表示溢出）
  return (flag^!th)|(!(x^z)&!!x);
 //th取反表示如果y-x是正数，则th为1，如果是负数则th为0
 //flag^!th，因为0^x == x 1^x == ~x，表示如果溢出，结果!th取反
 //(!(x^z)&!!x)表示当x为tmin是结果总是成立，&!!x排除x为0的情况，之所以加上这一项是因为溢出取反操作当x为tmin时并不需要做
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  //第一步，构造-1，即全部的bits为1
  int a = 1+(~1); 
  //(a+x)>>31可能的结果有两个
  //为0时，表明x处于0-1000...0之间，直接返回0
  //为111...1时，并上1得到000...01，可能的情况是x为0或者为1xxxx
  //所以后面(a&~x)>>31，当x为0时，得到的是111...1当x为1xxx时，得到的是0
  //总体而言氛围0-1000..0与1xxxx两种情况讨论
  return ((a+x)>>31)&1&((a&~x)>>31);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int a = (x>>31)^x;
  int b = a;  //保留变化后的x
  int flag = 0;
  int result = 0;
  
  
  a = b>>16;   //a代表b的前16位
  flag = !!a;  //前面16位为0，flag为0
  //当前面16位不为0时取前面16位
  b = ((~flag+1)&a)+((~(!flag)+1)&b); //当flag==0时，b不改变，当flag==1时，b为前16位
  result = result + (flag<<4);
  
  a = b>>8;   //a代表b的前16位
  flag = !!a;  //前面16位为0，flag为0
  b = ((~flag+1)&a)+((~(!flag)+1)&b); //当flag==0时，b不改变，当flag==1时，b为前8位
  result = result + (flag<<3);

  a = b>>4;   //a代表b的前16位
  flag = !!a;  //前面16位为0，flag为0
  b = ((~flag+1)&a)+((~(!flag)+1)&b); //当flag==0时，b不改变，当flag==1时，b为前4位
  result = result + (flag<<2);

  a = b>>2;   //a代表b的前16位
  flag = !!a;  //前面16位为0，flag为0
  b = ((~flag+1)&a)+((~(!flag)+1)&b); //当flag==0时，b不改变，当flag==1时，b为前2位
  result = result + (flag<<1);

  a = b>>1;   //a代表b的前16位
  flag = !!a;  //前面16位为0，flag为0
  b = ((~flag+1)&a)+((~(!flag)+1)&b); //当flag==0时，b不改变，当flag==1时，b为前1位
  result = result + flag;
   
  return result + b + 1; //32 - zero_number + 1 + b，result = 32 - zero_number 
  
}

//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  //得到exp,因为是unsigned类型,所以右移都是逻辑右移
  int exp = (uf<<1)>>24; 
  //得到M
  int str = (((255<<8)+255)<<7)+127;
  int M = str&uf; 
  //如果为规格化的值，那么exp+1代表*2
  if(exp != 0 && exp != 255){
	exp = exp+1;
  }
  //如果是非规格化的值，那么M直接左移一位代表*2
  //有两种情况，第一种是M的最高位为1，那么左移之后相当于exp加1且M的每一位都左移一位（转为为规格化数）
  //最高位为0，那么没有任何问题
  else if(exp == 0){
	M = M<<1;
  }
  //特殊值返回本身
  else
	return uf;			
  return ((uf>>31)<<31)+(exp<<23)+M;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  //得到指数位
  int exp = (uf<<1)>>24;
  //得到偏移位
  int E = exp - 127;
  //得到符号位，并且将符号位保持在最高位
  int flag = (uf>>31)<<31;
  if(E>=0 && E<=30){
	//得到M，此时M肯定位规格化数
	unsigned M = (1<<23)+((uf<<9)>>9);	
	//M表示为0000 0000 1xxx ...
	//当E为0时，M = 1，所以要将M右移23位
	//当E为23时，将M最高位1外所有数字显现，表示M本身
	//当E为24时，表示M乘以2，左移1位，以此类推
	//注意E最高只能到30，结果是01xx ... ,可以表示2^(-16)-1~2^16-1，至于2^(-16)则由else表示
	M = M >> (23-E);
	//如果flag不等于0，要将M转化为补码格式，再将M的符号位去除
	if(flag){
		M = ((~M+1)<<1)>>1;
	}
	return flag + M;	
  }
  //在0<=exp<127这个区间内，E都小于0，这时候表示uf是小数，int不能表示小数
  else if(E < 0){
	return 0;
  }
  //在E>31这个区间中，相当于M至少成为2的32次方，一定会溢出
  else{
	return 0x80000000u;
  }
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  //能够表示的范围是2^-149~2^127
  if(x<-149){
	return 0;
  }
  //在x是-149~-127范围内，float的exp域为0，此时M域左移一位代表乘2
  else if(x>=-149 && x<-126){
	return 1<<(x+149);
  }
  //在x是-126到127范围内，此时exp域不为0，加1代表乘以2
  else if(x>=-126 && x<128){
	return (1+(x+126))<<23;
  }
  else{
    return 255<<23;
  }
}
