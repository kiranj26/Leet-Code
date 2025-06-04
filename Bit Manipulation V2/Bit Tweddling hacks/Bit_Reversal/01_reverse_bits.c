#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/*
 * ============================================================================
 * BIT REVERSAL - COMPREHENSIVE BIT MANIPULATION TECHNIQUES
 * ============================================================================
 * 
 * This file demonstrates multiple approaches to reverse all bits in a 32-bit
 * unsigned integer. Bit reversal is heavily used in embedded systems such as:
 * - CRC engines
 * - DMA burst orderings
 * - RTOS schedulers
 * - Network packet bit ordering
 * 
 * LEARNING OBJECTIVES:
 * 1. Build full intuition for naive loop-based reversal
 * 2. Understand divide-and-conquer block swapping method
 * 3. Prepare for firmware interview-level solutions
 */

/*
 * APPROACH 1: NAIVE SHIFTING METHOD (Full Derivation)
 * =====================================================
 * 
 * HOW IT WORKS:
 * - Start with empty result
 * - Extract LSB of v one bit at a time and shift into MSB of result
 * 
 * BENEFITS:
 * ✅ Fully correct
 * ✅ Fully portable
 * ✅ Educationally valuable
 * 
 * DRAWBACKS:
 * ❌ 32 iterations (slow for performance-critical code)
 */
unsigned int reverse_bits_naive(unsigned int v) {
    unsigned int result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;
        result |= (v & 1);
        v >>= 1;
    }
    return result;
}

/*
 * APPROACH 2: DIVIDE-AND-CONQUER BIT SWAPPING (Highly Efficient)
 * ===============================================================
 * 
 * HOW IT WORKS:
 * - Swap bit pairs recursively: halves → bytes → nibbles → pairs → single bits.
 * - Uses masks to isolate and reposition groups of bits.
 * 
 * BENEFITS:
 * ✅ Constant time O(1)
 * ✅ Branchless
 * ✅ Extremely efficient for real-time embedded systems
 */
unsigned int reverse_bits_swapping(unsigned int v) {
    v = ((v >> 16) | (v << 16));
    v = ((v & 0xFF00FF00) >> 8) | ((v & 0x00FF00FF) << 8);
    v = ((v & 0xF0F0F0F0) >> 4) | ((v & 0x0F0F0F0F) << 4);
    v = ((v & 0xCCCCCCCC) >> 2) | ((v & 0x33333333) << 2);
    v = ((v & 0xAAAAAAAA) >> 1) | ((v & 0x55555555) << 1);
    return v;
}

/*
 * APPROACH 3: GCC/CLANG BUILTIN METHOD (Hardware Optimized)
 * ==========================================================
 * 
 * HOW IT WORKS:
 * - Use __builtin_bitreverse32() if compiler supports it.
 * - Directly maps to hardware instruction if available.
 * 
 * BENEFITS:
 * ✅ Extremely fast
 * ✅ Compiler intrinsic for modern toolchains
 * 
 * DRAWBACKS:
 * ❌ Compiler-specific
 */
unsigned int reverse_bits_builtin(unsigned int v) {
    return __builtin_bitreverse32(v);
}

int main() {
    unsigned int test_values[] = {0, 1, 2, 3, 4, 5, 10, 13, 16, 32, 64, 128, 255, 1023, UINT_MAX};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    printf("Bit Reversal Test Results:\n");
    printf("Value\t| Naive\t\t| Swap\t\t| Builtin\n");
    printf("--------|---------------|---------------|--------\n");

    for (int i = 0; i < num_tests; i++) {
        unsigned int v = test_values[i];

        unsigned int res_naive = reverse_bits_naive(v);
        unsigned int res_swap = reverse_bits_swapping(v);
        unsigned int res_builtin = reverse_bits_builtin(v);

        printf("%u\t| %u\t| %u\t| %u\n", v, res_naive, res_swap, res_builtin);
    }

    printf("\nAll methods should return identical reversed results.\n");

    return 0;
}
