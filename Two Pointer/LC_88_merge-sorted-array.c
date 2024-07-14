/**
 * @file LC_88_merge-sorted-array.c
 * @brief Solution to merging two sorted arrays in place.
 *
 * Detailed explanation and implementation of the algorithm to merge two sorted arrays
 * where the first array has enough extra space to accommodate the second array.
 *
 * Author: Kiran Jojare
 * 
 * Time Complexity: O(m + n) - We iterate through both arrays once, where m is the number of elements in the first array, and n is the number of elements in the second array.
 * Space Complexity: O(1) - We use a constant amount of extra space regardless of the input sizes.
 */

#include <stdio.h>
#include <assert.h> // Include the assert library for testing

/**
 * @brief Merges two sorted arrays in place.
 * 
 * This function assumes that nums1 has enough extra space to accommodate the elements of nums2.
 * The merged result will be stored in nums1.
 *
 * @param nums1 The first sorted array with extra space at the end.
 * @param m The number of actual elements in nums1.
 * @param nums2 The second sorted array.
 * @param n The number of elements in nums2.
 */
void merge(int* nums1, int m, int* nums2, int n) {
    // Initialize pointers for nums1, nums2, and the end of the merged array
    int i = m - 1;         // Pointer for the last element in the actual part of nums1
    int j = n - 1;         // Pointer for the last element in nums2
    int index = m + n - 1; // Pointer for the last position in nums1

    // Traverse nums1 and nums2 from the end and place the larger element in the correct position
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[index] = nums1[i];
            i--;
        } else {
            nums1[index] = nums2[j];
            j--;
        }
        index--;
    }

    // Copy any remaining elements from nums2 into nums1
    while (j >= 0) {
        nums1[index] = nums2[j];
        index--;
        j--;
    }

    // No need to copy remaining elements from nums1 since they are already in place
}

/**
 * @brief Test function to validate the `merge` function with various test cases.
 */
void test_merge() {
    // Test case 1
    int nums1_1[6] = {1, 2, 3, 0, 0, 0};
    int nums2_1[3] = {2, 5, 6};
    merge(nums1_1, 3, nums2_1, 3);
    int expected1[6] = {1, 2, 2, 3, 5, 6};
    for (int i = 0; i < 6; i++) {
        assert(nums1_1[i] == expected1[i]);
    }

    // Test case 2
    int nums1_2[7] = {1, 3, 4, 5, 0, 0, 0};
    int nums2_2[3] = {2, 6, 7};
    merge(nums1_2, 4, nums2_2, 3);
    int expected2[7] = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 7; i++) {
        assert(nums1_2[i] == expected2[i]);
    }

    // Test case 3
    int nums1_3[1] = {0};
    int nums2_3[1] = {1};
    merge(nums1_3, 0, nums2_3, 1);
    int expected3[1] = {1};
    for (int i = 0; i < 1; i++) {
        assert(nums1_3[i] == expected3[i]);
    }

    // Test case 4
    int nums1_4[10] = {1, 2, 3, 4, 5, 0, 0, 0, 0, 0};
    int nums2_4[5] = {6, 7, 8, 9, 10};
    merge(nums1_4, 5, nums2_4, 5);
    int expected4[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++) {
        assert(nums1_4[i] == expected4[i]);
    }

    // Test case 5
    int nums1_5[5] = {1, 2, 3, 4, 5};
    int nums2_5[0] = {};
    merge(nums1_5, 5, nums2_5, 0);
    int expected5[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        assert(nums1_5[i] == expected5[i]);
    }

    printf("All test cases passed!\n");
}

/**
 * @brief Main function to execute the test cases for the `merge` function.
 */
int main() {
    // Run the test cases to validate the `merge` function.
    test_merge();
    printf("All test cases passed!\n");
    return 0;
}
