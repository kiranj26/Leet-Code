#include <stdio.h>
#include <stdlib.h>

/**
 * Brute Force Approach to find the pivot index.
 * 
 * Approach:
 * This method iterates over each element of the array, calculating the sum of elements to the left 
 * and the sum of elements to the right for each index. If at any point, the left sum equals the right sum,
 * that index is returned as the pivot index.
 *
 * Time Complexity: O(n^2), where n is the size of the array. For each element, the sum of elements 
 * to the left and right are calculated, leading to a quadratic time complexity.
 *
 * Space Complexity: O(1), as it uses a constant amount of space regardless of the input array size.
 *
 * @param nums The array of integers.
 * @param numsSize The size of the array.
 * @return The leftmost pivot index if one exists, otherwise -1.
 */
/* int pivotIndexBruteForce(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        int sumLeft = 0, sumRight = 0;
        
        // Calculate left sum for index i
        for (int j = 0; j < i; j++) {
            sumLeft += nums[j];
        }
        
        // Calculate right sum for index i
        for (int j = i + 1; j < numsSize; j++) {
            sumRight += nums[j];
        }
        
        if (sumLeft == sumRight) {
            return i;
        }
    }
    return -1;
} */

/**
 * Optimized Approach to find the pivot index.
 * 
 * Approach:
 * First, calculate the total sum of the array. Then, iterate through the array while maintaining a running 
 * sum of elements to the left of the current index. The right sum is computed by subtracting the left sum and 
 * the current element from the total sum. If the left sum equals the right sum, the current index is the pivot index.
 *
 * Time Complexity: O(n), where n is the size of the array. The array is traversed twice: once to calculate 
 * the total sum and once to find the pivot index, leading to linear time complexity.
 *
 * Space Complexity: O(1), as it uses a constant amount of space regardless of the input array size.
 *
 * @param nums The array of integers.
 * @param numsSize The size of the array.
 * @return The leftmost pivot index if one exists, otherwise -1.
 */
int pivotIndex(int* nums, int numsSize) {
    int totalSum = 0, leftSum = 0;
    
    // Calculate the total sum of the array
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }
    
    for (int i = 0; i < numsSize; i++) {
        // Right sum is calculated by subtracting the left sum and current element from the total sum
        if (leftSum == totalSum - leftSum - nums[i]) {
            return i;
        }
        leftSum += nums[i];
    }
    
    return -1;
}

int main() {
    // Test cases
    int nums[] = {1, 7, 3, 6, 5, 6};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    printf("Brute Force Approach: Pivot index is %d\n", pivotIndexBruteForce(nums, size));
    printf("Optimized Approach: Pivot index is %d\n", pivotIndex(nums, size));

    return 0;
}
