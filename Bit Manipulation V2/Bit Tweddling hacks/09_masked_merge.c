#include <stdio.h>
#include <stdint.h>

/*
 * =============================================================================
 * MERGE BITS FROM TWO VALUES ACCORDING TO MASK - PURE BIT MANIPULATION
 * =============================================================================
 * 
 * This file demonstrates how to merge bits from two values `a` and `b` based on a bit mask,
 * using both the obvious AND/OR approach and the optimized XOR-based approach.
 * 
 * =============================================================================
 * PROBLEM STATEMENT:
 * -------------------
 * Given:
 *   - a: value to take when mask bit is 0
 *   - b: value to take when mask bit is 1
 *   - mask: bitmask deciding which bits come from a or b
 * 
 * Classical formula:
 *   result = (a & ~mask) | (b & mask);
 * 
 * =============================================================================
 * XOR-BASED OPTIMIZATION (FULLY DERIVED STEP-BY-STEP):
 * -----------------------------------------------------
 * 1. Compute difference between a and b:
 *      diff = a ^ b;
 *      - This gives 1 for bits where a and b differ, 0 where they match.
 * 
 * 2. Apply mask to select only the differences we care about:
 *      selected_diff = diff & mask;
 * 
 * 3. Apply XOR to flip only those selected differences into a:
 *      result = a ^ selected_diff;
 * 
 * Combined into a single formula:
 *      result = a ^ ((a ^ b) & mask);
 * 
 * This form saves one operation and avoids both AND and OR.
 * 
 * =============================================================================
 * LEARNING OBJECTIVES:
 * ---------------------
 * 1. Learn how XOR reveals bitwise differences between values.
 * 2. Learn how AND masks isolate which differences to apply.
 * 3. Learn how XOR flips selected bits efficiently.
 * 4. Build firmware-grade mental model for register-level masked updates.
 * =============================================================================
 */

/* Classical AND/OR implementation */
uint32_t merge_and_or(uint32_t a, uint32_t b, uint32_t mask) {
    return (a & ~mask) | (b & mask);
}

/* XOR-based optimized implementation */
uint32_t merge_xor(uint32_t a, uint32_t b, uint32_t mask) {
    return a ^ ((a ^ b) & mask);
}

/* Helper to print binary values (for visualization) */
void print_binary(uint32_t val, int bits) {
    for (int i = bits-1; i >= 0; i--) {
        printf("%d", (val >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
}

int main() {
    uint32_t a = 0b0101;    // Example value a (5)
    uint32_t b = 0b1000;    // Example value b (8)
    uint32_t mask = 0b1001; // Selective mask

    printf("Input values:\n");
    printf("a:     "); print_binary(a, 4); printf("\n");
    printf("b:     "); print_binary(b, 4); printf("\n");
    printf("mask:  "); print_binary(mask, 4); printf("\n\n");

    uint32_t result_and_or = merge_and_or(a, b, mask);
    uint32_t result_xor = merge_xor(a, b, mask);

    printf("Classical AND/OR result: "); print_binary(result_and_or, 4); printf("\n");
    printf("Optimized XOR result:    "); print_binary(result_xor, 4); printf("\n");

    return 0;
}
