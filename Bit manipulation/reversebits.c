#include <stdio.h>
#include <stdint.h>

// Function to reverse the bits of a given 32-bit unsigned integer
uint32_t reverseBits(uint32_t num) {
    uint32_t result = 0;     // Variable to store the reversed number
    uint32_t lsb = 0;        // Variable to store the least significant bit
    
    // Iterate through each bit of the input number
    for (uint32_t i = 0; i < 32; i++) {
        result = result << 1;   // Shift the result to the left by 1 bit
        
        lsb = num & 1;          // Get the least significant bit of the input number
        
        if (lsb == 1) {
            result = result | 1;   // If the least significant bit is 1, set the corresponding bit in the result to 1
        }
        
        num >>= 1;   // Right shift the input number by 1 bit to process the next bit
    }
    
    return result;   // Return the reversed number
}

// Main function
int main() {
    uint32_t tests[] = {0b1011, 0b1100, 0b11110000, 0b0, 0b11111111};   // Test cases
    int numTests = sizeof(tests) / sizeof(tests[0]);   // Calculate the number of test cases
    
    // Iterate through each test case
    for (int i = 0; i < numTests; i++) {
        uint32_t input = tests[i];   // Get the input number from the test cases
        uint32_t output = reverseBits(input);   // Calculate the reversed bits using the reverseBits function
        
        // Print the input and output numbers in decimal form
        printf("Input in decimal: %u\n", input);
        printf("Output in decimal: %u\n\n", output);
    }
    
    return 0;
}
