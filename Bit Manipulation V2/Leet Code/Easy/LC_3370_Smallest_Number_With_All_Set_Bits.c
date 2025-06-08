#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * =========================================================================
 * LeetCode Problem: Smallest Number With All Set Bits (3370)
 * =========================================================================
 * 
 * Problem:
 * You are given a positive number n.
 * Return the smallest number x greater than or equal to n,
 * such that the binary representation of x contains only set bits (all 1's).
 * 
 * Example 1:
 * Input: n = 5  -> Output: 7  (5 = 101, smallest all-ones >= 5 is 111)
 * 
 * Example 2:
 * Input: n = 10 -> Output: 15 (10 = 1010, smallest all-ones >= 10 is 1111)
 * 
 * Example 3:
 * Input: n = 3  -> Output: 3  (3 = 11, already all set bits)
 * 
 * =========================================================================
 * COMPLETE LEARNING OBJECTIVES (for future detailed revision):
 * 
 * 1️⃣ Key Bit Manipulation Insight:
 *     - We want smallest number with k bits all set where k = number of bits required for n.
 *     - Use bit length calculation to find how many bits are needed to cover n.
 * 
 * 2️⃣ Counting Number of Bits:
 *     - Right shift num until it becomes zero.
 *     - Count number of shifts to determine number of bits.
 * 
 * 3️⃣ Formula To Build All-Set-Bit Number:
 *     - Smallest number with k bits all set = (1 << k) - 1
 *     - This gives binary with exactly k 1's.
 * 
 * 4️⃣ Optimization:
 *     - Fully constant-time solution after counting bits.
 *     - No loops needed for building final result.
 */

/**
 * -------------------------------------------------------------------------
 * Helper function to count number of bits required to represent n
 * -------------------------------------------------------------------------
 */
int countBits(int num) {
    int count = 0;
    while (num > 0) {
        num >>= 1;
        count++;
    }
    return count;
}

/**
 * -------------------------------------------------------------------------
 * Main Solution Logic
 * -------------------------------------------------------------------------
 */
int smallestNumber(int n) {
    int count = countBits(n);
    return (1 << count) - 1;
}

/**
 * -------------------------------------------------------------------------
 * Test Driver Code
 * -------------------------------------------------------------------------
 */
int main() {
    int test_cases[] = {5, 10, 3, 1, 1000, 15, 7};
    int n = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("Smallest number with all set bits:\n\n");

    for (int i = 0; i < n; i++) {
        int input = test_cases[i];
        int result = smallestNumber(input);
        printf("Input: %d -> Output: %d\n", input, result);
    }

    return 0;
}
