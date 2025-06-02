#include <stdio.h>
#include <stdlib.h>

int main()
{

/*
 * SIGN OF INTEGER - BIT MANIPULATION TECHNIQUE: -(v < 0)
 * 
 * BENEFITS:
 * - Simple one-liner expression
 * - Easy to understand logic flow
 * - No branching (good for some processors)
 * - Compact code size
 * 
 * EMBEDDED SYSTEMS ISSUES:
 * - Boolean-to-integer conversion not guaranteed across all compilers
 * - Assumes two's complement (breaks on one's complement/sign-magnitude systems)
 * - Aggressive compiler optimizations may change behavior unexpectedly
 * - Only gives negative(-1) vs non-negative(0), doesn't distinguish zero from positive
 * - Comparison operations slower than direct bit manipulation on some microcontrollers
 * - Portability issues across different embedded platforms and integer sizes
 * - Unpredictable performance in real-time systems
 */
    //  APPROACH 1: sign of a bit v
    int test_values[] = {10, -5, 0, -15, 42, -100, 255, -255};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);
    
    for (int i = 0; i < num_tests; i++) {
        int v = test_values[i];
        int sign;
        
        sign = -(v < 0);
        
        printf("Sign of %d is %d\n", v, sign);
    }

    return 0;
}
