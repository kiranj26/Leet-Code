#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    // logic
    // fill in the neccessary bits when a 5 bit integer is extended to proper 32 bit integer

    // signed bit int of 5 bits
    typedef struct {
        signed int a :5;
    }FIveBitNum;

    FIveBitNum num1;
    num1.a = 33;

    // compiler should do automatic bit padding here in printf()
    printf(" Num after automoatc sign extentions: %d\n", num1.a);
}

