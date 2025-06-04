#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/*
 * ============================================================================
 * SUBTRACTION WITHOUT USING '-' - PURE BIT MANIPULATION TECHNIQUE
 * ============================================================================
 * 
 * This file demonstrates how to subtract two integers without using any arithmetic
 * operators (-, +, *, /). We only use bit manipulation operators to perform 
 * the subtraction. This directly simulates how hardware subtractors work.
 * 
 * LEARNING OBJECTIVES:
 * 1. Derive subtraction from difference and borrow logic
 * 2. Understand XOR (difference without borrow)
 * 3. Understand (~A & B) for borrow generation
 * 4. Build iterative subtraction using bitwise operators
 * 5. Prepare for embedded firmware interview questions
 */

/*
 * APPROACH 1: PURE BITWISE ITERATIVE SUBTRACTION
 * ===============================================
 * 
 * HOW IT WORKS:
 * - diff  = a ^ b          (partial difference without borrow)
 * - borrow = (~a & b) << 1 (borrow bits, shifted to next bit position)
 * - Repeat until borrow becomes zero.
 * 
 * BENEFITS:
 * ✅ Fully bit manipulation only
 * ✅ Matches digital hardware subtractor logic
 * ✅ Fully portable, branchless loop
 * 
 * DRAWBACKS:
 * ❌ Slightly more iterations for larger values
 */
int subtract_bitwise(int a, int b) {
    while (b != 0) {
        int borrow = (~a & b) << 1;
        a = a ^ b;
        b = borrow;
    }
    return a;
}

/*
 * APPROACH 2: NAIVE LOOP SUBTRACTION (Educational Reference Only)
 * ================================================================
 * 
 * HOW IT WORKS:
 * - Decrement 'b' times.
 * 
 * BENEFITS:
 * ✅ Conceptually simplest
 * 
 * DRAWBACKS:
 * ❌ Extremely inefficient for large values
 */
int subtract_naive(int a, int b) {
    while (b != 0) {
        a--;
        b--;
    }
    return a;
}

int main() {
    int test_pairs[][2] = {
        {7, 3}, {10, 4}, {123, 56}, {0, 0}, {50, 25}, {-25, -10}, {INT_MAX, INT_MIN}
    };

    int num_tests = sizeof(test_pairs) / sizeof(test_pairs[0]);

    printf("Subtraction Without '-' Test Results:\n");
    printf("A\tB\t| Naive\t| Bitwise\n");
    printf("--------|--------|--------|--------\n");

    for (int i = 0; i < num_tests; i++) {
        int a1 = test_pairs[i][0], b1 = test_pairs[i][1];
        int a2 = test_pairs[i][0], b2 = test_pairs[i][1];

        int res_naive = subtract_naive(a1, b1);
        int res_bitwise = subtract_bitwise(a2, b2);

        printf("%d\t%d\t| %d\t| %d\n", test_pairs[i][0], test_pairs[i][1], res_naive, res_bitwise);
    }

    printf("\nAll approaches should return identical subtraction results.\n");

    return 0;
}
