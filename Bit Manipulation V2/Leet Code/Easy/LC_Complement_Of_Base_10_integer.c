#include <stdio.h>
#include <stdlib.h>

/**
 * =========================================================================
 * LeetCode Problem: Complement of Base 10 Integer (1009)
 * =========================================================================
 * 
 * Problem:
 * Given an integer n, return its complement — where we flip all 0's to 1's
 * and 1's to 0's in its binary representation (ignoring leading zeros).
 * 
 * Example 1:
 * Input: n = 5  (binary: 101)
 * Output: 2     (complement: 010)
 * 
 * Example 2:
 * Input: n = 7  (binary: 111)
 * Output: 0     (complement: 000)
 * 
 * Example 3:
 * Input: n = 10 (binary: 1010)
 * Output: 5     (complement: 0101)
 * 
 * =========================================================================
 * COMPLETE LEARNING OBJECTIVES:
 * 
 * 1️⃣ Key Bit Manipulation Insight:
 * - Only flip actual bits (ignoring leading zeros).
 * - First calculate how many bits n has.
 * 
 * 2️⃣ Counting Bit Length:
 * - Keep right-shifting n while counting how many shifts until n becomes 0.
 * 
 * 3️⃣ Build the mask with all bits set:
 * - mask = (1 << count) - 1
 * 
 * 4️⃣ XOR Trick to flip bits:
 * - result = n ^ mask
 * 
 * 5️⃣ Special Edge Case:
 * - If n == 0 → complement should be 1.
 * 
 * 6️⃣ Time and Space Complexity:
 * - Time: O(log n)
 * - Space: O(1)
 */

int bitwiseComplement(int n) {
    if (n == 0) return 1;
    
    int temp = n;
    int count = 0;
    
    while (n > 0) {
        n = n >> 1;
        count++;
    }
    
    return (temp ^ ((1 << count) - 1));
}

int main() {
    int test_cases[] = {5, 7, 10, 0, 1, 15, 100, 12345};
    int n = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("Bitwise Complements:\n\n");
    for (int i = 0; i < n; i++) {
        int input = test_cases[i];
        int result = bitwiseComplement(input);
        printf("Input: %d -> Complement: %d\n", input, result);
    }

    return 0;
}
