#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/*
 * ============================================================================
 * OPPOSITE SIGN DETECTION - BIT MANIPULATION TECHNIQUES
 * ============================================================================
 * 
 * This file demonstrates multiple approaches to detect whether two integers
 * have opposite signs using bit manipulation. The XOR method is especially
 * elegant and efficient for embedded systems.
 * 
 * LEARNING OBJECTIVES:
 * 1. Understand XOR behavior in bit manipulation
 * 2. Explore sign bit detection using MSB
 * 3. Differentiate between portable and highly optimized versions
 * 4. Review two's complement behavior when analyzing signs
 */

/*
 * APPROACH 1: XOR SIGN DETECTION METHOD (Highly Efficient)
 * =========================================================
 * Formula: (x ^ y) < 0
 * 
 * HOW IT WORKS:
 * - XOR detects bit differences between x and y.
 * - The sign bit (MSB) differs if and only if signs differ.
 * - If MSB is 1 after XOR, result is negative => opposite signs.
 * 
 * BIT-LEVEL EXPLANATION:
 * Positive XOR Positive -> MSB 0
 * Negative XOR Negative -> MSB 0
 * Positive XOR Negative -> MSB 1
 * 
 * BENEFITS:
 * ✅ Branchless
 * ✅ Extremely fast
 * ✅ Efficient for embedded hardware
 * ✅ Minimal operations (XOR + compare)
 * 
 * DRAWBACKS:
 * ❌ Depends on two's complement representation
 * ❌ Undefined for non-two's complement systems (rare today)
 */
bool opposite_signs_xor(int x, int y) {
    return ((x ^ y) < 0);
}

/*
 * APPROACH 2: BOOLEAN SIGN COMPARISON METHOD (Fully Portable)
 * ============================================================
 * Formula: ( (x >= 0) != (y >= 0) )
 * 
 * HOW IT WORKS:
 * - Separately check whether x and y are non-negative.
 * - If one is non-negative and other is negative, result differs.
 * - Boolean inequality directly tells if signs differ.
 * 
 * BENEFITS:
 * ✅ Fully portable (no assumptions about representation)
 * ✅ Easy to read and maintain
 * ✅ Guaranteed behavior on any C-compliant system
 * 
 * DRAWBACKS:
 * ❌ May involve branches (depending on compiler optimization)
 * ❌ Slightly less efficient than XOR method
 */
bool opposite_signs_portable(int x, int y) {
    return ( (x >= 0) != (y >= 0) );
}

/*
 * APPROACH 3: MSB EXTRACTION METHOD (Bitmask)
 * ===========================================
 * Formula: ((x & SIGN_MASK) != (y & SIGN_MASK))
 * 
 * HOW IT WORKS:
 * - Directly extracts MSB (sign bit) using bitmask
 * - Compares if sign bits differ
 * 
 * BENEFITS:
 * ✅ Branchless
 * ✅ Portable if SIGN_MASK correctly defined
 * ✅ Works for other bit-width integers easily
 * 
 * DRAWBACKS:
 * ❌ Requires careful mask definition
 */
bool opposite_signs_msb_mask(int x, int y) {
    const unsigned int SIGN_MASK = (1U << (sizeof(int) * CHAR_BIT - 1));
    return (( (unsigned int)x & SIGN_MASK ) != ( (unsigned int)y & SIGN_MASK ));
}

int main() {
    // Test value pairs covering various sign combinations
    int test_pairs[][2] = {
        {10, -5}, {5, 0}, {-15, 42}, {0, 0}, {42, 100}, {-100, -50},
        {INT_MAX, INT_MIN}, {-255, 255}, {1, -1}, {-1, -1}, {0, -42}, {42, 0}
    };

    int num_tests = sizeof(test_pairs) / sizeof(test_pairs[0]);

    printf("Opposite Sign Detection Test Results:\n");
    printf("X\tY\t| XOR\t| Boolean\t| MSB Mask\n");
    printf("--------|-----------|-----------|-----------\n");

    for (int i = 0; i < num_tests; i++) {
        int x = test_pairs[i][0];
        int y = test_pairs[i][1];

        bool res_xor = opposite_signs_xor(x, y);
        bool res_bool = opposite_signs_portable(x, y);
        bool res_msb = opposite_signs_msb_mask(x, y);

        printf("%d\t%d\t| %d\t| %d\t\t| %d\n", x, y, res_xor, res_bool, res_msb);
    }

    printf("\nOutput: 1 means opposite signs, 0 means same sign.\n");

    return 0;
}
