#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/*
 * ============================================================================
 * CLEAR TRAILING 1's (CLEAR AFTER RIGHTMOST 0) - FULL BIT MANIPULATION STUDY
 * ============================================================================
 * 
 * This file demonstrates how to clear all trailing 1’s after the rightmost zero
 * using bit manipulation. This is a companion trick to rightmost set bit clearing.
 * 
 * LEARNING OBJECTIVES:
 * 1. Build deep intuition behind binary addition and flipping behavior.
 * 2. Derive v & (v+1) as the magic formula.
 * 3. Understand how adding 1 clears trailing ones.
 * 4. Prepare for embedded firmware scheduler, DMA, and interrupt queue designs.
 */

/*
 * APPROACH 1: CORE FORMULA
 * =========================
 * Formula: v & (v + 1)
 * 
 * HOW IT WORKS:
 * - Adding 1 flips all trailing 1’s to 0, and flips the first 0 to 1.
 * - ANDing original value with (v+1) clears all trailing 1’s while preserving upper bits.
 * 
 * EXAMPLES:
 * v = 23 (10111)
 * v+1 = 24 (11000)
 * v & (v+1) = 16 (10000)
 * 
 * BENEFITS:
 * ✅ Fully branchless
 * ✅ Constant time execution
 * ✅ Minimal instructions on MCU
 * ✅ Perfect for RTOS event schedulers
 */
unsigned int clear_trailing_ones(unsigned int v) {
    return v & (v + 1);
}

/*
 * APPROACH 2: FOR LEARNING - VERBOSE STEP SIMULATION
 * ===================================================
 * Demonstrates addition and masking step-by-step.
 */
unsigned int clear_trailing_ones_verbose(unsigned int v) {
    unsigned int v_plus_one = v + 1;
    unsigned int result = v & v_plus_one;
    return result;
}

/*
 * APPROACH 3: SAFETY CHECKED VERSION (DEFENSIVE)
 * ===============================================
 * - Handles v = 0 gracefully.
 * - For v=0, nothing to clear.
 */
unsigned int clear_trailing_ones_safe(unsigned int v) {
    if (v == 0)
        return 0;
    return v & (v + 1);
}

int main() {
    unsigned int test_values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 15, 20, 23, 31, 32, 40, 63, 64, 127, 255, 1023, UINT_MAX};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    printf("Clear Trailing 1s Test Results:\n");
    printf("Value\t| Core\t| Verbose\t| Safe\n");
    printf("--------|--------|------------|--------\n");

    for (int i = 0; i < num_tests; i++) {
        unsigned int v = test_values[i];

        unsigned int res_core = clear_trailing_ones(v);
        unsigned int res_verbose = clear_trailing_ones_verbose(v);
        unsigned int res_safe = clear_trailing_ones_safe(v);

        printf("%u\t| %u\t| %u\t\t| %u\n", v, res_core, res_verbose, res_safe);
    }

    printf("\nAll approaches should return v with trailing 1’s cleared.\n");

    return 0;
}
