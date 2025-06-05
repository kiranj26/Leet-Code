/*
 * File: single_number_II_full.c
 * Problem: LeetCode 137 - Single Number II (Extended)
 * Author: Kiran (Tesla interview prep - Bit Manipulation Mastery)
 *
 * FULL EXPLANATION INSIDE CODE COMMENTS
 *
 * We present both the brute force and optimized bit manipulation approach.
 * This helps solidify understanding and demonstrates thought process for interviews.
 *
 * In this problem, every number appears exactly three times except for one unique number.
 * Our goal is to identify that unique number.
 */

#include <stdio.h>
#include <assert.h>

/*
 * Brute Force Approach:
 * ---------------------
 * - For every number in the array, count how many times it appears.
 * - If a number appears only once, that's the unique number.
 * - Time Complexity: O(N^2) since for each element we search entire array.
 * - Space Complexity: O(1) as we don't use extra data structures.
 *
 * Note: In real interview, you would often mention that a hash map would be more efficient (O(N)) for brute force.
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
    return -1; // Should never happen if input is valid
}

/*
 * Optimized Bit Manipulation Approach:
 * ------------------------------------
 * - Since every number appears 3 times except one, we use bitwise counting to isolate the unique number.
 * - We simulate 32 counters (for 32 bits of an integer) to count how many times each bit is set across all numbers.
 * - If a bit count % 3 is not zero, that bit must belong to the unique number.
 *
 * Step 1: Iterate over all numbers and for each bit (0 to 31), increment bucket if bit is set.
 * Step 2: After counting, take modulo 3 on each bucket to eliminate contributions from triplet numbers.
 * Step 3: Reconstruct the unique number using these final bits.
 *
 * Time Complexity: O(N * 32) -> effectively O(N)
 * Space Complexity: O(1) since buckets array has constant size.
 */
int singleNumberBitManipulation(int* nums, int numsSize) {
    int buckets[32] = {0}; // Array to count number of 1's for each bit position (0-31)

    // Step 1: Fill the buckets
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < 32; j++) {
            if (nums[i] & (1 << j)) { // If j-th bit is set in nums[i]
                buckets[j]++;
            }
        }
    }

    // Step 2: Reconstruct the result from buckets
    int ans = 0;
    for (int j = 0; j < 32; j++) {
        if (buckets[j] % 3 != 0) {
            ans |= (1 << j); // Set bit j in ans if count modulo 3 is not zero
        }
    }

    /*
     * Negative number handling:
     * Since we're reconstructing bit-by-bit into a signed int,
     * the sign bit (31st bit) is handled correctly in C by default.
     * If bit 31 is set, 'ans' will be correctly interpreted as negative.
     */

    return ans;
}

// Main function to test both approaches with multiple scenarios
int main() {
    // Test Case 1: Example from problem (basic)
    int nums1[] = {2, 2, 3, 2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    assert(singleNumberBruteForce(nums1, size1) == 3);
    assert(singleNumberBitManipulation(nums1, size1) == 3);
    printf("Test Case 1 passed!\n");

    // Test Case 2: Larger positive numbers
    int nums2[] = {5, 5, 5, 99};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    assert(singleNumberBruteForce(nums2, size2) == 99);
    assert(singleNumberBitManipulation(nums2, size2) == 99);
    printf("Test Case 2 passed!\n");

    // Test Case 3: Negative numbers (verifies sign bit handling)
    int nums3[] = {-2, -2, -2, -4};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    assert(singleNumberBruteForce(nums3, size3) == -4);
    assert(singleNumberBitManipulation(nums3, size3) == -4);
    printf("Test Case 3 passed!\n");

    // Test Case 4: Mixed positive and negative
    int nums4[] = {-1, -1, -1, 7};
    int size4 = sizeof(nums4) / sizeof(nums4[0]);
    assert(singleNumberBruteForce(nums4, size4) == 7);
    assert(singleNumberBitManipulation(nums4, size4) == 7);
    printf("Test Case 4 passed!\n");

    // Test Case 5: Edge case (only one number)
    int nums5[] = {42};
    int size5 = sizeof(nums5) / sizeof(nums5[0]);
    assert(singleNumberBruteForce(nums5, size5) == 42);
    assert(singleNumberBitManipulation(nums5, size5) == 42);
    printf("Test Case 5 passed!\n");

    return 0;
}
