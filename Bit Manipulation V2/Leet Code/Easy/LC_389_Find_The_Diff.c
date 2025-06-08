#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * =========================================================================
 * LeetCode Problem: Single Number (136)
 * =========================================================================
 * 
 * Problem:
 * Given a non-empty array of integers, every element appears twice except for one. 
 * Find that single one.
 * 
 * Input:  nums = [2,2,3,3,4,4,5,5,6,6,7,7,8]
 * Output: 8
 * 
 * =========================================================================
 * COMPLETE LEARNING OBJECTIVES (for future detailed revision):
 * 
 * 1️⃣ XOR Fundamental Property:
 *     - a ^ a = 0  (any number XOR itself cancels out)
 *     - a ^ 0 = a  (any number XOR 0 remains unchanged)
 * 
 * 2️⃣ Problem Insight:
 *     - Since all numbers except one appear exactly twice, 
 *       XOR-ing all numbers will cancel out the duplicates.
 *     - The remaining value after XOR-ing the full array will be the unique single number.
 * 
 * 3️⃣ Why XOR works perfectly for this problem:
 *     - XOR is both commutative and associative:
 *         - a ^ b == b ^ a
 *         - (a ^ b) ^ c == a ^ (b ^ c)
 *     - So the order of XOR does not matter.
 * 
 * 4️⃣ Bit Manipulation Benefit:
 *     - Very efficient: only 1 pass through array.
 *     - No extra memory needed (space complexity O(1)).
 * 
 * 5️⃣ Important Interview Insight:
 *     - XOR trick is extremely powerful for many problems where pairs cancel out.
 */

/**
 * -------------------------------------------------------------------------
 * APPROACH 1: Pure XOR-based Solution
 * -------------------------------------------------------------------------
 * 
 * Full Logic Breakdown:
 * - Initialize result to 0.
 * - Iterate through entire array.
 * - XOR current number with result.
 * - Duplicates cancel out, unique number remains.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];  // XOR each number
    }
    return result;
}

/**
 * -------------------------------------------------------------------------
 * APPROACH 2: Naive Brute-Force (For comparison only)
 * -------------------------------------------------------------------------
 * 
 * Logic:
 * - For every element, count its occurrences.
 * - If count == 1, return that element.
 * 
 * Drawbacks:
 * - Time Complexity: O(n^2)
 * - Space Complexity: O(1)
 * - Not efficient for interviews, provided here for learning only.
 */
int singleNumberBruteForce(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        int count = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                count++;
            }
        }
        if (count == 1) {
            return nums[i];
        }
    }
    return -1; // Should never reach here if input is valid
}

/**
 * -------------------------------------------------------------------------
 * Test Driver Code
 * -------------------------------------------------------------------------
 * Runs multiple test cases to validate both approaches.
 */
int main() {
    int nums1[] = {2,2,3,3,4,4,5,5,6,6,7,7,8};
    int numsSize = sizeof(nums1)/sizeof(nums1[0]);
    
    // Test XOR-based solution
    int resultXOR = singleNumber(nums1, numsSize);
    printf("Using XOR approach: The single number is: %d\n", resultXOR);
    
    // Test Brute-force solution (for verification)
    int resultBrute = singleNumberBruteForce(nums1, numsSize);
    printf("Using Brute-Force approach: The single number is: %d\n", resultBrute);

    return 0;
}
