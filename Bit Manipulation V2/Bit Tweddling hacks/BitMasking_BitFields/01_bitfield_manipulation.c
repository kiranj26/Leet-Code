#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/*
 * ============================================================================
 * BITFIELD MANIPULATION - SET / CLEAR / TOGGLE / TEST BITS
 * ============================================================================
 * 
 * This file demonstrates how to manipulate individual bits inside an integer
 * using pure bitwise operators. This is the foundation for embedded firmware
 * register control, hardware drivers, protocols, and RTOS kernel flags.
 * 
 * LEARNING OBJECTIVES:
 * 1. Build complete bitfield toolkit: set, clear, toggle, test
 * 2. Understand how masks are constructed using shift operators
 * 3. Build fully branchless, MCU-friendly bit control functions
 * 4. Prepare for embedded firmware interview questions
 */

/* SET BIT */
unsigned int set_bit(unsigned int num, unsigned int pos) {
    return num | (1 << pos);
}

/* CLEAR BIT */
unsigned int clear_bit(unsigned int num, unsigned int pos) {
    return num & ~(1 << pos);
}

/* TOGGLE BIT */
unsigned int toggle_bit(unsigned int num, unsigned int pos) {
    return num ^ (1 << pos);
}

/* TEST BIT */
bool test_bit(unsigned int num, unsigned int pos) {
    return (num & (1 << pos)) != 0;
}

int main() {
    unsigned int num = 0b10101010;  // Starting value: 170 decimal
    unsigned int positions[] = {0, 1, 3, 5, 7};
    int num_positions = sizeof(positions) / sizeof(positions[0]);

    printf("Bitfield Manipulation Test Results:\n");
    printf("Original number: %u (binary: 0b10101010)\n\n", num);

    for (int i = 0; i < num_positions; i++) {
        unsigned int pos = positions[i];
        printf("--- Bit Position %u ---\n", pos);

        unsigned int set_result = set_bit(num, pos);
        unsigned int clear_result = clear_bit(num, pos);
        unsigned int toggle_result = toggle_bit(num, pos);
        bool test_result = test_bit(num, pos);

        printf("Set:     %u\n", set_result);
        printf("Clear:   %u\n", clear_result);
        printf("Toggle:  %u\n", toggle_result);
        printf("Test:    %s\n\n", test_result ? "SET" : "NOT SET");
    }

    return 0;
}
