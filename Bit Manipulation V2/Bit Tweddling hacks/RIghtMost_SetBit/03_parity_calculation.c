#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/*
 * ============================================================================
 * PARITY CALCULATION - COMPREHENSIVE BIT MANIPULATION TECHNIQUES
 * ============================================================================
 * 
 * This file demonstrates multiple ways to calculate the parity (even or odd number
 * of set bits) of an unsigned integer.
 * 
 * LEARNING OBJECTIVES:
 * 1. Understand XOR folding to compute parity
 * 2. Explore naive vs. highly efficient embedded-friendly techniques
 * 3. Learn real-time branchless methods widely used in embedded protocols
 * 4. Prepare for embedded firmware interview questions
 */

/*
 * APPROACH 1: NAIVE POPCOUNT THEN MODULO METHOD
 * ==============================================
 * 
 * HOW IT WORKS:
 * - First count set bits using popcount (from earlier lessons)
 * - Then check if count is odd by modulo 2
 * 
 * BENEFITS:
 * ✅ Fully portable and easy to understand
 * ✅ Fully correct
 * 
 * DRAWBACKS:
 * ❌ Slower, requires full popcount computation
 */
unsigned int count_set_bits_kernighan(unsigned int v) {
    unsigned int count = 0;
    while (v) {
        v = v & (v - 1);
        count++;
    }
    return count;
}

bool parity_naive(unsigned int v) {
    unsigned int pop = count_set_bits_kernighan(v);
    return (pop % 2) ? 1 : 0;
}

/*
 * APPROACH 2: XOR FOLDING METHOD (Highly Efficient)
 * ===================================================
 * 
 * HOW IT WORKS:
 * - Repeatedly fold bits by XORing halves
 * - Parity information bubbles down to least significant bit
 * 
 * FORMULA:
 * v ^= v >> 16;
 * v ^= v >> 8;
 * v ^= v >> 4;
 * v ^= v >> 2;
 * v ^= v >> 1;
 * 
 * FINAL PARITY: v & 1
 * 
 * BENEFITS:
 * ✅ Extremely fast
 * ✅ Branchless
 * ✅ Industry-standard for embedded parity calculation
 */
bool parity_xor_folding(unsigned int v) {
    v ^= v >> 16;
    v ^= v >> 8;
    v ^= v >> 4;
    v ^= v >> 2;
    v ^= v >> 1;
    return v & 1;
}

/*
 * APPROACH 3: BUILTIN POPCOUNT + MODULO (Compiler Optimization)
 * ==============================================================
 * 
 * HOW IT WORKS:
 * - Uses __builtin_popcount if compiler supports it
 * 
 * BENEFITS:
 * ✅ Extremely fast with hardware popcount
 * ✅ Fully portable to compilers that support builtin
 * 
 * DRAWBACKS:
 * ❌ Compiler-specific
 */
bool parity_builtin(unsigned int v) {
    unsigned int pop = __builtin_popcount(v);
    return (pop % 2) ? 1 : 0;
}

int main() {
    unsigned int test_values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 15, 16, 31, 32, 63, 64, 127, 128, 255, 1023, UINT_MAX};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    printf("Parity Calculation Test Results:\n");
    printf("Value\t| Naive\t| XOR Fold\t| Builtin\n");
    printf("--------|--------|----------|--------\n");

    for (int i = 0; i < num_tests; i++) {
        unsigned int v = test_values[i];

        bool res_naive = parity_naive(v);
        bool res_fold = parity_xor_folding(v);
        bool res_builtin = parity_builtin(v);

        printf("%u\t| %d\t| %d\t\t| %d\n", v, res_naive, res_fold, res_builtin);
    }

    printf("\nAll methods should return 0 for even parity and 1 for odd parity.\n");

    return 0;
}
