#include <stdio.h>
#include <stdlib.h>

/* Brute Force Approach
   - Iterate over each pair of elements in the array and check if their absolute difference is k.
   - Time Complexity: O(N^2), where N is the size of the array. This is due to the nested loops iterating over all pairs.
   - Space Complexity: O(1), as no extra space is used apart from the counter variable.
*/
/* 
int countKDifference(int* nums, int numsSize, int k) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (abs(nums[i] - nums[j]) == k) {
                count++;
            }
        }    
    }
    return count;
}    
*/

/* Using Hash Table
   - First, populate a frequency array to store the occurrence count of each number in the array.
   - Then, for each element, check if its complements (element ± k) exist in the frequency array and add their frequency to the count.
   - Each pair is counted twice (for each element in the pair), so the final count is divided by 2.
   - Time Complexity: O(N), where N is the size of the array. The array is iterated over twice.
   - Space Complexity: O(1), as the frequency array size is constant and does not depend on the input size.
*/
int countKDifference(int* nums, int numsSize, int k) {
    int count = 0;
    int freq[101] = {0}; // Since 1 <= nums[i] <= 100

    // Populate the frequency array
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }

    // Count pairs with absolute difference k
    for (int i = 0; i < numsSize; i++) {
        int complement1 = nums[i] - k;
        int complement2 = nums[i] + k;
        if (complement1 >= 1 && complement1 <= 100) {
            count += freq[complement1];
        }
        if (complement2 >= 1 && complement2 <= 100 && complement2 != complement1) {
            count += freq[complement2];
        }
    }

    // Each pair is counted twice, so divide by 2
    return count / 2;
}

int main() {
    int nums1[] = {1, 2, 2, 1};
    int k1 = 1;
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Number of pairs with absolute difference %d in [1,2,2,1]: %d\n", k1, countKDifference(nums1, numsSize1, k1));

    int nums2[] = {1, 3};
    int k2 = 3;
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Number of pairs with absolute difference %d in [1,3]: %d\n", k2, countKDifference(nums2, numsSize2, k2));

    int nums3[] = {3, 2, 1, 5, 4};
    int k3 = 2;
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Number of pairs with absolute difference %d in [3,2,1,5,4]: %d\n", k3, countKDifference(nums3, numsSize3, k3));

    return 0;
}
