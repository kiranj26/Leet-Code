/**
 * LeetCode Problem: Remove Duplicates from Sorted Array
 * Author: Kiran Jojare
 *
 * Approach:
 * - We use a two-pointer technique to solve this problem.
 * - Initialize two pointers: `i` (to track the position of the last unique element) and `j` (to traverse the array).
 * - Traverse the array with the right pointer `j`.
 *   - For each unique element (element different from the previous unique element), increment the `i` pointer and update the element at `i` with the element at `j`.
 * - Continue this process until the end of the array.
 * - The final value of `i + 1` will be the number of unique elements in the array.
 *
 * Time Complexity:
 * - O(n): We traverse the array once with the pointer `j`.
 *
 * Space Complexity:
 * - O(1): We use only a constant amount of extra space.
 */

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {    
    int i = 0; 
    
    for (int j = 1; j < numsSize; ++j) {
        if (nums[j] != nums[i]) {
            ++i; // Increment i to move to the next position
            nums[i] = nums[j]; // Overwrite the element at i with the current element
        }
    }
    
    return i + 1; // Return the length of the array with unique elements
}

// Main function to test the implementation
int main() {
    // Test Case 1
    int nums1[] = {1, 1, 2};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int k1 = removeDuplicates(nums1, numsSize1);
    printf("Test Case 1 - Expected k = 2: ");
    for (int i = 0; i < k1; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    // Test Case 2
    int nums2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    int k2 = removeDuplicates(nums2, numsSize2);
    printf("Test Case 2 - Expected k = 5: ");
    for (int i = 0; i < k2; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    // Test Case 3
    int nums3[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    int k3 = removeDuplicates(nums3, numsSize3);
    printf("Test Case 3 - Expected k = 5: ");
    for (int i = 0; i < k3; i++) {
        printf("%d ", nums3[i]);
    }
    printf("\n");

    // Test Case 4
    int nums4[] = {1, 1, 1, 1, 1, 1};
    int numsSize4 = sizeof(nums4) / sizeof(nums4[0]);
    int k4 = removeDuplicates(nums4, numsSize4);
    printf("Test Case 4 - Expected k = 1: ");
    for (int i = 0; i < k4; i++) {
        printf("%d ", nums4[i]);
    }
    printf("\n");

    // Test Case 5
    int nums5[] = {1, 2, 2, 2, 3, 3, 3, 4, 4, 5};
    int numsSize5 = sizeof(nums5) / sizeof(nums5[0]);
    int k5 = removeDuplicates(nums5, numsSize5);
    printf("Test Case 5 - Expected k = 5: ");
    for (int i = 0; i < k5; i++) {
        printf("%d ", nums5[i]);
    }
    printf("\n");

    return 0;
}
