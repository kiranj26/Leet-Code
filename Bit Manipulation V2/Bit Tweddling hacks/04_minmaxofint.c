#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * ============================================================================
 * MIN/MAX - COMPREHENSIVE BIT MANIPULATION TECHNIQUES
 * ============================================================================
 * 
 * This file demonstrates multiple approaches to compute minimum and maximum
 * of two integers using advanced bit manipulation techniques. Each approach
 * showcases trade-offs between portability, performance, and clarity.
 * 
 * LEARNING OBJECTIVES:
 * 1. Understand how subtraction reveals sign information
 * 2. Learn how arithmetic right shift can extract sign bits
 * 3. Explore conditional masking using XOR & boolean masks
 * 4. Avoid branching for embedded systems optimizations
 * 5. Understand hardware behavior for deterministic execution
 */

/*
 * APPROACH 1: SUBTRACTION & ARITHMETIC RIGHT SHIFT METHOD
 * ========================================================
 * 
 * FORMULA:
 *   diff = a - b;
 *   mask = diff >> (sizeof(int) * CHAR_BIT - 1);
 *   min = b + (diff & mask);
 *   max = a - (diff & mask);
 * 
 * HOW IT WORKS:
 * - Subtraction computes the difference between a and b.
 * - Right shift extracts sign bit into full mask:
 *     - 0 if diff >= 0
 *     - -1 (all 1's) if diff < 0
 * - AND selects whether to apply the difference.
 * 
 * EMBEDDED SYSTEMS CONCERNS:
 * ✅ Fully branchless for real-time systems
 * ✅ Very fast on CPUs supporting arithmetic shift
 * ❌ Implementation-defined shift for signed ints (C standard caution)
 * ✅ Modern ARM/x86 safe
 */
int min_sub_shift(int a, int b) {
    int diff = a - b;
    int mask = diff >> (sizeof(int) * CHAR_BIT - 1);
    return b + (diff & mask);
}

int max_sub_shift(int a, int b) {
    int diff = a - b;
    int mask = diff >> (sizeof(int) * CHAR_BIT - 1);
    return a - (diff & mask);
}

/*
 * APPROACH 2: XOR & BOOLEAN MASK METHOD (Fully Portable)
 * =======================================================
 * 
 * FORMULA:
 *   min = y ^ ((x ^ y) & -(x < y));
 *   max = x ^ ((x ^ y) & -(x < y));
 * 
 * HOW IT WORKS:
 * - (x < y) yields 1 if true, 0 otherwise.
 * - Negation (-) converts boolean to full mask: 0xFFFFFFFF or 0x00000000.
 * - XOR computes bitwise difference.
 * - AND zeroes or keeps the XOR result depending on mask.
 * - Final XOR switches values if mask applied.
 * 
 * BIT LEVEL INSIGHT:
 * - When mask = -1: XOR flips to select other value.
 * - When mask = 0: XOR leaves value unchanged.
 * 
 * EMBEDDED SYSTEMS CONCERNS:
 * ✅ Fully portable (safe for any C implementation)
 * ✅ Fully branchless
 * ✅ Excellent for modern embedded MCUs
 * ✅ Compiler safely optimizes comparison
 * ✅ No dependency on signed shift behavior
 */
int min_xor_mask(int x, int y) {
    return y ^ ((x ^ y) & -(x < y));
}

int max_xor_mask(int x, int y) {
    return x ^ ((x ^ y) & -(x < y));
}

/*
 * APPROACH 3: NORMAL COMPARISON METHOD (Reference Baseline)
 * ===========================================================
 * 
 * FORMULA:
 *   min = (a < b) ? a : b;
 *   max = (a > b) ? a : b;
 * 
 * HOW IT WORKS:
 * - Uses standard conditional operator for clarity.
 * - Fully portable and simple to understand.
 * 
 * EMBEDDED SYSTEMS CONCERNS:
 * ✅ Portable across all compilers
 * ❌ May generate actual branches (not branchless)
 * ❌ Potential branch mispredictions in tight loops
 */
int min_comparison(int a, int b) {
    return (a < b) ? a : b;
}

int max_comparison(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    // Test value pairs covering edge cases and typical scenarios
    int test_pairs[][2] = {
        {10, -5}, {5, 0}, {-15, 42}, {0, 0}, {42, 100}, {-100, -50},
        {INT_MAX, INT_MIN}, {-255, 255}, {1, -1}, {-1, -1}, {0, -42}, {42, 0}
    };

    int num_tests = sizeof(test_pairs) / sizeof(test_pairs[0]);

    printf("Min-Max Bit Manipulation Test Results:\n");
    printf("A\tB\t| SubMin\tSubMax\t| XorMin\tXorMax\t| CmpMin\tCmpMax\n");
    printf("--------|----------------|----------------|----------------\n");

    for (int i = 0; i < num_tests; i++) {
        int a = test_pairs[i][0];
        int b = test_pairs[i][1];

        int sub_min = min_sub_shift(a, b);
        int sub_max = max_sub_shift(a, b);
        int xor_min = min_xor_mask(a, b);
        int xor_max = max_xor_mask(a, b);
        int cmp_min = min_comparison(a, b);
        int cmp_max = max_comparison(a, b);

        printf("%d\t%d\t| %d\t\t%d\t\t| %d\t\t%d\t\t| %d\t\t%d\n",
               a, b, sub_min, sub_max, xor_min, xor_max, cmp_min, cmp_max);
    }

    printf("\nAll approaches should return identical min/max results.\n");

    return 0;
}
