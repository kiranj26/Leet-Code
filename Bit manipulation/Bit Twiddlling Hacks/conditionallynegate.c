
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    /* // negate a number based on flag value
    int flag = 0;

    int num = -10;

    // WITH BRANCHING
    int result = (flag == 1) ? num: -num;

    printf("%d", result); */

    // WITHOUT BRANCHING (using Bitwise Operators)
    // LOGIC : Using 2's complement property of arithmetic and Bitwise Operations
    // To negate a number using 2's complement methode we do is 1st - we invert all bits 2nd -we add one

    // so lets begin 
    // if f (condition) is true we want to negate all the bits of 1 
    int f = 1;
    int mask  = -f;
    int num  = 15; // 0b1111
    int x  = num ^ mask; // so if f is 1 invert all the bits else dont

    // and then just add 1 if its true and none if false
    x = x + f;

    printf("Resulting = %d\n", x);
}