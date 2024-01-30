#include <stdio.h>

/* Approach and Complexity Analysis for Brute Force Method
   - This function counts the number of arithmetic triplets in a given array 'nums' with a specified difference 'diff'.
   - Approach:
     1. Iterate over the array with three nested loops to consider all possible triplets (i, j, k) with i < j < k.
     2. Check if each triplet satisfies the arithmetic condition: nums[j] - nums[i] == diff and nums[k] - nums[j] == diff.
     3. If a triplet satisfies the condition, increment the count.
   - Time Complexity: O(N^3), where N is the size of the array.
     This is due to the three nested loops each iterating through the array.
   - Space Complexity: O(1).
     The function uses a fixed number of integer variables and does not require any additional space that depends on the size of the input.
*/
int arithmeticTriplets(int* nums, int numsSize, int diff) {
    int count  = 0; 
    for (int  i = 0 ; i < numsSize ;i++) {
        for (int j = i + 1; j < numsSize; j++) {
            for (int k = j + 1; k < numsSize; k++) {
                if ((nums[j] - nums[i] == diff) && (nums[k] - nums[j] == diff)) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    int nums1[] = {0, 1, 4, 6, 7, 10};
    int diff1 = 3;
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Number of Arithmetic Triplets in [0,1,4,6,7,10] with diff 3: %d\n", arithmeticTriplets(nums1, numsSize1, diff1));

    int nums2[] = {4, 5, 6, 7, 8, 9};
    int diff2 = 2;
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Number of Arithmetic Triplets in [4,5,6,7,8,9] with diff 2: %d\n", arithmeticTriplets(nums2, numsSize2, diff2));

    return 0;
}
