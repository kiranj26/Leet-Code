#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * =========================================================================
 * LeetCode Problem: Add Binary (67)
 * =========================================================================
 * 
 * Problem:
 * Given two binary strings a and b, return their sum as a binary string.
 * 
 * Input:  a = "11", b = "1"
 * Output: "100"
 * 
 * =========================================================================
 * COMPLETE LEARNING OBJECTIVES (for future detailed revision):
 * 
 * 1️⃣ Binary Addition Intuition:
 *     - Binary addition works exactly like decimal addition but in base 2.
 *     - Each column can produce either 0, 1 (sum < 2) or produce a carry-over when sum >= 2.
 * 
 * 2️⃣ How to simulate binary addition on strings:
 *     - Start from rightmost characters (Least Significant Bit - LSB).
 *     - For each pair of characters, convert them to integers.
 *     - Sum them along with any carry from previous step.
 *     - The result digit is (sum % 2).
 *     - The new carry is (sum / 2).
 *     - Store the result digits in reverse order.
 * 
 * 3️⃣ Reverse Logic:
 *     - As we build the result string from LSB to MSB, we must reverse it before returning.
 * 
 * 4️⃣ Why can't we use integer addition directly:
 *     - Inputs can be very long (up to 10^4 digits).
 *     - May not fit into built-in integer types like int, long, etc.
 * 
 * 5️⃣ Pure Bit Manipulation Concept:
 *     - XOR (^) produces sum without carry.
 *     - AND (&) finds where carry is generated.
 *     - Shift (<< 1) moves the carry to the correct next bit position.
 *     - Repeat the process until no more carry remains.
 */

/**
 * -------------------------------------------------------------------------
 * APPROACH 1: String Simulation of Binary Addition
 * -------------------------------------------------------------------------
 * 
 * This approach directly operates on characters instead of converting to integers.
 * This allows us to handle extremely long binary strings efficiently.
 * 
 * Full Logic Breakdown:
 * - Traverse both strings from right to left (like column-wise manual addition).
 * - If one string is shorter, treat missing digits as '0'.
 * - Compute sum = digit_a + digit_b + carry.
 * - Store (sum % 2) as current result bit.
 * - Update carry = sum / 2.
 * - After processing all digits, if carry remains, add it.
 * - Since result is built backwards, reverse before returning.
 * 
 * Time Complexity: O(max(len(a), len(b)))
 * Space Complexity: O(max(len(a), len(b)))
 */

// Helper function to reverse a string in-place
void reverse(char* str) {
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    
    // Allocate memory for maximum possible size (whichever string is longer + 1 carry + 1 null terminator)
    int max_len = (len_a > len_b ? len_a : len_b) + 2;
    char* result = (char*)malloc(max_len);

    int i = len_a - 1; // index for string 'a'
    int j = len_b - 1; // index for string 'b'
    int pos = 0;       // position in result array
    int carry = 0;     // initial carry is 0

    // Iterate until all digits and final carry are processed
    while (i >= 0 || j >= 0 || carry != 0) {
        // Convert character digits to integers safely
        int digit_a = (i >= 0) ? (a[i] - '0') : 0;
        int digit_b = (j >= 0) ? (b[j] - '0') : 0;

        // Calculate sum of both digits and carry
        int sum = digit_a + digit_b + carry;
        
        // Current result digit is sum modulo 2 (binary equivalent of sum without carry)
        int result_digit = sum % 2;
        
        // Carry for next iteration
        carry = sum / 2;

        // Store result as character
        result[pos++] = result_digit + '0';

        i--;
        j--;
    }

    // Null-terminate the result string
    result[pos] = '\0';

    // Reverse since we were appending from LSB to MSB
    reverse(result);

    return result;
}

/**
 * -------------------------------------------------------------------------
 * APPROACH 2: Pure Bit Manipulation Addition (Integer version)
 * -------------------------------------------------------------------------
 * 
 * Problem Variant: Add two integers without using + or - operators.
 * 
 * Core Bit Manipulation Principles:
 * - XOR (^) performs addition ignoring carries.
 * - AND (&) identifies where carries are generated.
 * - Shift (<< 1) moves carry to next higher bit.
 * - Repeat until carry vanishes.
 * 
 * Key Idea:
 * This directly mimics hardware-level full adder circuit.
 * 
 * Time Complexity: O(32) -> bounded for 32-bit integers
 * Space Complexity: O(1)
 */
int addBitwise(int a, int b) {
    while (b != 0) {
        int sum = a ^ b;            // XOR computes sum without carry
        int carry = (a & b) << 1;   // AND locates where carry needs to propagate
        a = sum;                    // Assign sum to 'a'
        b = carry;                  // Assign new carry to 'b' for next iteration
    }
    return a;
}

/**
 * -------------------------------------------------------------------------
 * Test Driver Code
 * -------------------------------------------------------------------------
 * Runs multiple test cases for both string and integer additions.
 */
int main() {
    // Test cases for String-based binary addition
    char a1[] = "11";
    char b1[] = "1";
    char* result1 = addBinary(a1, b1);
    printf("Binary String Add: %s + %s = %s\n", a1, b1, result1);
    free(result1);

    char a2[] = "1010";
    char b2[] = "1011";
    char* result2 = addBinary(a2, b2);
    printf("Binary String Add: %s + %s = %s\n", a2, b2, result2);
    free(result2);

    // Test cases for Integer-based bit manipulation addition
    int test_cases[][2] = {{5, 3}, {0, 0}, {123, 456}, {-25, 75}, {-50, -100}, {INT_MAX, 0}, {INT_MAX, INT_MIN}};
    int n = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("\nInteger Addition Using Bit Manipulation:\n");
    for (int i = 0; i < n; i++) {
        int a = test_cases[i][0];
        int b = test_cases[i][1];
        int sum = addBitwise(a, b);
        printf("%d + %d = %d\n", a, b, sum);
    }

    return 0;
}
