/*
    Program: Range Bitwise AND
    Language: C

    Description:
    This program calculates the bitwise AND of a range of numbers using a bitwise manipulation approach.
    It demonstrates how to solve such problems efficiently without iterating through all the numbers in the range.

    Approach:
    - The rangeBitwiseAnd function takes two integers 'left' and 'right' as input.
    - It enters a loop while 'left' is less than 'right'.
    - In each iteration, the rightmost set bit in 'right' is cleared using the expression 'right &= (right - 1)'.
    - This operation removes the lowest-order bit, ensuring the next iteration will have a common leftmost bit.
    - Once 'left' is no longer less than 'right', the loop exits.
    - The function returns the final value of 'right', which represents the result of the bitwise AND operation on the given range.

    Usage:
    - Call the rangeBitwiseAnd function with the desired range of numbers.
    - The function efficiently calculates the bitwise AND of the given range.
    - The result is returned as an integer.

    Example:
    - Calculating the bitwise AND of the range [5, 7]: rangeBitwiseAnd(5, 7) returns 4.

    Note:
    - This approach solves the problem without iterating through all the numbers in the range, providing efficiency for large ranges.

*/

#include <stdio.h>

// Function to perform bitwise AND operation on a range of numbers
int rangeBitwiseAnd(int left, int right) {
    while (left < right) {
        right &= (right - 1);
        // The right-1 operation removes the rightmost set bit in 'right'
        // This effectively clears the lowest-order bit, ensuring the next iteration will have a common leftmost bit
    }
    return right;
}

int main() {
    int result = rangeBitwiseAnd(5, 7);
    printf("result = %d\n", result);
    return 0;
}
