#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    /* int num = 0;

    int result  = num >> 31;

    printf("Number = %d", result);

    int result1  =  num >> (sizeof(int) * __CHAR_BIT__ -1);
    printf("Number = %d", result1);

    // to get +1 and -1 as result
    // OR result with +1

    int result2  =  +1 | (num >> (sizeof(int) * __CHAR_BIT__ -1));
    printf("Number = %d", result2);    

    // to get the result in -1 o and +1
    int result3  =  (num != 0) | (num >> (sizeof(int) * __CHAR_BIT__ -1));
    printf("Number = %d", result3);         */


    /* // detect if two integers have opoosite signs

    int num1 = -10;
    int num2 = -10;

    int result  = (num1 ^ num2) < 0;

    printf("result = %d", result); */

    /* // compute the ineteger absolute value
    int num = -1010;

    int sign = (num >> (__CHAR_BIT__ * sizeof(int) -1));

    printf("sign = %d", sign);

    int new_num = (num ^ sign) - (sign);
    printf("new num = %d", new_num); */

    /* // determine if the integer is power of two

    int num = 6;
    int result  = ((num & (num -1)) == 0 )? 1 : 0;
    printf("result = %d", result); */

    // Conditionally set or clear bits without branching
    // neive way
    // to set a bt keep 1 at desired location and 0 everywhere else
    // to clear a bit set 0 at desired location and 1 everywhere elese
/* 
    // WITH BRACHING
    int position = 1;
    int mask = (1 << position);
    int condition = 11;

    int num = 5;
    int result  = (condition == 10) ? (num | mask):(num & ~mask);

    printf("result = %d", result); */

    // WITHOUT BRANCHING (VERSION 1)
    // the goal is ot set or clear bit from word W without branching
    // branching is an expansive in terms of CPU cycles
    int w = 5;
    int pos = 1; // starts from 0
    int m  = (1<< pos); // mask to set or clear bit at position 1

    int f = 1;
    // when you negate a boolean its treated as integer -f
    // so if -0 its 0 and -1 its -1 as int
    // representing in 2's complement representation -1 is all 1's & 0 is all zeros
    // (-f ^ w): This XORs the word w with either 0 (if f is false) or with all 1s (if f is true).
    // & m: This ensures that only the bits specified in the mask m are affected.
    // w ^= ...: The XOR operation effectively toggles the bits. So, if f is true, the bits in w specified by m are set. If f is false, they are cleared.
    w ^= (-f ^ w) & m;

    // example
    // bool f = true;          // conditional flag
    // unsigned int m = 0x4;   // the bit mask, which represents the third bit (0b0100)
    // unsigned int w = 0xA;   // the word to modify, which is 0b1010 in binary

    // -f would be -1 which in two's complement is all 1s (0xFFFFFFFF for a 32-bit integer).
    // (-f ^ w) would be (0xFFFFFFFF ^ 0xA) which is 0xFFFFFFF5.
    // (-f ^ w) & m would be 0xFFFFFFF5 & 0x4 which is 0x4.
    // w ^= 0x4 would toggle the third bit of w, setting it to 1. So, w becomes 0xE or 0b1110 in binary.

    printf("result = %d", w);


}