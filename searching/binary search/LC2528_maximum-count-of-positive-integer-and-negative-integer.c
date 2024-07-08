#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
// This is a utility function that may be used if sorting is needed
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/**
 * Approach: Binary Search and Counting
 * 
 * This approach involves using binary search to find the first positive number
 * and then counting the positive and negative numbers separately.
 * 
 * Steps:
 * 1. Use binary search to find the index of the first positive number.
 * 2. Count the positive numbers from the found index to the end of the array.
 * 3. Count the negative numbers from the start of the array to the found index, excluding zeros.
 * 4. Return the maximum of the positive and negative counts.
 * 
 * Time Complexity: O(log n + n), where n is the size of the input array.
 * This includes the time for binary search (O(log n)) and counting elements (O(n)).
 * 
 * Space Complexity: O(1), as the algorithm uses a constant amount of extra space.
 */

/**
 * Function to find the maximum count of positive integers and negative integers
 * in a given array.
 *
 * @param nums - The input array of integers.
 * @param numsSize - The size of the input array.
 * @return The maximum count of positive or negative integers.
 */
int maximumCount(int* nums, int numsSize) {
    int start = 0;
    int end = numsSize - 1;
    int firstPositiveIndex = numsSize; // Assume no positive numbers initially

    // Binary Search: Find the first positive number (greater than 0)
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] > 0) {
            firstPositiveIndex = mid;
            end = mid - 1; // Search the left half
        } else {
            start = mid + 1; // Search the right half
        }
    }

    // Count of positive numbers is numsSize - firstPositiveIndex
    int positiveCount = numsSize - firstPositiveIndex;

    // Count of negative numbers is firstPositiveIndex - count of zeros
    int zeroCount = 0;
    for (int i = 0; i < firstPositiveIndex; ++i) {
        if (nums[i] == 0) {
            zeroCount++;
        }
    }
    int negativeCount = firstPositiveIndex - zeroCount;

    // Return the maximum of positive and negative counts
    return positiveCount > negativeCount ? positiveCount : negativeCount;
}

// Function to print an array
void printArray(int* array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%d", array[i]);
    }
    printf("]\n");
}

// Function to test the maximumCount function
void testMaximumCount() {
    // Test Case 1
    int nums1[] = {-1, -2, -3, 3, 4, 5};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int result1 = maximumCount(nums1, size1);
    printf("Test Case 1: ");
    printf("Input: ");
    printArray(nums1, size1);
    printf("Output: %d\n", result1);

    // Test Case 2
    int nums2[] = {-5, -4, -3, -2, -1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int result2 = maximumCount(nums2, size2);
    printf("Test Case 2: ");
    printf("Input: ");
    printArray(nums2, size2);
    printf("Output: %d\n", result2);

    // Test Case 3
    int nums3[] = {1, 2, 3, 4, 5};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    int result3 = maximumCount(nums3, size3);
    printf("Test Case 3: ");
    printf("Input: ");
    printArray(nums3, size3);
    printf("Output: %d\n", result3);

    // Additional Test Cases
    int nums4[] = {-1, 1, -2, 2, -3, 3};
    int size4 = sizeof(nums4) / sizeof(nums4[0]);
    int result4 = maximumCount(nums4, size4);
    printf("Test Case 4: ");
    printf("Input: ");
    printArray(nums4, size4);
    printf("Output: %d\n", result4);

    int nums5[] = {0, 0, 0, 0};
    int size5 = sizeof(nums5) / sizeof(nums5[0]);
    int result5 = maximumCount(nums5, size5);
    printf("Test Case 5: ");
    printf("Input: ");
    printArray(nums5, size5);
    printf("Output: %d\n", result5);
}

int main() {
    testMaximumCount();
    return 0;
}
