#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    // use of XOR because XOR throws 1s where two variables have different bits
    // example 
    // 1100
    // 0010

    // 1110
    int x = -1;
    int y = 2;
    int result = ((x ^ y) < 0);

    printf("x = %d, y = %d, result = %d\n", x, y, result);

}

