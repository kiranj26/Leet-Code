#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int num = -100;

    // math
    // shif the resiter to no of bits in int -1
    // check if its positive or negatice

    int n = num >> (__CHAR_BIT__ * sizeof(int) -1);

    // NOW XOR and subtract 
    // XOR the main number wihh N and subtract by the N 
    // num ^ n is -100 ^ 1 gives -99 
    // -99 - 1
    // 100 
    int result =  (num ^ n) - (n);

    printf("result = %d", result);
}

