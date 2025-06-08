#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * =========================================================================
 * LeetCode Problem: Number Complement (476)
 * =========================================================================
 * 
 * Problem:
 * The complement of an integer is the integer you get when you flip all the 0's
 * to 1's and all the 1's to 0's in its binary representation (ignoring leading zeroes).
 * 
 * Example 1:
 * Input: num = 5
 * Output: 2
 * Explanation: Binary 101 -> complement 010 -> integer 2
 * 
 * Example 2:
 * Input: num = 1
 * Output: 0
 * Explanation: Binary 1 -> complement 0 -> integer 0
 * 
 * =========================================================================
 * COMPLETE LEARNING OBJECTIVES (for future detailed revision):
 * 
 * 1️⃣ Key Bit Manipulation Insight:
 *     - We don't complement all 32 bits — only complement the active bits of num.
 *     - We need a mask of all 1's for the number of bits in num.
 *     - XOR with mask gives the complement.
 * 
 * 2️⃣ Why XOR works perfectly:
 *     - XOR flips the bits where mask has 1's.
 *     - The mask ensures we only flip actual bits, not leading zeroes.
 * 
 * 3️⃣ Key Trick To Build The Mask:
 *     - Use left shift to find highest bit position.
 *     - mask = (1 << number of bits) - 1
 * 
 * 4️⃣ Why use unsigned int:
 *     - Left shifting signed ints beyond sign bit can cause undefined behavior.
 *     - Unsigned shifting is always safe and portable.
 */

/**
 * -------------------------------------------------------------------------
 * APPROACH 1: Brute Force (String Simulation)
 * -------------------------------------------------------------------------
 * (For learning only; not efficient for real interviews)
 *
 * Idea:
 * - Convert num to binary string.
 * - Flip bits manually.
 * - Convert back to integer.
 *
 * Drawback:
 * - Requires extra space.
 * - Slower.
 */
int findComplementBruteForce(int num) {
    char binary[32] = {0};
    int len = 0;
    
    // Convert to binary string
    int temp = num;
    while (temp > 0) {
        binary[len++] = (temp % 2) ? '1' : '0';
        temp /= 2;
    }
    
    // Flip bits
    for (int i = 0; i < len; i++) {
        binary[i] = (binary[i] == '1') ? '0' : '1';
    }

    // Convert back to integer
    int result = 0;
    for (int i = len - 1; i >= 0; i--) {
        result = result * 2 + (binary[i] - '0');
    }
    
    return result;
}

/**
 * -------------------------------------------------------------------------
 * APPROACH 2: Bit Manipulation (Efficient and Interview Friendly)
 * -------------------------------------------------------------------------
 *
 * Time Complexity: O(log(num))
 * Space Complexity: O(1)
 *
 * Steps:
 * - Build a mask with all bits set to 1 up to the highest set bit.
 * - XOR num with mask to get complement.
 * - Use unsigned int to safely handle left shifts.
 */
int findComplement(int num) {
    unsigned int mask = 1;
    while (mask <= num) {
        mask <<= 1;
    }
    mask -= 1;
    return num ^ mask;
}

/**
 * -------------------------------------------------------------------------
 * Test Driver Code
 * -------------------------------------------------------------------------
 */
int main() {
    int test_cases[] = {5, 1, 0, 10, 123, 1023, 2147483647};
    int n = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("Number Complement Test Results:\n\n");

    for (int i = 0; i < n; i++) {
        int num = test_cases[i];
        printf("Input: %d\n", num);
        printf("Brute-Force Complement: %d\n", findComplementBruteForce(num));
        printf("Bit Manipulation Complement: %d\n\n", findComplement(num));
    }

    return 0;
}
