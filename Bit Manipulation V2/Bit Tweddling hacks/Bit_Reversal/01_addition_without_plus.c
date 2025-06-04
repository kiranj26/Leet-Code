#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/*
 * ============================================================================
 * ADDITION WITHOUT USING '+' - PURE BIT MANIPULATION TECHNIQUE
 * ============================================================================
 * 
 * This file demonstrates how to add two integers without using any arithmetic
 * operators (+, -, *, /). We only use bit manipulation operators to perform 
 * the addition. This is heavily used in digital circuits, embedded firmware, 
 * and technical interviews to simulate hardware-level adders.
 * 
 * LEARNING OBJECTIVES:
 * 1. Derive addition from sum and carry logic
 * 2. Understand XOR (sum without carry)
 * 3. Understand AND + shift (carry generation)
 * 4. Build iterative addition using bitwise operators
 * 5. Prepare for embedded firmware interview questions
 */

/*
 * APPROACH 1: PURE BITWISE ITERATIVE ADDITION
 * ============================================
 * 
 * HOW IT WORKS:
 * - sum  = a ^ b          (partial sum without carry)
 * - carry = (a & b) << 1  (carry bits, shifted to next bit position)
 * - Repeat until carry becomes zero.
 * 
 * BENEFITS:
 * ✅ Fully bit manipulation only
 * ✅ Matches digital hardware adder logic
 * ✅ Fully portable, branchless loop
 * 
 * DRAWBACKS:
 * ❌ Slightly more iterations for larger numbers
 */
int add_bitwise(int a, int b) {
    while (b != 0) {
        int sum = a ^ b;
        int carry = (a & b) << 1;
        a = sum;
        b = carry;
    }
    return a;
}

/*
 * APPROACH 2: NAIVE LOOP ADDITION (Educational Reference Only)
 * =============================================================
 * 
 * HOW IT WORKS:
 * - Increment 'a' by 1, 'b' times.
 * 
 * BENEFITS:
 * ✅ Conceptually simplest
 * 
 * DRAWBACKS:
 * ❌ Extremely inefficient for large values
 */
int add_naive(int a, int b) {
    while (b != 0) {
        a++;
        b--;
    }
    return a;
}

int main() {
    int test_pairs[][2] = {
        {5, 3}, {0, 0}, {123, 456}, {INT_MAX, 0}, {-100, 50}, {-25, -75}, {INT_MAX, INT_MIN}
    };

    int num_tests = sizeof(test_pairs) / sizeof(test_pairs[0]);

    printf("Addition Without '+' Test Results:\n");
    printf("A\tB\t| Naive\t| Bitwise\n");
    printf("--------|--------|--------|--------\n");

    for (int i = 0; i < num_tests; i++) {
        int a1 = test_pairs[i][0], b1 = test_pairs[i][1];
        int a2 = test_pairs[i][0], b2 = test_pairs[i][1];

        int res_naive = add_naive(a1, b1);
        int res_bitwise = add_bitwise(a2, b2);

        printf("%d\t%d\t| %d\t| %d\n", test_pairs[i][0], test_pairs[i][1], res_naive, res_bitwise);
    }

    printf("\nAll approaches should return identical sum results.\n");

    return 0;
}
