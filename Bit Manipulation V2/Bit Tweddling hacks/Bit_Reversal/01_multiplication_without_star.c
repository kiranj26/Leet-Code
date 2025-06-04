#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/*
 * ============================================================================
 * MULTIPLICATION WITHOUT USING '*' - PURE BIT MANIPULATION TECHNIQUE
 * ============================================================================
 * 
 * This file demonstrates how to multiply two integers without using any arithmetic
 * operators (*, /, +, -). We only use bit manipulation operators to perform 
 * the multiplication. This fully simulates how hardware multipliers work.
 * 
 * LEARNING OBJECTIVES:
 * 1. Derive multiplication from addition and shifting logic
 * 2. Understand how binary multiplication is series of shifted adds
 * 3. Reuse bitwise addition logic for intermediate sum
 * 4. Prepare for embedded firmware interview questions
 */

/*
 * BITWISE ADDITION FUNCTION (REUSED FROM PREVIOUS LESSONS)
 * =========================================================
 */
int bitwise_add(int a, int b) {
    while (b != 0) {
        int sum = a ^ b;
        int carry = (a & b) << 1;
        a = sum;
        b = carry;
    }
    return a;
}

/*
 * APPROACH 1: PURE BITWISE MULTIPLICATION (Shift + Add)
 * ======================================================
 * 
 * HOW IT WORKS:
 * - Walk through each bit of multiplier 'b'
 * - For every set bit, add shifted version of 'a' to result
 * - Use bitwise addition instead of '+'
 * 
 * BENEFITS:
 * ✅ Fully bit manipulation only
 * ✅ Mimics hardware multiplier design
 * ✅ Portable across all platforms
 */
int multiply_bitwise(int a, int b) {
    int result = 0;
    while (b != 0) {
        if (b & 1) {
            result = bitwise_add(result, a);
        }
        a <<= 1;
        b >>= 1;
    }
    return result;
}

/*
 * APPROACH 2: NAIVE LOOP MULTIPLICATION (Educational Reference Only)
 * ===================================================================
 * 
 * HOW IT WORKS:
 * - Increment result by 'a', 'b' times.
 * 
 * BENEFITS:
 * ✅ Conceptually simplest
 * 
 * DRAWBACKS:
 * ❌ Extremely inefficient for large values
 */
int multiply_naive(int a, int b) {
    int result = 0;
    while (b != 0) {
        result = result + a;
        b--;
    }
    return result;
}

int main() {
    int test_pairs[][2] = {
        {3, 5}, {7, 6}, {0, 10}, {15, 15}, {123, 4}, {INT_MAX, 1}, {25, -4}
    };

    int num_tests = sizeof(test_pairs) / sizeof(test_pairs[0]);

    printf("Multiplication Without '*' Test Results:\n");
    printf("A\tB\t| Naive\t| Bitwise\n");
    printf("--------|--------|--------|--------\n");

    for (int i = 0; i < num_tests; i++) {
        int a1 = test_pairs[i][0], b1 = test_pairs[i][1];
        int a2 = test_pairs[i][0], b2 = test_pairs[i][1];

        int res_naive = multiply_naive(a1, b1);
        int res_bitwise = multiply_bitwise(a2, b2);

        printf("%d\t%d\t| %d\t| %d\n", test_pairs[i][0], test_pairs[i][1], res_naive, res_bitwise);
    }

    printf("\nAll approaches should return identical multiplication results.\n");

    return 0;
}
