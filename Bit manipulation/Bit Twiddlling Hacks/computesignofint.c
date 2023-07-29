#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int v = -0;              // we want to find the sign of V
    int sign;           // we want to find the sign of V

    // if V is negative then return -1
    sign = -(v<0);

    // using bitwise operations which is based on type of variable
    sign = v >> ( __CHAR_BIT__ * (sizeof(int) -1)   );

    // to get the result in -1 and 1
    sign = +1 | ( v >> ( __CHAR_BIT__ * (sizeof(int)- 1 )) );

    // if you prefer the reuslt in -1 0 and +1
    sign =  (v != 0) | ( v >> ( __CHAR_BIT__ * (sizeof(int)- 1 )) );
    printf("sign = %d\n", sign);

}

