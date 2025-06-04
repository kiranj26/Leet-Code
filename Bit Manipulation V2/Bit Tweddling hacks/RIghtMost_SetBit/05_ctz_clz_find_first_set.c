#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/*
 * ============================================================================
 * COUNT TRAILING ZEROS (CTZ) - FIND FIRST SET BIT (RIGHTMOST BIT INDEX)
 * ============================================================================
 * 
 * This file demonstrates multiple approaches to calculate how many trailing
 * zeros exist in an unsigned integer (count trailing zeros). This is also called
 * "Find First Set" (starting from the least significant bit).
 * 
 * LEARNING OBJECTIVES:
 * 1. Derive CTZ step-by-step from isolate-rightmost-set-bit trick
 * 2. Learn how log2 computation relates to CTZ
 * 3. Build embedded-friendly branchless and defensive solutions
 * 4. Prepare for embedded firmware interviews
 */

/*
 * APPROACH 1: NAIVE BIT SHIFT METHOD (Derivation Method)
 * =======================================================
 * 
 * HOW IT WORKS:
 * - First isolate rightmost set bit using (v & -v)
 * - Then count how many right shifts are required to reduce result to 1
 * 
 * FORMULA:
 * ctz(v) = log2(v & -v)
 * 
 * EXAMPLES:
 * v = 40 (101000):
 * v & -v = 1000 → log2(8) = 3 → CTZ = 3
 * 
 * BENEFITS:
 * ✅ Pure bit manipulation
 * ✅ Fully portable
 * ✅ Easy derivation from earlier tricks
 */
unsigned int count_trailing_zeros_naive(unsigned int v) {
    if (v == 0) return 32; // Special case: no set bits
    unsigned int isolated = v & -v;
    int count = 0;
    while (isolated > 1) {
        isolated >>= 1;
        count++;
    }
    return count;
}

/*
 * APPROACH 2: GCC/CLANG BUILTIN METHOD (If Available)
 * =====================================================
 * 
 * HOW IT WORKS:
 * - Use __builtin_ctz() if compiler supports it.
 * - This directly maps to hardware instruction on most MCUs (CLZ/CTZ).
 * 
 * BENEFITS:
 * ✅ Extremely fast
 * ✅ Fully optimized by compiler
 * 
 * DRAWBACKS:
 * ❌ Compiler-specific
 */
unsigned int count_trailing_zeros_builtin(unsigned int v) {
    if (v == 0) return 32; // Defensive safe check
    return __builtin_ctz(v);
}

/*
 * APPROACH 3: BIT TESTING ONE BY ONE (Educational Purpose)
 * =========================================================
 * 
 * HOW IT WORKS:
 * - Shift v one bit at a time and count until first set bit is found.
 * 
 * BENEFITS:
 * ✅ Fully portable and understandable
 * ❌ Slow (not efficient for embedded real-time)
 */
unsigned int count_trailing_zeros_bitwalk(unsigned int v) {
    if (v == 0) return 32;
    int count = 0;
    while ((v & 1) == 0) {
        v >>= 1;
        count++;
    }
    return count;
}

int main() {
    unsigned int test_values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 15, 16, 20, 23, 32, 40, 64, 127, 255, 256, 1023, UINT_MAX};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    printf("Count Trailing Zeros (CTZ) Test Results:\n");
    printf("Value\t| Naive\t| Bitwalk\t| Builtin\n");
    printf("--------|--------|--------|--------\n");

    for (int i = 0; i < num_tests; i++) {
        unsigned int v = test_values[i];

        unsigned int res_naive = count_trailing_zeros_naive(v);
        unsigned int res_bitwalk = count_trailing_zeros_bitwalk(v);
        unsigned int res_builtin = count_trailing_zeros_builtin(v);

        printf("%u\t| %u\t| %u\t| %u\n", v, res_naive, res_bitwalk, res_builtin);
    }

    printf("\nAll methods should return the number of trailing zero bits.\n");

    return 0;
}
