#include <stdio.h>
#include <stdlib.h>

/* 
* Problem: Decode XORed Array
* 
* Given an array of encoded elements obtained by performing XOR operations on consecutive elements of a 
* decoded array, along with the first element of the decoded array, this program decodes the array 
* and returns the decoded array.
*
* Approach:
* - Allocate memory for the decoded array based on the size of the encoded array.
* - Set the first element of the decoded array as the provided "first" parameter.
* - Iterate through the encoded array, performing XOR operations between consecutive elements 
*   and storing the result in the decoded array.
* - Return the decoded array along with its size using the "returnSize" parameter.
*
* Test the Function:
* - Modify the values of the "encoded" array, "encodedSize", and "first" variable to test different scenarios.
*/

int* decode(int* encoded, int encodedSize, int first, int* returnSize){
    int* result = (int*)malloc((encodedSize + 1) * sizeof(int)); 
    result[0] = first;
    
    for (int i = 1; i < encodedSize + 1; i++){
        result[i] = encoded[i - 1] ^ encoded[i];          
    }
    
    *returnSize = encodedSize + 1;
    return result;
}

int main(){
    // Input parameters
    int encoded[] = {1, 2, 3};
    int encodedSize = sizeof(encoded) / sizeof(encoded[0]);
    int first = 1;
    
    // Decode the encoded array
    int returnSize;
    int* decoded = decode(encoded, encodedSize, first, &returnSize);
    
    // Print the decoded array
    printf("Decoded Array: ");
    for (int i = 0; i < returnSize; i++){
        printf("%d ", decoded[i]);
    }
    
    // Free dynamically allocated memory
    free(decoded);
    
    return 0;
}
