#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * =========================================================================
 * LeetCode Problem: Two Out of Three (2032)
 * =========================================================================
 *
 * Problem:
 * Given three integer arrays nums1, nums2, and nums3, return a distinct array
 * containing all the values that are present in at least two out of the three arrays.
 * You may return the values in any order.
 *
 * =========================================================================
 * COMPLETE LEARNING OBJECTIVES:
 *
 * 1️⃣ Goal:
 *     - We want to find values that appear in at least 2 of the 3 arrays.
 *     - Duplicates within the same array don't matter.
 *     - Final result must be distinct.
 *
 * 2️⃣ APPROACH 1: Using Frequency Maps
 *     - Use 3 fixed-size arrays (maps) to track whether a number exists in nums1, nums2, and nums3.
 *     - Values range from 1 to 100, so use arrays of size 101.
 *     - If a number appears in any two of the maps, add it to result.
 *
 * Time Complexity: O(n1 + n2 + n3 + 100) = O(n)  where n is total elements
 * Space Complexity: O(1) because value range is bounded
 *
 * 3️⃣ APPROACH 2: Using Bit Manipulation
 *     - Maintain a bitmask for each number (1 to 100).
 *     - Bit 0 => present in nums1
 *     - Bit 1 => present in nums2
 *     - Bit 2 => present in nums3
 *     - After all arrays are processed, we check which values have >= 2 bits set
 *       (by checking if __builtin_popcount(mask[i]) >= 2).
 *
 * Time Complexity: O(n1 + n2 + n3)
 * Space Complexity: O(1)
 */

int* twoOutOfThree_MapApproach(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize) {
    int map1[101] = {0}, map2[101] = {0}, map3[101] = {0};
    int* result = (int*)malloc(sizeof(int) * 101);
    *returnSize = 0;

    for (int i = 0; i < nums1Size; i++) map1[nums1[i]] = 1;
    for (int i = 0; i < nums2Size; i++) map2[nums2[i]] = 1;
    for (int i = 0; i < nums3Size; i++) map3[nums3[i]] = 1;

    for (int i = 1; i <= 100; i++) {
        if ((map1[i] + map2[i] + map3[i]) >= 2) {
            result[(*returnSize)++] = i;
        }
    }
    return result;
}

int* twoOutOfThree_BitApproach(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize) {
    int seen[101] = {0}; // bitmask: bit 0 - nums1, bit 1 - nums2, bit 2 - nums3
    int* result = (int*)malloc(sizeof(int) * 101);
    *returnSize = 0;

    for (int i = 0; i < nums1Size; i++) seen[nums1[i]] |= 1 << 0;
    for (int i = 0; i < nums2Size; i++) seen[nums2[i]] |= 1 << 1;
    for (int i = 0; i < nums3Size; i++) seen[nums3[i]] |= 1 << 2;

    for (int i = 1; i <= 100; i++) {
        int mask = seen[i];
        int bits = (mask & 1) + ((mask >> 1) & 1) + ((mask >> 2) & 1);
        if (bits >= 2) {
            result[(*returnSize)++] = i;
        }
    }

    return result;
}

// -------------------------- Test Driver Code --------------------------
int main() {
    int nums1[] = {1, 1, 3, 2};
    int nums2[] = {2, 3};
    int nums3[] = {3};
    int returnSize;

    printf("Map-Based Approach:\n");
    int* res1 = twoOutOfThree_MapApproach(nums1, 4, nums2, 2, nums3, 1, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res1[i]);
    }
    printf("\n");
    free(res1);

    printf("\nBitmask-Based Approach:\n");
    int* res2 = twoOutOfThree_BitApproach(nums1, 4, nums2, 2, nums3, 1, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res2[i]);
    }
    printf("\n");
    free(res2);

    return 0;
}
