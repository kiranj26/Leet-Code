#include <stdio.h>
#include <stdlib.h>

// Logic: Given an array of integers `nums` and a target value `target`,
// the task is to count the number of pairs (i, j) such that nums[i] + nums[j] < target.

// Algorithm Steps:
// 1. Sort the array in ascending order.
// 2. Initialize a variable `count` to keep track of the number of pairs.
// 3. Iterate through each element `nums[i]` in the array from left to right.
// 4. For each `nums[i]`, perform a binary search on the portion of the array `nums[i+1:]` to find the upper bound.
//    - The upper bound is the index of the first element greater than or equal to `target - nums[i]`.
//    - If the upper bound is found, increment `count` by the number of elements between `nums[i+1]` and the upper bound.
// 5. Return the final value of `count`.

// Time Complexity: O(n log n), where n is the size of the input array `nums`.
// - Sorting the array takes O(n log n) time.
// - Performing binary search for each element takes O(n log n) time.
// - Overall, the time complexity is dominated by the sorting step.
// Space Complexity: O(1), as the algorithm uses only a constant amount of extra space.

// Function to compare two integers (used for sorting)
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int countPairs(int* nums, int numsSize, int target) {
    int count = 0;
    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);
    // Initialize two pointers
    int left = 0;
    int right = numsSize - 1;
    // Iterate until the pointers meet
    while (left < right) {
        // Check if the sum is less than the target
        if (nums[left] + nums[right] < target) {
            // Increment count by the number of elements between left and right
            count += right - left;
            // Move the left pointer to the next element
            left++;
        } else {
            // Move the right pointer to the previous element
            right--;
        }
    }
    return count;
}

int main() {
    // Test cases
    int nums[] = {2, 4, 6, 8, 10};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 12;
    printf("Number of pairs: %d\n", countPairs(nums, numsSize, target));

    int nums2[] = {1, 3, 5, 7, 9};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    int target2 = 10;
    printf("Number of pairs: %d\n", countPairs(nums2, numsSize2, target2));

    // Add more test cases here

    return 0;
}
