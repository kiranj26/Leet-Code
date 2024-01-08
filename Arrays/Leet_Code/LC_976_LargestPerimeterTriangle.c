#include <stdio.h>
#include <stdlib.h>
/**
 * Brute Force Approach (Commented Out):
 * - Iterate over all possible triplets in the array.
 * - Check if the triplet forms a valid triangle using the triangle inequality theorem.
 * - Calculate and update the maximum perimeter found so far.
 * - Time Complexity: O(n^3), where n is the size of the array.
 * - Space Complexity: O(1), no extra space used apart from variables.
 */
/* int largestPerimeter(int* nums, int numsSize){
    int max_perimeter = 0;
    for(int i = 0;i<numsSize;i++){
        for(int j= i+1;j<numsSize;j++){
            for(int k= j+1;k<numsSize;k++){
            
            // check if triangle is valid by checking 
            int a = nums[i]; 
            int b = nums[j];
            int c = nums[k];

            if (
                ((a+b) > c) &&
                ((b+c) > a) &&
                ((c+a) > b)
            ){
                // UPDATE MAX_PERIMETER
                max_perimeter = (a+b+c) > max_perimeter ? (a+b+c): max_perimeter;
            }
            }
        }
    }
    return max_perimeter;
} */

/**
 * Optimized Approach:
 * - Sort the array in ascending order.
 * - Start from the largest elements (at the end of the array).
 * - Check each triplet for a valid triangle (triangle inequality theorem).
 * - Return the perimeter of the first valid triangle found (largest perimeter).
 * - Time Complexity: O(n log n) for sorting, O(n) for checking triplets, overall O(n log n).
 * - Space Complexity: O(1), in-place sorting, no additional space needed.
 */
int cmpfun(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int largestPerimeter(int* nums, int numsSize) {
    // Sort the array
    qsort(nums, numsSize, sizeof(int), cmpfun);

    // Iterate from the end of the sorted array
    for (int i = numsSize - 1; i >= 2; i--) {
        int a = nums[i];
        int b = nums[i - 1];
        int c = nums[i - 2];

        if (a < b + c) {
            // Valid Triangle
            return a + b + c;
        }
    }

    return 0; // No valid triangle found
}


int main() {
    // Test Case 1
    int nums1[] = {2, 1, 2};
    int result1 = largestPerimeter(nums1, sizeof(nums1) / sizeof(nums1[0]));
    printf("Test Case 1: Largest Perimeter = %d\n", result1);

    // Test Case 2
    int nums2[] = {3, 6, 2, 3};
    int result2 = largestPerimeter(nums2, sizeof(nums2) / sizeof(nums2[0]));
    printf("Test Case 2: Largest Perimeter = %d\n", result2);

    return 0;
}
