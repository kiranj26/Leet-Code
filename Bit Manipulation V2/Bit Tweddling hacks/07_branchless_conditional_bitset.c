#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
 * =========================================================================
 * BRANCHLESS CONDITIONAL BIT SET / CLEAR - PURE BIT MANIPULATION
 * =========================================================================
 * 
 * This file demonstrates how to conditionally set or clear bits in a word
 * without using branching (if/else). These tricks are heavily used in firmware,
 * real-time kernels, register access, ISRs, and protocol stacks.
 * 
 * We present two fully explained approaches below.
 * 
 * =========================================================================
 * APPROACH 1: XOR-AND-XOR FORMULA
 * =========================================================================
 * FORMULA: w ^= (-f ^ w) & m;
 * 
 * LEARNING OBJECTIVES:
 * 1. Convert boolean flag to full-word mask:
 *    - If f == 1 --> -f = 0xFFFFFFFF
 *    - If f == 0 --> -f = 0x00000000
 * 
 * 2. WHY XOR FIRST:
 *    - XOR with 0 leaves bit unchanged.
 *    - XOR with 1 flips the bit.
 *    - For f==1: (-f ^ w) becomes ~w (inverts w)
 *    - For f==0: (-f ^ w) becomes w itself.
 * 
 * 3. WHY AND NEXT:
 *    - AND with mask m isolates only the bits we care about.
 *    - Everything outside m gets cleared to 0.
 * 
 * 4. FINAL XOR APPLICATION:
 *    - XOR applies conditional flipping back into w.
 *    - XOR leaves unmasked bits unchanged.
 *    - XOR flips masked bits if needed.
 * 
 * This approach is very compact and eliminates all branching, but involves multiple operations per cycle.
 * 
 * =========================================================================
 * APPROACH 2: AND-OR FORMULA (SUPERSCALAR FRIENDLY)
 * =========================================================================
 * FORMULA: w = (w & ~m) | (-f & m);
 * 
 * LEARNING OBJECTIVES:
 * 1. (w & ~m):
 *    - First clears all bits selected by mask m.
 *    - Bits not in m remain unchanged.
 * 
 * 2. (-f & m):
 *    - If f == 1, produces full mask m (set those bits).
 *    - If f == 0, produces zero (no changes applied).
 * 
 * 3. OR operation:
 *    - Merges the newly prepared set bits into cleared word.
 *    - Cleanly simulates both set and clear without any branching.
 * 
 * This formula is often easier for the CPU to pipeline and optimize.
 */

/* Version 1: XOR-AND-XOR formula */
uint32_t conditional_bitset_xor(uint32_t w, uint32_t m, bool f) {
    return w ^ ((-f ^ w) & m);
}

/* Version 2: AND-OR formula (superscalar friendly) */
uint32_t conditional_bitset_andor(uint32_t w, uint32_t m, bool f) {
    return (w & ~m) | (-f & m);
}

/* Helper to print binary (for learning purpose) */
void print_binary(uint32_t val) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (val >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
}

int main() {
    // Test example selected carefully for learning step-by-step walkthrough
    uint32_t test_w = 0b10101010;  // original word
    uint32_t test_m = 0b00001100;  // mask selecting bits 2 and 3

    printf("Original Word (w):        ");
    print_binary(test_w); printf("\n");
    printf("Mask (m):                ");
    print_binary(test_m); printf("\n\n");

    for (int flag = 0; flag <= 1; flag++) {
        printf("=== Testing with f = %d ===\n", flag);

        uint32_t res_xor = conditional_bitset_xor(test_w, test_m, flag);
        uint32_t res_andor = conditional_bitset_andor(test_w, test_m, flag);

        printf("XOR-AND-XOR Result:       ");
        print_binary(res_xor); printf("\n");

        printf("AND-OR Result:            ");
        print_binary(res_andor); printf("\n\n");
    }

    return 0;
}