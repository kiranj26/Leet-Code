#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
    /* // naive way
    // take the LSB using  num & 1 and add it to c

    int v = 5; // 0b0101
    int c = 0;
    for (c = 0; v ; v >>= 1)
    {
        c += v & 1;
    }
    printf("c = %d\n", c); */

    // Brian Kernighan's way
    int v = 5;
    int c = 0;

    for (c = 0;v;c++)
    {
        v =  v & (v -1);
    }
    printf("c = %d\n", c);

}