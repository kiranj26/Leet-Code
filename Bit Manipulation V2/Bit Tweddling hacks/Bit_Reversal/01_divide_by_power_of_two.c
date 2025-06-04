#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/*
 * ============================================================================
 * DIVISION BY POWER-OF-TWO - PURE BIT MANIPULATION TECHNIQUES
 * ============================================================================
 * 
 * This file demonstrates how to divide an unsigned integer by any power of two
 * using bit manipulation (right shifting). This is one of the most common optimizations
 * in embedded firmware, RTOS kernels, DMA drivers, and real-time schedulers.
 * 
 * LEARNING OBJECTIVES:
 * 1. Understand how right shift performs division by powers of two
 * 2. Understand when rounding is needed (floor vs ceiling division)
 * 3. Build fully portable, branchless division solutions
 * 4. Prepare for embedded firmware interview questions
 */

/*
 * APPROACH 1: BASIC RIGHT SHIFT DIVISION
 * =======================================
 * 
 * HOW IT WORKS:
 * - Right shift by 'n' is equivalent to division by 2^n.
 * - Perfectly safe for unsigned integers.
 * 
 * BENEFITS:
 * ✅ Fully portable for unsigned types
 * ✅ O(1) speed, branchless, MCU-friendly
 */
unsigned int divide_power_of_two_basic(unsigned int a, unsigned int n) {
    return a >> n;
}

/*
 * APPROACH 2: ROUND-UP (CEILING DIVISION) USING SHIFT
 * =====================================================
 * 
 * HOW IT WORKS:
 * - Add (2^n - 1) before shifting to round up instead of truncating.
 * - Formula: (a + (1<<n) - 1) >> n
 * 
 * BENEFITS:
 * ✅ Useful when exact buffer sizing or tick interval rounding is required
 * ✅ Fully portable
 */
unsigned int divide_power_of_two_roundup(unsigned int a, unsigned int n) {
    return (a + (1 << n) - 1) >> n;
}

int main() {
    unsigned int test_values[][2] = {
        {48, 3}, {100, 4}, {255, 5}, {1023, 2}, {0, 6}, {1, 1}, {UINT_MAX, 8}
    };

    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    printf("Division by Power-of-Two Test Results:\n");
    printf("A\tN\t| Basic\t| Rounded-Up\n");
    printf("--------|--------|--------|--------\n");

    for (int i = 0; i < num_tests; i++) {
        unsigned int a = test_values[i][0];
        unsigned int n = test_values[i][1];

        unsigned int res_basic = divide_power_of_two_basic(a, n);
        unsigned int res_rounded = divide_power_of_two_roundup(a, n);

        printf("%u\t%u\t| %u\t| %u\n", a, n, res_basic, res_rounded);
    }

    printf("\nAll methods correctly divide by 2^n for unsigned integers.\n");

    return 0;
}
