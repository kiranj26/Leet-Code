Copy code
/*
    Program: Gray Code Sequence Generation
    Language: C

    Description:
    This program generates an n-bit Gray code sequence using the Gray code algorithm.
    It demonstrates how to generate a Gray code sequence using bitwise operations.

    Approach:
    - The grayCodeSequence function takes the number of bits 'n' and a pointer to 'returnSize' as input.
    - It calculates the size of the Gray code sequence based on 'n'.
    - Memory is allocated for the result array to store the sequence.
    - The Gray code sequence is generated using bitwise XOR and right shift operations.
    - The 'returnSize' value is set to the calculated size.
    - The result array is returned.
    
    Usage:
    - Call the grayCodeSequence function with the desired number of bits and a pointer to a size variable.
    - The function returns a dynamically allocated array containing the Gray code sequence.
    - Iterate over the array to access each element of the sequence.

    Example:
    - Generating a 2-bit Gray code sequence: grayCodeSequence(2, &size);
    - The function returns an array [0, 1, 3, 2], representing the Gray code sequence.

    Note:
    - Make sure to free the allocated memory using 'free' to avoid memory leaks.
*/



#include <stdio.h>
#include <stdlib.h>

// Function to generate an n-bit Gray code sequence
unsigned int* grayCodeSequence(int n, int* returnSize) {
    // Calculate the size of the Gray code sequence
    int size = 1 << n;

    // Allocate memory for the result array
    unsigned* result = (unsigned*)malloc(size * sizeof(unsigned int));

    // Generate the Gray code sequence
    for (unsigned int i = 0; i < size; i++) {
        result[i] = i ^ (i >> 1);
    }

    // Set the return size to the calculated size
    *returnSize = size;

    // Return the generated Gray code sequence
    return result;
}

int main(int argc, char **argv) {
    int size = 0;
    
    // Call the grayCodeSequence function to generate a 2-bit Gray code sequence
    unsigned* result = grayCodeSequence(2, &size);

    // Print the generated Gray code sequence
    for (unsigned int i = 0; i < size; i++) {
        printf("%u ", result[i]);
    }
    
    // Free the allocated memory
    free(result);

    return 0;
}
