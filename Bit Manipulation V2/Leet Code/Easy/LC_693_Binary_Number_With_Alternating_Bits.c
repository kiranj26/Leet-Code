#include <stdio.h>
#include <stdbool.h>

/**
 * =========================================================================
 * LeetCode Problem: Binary Number with Alternating Bits (693)
 * =========================================================================
 * 
 * Problem:
 * Given a positive integer n, check whether it has alternating bits:
 * i.e., no two adjacent bits are the same.
 * 
 * Example:
 * Input: 5 (binary 101)  => Output: true
 * Input: 7 (binary 111)  => Output: false
 * Input: 11 (binary 1011) => Output: false
 * 
 * =========================================================================
 * COMPLETE LEARNING OBJECTIVES (for future detailed revision):
 * 
 * 1️⃣ Alternating Bits Intuition:
 *     - Bits alternate if 0 and 1 appear consecutively.
 *     - Examples: 1010, 0101 are alternating. 111 or 100 are not.
 *
 * 2️⃣ XOR-Based Trick:
 *     - Observation:
 *       If n has alternating bits, then (n >> 1) XORed with n
 *       results in all 1s. E.g., for 101:
 *         n      = 101
 *         n>>1   = 010
 *         n ^ n>>1 = 111
 *     - If result is all 1s => result & (result + 1) == 0
 *       Because all-1 pattern +1 flips the bits and causes carry-over
 * 
 * 3️⃣ Brute Force Method (for intuition):
 *     - Continuously check LSB (n % 2) with previous bit.
 *     - Shift n right until 0.
 *     - If two adjacent bits are same => return false.
 *     - Else true.
 */

/**
 * -------------------------------------------------------------------------
 * APPROACH 1: Bitwise XOR Elegant Method
 * -------------------------------------------------------------------------
 * Time Complexity: O(1) - max 32 bits for input
 * Space Complexity: O(1)
 */
bool hasAlternatingBits_XOR(int n) {
    int x = n ^ (n >> 1);          // XOR produces all 1s if alternating
    return (x & (x + 1)) == 0;     // Check if x is like 111..11 pattern
}

/**
 * -------------------------------------------------------------------------
 * APPROACH 2: Bit-by-Bit Comparison
 * -------------------------------------------------------------------------
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
bool hasAlternatingBits_Brute(int n) {
    int prev = n & 1; // LSB
    n >>= 1;
    while (n > 0) {
        int curr = n & 1;
        if (curr == prev) return false;
        prev = curr;
        n >>= 1;
    }
    return true;
}

/**
 * -------------------------------------------------------------------------
 * Test Driver Code
 * -------------------------------------------------------------------------
 */
int main() {
    int test_cases[] = {5, 7, 11, 10, 0, 1, 170, 85}; // 170 = 10101010, 85 = 01010101
    int n = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("Testing hasAlternatingBits_XOR and Brute Force Approaches:\n\n");
    for (int i = 0; i < n; i++) {
        int input = test_cases[i];
        bool xor_result = hasAlternatingBits_XOR(input);
        bool brute_result = hasAlternatingBits_Brute(input);

        printf("Input: %d\t| Binary: ", input);
        for (int j = 31; j >= 0; j--) {
            printf("%d", (input >> j) & 1);
        }
        printf("\n  XOR Trick:   %s\n  Brute Check: %s\n\n",
            xor_result ? "True" : "False",
            brute_result ? "True" : "False");
    }

    return 0;
}
