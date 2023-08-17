// INCOMPLETE
// INCOMPLETE
// INCOMPLETE


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    // for any number which is power of two
    // number n and number (n-1) do not share any 1's in common


    // lets take 2
    // 0010
    // lets take 2-1
    // 0001
    // 0010
    // 0001
    // AND
    // 0000
    int num = 4;

    int result =  (num != 0) & !(num & (num -1));
    if (result == 0)
    {
        printf("Not power of two ");
    }else
    {
        printf("Power of two ");
    }
}

