#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/*
 * ============================================================================
 * ISOLATE RIGHTMOST SET BIT - COMPREHENSIVE BIT MANIPULATION TECHNIQUES
 * ============================================================================
 * 
 * This file demonstrates multiple approaches to isolate the rightmost set bit
 * of an unsigned integer. This is one of the most heavily used tricks in embedded
 * RTOS kernels, schedulers, priority encoders, DMA controllers, and interview problems.
 * 
 * LEARNING OBJECTIVES:
 * 1. Build intuition for how subtraction flips bits.
 * 2. Understand how two's complement negation allows isolation.
 * 3. Explore multiple branchless hardware-safe solutions.
 * 4. Prepare for embedded firmware interview mastery.
 */

/*
 * APPROACH 1: SUBTRACTION DIFFERENCE METHOD
 * ==========================================
 * Formula: v - (v & (v - 1))
 * 
 * HOW IT WORKS:
 * - v & (v - 1) clears the rightmost 1 bit.
 * - Subtracting that result from original v leaves only the cleared bit position.
 * 
 * EXAMPLE:
 * v = 40 (101000)
 * v & (v - 1) = 32 (100000)
 * v - (v & (v - 1)) = 8 (00001000)
 * 
 * BENEFITS:
 * ✅ Fully branchless
 * ✅ Easy to derive from rightmost clear formula
 * ✅ Excellent for firmware kernels
 */
unsigned int isolate_rightmost_set_bit_subtraction(unsigned int v) {
    return v - (v & (v - 1));
}

/*
 * APPROACH 2: TWO'S COMPLEMENT NEGATION METHOD (Most Famous)
 * ===========================================================
 * Formula: v & -v
 * 
 * HOW IT WORKS:
 * - In two's complement, -v = (~v + 1)
 * - When ANDed, only the lowest set bit remains.
 * 
 * EXAMPLE:
 * v = 40 (101000)
 * -v = (~101000 + 1) = 011000
 * v & -v = 00001000
 * 
 * BENEFITS:
 * ✅ Extremely fast: 1 instruction on most hardware
 * ✅ Fully branchless
 * ✅ Industry standard embedded kernel trick
 * ✅ Used directly in ARM CLZ/CTZ instructions
 */
unsigned int isolate_rightmost_set_bit_twos_complement(unsigned int v) {
    return v & -v;
}

/*
 * APPROACH 3: SAFETY CHECKED VERSION (Defensive Programming)
 * ===========================================================
 * - Handles v = 0 case to prevent meaningless output.
 */
unsigned int isolate_rightmost_set_bit_safe(unsigned int v) {
    if (v == 0)
        return 0;  // No set bit exists
    return v & -v;
}

int main() {
    unsigned int test_values[] = {0, 1, 2, 3, 4, 5, 6, 8, 12, 20, 40, 63, 64, 128, 255, 1024, UINT_MAX};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    printf("Isolate Rightmost Set Bit Test Results:\n");
    printf("Value\t| Subtraction\t| Two's Complement\t| Safe\n");
    printf("--------|--------------|-------------------|--------\n");

    for (int i = 0; i < num_tests; i++) {
        unsigned int v = test_values[i];

        unsigned int res_sub = isolate_rightmost_set_bit_subtraction(v);
        unsigned int res_twos = isolate_rightmost_set_bit_twos_complement(v);
        unsigned int res_safe = isolate_rightmost_set_bit_safe(v);

        printf("%u\t| %u\t\t| %u\t\t| %u\n", v, res_sub, res_twos, res_safe);
    }

    printf("\nAll approaches should return value where only rightmost 1-bit remains.\n");

    return 0;
}
