#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * ============================================================================
 * ABSOLUTE VALUE USING BIT MANIPULATION TECHNIQUES
 * ============================================================================
 * 
 * This file demonstrates multiple branchless techniques to compute the absolute
 * value of a signed integer using bit manipulation. All methods avoid branches
 * and work efficiently on modern embedded processors.
 * 
 * LEARNING OBJECTIVES:
 * 1. Extract sign using arithmetic shifts.
 * 2. Apply conditional negation without using branches.
 * 3. Leverage two's complement properties to derive bitwise formulas.
 * 4. Build hardware-friendly code with minimal instructions.
 */

/*
 * APPROACH 1: Using Arithmetic Right Shift and XOR Formula
 * =========================================================
 * Formula: abs(v) = (v + mask) ^ mask
 * 
 * HOW IT WORKS:
 * - mask = v >> 31 extracts sign (0 if positive, -1 if negative)
 * - Adding mask adjusts value: no change if mask = 0, subtracts 1 if mask = -1
 * - XOR with mask flips bits if negative, leaves unchanged if positive
 * 
 * BENEFITS:
 * ✅ Fully branchless
 * ✅ Minimal instructions
 * ✅ Excellent for embedded systems
 * ✅ Efficient on ARM Cortex-M, x86, etc.
 */
int abs_approach1_shift_xor(int v) {
    int mask = v >> 31;
    return (v + mask) ^ mask;
}

/*
 * APPROACH 2: Using XOR and Subtraction (Alternate Form)
 * ========================================================
 * Formula: abs(v) = (v ^ mask) - mask
 * 
 * HOW IT WORKS:
 * - Same as Approach 1, just rearranged algebraically.
 * - For positive numbers, mask = 0 → returns v
 * - For negative numbers, mask = -1 → performs two's complement negation
 * 
 * BENEFITS:
 * ✅ Equally efficient as Approach 1
 * ✅ Sometimes preferred by compiler optimizers
 */
int abs_approach2_xor_subtract(int v) {
    int mask = v >> 31;
    return (v ^ mask) - mask;
}

/*
 * APPROACH 3: Portable Comparison-based Method (Standard Logic)
 * ==============================================================
 * Formula: (v >= 0) ? v : -v
 * 
 * HOW IT WORKS:
 * - Traditional conditional logic to compute absolute value
 * - Always portable across all platforms
 * 
 * BENEFITS:
 * ✅ 100% portable
 * ✅ Most readable
 * ✅ Compiler often optimizes to branchless code on modern CPUs
 * 
 * DRAWBACKS:
 * ❌ May introduce branches depending on compiler & target architecture
 */
int abs_approach3_comparison(int v) {
    return (v >= 0) ? v : -v;
}

/*
 * APPROACH 4: Using Standard Library (for reference)
 * ===================================================
 * Formula: abs(v) (from <stdlib.h>)
 * 
 * WHY INCLUDE:
 * - For completeness
 * - Standard C library function
 */
int abs_approach4_stdlib(int v) {
    return abs(v);
}

int main() {
    // Test values including edge cases
    int test_values[] = {10, -5, 0, -15, 42, -100, 255, -255, INT_MAX, INT_MIN, 1, -1};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    printf("Absolute Value Bit Manipulation Test Results:\n");
    printf("Value\t| Shift+XOR\t| XOR-Sub\t| Compare\t| Stdlib\n");
    printf("--------|------------|----------|----------|---------\n");

    for (int i = 0; i < num_tests; i++) {
        int v = test_values[i];

        int res1 = abs_approach1_shift_xor(v);
        int res2 = abs_approach2_xor_subtract(v);
        int res3 = abs_approach3_comparison(v);
        int res4 = abs_approach4_stdlib(v);

        printf("%d\t| %d\t\t| %d\t\t| %d\t\t| %d\n", v, res1, res2, res3, res4);
    }

    printf("\nAll approaches should match: output is always non-negative absolute value.\n");

    return 0;
}