#include <stdio.h>
#include <stdlib.h>

/**
 * =========================================================================
 * LeetCode Problem: Set Mismatch (645)
 * =========================================================================
 * 
 * Problem:
 * Given an array representing numbers from 1 to n with one number duplicated 
 * and one number missing, return both [duplicate, missing].
 * 
 * Example:
 * Input: [1,2,2,4]
 * Output: [2,3]
 * 
 * =========================================================================
 * COMPLETE LEARNING OBJECTIVES:
 * 
 * 1️⃣ Key Insight:
 * - Correct sum: n*(n+1)/2
 * - Correct square sum: n*(n+1)*(2n+1)/6
 * 
 * 2️⃣ Formula System:
 * - Let x = duplicate, y = missing.
 * - sum_diff = actual_sum - expected_sum  --> (x - y)
 * - sq_sum_diff = actual_sq_sum - expected_sq_sum --> (x^2 - y^2)
 * 
 * 3️⃣ Derive:
 * - (x + y) = sq_sum_diff / sum_diff
 * - x = (sum_diff + (sq_sum_diff / sum_diff)) / 2
 * - y = x - sum_diff
 * 
 * 4️⃣ Complexity:
 * - Time: O(n)
 * - Space: O(1)
 */

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    long long actual_sum = 0, actual_sq_sum = 0;
    int n = numsSize;

    for (int i = 0; i < n; i++) {
        actual_sum += nums[i];
        actual_sq_sum += (long long)nums[i] * nums[i];
    }

    long long expected_sum = (long long)n * (n + 1) / 2;
    long long expected_sq_sum = (long long)n * (n + 1) * (2 * n + 1) / 6;

    long long sum_diff = actual_sum - expected_sum;           // x - y
    long long sq_sum_diff = actual_sq_sum - expected_sq_sum;  // x^2 - y^2

    long long sum_plus = sq_sum_diff / sum_diff;              // x + y

    int duplicate = (int)((sum_diff + sum_plus) / 2);
    int missing = (int)(duplicate - sum_diff);

    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = duplicate;
    result[1] = missing;
    *returnSize = 2;
    return result;
}
/**
 * =========================================================================
 * LeetCode Problem: Set Mismatch (645) — XOR Approach
 * =========================================================================
 * 
 * This solution uses pure Bit Manipulation (XOR partitioning trick).
 * Similar concept as Single Number III problem.
 * 
 * COMPLETE LEARNING OBJECTIVES:
 * 
 * 1️⃣ Key XOR Insight:
 *  - XOR of full array and 1..n gives xor_all = x ^ y (duplicate ^ missing).
 *  - Use any set bit to partition numbers into two groups.
 *  - XOR both groups separately to isolate x and y.
 * 
 * 2️⃣ Partition Rule:
 *  - rightmost_set_bit = xor_all & (-xor_all)
 * 
 * 3️⃣ At end:
 *  - group1 will have either x or y.
 *  - group2 will have the other.
 *  - One extra pass needed to identify which is duplicate.
 * 
 * 4️⃣ Complexity:
 *  - Time: O(n)
 *  - Space: O(1)
 */

/* int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int xor_all = 0;
    int n = numsSize;
    
    for (int i = 0; i < n; i++) {
        xor_all ^= nums[i];
        xor_all ^= (i + 1);
    }
    
    int rightmost_set_bit = xor_all & -xor_all;
    
    int group1 = 0, group2 = 0;
    
    for (int i = 0; i < n; i++) {
        if (nums[i] & rightmost_set_bit)
            group1 ^= nums[i];
        else
            group2 ^= nums[i];
    }
    
    for (int i = 1; i <= n; i++) {
        if (i & rightmost_set_bit)
            group1 ^= i;
        else
            group2 ^= i;
    }
    
    int duplicate = 0, missing = 0;
    
    // One of group1 or group2 is duplicate
    for (int i = 0; i < n; i++) {
        if (nums[i] == group1) {
            duplicate = group1;
            missing = group2;
            break;
        }
        if (nums[i] == group2) {
            duplicate = group2;
            missing = group1;
            break;
        }
    }
    
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = duplicate;
    result[1] = missing;
    *returnSize = 2;
    return result;
} */

int main() {
    int nums[] = {1, 2, 2, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int returnSize;
    int* result = findErrorNums(nums, numsSize, &returnSize);

    printf("Duplicate: %d, Missing: %d\n", result[0], result[1]);

    free(result);
    return 0;
}
