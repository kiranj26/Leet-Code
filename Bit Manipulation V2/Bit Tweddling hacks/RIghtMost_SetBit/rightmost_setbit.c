/********************************************************************************
 *
 * Rightmost Set Bit - Bit Twiddling Hacks
 * ======================================
 *
 * This file demonstrates multiple approaches to computing the index of the
 * rightmost set bit in an integer using bit manipulation.
 *
 ********************************************************************************/

 // This  is a swiss army kniwfe for bit manipulation i.e v & (v-1)

 // Lets fully understand how v & v-1 turns off righmost set bit
 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/*
 * ============================================================================
 * RIGHTMOST SET BIT - COMPREHENSIVE BIT MANIPULATION TECHNIQUE
 * ============================================================================
 * 
 * This file demonstrates one of the most powerful bit manipulation tricks:
 * Turning off (clearing) the rightmost set bit using:
 * 
 * Formula: v & (v - 1)
 * 
 * LEARNING OBJECTIVES:
 * 1. Understand how subtracting 1 flips lower bits.
 * 2. Learn how to clear rightmost 1-bit efficiently.
 * 3. Explore how this trick becomes the foundation of multiple advanced algorithms.
 * 4. Build a reusable embedded-systems friendly primitive for future algorithms.
 * 5. Prepare for interviews and low-level firmware optimizations.
 */

/*
 * APPROACH 1: CORE FORMULA
 * =========================
 * Formula: v & (v - 1)
 * 
 * HOW IT WORKS:
 * - Subtracting 1 flips all bits to the right of the rightmost set bit.
 * - ANDing it with original number clears only the rightmost set bit.
 * 
 * EXAMPLES:
 * v = 12 (1100), v-1 = 11 (1011) → result = 1000
 * v = 20 (10100), v-1 = 19 (10011) → result = 10000
 * 
 * EMBEDDED SYSTEMS BENEFITS:
 * ✅ Branchless
 * ✅ Extremely fast: 1-2 CPU instructions
 * ✅ Excellent for RTOS kernel bitmaps, resource managers, DMA, schedulers
 */
unsigned int turn_off_rightmost_set_bit(unsigned int v) {
    return v & (v - 1);
}

/*
 * APPROACH 2: FOR LEARNING - SIMULATE BIT FLIPPING STEP-BY-STEP
 * ==============================================================
 * Pure educational version to walk through flipping behavior.
 */
unsigned int turn_off_rightmost_set_bit_verbose(unsigned int v) {
    unsigned int v_minus_one = v - 1;
    unsigned int result = v & v_minus_one;
    return result;
}

/*
 * APPROACH 3: SPECIAL CASE HANDLING (DEFENSIVE PROGRAMMING)
 * ==========================================================
 * - In case v = 0, no set bits exist, result is still 0.
 * - This is fully safe for unsigned integers.
 */
unsigned int turn_off_rightmost_set_bit_safe(unsigned int v) {
    if (v == 0)
        return 0;
    return v & (v - 1);
}

int main() {
    unsigned int test_values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 15, 16, 31, 32, 63, 64, 127, 128, UINT_MAX};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    printf("Rightmost Set Bit - Clear Test Results:\n");
    printf("Value\t| Core\t| Verbose\t| Safe\n");
    printf("--------|--------|------------|--------\n");

    for (int i = 0; i < num_tests; i++) {
        unsigned int v = test_values[i];

        unsigned int res_core = turn_off_rightmost_set_bit(v);
        unsigned int res_verbose = turn_off_rightmost_set_bit_verbose(v);
        unsigned int res_safe = turn_off_rightmost_set_bit_safe(v);

        printf("%u\t| %u\t| %u\t\t| %u\n", v, res_core, res_verbose, res_safe);
    }

    printf("\nAll approaches should return v with rightmost 1-bit cleared.\n");

    return 0;
}
