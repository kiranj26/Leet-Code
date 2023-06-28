// Scenario 1: Positive Input

// Start with the given positive decimal number.
// Divide the number by 7 and keep track of the quotient and remainder.
// Write down the remainder as the rightmost digit of the base-7 representation.
// Take the quotient from step 2 and repeat steps 2-4 until the quotient becomes 0.
// Write down each remainder obtained in step 3, from right to left, to form the base-7 representation of the decimal number.
// If the input is 0, the base-7 representation is simply "0".

// Scenario 2: Negative Input

// Start with the absolute value of the given negative decimal number.
// Follow the steps for positive input (as described in Scenario 1) to obtain the base-7 representation of the absolute value.
// Prepend a minus sign ("-") to the resulting base-7 representation to indicate that it is a negative number.

// Scenario 3: Input is 0

// Since the input is 0, the base-7 representation is simply "0".
// By following these steps for each scenario, you can convert decimal numbers to base-7 representation effectively.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* convertToBase7(int num1) {
    // Determine the absolute value: |-123| = 123.
    if (num1 == 0) return "0";
    int num = abs(num1);
    int rem = 0;
    int i = 0;
    char* base7 = (char*)malloc(100 * sizeof(char)); // Allocate memory for base-7 digits

    // divide number until num is 0
    while (num != 0) {
        rem = num % 7;
        base7[i] = '0' + rem;
        num = num / 7;
        i++;
    }

    // Add - to the base-7 representation if num1 is negative
    if (num1 < 0) {
        base7[i++] = '-';
    }

    // Reverse the string
    int len = i;
    for (int j = 0; j < len / 2; j++) {
        char temp = base7[j];
        base7[j] = base7[len - j - 1];
        base7[len - j - 1] = temp;
    }

    // Null-terminate the string
    base7[i] = '\0';

    return base7;  
}

int main(int argc, char* argv[]) {
    int num = -7;

    // Convert the number to base-7 representation
    char* base7 = convertToBase7(num);
    printf("After conversion: %s\n", base7);
    free(base7); // Free the dynamically allocated memory

    return 0;
}
