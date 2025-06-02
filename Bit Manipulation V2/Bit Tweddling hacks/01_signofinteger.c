#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * ============================================================================
 * SIGN OF INTEGER - COMPREHENSIVE BIT MANIPULATION TECHNIQUES
 * ============================================================================
 * 
 * This file demonstrates multiple approaches to determine the sign of an integer
 * using bit manipulation techniques. Each approach has different trade-offs in
 * terms of portability, performance, and readability.
 * 
 * LEARNING OBJECTIVES:
 * 1. Understand boolean-to-integer conversion in C
 * 2. Learn arithmetic vs logical right shifts
 * 3. Explore portable vs performance-optimized code
 * 4. Understand two's complement representation
 * 5. Learn about implementation-defined behavior in C
 */

/*
 * APPROACH 1: BOOLEAN COMPARISON METHOD
 * ====================================
 * Formula: -(v < 0)
 * 
 * HOW IT WORKS:
 * - (v < 0) evaluates to 1 if negative, 0 if non-negative
 * - Unary minus converts: 0 → 0, 1 → -1
 * - Result: 0 for non-negative, -1 for negative
 * 
 * BENEFITS:
 * ✅ Simple one-liner expression
 * ✅ Easy to understand logic flow
 * ✅ No branching (good for some processors)
 * ✅ Compact code size
 * 
 * EMBEDDED SYSTEMS CONCERNS:
 * ❌ Boolean-to-integer conversion not guaranteed across all compilers
 * ❌ Assumes two's complement (breaks on one's complement/sign-magnitude)
 * ❌ Aggressive compiler optimizations may change behavior
 * ❌ Only gives negative(-1) vs non-negative(0), doesn't distinguish zero from positive
 * ❌ Comparison operations slower than direct bit manipulation on some microcontrollers
 * ❌ Portability issues across different embedded platforms
 */
int sign_approach1_boolean(int v) {
    return -(v < 0);
}

/*
 * APPROACH 2: ARITHMETIC RIGHT SHIFT METHOD
 * =========================================
 * Formula: v >> ((sizeof(int) * CHAR_BIT) - 1)
 * 
 * HOW IT WORKS:
 * - Exploits two's complement representation where MSB is sign bit
 * - Right shift by (word_size - 1) moves sign bit to LSB position
 * - Arithmetic shift fills vacant positions with sign bit
 * - Result: 0x00000000 for positive, 0xFFFFFFFF (-1) for negative
 * 
 * TECHNICAL DETAILS:
 * - Arithmetic Shift: Fills vacant bits with sign bit (preserves sign)
 * - Logical Shift: Fills vacant bits with 0 (unsigned behavior)
 * 
 * C STANDARD GOTCHA:
 * "The result of right-shifting a negative signed integer is implementation-defined"
 * - Pre-C99/C11: Behavior was implementation-defined
 * - Modern systems: Usually arithmetic shift
 * - Legacy systems: Might do logical shift
 * 
 * ASSEMBLY EXAMPLES:
 * - x86: SAR eax, 31    ; Shift Arithmetic Right
 * - ARM: ASR r0, #31    ; Arithmetic Shift Right
 * 
 * PERFORMANCE:
 * ✅ FAST - Constant time, no branches, no pipeline stalls
 * ✅ Often compiles to single CPU instruction
 * ✅ Optimal for high-performance inner loops
 * 
 * PORTABILITY CONCERNS:
 * ❌ Implementation-defined behavior on some systems
 * ❌ Assumes arithmetic right shift
 */
int sign_approach2_arithmetic_shift(int v) {
    return v >> ((sizeof(int) * CHAR_BIT) - 1);
}

/*
 * APPROACH 3: PORTABLE UNSIGNED CAST METHOD
 * ==========================================
 * Formula: -((int)((unsigned int)v >> 31))
 * 
 * HOW IT WORKS:
 * 1. Cast to unsigned int - ensures logical right shift (well-defined)
 * 2. Right shift by 31 - moves sign bit to LSB, fills with zeros
 * 3. Cast back to int - converts 0/1 to int
 * 4. Negate - converts 0 to 0, 1 to -1
 * 
 * WHY THIS IS PORTABLE:
 * - Unsigned right shift is always logical (fills with zeros)
 * - No implementation-defined behavior
 * - Works consistently across all platforms
 * - Guaranteed by C standard
 * 
 * TRADE-OFFS:
 * ✅ Portable across all platforms and compilers
 * ✅ Well-defined behavior in C standard
 * ✅ Maintainable firmware code
 * ❌ Slightly slower due to extra cast operations on some architectures
 * ❌ More verbose than direct shift
 * 
 * RULE OF THUMB:
 * Use this approach when:
 * - Writing portable, maintainable firmware
 * - Working across multiple MCU platforms
 * - Compliance with strict coding standards required
 */
int sign_approach3_portable_shift(int v) {
    return -((int)((unsigned int)v >> (sizeof(int) * CHAR_BIT - 1)));
}

/*
 * APPROACH 4: TWO-WAY SIGN DETECTION METHOD (+1 or -1 only)
 * ==========================================================
 * Formula: (1 | (v >> (sizeof(int) * CHAR_BIT - 1)))
 * 
 * HOW IT WORKS:
 * - This approach returns ONLY +1 or -1 (never 0)
 * - (v >> 31) extracts sign bit: 0 for positive/zero, -1 for negative
 * - OR with 1 converts: 0|1 = +1 (positive/zero), -1|1 = -1 (negative)
 * 
 * DETAILED BREAKDOWN:
 * Positive numbers: 0 | 1 = +1
 * Negative numbers: -1 | 1 = -1 (because -1 = 0xFFFFFFFF, OR with anything keeps it -1)
 * Zero: 0 | 1 = +1 (Zero is treated as positive!)
 * 
 * BIT-LEVEL EXPLANATION:
 * - Positive/Zero: 00000000 | 00000001 = 00000001 (+1)
 * - Negative:      11111111 | 00000001 = 11111111 (-1)
 * 
 * USE CASES:
 * - Mathematical sign function where sgn(0) = +1
 * - Comparison functions that need strict -1/+1 output
 * - Binary decision systems (negative vs non-negative)
 * - Signal processing where zero is considered positive
 * - When you need to avoid zero in calculations
 * 
 * BENEFITS:
 * ✅ Very fast - single shift and OR operation
 * ✅ No branching or comparisons
 * ✅ Compact single expression
 * ✅ Always returns non-zero value
 * ✅ Good for performance-critical code
 * 
 * DRAWBACKS:
 * ❌ Zero is treated as positive (+1), not neutral
 * ❌ Implementation-defined right shift behavior
 * ❌ Less intuitive than boolean approaches
 * ❌ Not suitable when zero needs to be distinguished
 * 
 * COMPARISON WITH OTHER APPROACHES:
 * - Approaches 1-3: Three-way classification (returns -1, 0, or +1)
 * - Approach 4: Two-way classification (returns -1 or +1 only)
 * 
 * MATHEMATICAL NOTE:
 * This implements a variant of the mathematical sign function:
 * - Standard sgn(x): returns -1, 0, +1
 * - This variant: returns -1, +1 (treating 0 as positive)
 */
int sign_approach_4_output_plus1_minus_1(int v)
{
    return (1 | (v >> (sizeof(int) * CHAR_BIT - 1)));
}

/*
 * APPROACH 5: THREE-WAY PORTABLE SIGN DETECTION METHOD
 * =====================================================
 * Formula: (v != 0) | -(int)((unsigned int)((int)v) >> (sizeof(int) * CHAR_BIT - 1))
 * Returns: -1 for negative, 0 for zero, +1 for positive
 * 
 * HOW IT WORKS:
 * Step 1: (v != 0) gives 1 if non-zero, 0 if zero
 * Step 2: ((unsigned int)((int)v) >> 31) extracts sign bit with portable shift
 * Step 3: -(int)(...) converts sign bit: 0 → 0, 1 → -1
 * Step 4: OR combines results
 * 
 * DETAILED BREAKDOWN:
 * Positive: (1) | -(0) = 1 | 0 = +1
 * Negative: (1) | -(1) = 1 | -1 = -1 (because -1 has all bits set)
 * Zero:     (0) | -(0) = 0 | 0 = 0
 * 
 * PORTABILITY FEATURES:
 * - Explicit unsigned cast ensures logical right shift
 * - No implementation-defined behavior
 * - Works across all platforms and compilers
 * - Handles different integer sizes automatically
 * 
 * BENEFITS:
 * ✅ Fully portable across all systems
 * ✅ Three-way classification (-1, 0, +1)
 * ✅ No implementation-defined behavior
 * ✅ Suitable for production embedded code
 * ✅ Clear separation of zero detection and sign detection
 * 
 * DRAWBACKS:
 * ❌ More complex expression
 * ❌ Multiple casts may impact performance slightly
 * ❌ Less readable than boolean approach
 */
int sign_approach5_three_way_portable(int v) {
    return (v != 0) | -(int)((unsigned int)((int)v) >> (sizeof(int) * CHAR_BIT - 1));
}

/*
 * APPROACH 6: THREE-WAY FAST SIGN DETECTION METHOD
 * =================================================
 * Formula: (v != 0) | (v >> (sizeof(int) * CHAR_BIT - 1))
 * Returns: -1 for negative, 0 for zero, +1 for positive
 * 
 * HOW IT WORKS:
 * Step 1: (v != 0) gives 1 if non-zero, 0 if zero
 * Step 2: (v >> 31) extracts sign bit directly
 * Step 3: OR combines: positive gets 1|0=1, negative gets 1|(-1)=-1, zero gets 0|0=0
 * 
 * SPEED OPTIMIZATION:
 * - Direct arithmetic right shift (no casting)
 * - Minimal operations for maximum performance
 * - Often compiles to just a few CPU instructions
 * 
 * DETAILED BREAKDOWN:
 * Positive: (1) | (0) = +1
 * Negative: (1) | (-1) = -1
 * Zero:     (0) | (0) = 0
 * 
 * BENEFITS:
 * ✅ Maximum speed - minimal operations
 * ✅ Three-way classification (-1, 0, +1)
 * ✅ Very compact expression
 * ✅ Optimal for performance-critical inner loops
 * 
 * DRAWBACKS:
 * ❌ Implementation-defined right shift behavior
 * ❌ Not portable to all systems
 * ❌ May behave differently on legacy hardware
 * ❌ Assumes arithmetic right shift
 * 
 * USE WHEN:
 * - Performance is critical
 * - Target platform is known and tested
 * - Modern hardware with guaranteed arithmetic shifts
 */
int sign_approach6_three_way_fast(int v) {
    return (v != 0) | (v >> (sizeof(int) * CHAR_BIT - 1));
}

/*
 * APPROACH 7: THREE-WAY BOOLEAN SIGN DETECTION METHOD
 * ====================================================
 * Formula: (v > 0) - (v < 0)
 * Returns: -1 for negative, 0 for zero, +1 for positive
 * 
 * HOW IT WORKS:
 * - (v > 0) evaluates to 1 if positive, 0 otherwise
 * - (v < 0) evaluates to 1 if negative, 0 otherwise
 * - Subtraction gives the three-way result
 * 
 * TRUTH TABLE:
 * v > 0 | v < 0 | (v > 0) - (v < 0) | Meaning
 * ------|-------|-------------------|----------
 *   1   |   0   |        1          | Positive
 *   0   |   1   |       -1          | Negative
 *   0   |   0   |        0          | Zero
 * 
 * BENEFITS:
 * ✅ Maximum portability and brevity
 * ✅ Self-documenting and intuitive
 * ✅ No bit manipulation complexity
 * ✅ Works on any C-compliant system
 * ✅ Easy to understand and maintain
 * ✅ Compiler can optimize well
 * 
 * DRAWBACKS:
 * ❌ Two comparison operations
 * ❌ May involve branching at assembly level
 * ❌ Potentially slower than pure bit manipulation
 * 
 * BEST FOR:
 * - Readable, maintainable code
 * - Cross-platform development
 * - When performance is not critical
 * - Educational purposes
 */
int sign_approach7_three_way_boolean(int v) {
    return (v > 0) - (v < 0);
}


int main() {
    // Test values covering edge cases and typical scenarios
    int test_values[] = {10, -5, 0, -15, 42, -100, 255, -255, INT_MAX, INT_MIN, 1, -1};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);
    
    printf("Sign Detection Test Results:\n");
    printf("Value\t| Boolean\t| Arith Shift\t| Portable\n");
    printf("--------|---------------|---------------|----------\n");
    
    for (int i = 0; i < num_tests; i++) {
        int v = test_values[i];
        
        int sign1 = sign_approach1_boolean(v);
        int sign2 = sign_approach2_arithmetic_shift(v);
        int sign3 = sign_approach3_portable_shift(v);
        
        printf("%d\t| %d\t\t| %d\t\t| %d\n", v, sign1, sign2, sign3);
    }
    
    printf("\nAll approaches return: 0 for non-negative, -1 for negative\n");
    
    return 0;
}
