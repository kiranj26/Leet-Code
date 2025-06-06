#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
 * ============================================================================
 * CONDITIONAL NEGATION WITHOUT BRANCHING - PURE BIT MANIPULATION
 * ============================================================================
 * 
 * This file demonstrates how to conditionally negate a value without using any branching.
 * This trick is extremely useful in embedded firmware, protocol stacks, DSP kernels,
 * register manipulation, and tight ISR loops where branching can cause performance stalls.
 * 
 * ============================================================================
 * LEARNING OBJECTIVES:
 * ============================================================================
 * 
 * PROBLEM: Perform: result = fNegate ? -v : v; WITHOUT any branching.
 * 
 * -------------------------------------------------------------
 * STEP 1: Convert boolean flag to full 32-bit mask using -fNegate:
 * -------------------------------------------------------------
 *   - If fNegate == 1 --> -fNegate = -1 = 0xFFFFFFFF (all bits set)
 *   - If fNegate == 0 --> -fNegate =  0 = 0x00000000 (all bits clear)
 * 
 * This allows us to turn boolean condition into a full-word mask.
 * 
 * -------------------------------------------------------------
 * STEP 2: Flip v bits conditionally using XOR:
 * -------------------------------------------------------------
 *   - XOR with 0 leaves bit unchanged
 *   - XOR with 1 flips bit
 * 
 *   Formula: (v ^ -fNegate)
 * 
 *   - If fNegate == 0 --> v ^ 0 = v (no negation)
 *   - If fNegate == 1 --> v ^ 0xFFFFFFFF = ~v (partial negation)
 * 
 * -------------------------------------------------------------
 * STEP 3: Apply Two's Complement (+1) Only When Needed:
 * -------------------------------------------------------------
 *   - Full negation requires: -v = ~v + 1
 * 
 *   - We already have ~v from XOR above.
 *   - We now add fNegate itself:
 *       (v ^ -fNegate) + fNegate
 * 
 *   - If fNegate == 0 --> adding 0 --> keeps value unchanged
 *   - If fNegate == 1 --> adding 1 --> completes full two's complement negation
 * 
 * ============================================================================
 */

/* The full conditional negation function */
int conditional_negate(int v, bool fNegate) {
    return (v ^ -fNegate) + fNegate;
}

int main() {
    int test_values[] = {10, -15, 0, 12345, -32768};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    printf("Conditional Negation Without Branching:\n\n");
    for (int i = 0; i < num_tests; i++) {
        int v = test_values[i];

        for (int flag = 0; flag <= 1; flag++) {
            int result = conditional_negate(v, flag);
            printf("v = %6d, fNegate = %d --> result = %6d\n", v, flag, result);
        }
        printf("\n");
    }

    return 0;
}
