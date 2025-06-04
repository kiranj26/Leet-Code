#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/*
 * ============================================================================
 * SWAP TWO INTEGERS WITHOUT TEMP VARIABLE - BIT MANIPULATION TECHNIQUES
 * ============================================================================
 * 
 * This file demonstrates multiple ways to swap two integers without using a
 * temporary variable, a very popular embedded firmware interview question.
 * 
 * LEARNING OBJECTIVES:
 * 1. Understand XOR-based swapping derivation
 * 2. Learn how arithmetic method works
 * 3. Understand practical constraints of each method
 * 4. Prepare for embedded interview problem solving
 */

/*
 * APPROACH 1: NAIVE SWAP USING TEMPORARY VARIABLE
 * =================================================
 * 
 * HOW IT WORKS:
 * - Use a temp variable to hold one value during swap.
 * 
 * BENEFITS:
 * ✅ Fully safe and portable
 * ✅ Handles all corner cases
 * 
 * DRAWBACKS:
 * ❌ Uses extra memory
 */
void swap_naive(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * APPROACH 2: XOR SWAP (Bit Manipulation)
 * ========================================
 * 
 * HOW IT WORKS:
 * - XOR both variables step-by-step
 * - XOR's reversible property cancels out original values
 * 
 * FORMULA:
 * a = a ⊕ b
 * b = a ⊕ b
 * a = a ⊕ b
 * 
 * BENEFITS:
 * ✅ Fully branchless
 * ✅ No memory usage
 * ✅ Industry-standard bit manipulation trick
 * 
 * DRAWBACKS:
 * ❌ Careful with aliasing (if a & b point to same memory location)
 */
void swap_xor(int *a, int *b) {
    if (a == b) return; // Defensive programming (avoid self-aliasing)
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

/*
 * APPROACH 3: ARITHMETIC SWAP (No Bit Manipulation)
 * ===================================================
 * 
 * HOW IT WORKS:
 * - Uses addition and subtraction to store diff internally
 * 
 * FORMULA:
 * a = a + b
 * b = a - b
 * a = a - b
 * 
 * BENEFITS:
 * ✅ Fully branchless
 * ✅ No temp variable
 * 
 * DRAWBACKS:
 * ❌ May overflow for large values
 */
void swap_arithmetic(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    int test_pairs[][2] = {
        {5, 9}, {0, 0}, {INT_MAX, INT_MIN}, {100, -200}, {-123, 456}, {42, 42}
    };

    int num_tests = sizeof(test_pairs) / sizeof(test_pairs[0]);

    printf("Swap Without Temp Test Results:\n");
    printf("A\tB\t| Naive\t| XOR\t| Arithmetic\n");
    printf("--------|--------|--------|--------|--------\n");

    for (int i = 0; i < num_tests; i++) {
        int a1 = test_pairs[i][0], b1 = test_pairs[i][1];
        int a2 = test_pairs[i][0], b2 = test_pairs[i][1];
        int a3 = test_pairs[i][0], b3 = test_pairs[i][1];

        swap_naive(&a1, &b1);
        swap_xor(&a2, &b2);
        swap_arithmetic(&a3, &b3);

        printf("%d\t%d\t| %d,%d\t| %d,%d\t| %d,%d\n",
               test_pairs[i][0], test_pairs[i][1],
               a1, b1, a2, b2, a3, b3);
    }

    printf("\nAll approaches should produce identical swap results.\n");

    return 0;
}
