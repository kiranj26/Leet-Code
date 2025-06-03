#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/*
 * ============================================================================
 * POWER OF TWO DETECTION - COMPREHENSIVE BIT MANIPULATION TECHNIQUES
 * ============================================================================
 * 
 * This file demonstrates multiple approaches to detect whether a given
 * integer is a power of two using bit manipulation. This problem teaches
 * one of the most elegant and interview-critical binary tricks.
 * 
 * LEARNING OBJECTIVES:
 * 1. Understand binary properties of powers of 2
 * 2. Derive conditional tests using subtraction and AND operations
 * 3. Handle zero as a special case
 * 4. Build fully branchless embedded-friendly solutions
 * 5. Prepare for high-frequency embedded/firmware interview questions
 */

/*
 * APPROACH 1: NAIVE LOOPING METHOD (For Learning Only)
 * ======================================================
 * 
 * HOW IT WORKS:
 * - Loops through each bit position to count how many bits are set.
 * - If only one bit is set, then it's a power of 2.
 * 
 * BENEFITS:
 * ✅ Fully portable
 * ✅ Easy to understand conceptually
 * 
 * DRAWBACKS:
 * ❌ Slow for large integers
 * ❌ Involves loops and branches
 * ❌ Not efficient for embedded real-time systems
 */
bool is_power_of_two_loop(unsigned int v) {
    int count = 0;
    for (int i = 0; i < sizeof(unsigned int) * CHAR_BIT; i++) {
        if (v & (1U << i)) count++;
    }
    return (count == 1);
}

/*
 * APPROACH 2: CORE BITWISE TRICK (Main Formula)
 * ==============================================
 * Formula: (v & (v - 1)) == 0
 * 
 * HOW IT WORKS:
 * - For any power of 2, only one bit is set.
 * - Subtracting 1 flips all bits below that set bit.
 * - AND operation clears that single bit, leaving 0 if power of 2.
 * 
 * EXAMPLES:
 *   v = 8:  1000 & 0111 → 0000
 *   v = 6:  0110 & 0101 → 0100
 * 
 * EMBEDDED SYSTEMS CONCERNS:
 * ✅ Fully branchless
 * ✅ 1-2 CPU instructions
 * ✅ Excellent for real-time code
 * ❌ Incorrectly classifies 0 as power of 2
 */
bool is_power_of_two_basic(unsigned int v) {
    return (v & (v - 1)) == 0;
}

/*
 * APPROACH 3: FULLY CORRECTED FORMULA (Best Practice)
 * ====================================================
 * Formula: v && !(v & (v - 1))
 * 
 * HOW IT WORKS:
 * - Adds check to exclude zero explicitly.
 * - Fully accurate across all possible inputs.
 * 
 * BENEFITS:
 * ✅ Fully correct
 * ✅ Fully branchless
 * ✅ Embedded-safe
 * ✅ High-performance inner loop safe
 */
bool is_power_of_two_safe(unsigned int v) {
    return v && !(v & (v - 1));
}

/*
 * APPROACH 4: PORTABLE PURE BOOLEAN FORMULATION
 * ==============================================
 * Formula: (v != 0) && ((v & (v - 1)) == 0)
 * 
 * HOW IT WORKS:
 * - Exact same logic as Approach 3, rewritten for clarity.
 * - Compiler will typically optimize to same instructions.
 * 
 * BENEFITS:
 * ✅ 100% portable
 * ✅ Fully expressive for interviews
 */
bool is_power_of_two_portable(unsigned int v) {
    return (v != 0) && ((v & (v - 1)) == 0);
}

int main() {
    // Test values including edge cases and typical scenarios
    unsigned int test_values[] = {0, 1, 2, 3, 4, 5, 8, 16, 32, 64, 127, 128, 255, 256, 1023, 1024, UINT_MAX};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    printf("Power of Two Detection Test Results:\n");
    printf("Value\t| Loop\t| Basic\t| Safe\t| Portable\n");
    printf("--------|--------|--------|--------|----------\n");

    for (int i = 0; i < num_tests; i++) {
        unsigned int v = test_values[i];

        bool res_loop = is_power_of_two_loop(v);
        bool res_basic = is_power_of_two_basic(v);
        bool res_safe = is_power_of_two_safe(v);
        bool res_portable = is_power_of_two_portable(v);

        printf("%u\t| %d\t| %d\t| %d\t| %d\n", v, res_loop, res_basic, res_safe, res_portable);
    }

    printf("\nNote: 'Basic' version misclassifies 0 as power of 2. 'Safe' & 'Portable' are fully correct.\n");

    return 0;
}
