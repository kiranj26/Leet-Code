#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    // NORMAL WAY
    // Normal way from chat gpt's math explanation

    int a = 5; // in binary 0b 0101
    int b = 3; // in binary 0b 0011

    int mask = 6; // in binary 0b0110

    // extract the bits from a where mask is 1's
    int result1 = a & mask;
    /* result_from_a = a & mask
                = 0101 (a)
                & 0110 (mask)
                ----------
                = 0100     */

    // extracts the bits from b where the mask is 0's
    int result2 =  b & (~mask);
    /* result_from_b = b & inverted_mask
                = 0011 (b)
                & 1001 (inverted_mask)
                ----------
                = 0001 */
    printf("Result = %d", result1 | result2);
}