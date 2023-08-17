// INCOMPLETE
// INCOMPLETE
// INCOMPLETE


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int x = 1;
    int y = 2;

    int diff = x - y;

    int bit = diff >> (__CHAR_BIT__ * sizeof(int) - 1);

    int max = x - bit * diff;
    int min = y + x * diff;

    printf("max = %d, min = %d\n", max, min);
}

