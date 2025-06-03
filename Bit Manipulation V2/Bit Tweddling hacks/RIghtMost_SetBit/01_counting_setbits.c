#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/*
 * ============================================================================
 * COUNTING SET BITS - USING RIGHTMOST SET BIT CLEARING TECHNIQUE
 * ============================================================================
 * 
 * This file demonstrates multiple approaches to count the number of set bits
 * (also called population count or Hamming weight) using one of the most famous
 * embedded bit manipulation tricks: v & (v - 1).
 * 
 * LEARNING OBJECTIVES:
 * 1. Derive popcount from rightmost set bit clearing
 * 2. Understand why this trick minimizes loop iterations
 * 3. Build portable, fast algorithms for embedded firmware
 * 4. Prepare for embedded firmware interview questions
 * 5. Understand hardware population count instructions
 */

/*
 * APPROACH 1: NAIVE SHIFTING LOOP (For Learning Only)
 * =====================================================
 * 
 * HOW IT WORKS:
 * - Test each bit position one-by-one using right shift.
 * - Increment count if current bit is 1.
 * 
 * BENEFITS:
 * ✅ Fully portable
 * ✅ Easy to understand
 * 
 * DRAWBACKS:
 * ❌ Always iterates full word size (32 or 64 times)
 * ❌ Inefficient for sparse bit patterns
 */
unsigned int count_set_bits_naive(unsigned int v) {
    unsigned int count = 0;
    while (v) {
        count += (v & 1);
        v >>= 1;
    }
    return count;
}

/*
 * APPROACH 2: BRIAN KERNIGHAN'S ALGORITHM (Highly Efficient)
 * ===========================================================
 * 
 * Formula: repeatedly apply v = v & (v - 1) until v becomes 0.
 * 
 * HOW IT WORKS:
 * - Each operation clears exactly one set bit.
 * - Number of iterations equals number of set bits.
 * 
 * EXAMPLES:
 * v = 12 (1100): 1100 → 1000 → 0000 → count = 2
 * 
 * BENEFITS:
 * ✅ Loop runs only as many times as set bits exist
 * ✅ Extremely fast for sparse bit patterns
 * ✅ Branchless on many CPUs
 * ✅ Industry-standard embedded trick
 */
unsigned int count_set_bits_kernighan(unsigned int v) {
    unsigned int count = 0;
    while (v) {
        v = v & (v - 1);
        count++;
    }
    return count;
}

/*
 * APPROACH 3: GCC/CLANG BUILTIN POPCOUNT (Compiler Optimization)
 * ================================================================
 * 
 * NOTE:
 * - Modern compilers like GCC and Clang provide __builtin_popcount.
 * - May directly map to hardware instructions like POPCNT on x86 or ARM.
 * 
 * BENEFITS:
 * ✅ Extremely fast
 * ✅ May utilize hardware instruction if available
 * ✅ No manual loop
 * 
 * DRAWBACK:
 * ❌ Compiler-specific
 */
unsigned int count_set_bits_builtin(unsigned int v) {
    return __builtin_popcount(v);
}

int main() {
    unsigned int test_values[] = {0, 1, 2, 3, 4, 5, 7, 8, 15, 16, 31, 32, 63, 64, 127, 128, 255, 256, UINT_MAX};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    printf("Counting Set Bits Test Results:\n");
    printf("Value\t| Naive\t| Kernighan\t| Builtin\n");
    printf("--------|--------|------------|----------\n");

    for (int i = 0; i < num_tests; i++) {
        unsigned int v = test_values[i];

        unsigned int res_naive = count_set_bits_naive(v);
        unsigned int res_kernighan = count_set_bits_kernighan(v);
        unsigned int res_builtin = count_set_bits_builtin(v);

        printf("%u\t| %u\t| %u\t\t| %u\n", v, res_naive, res_kernighan, res_builtin);
    }

    printf("\nAll methods should produce identical popcount results.\n");

    return 0;
}
