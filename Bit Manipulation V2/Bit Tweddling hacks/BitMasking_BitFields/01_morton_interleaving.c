#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

/*
 * ============================================================================
 * BIT INTERLEAVING (MORTON ENCODING) - PURE BIT MANIPULATION TECHNIQUE
 * ============================================================================
 * 
 * This file demonstrates how to interleave two integers into a Morton code
 * (Z-order curve) using pure bitwise operations. This technique is widely used
 * in embedded graphics, DMA optimization, spatial indexing, and firmware-level
 * multidimensional data layouts.
 * 
 * LEARNING OBJECTIVES:
 * 1. Understand bit spreading (bit dilation) concept
 * 2. Derive spreading for even and odd bit positions
 * 3. Assemble Morton encoding using bitwise OR
 * 4. Prepare for advanced embedded firmware interview questions
 */

/* Spread bits of X into even bit positions */
uint32_t spread_bits_x(uint16_t x) {
    uint32_t result = 0;
    for (int i = 0; i < 16; i++) {
        if (x & (1 << i)) {
            result |= (1 << (2 * i));
        }
    }
    return result;
}

/* Spread bits of Y into odd bit positions */
uint32_t spread_bits_y(uint16_t y) {
    uint32_t result = 0;
    for (int i = 0; i < 16; i++) {
        if (y & (1 << i)) {
            result |= (1 << (2 * i + 1));
        }
    }
    return result;
}

/* Morton Encoding: Interleave bits of X and Y */
uint32_t morton_encode(uint16_t x, uint16_t y) {
    return spread_bits_x(x) | spread_bits_y(y);
}

int main() {
    uint16_t test_pairs[][2] = {
        {0b1010, 0b1100}, {0b1111, 0b0000}, {0b0000, 0b1111}, {0b1001, 0b0110},
        {0xFFFF, 0x0000}, {0xAAAA, 0x5555}, {0, 0}
    };

    int num_tests = sizeof(test_pairs) / sizeof(test_pairs[0]);

    printf("Morton Encoding (Bit Interleaving) Test Results:\n");
    printf("X\t\tY\t\t| Morton Code\n");
    printf("---------------------------\n");

    for (int i = 0; i < num_tests; i++) {
        uint16_t x = test_pairs[i][0];
        uint16_t y = test_pairs[i][1];

        uint32_t morton = morton_encode(x, y);

        printf("0x%04X\t0x%04X\t| 0x%08X\n", x, y, morton);
    }

    printf("\nMorton code interleaves bits of X and Y into final 32-bit result.\n");

    return 0;
}
