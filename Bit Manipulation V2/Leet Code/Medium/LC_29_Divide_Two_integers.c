#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>

/**
 * =========================================================================
 * LeetCode Problem 29 ‒ Divide Two Integers
 * =========================================================================
 *
 *  🔹 Task
 *      - Implement integer division **without** using *, /, or %.
 *      - Return the quotient truncated toward 0.
 *      - Clamp overflow to  INT_MAX  (  2 147 483 647  ).
 *
 *  🔹 Example 1
 *      Input : dividend = 10, divisor = 3
 *      Output: 3     // 10 / 3  = 3.333… → truncate → 3
 *
 *  🔹 Example 2
 *      Input : dividend = 7, divisor = −3
 *      Output: −2    // 7 / −3 = −2.333… → truncate → −2
 *
 * =========================================================================
 * COMPLETE LEARNING OBJECTIVES (for future revision)
 *
 * 1️⃣  Shift-and-Subtract Division (Unsigned Core)
 *     • Align divisor with the dividend’s MSB by left-shifting.
 *     • Scan from bit 31 ↓ 0:
 *         – If (divisor << bit) ≤ remainder → subtract and set bit in quotient.
 *
 * 2️⃣  Bitwise Subtraction with XOR & Borrow
 *     • diff   =  a  ^  b
 *     • borrow = (~a & b) << 1
 *       Repeat until borrow == 0.
 *
 * 3️⃣  Signed Handling
 *     • Sign = (dividend < 0) ⊕ (divisor < 0).
 *     • Work on |dividend| and |divisor| as uint32_t.
 *     • Special cases:
 *         – divisor == 0                → INT_MAX
 *         – dividend == INT_MIN && divisor == −1  → INT_MAX (overflow)
 *         – divisor ±1 fast paths
 *
 * 4️⃣  Complexity
 *     • Time  : O(32)  ≈  O(1)  (constant 32-bit scan)
 *     • Space : O(1)
 *
 * 5️⃣  Interview Insights
 *     • Demonstrates mastery of bit tricks, edge-case vigilance, and overflow safety.
 *     • Faster and cleaner than repeated subtraction or while-loops that count.
 *
 * =========================================================================
 * APPROACH 1:  Bitwise Shift-and-Subtract  (Recommended Solution)
 * -------------------------------------------------------------------------
 */

/* ---------- 1A.  Unsigned bitwise subtraction (XOR+borrow) ---------- */
static inline uint32_t sub_u32(uint32_t a, uint32_t b)
{
    while (b) {
        uint32_t diff   = a ^ b;
        uint32_t borrow = (~a & b) << 1;
        a = diff;
        b = borrow;
    }
    return a;
}

/* ---------- 1B.  Core unsigned division engine ---------- */
static uint32_t divide_unsigned(uint32_t dividend, uint32_t divisor)
{
    if (divisor == 0) return UINT32_MAX;            /* defensive (not reached in caller) */

    uint32_t quo = 0;
    for (int bit = 31; bit >= 0; --bit) {
        /* Safe-shift guard: if shifting left would overflow 32 bits, skip */
        if ((divisor << bit) >> bit != divisor) continue;

        if ((divisor << bit) <= dividend) {
            dividend = sub_u32(dividend, divisor << bit);
            quo     |= (1U << bit);
        }
    }
    return quo;   /* remainder is “dividend” at this point if ever needed */
}

/* ---------- 1C.  Signed wrapper with all edge-case guards ---------- */
int divide_bitwise(int dividend, int divisor)
{
    /* Mandatory guards -------------------------------------------------- */
    if (divisor == 0)                         return INT_MAX;        /* /0 */
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;        /* overflow */
    if (divisor ==  1)                        return dividend;       /* fast path */
    if (divisor == -1)                        return -dividend;      /* fast path */
    if (dividend == 0)                        return 0;              /* quick */

    /* Determine sign of the result ------------------------------------- */
    bool negative = (dividend < 0) ^ (divisor < 0);

    /* Convert to unsigned magnitudes (INT_MIN requires special care) --- */
    uint32_t u_dividend = (dividend == INT_MIN) ? (1U << 31)
                                               : (uint32_t)labs(dividend);
    uint32_t u_divisor  = (divisor  == INT_MIN) ? (1U << 31)
                                               : (uint32_t)labs(divisor);

    /* Perform unsigned division ---------------------------------------- */
    uint32_t u_quot = divide_unsigned(u_dividend, u_divisor);

    /* Clamp (the algo never exceeds INT_MAX except when dividend == INT_MIN and divisor == 1) */
    if (u_quot > INT_MAX) u_quot = INT_MAX;

    int result = (int)u_quot;
    return negative ? -result : result;
}


/**
 * -------------------------------------------------------------------------
 * APPROACH 2:  Naïve Repeated Subtraction  (Educational only)
 * -------------------------------------------------------------------------
 *
 * Simple loop subtracting |divisor| repeatedly from |dividend|.
 * Extremely slow for large magnitudes (O(|quotient|)).
 */
int divide_naive(int dividend, int divisor)
{
    if (divisor == 0)                         return INT_MAX;
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;

    bool negative = (dividend < 0) ^ (divisor < 0);
    long long  a  = llabs((long long)dividend);   /* promote to avoid UB */
    long long  b  = llabs((long long)divisor);
    long long  q  = 0;

    while (a >= b) { a -= b; ++q; }               /* O(q) */

    if (q > INT_MAX) q = INT_MAX;
    return negative ? -(int)q : (int)q;
}


/**
 * -------------------------------------------------------------------------
 * TEST DRIVER
 * -------------------------------------------------------------------------
 * Covers typical and nasty edge cases for quick sanity checks.
 */
static void run_test(int dividend, int divisor)
{
    int q1 = divide_bitwise(dividend, divisor);
    int q2 = divide_naive  (dividend, divisor);

    printf("  %11d / %11d  =>  bitwise = %11d | naive = %11d\n",
           dividend, divisor, q1, q2);
}

int main(void)
{
    puts("Quick sanity tests for “Divide Two Integers”:\n");

    /* Basic cases ------------------------------------------------------ */
    run_test( 10,  3);
    run_test(  7, -3);
    run_test(-15,  4);
    run_test(  0, 42);

    /* Corner / overflow cases ----------------------------------------- */
    run_test( INT_MIN, -1);     /* should clamp to INT_MAX */
    run_test( INT_MIN,  1);
    run_test( INT_MIN,  2);
    run_test( INT_MIN, INT_MIN);
    run_test( INT_MAX,       2);
    run_test( INT_MAX, INT_MIN);

    return 0;
}
