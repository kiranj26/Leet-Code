/******************************************************************************
 * File:    change_bits_clear_only.c
 * Author:  Kiran Jojare  (Embedded SW / Firmware Engineer)
 * ----------------------------------------------------------------------------
 * LeetCode-Style Problem (Custom):
 * --------------------------------
 * Given two **positive 32-bit integers** `n` and `k`, determine whether it is
 * possible to transform `n` into `k` **by flipping ONLY bits that are 1 in `n`
 * to 0** (you may NOT turn a 0 into a 1).  
 *
 * Tasks
 *  1️⃣  Decide if the transformation is possible.
 *  2️⃣  If possible, compute the **minimum number of bit flips** required.  
 *  3️⃣  (Optional) Return the transformed value (should equal `k` when allowed).
 *
 * Constraints
 *  • 0 ≤ n, k ≤ 2³² − 1 (treat as `uint32_t`)  
 *  • Time: O(1) Space: O(1)
 *
 * ============================================================================
 * LEARNING OBJECTIVES (for future quick revision)
 * -----------------------------------------------
 * ✅  Bit Masks & Set/Clear Logic
 *      – `~x` creates a “negative mask” selecting the zeros of x.
 * ✅  Permission Check (subset test)
 *      – We may clear bits, never set bits ⟹ every 1 in k must already be 1 in n.
 *      – Condition: `(k & ~n) == 0`.
 * ✅  Counting 1-bits  ➜ Hamming Distance where flips are allowed
 *      – Bits that *must be flipped* are `n & ~k`  (1 in n, 0 in k).
 *      – Count them with Brian Kernighan trick: `x &= (x-1)` removes lowest set 1.
 * ✅  Boolean Algebra Shortcut
 *      – Performing the transformation is just `n & k` because AND clears disallowed 1s.
 *
 * ============================================================================
 * Compilation
 *   $ gcc -Wall -Wextra -std=c11 change_bits_clear_only.c -o change_bits
 *
 * Sample Run
 *   $ ./change_bits 15 10
 *   n = 0b00000000000000000000000000001111 (15)
 *   k = 0b00000000000000000000000000001010 (10)
 *   ✅ Possible, flips needed = 2
 *
 *   $ ./change_bits 8 12
 *   n = 0b00000000000000000000000000001000 (8)
 *   k = 0b00000000000000000000000000001100 (12)
 *   ❌ Not possible (would require setting bits)
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>

/* ---------- Utility: print a binary representation (for learning clarity) */
static void print_binary32(uint32_t x)
{
    for (int i = 31; i >= 0; --i) {
        putchar((x >> i) & 1U ? '1' : '0');
        if (i % 4 == 0 && i) putchar('_');   /* nibble separator for readability */
    }
}

/* ---------- Count set bits using Kernighan’s trick */
static unsigned popcount32(uint32_t x)
{
    unsigned cnt = 0;
    while (x) {
        x &= (x - 1);   /* clears lowest-set 1 bit */
        ++cnt;
    }
    return cnt;
}

/* ---------- Core API ----------------------------------------------------- */
/**
 *  transform_clear_only
 *  --------------------
 *  @param  n          Original value
 *  @param  k          Desired target
 *  @param  flips_out  Pointer where the function writes “how many flips
 *                     are needed”; undefined if impossible
 *  @return true  if transformation is possible
 *          false otherwise
 */
static bool transform_clear_only(uint32_t  n,
                                 uint32_t  k,
                                 unsigned *flips_out)
{
    /* 1. Permission check: ensure we never need 0 → 1 */
    if ( (k & ~n) != 0U )
        return false;

    /* 2. Bits that must flip are the 1s unique to n  */
    uint32_t to_flip = n & ~k;
    *flips_out = popcount32(to_flip);

    /* Optional: if we cared to return the new value, it is simply n & k      */
    /* uint32_t new_value = n & k;                                            */

    return true;
}

/* ---------------------------  Demo / Driver  ----------------------------- */
int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <n> <k>\n", argv[0]);
        return EXIT_FAILURE;
    }

    uint32_t n = (uint32_t)strtoul(argv[1], NULL, 0);  /* accepts dec/hex/0b */
    uint32_t k = (uint32_t)strtoul(argv[2], NULL, 0);

    printf("n = 0b"); print_binary32(n); printf(" (%" PRIu32 ")\n", n);
    printf("k = 0b"); print_binary32(k); printf(" (%" PRIu32 ")\n", k);

    unsigned flips = 0;
    if (transform_clear_only(n, k, &flips)) {
        printf("✅ Possible, flips needed = %u\n", flips);
        /* Uncomment to show final value
         * printf("Transformed value = %" PRIu32 "\n", (n & k));
         */
    } else {
        printf("❌ Not possible (would require setting bits)\n");
    }

    return EXIT_SUCCESS;
}

/*** END OF FILE *************************************************************/
