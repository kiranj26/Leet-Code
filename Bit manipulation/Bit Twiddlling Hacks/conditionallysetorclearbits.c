#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    // conditionally ste or clear bit 
    // based on value of conditionl flag lets say 1 or 0
    // if condition flag is 1 
    // required bits from bit mask will be set 
    // if condition is 0 then
    // required bits from bit mask will be reset

    int condition = 1;

    int mask  = 0b01111111111111111111111111111111;

    int num = 0b1;

    int result = result ^ ((-condition ^ num ) & mask);

    printf("result = %d\n", result);

    // DEATILED EXPLANATION
}

