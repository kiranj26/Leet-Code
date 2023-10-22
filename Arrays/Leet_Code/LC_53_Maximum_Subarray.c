#include <stdio.h>
#include <stdint.h>

/* // @ Note :Brute Force Algorithm
// @ Time Complexity : O(n62)
// @ Space Complexity : O(1)

int maxSubArray(int* nums, int numsSize) {
    int max_sum =INT_MIN;

    // Function logic will be implemented here.
    for(int i=0;i<numsSize;i++) {
        int sum = 0;
        for(int j=i;j<numsSize;j++) {
            
            sum = sum + nums[j];
            // printf("Current Max = %d \tSum %d \n",max_sum,sum);
            if( sum > max_sum)
            {
                // printf("Here\n");
                max_sum = sum;
            }else{
                // just traverse furthur and do nothing
            }
        }
    }

    return max_sum; // Dummy return, replace this with your logic.
} */

// Note2: Sliding Window Problem with Kadane's Algorithm
// 
int maxSubArray(int* nums, int numsSize) {
    int sum = 0;
    int max_sum = nums[0];

    if (numsSize == 1){
        return nums[0];
    }

    int left = 0;
    int right = 0;

    while(right < numsSize)
    {
        sum = sum + nums[right];
        // compare the current sum to the max sum
        if (sum > max_sum)
        {
            // if greater update the max sum
            max_sum = sum;
            // Expand windows
        }
        // if the current sum becomes negative
        if (sum < 0)
        {
            sum = 0;
            left ++;
            // right++;
        }
    right ++;

    }
    return max_sum;
}

int main(void) {
    // Test 1
    int nums1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Test 1 Result: %d\n", maxSubArray(nums1, size1)); // Expected Output: 6

    // Test 2
    int nums2[] = {1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Test 2 Result: %d\n", maxSubArray(nums2, size2)); // Expected Output: 1

    // Test 3
    int nums3[] = {5, 4, -1, 7, 8};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Test 3 Result: %d\n", maxSubArray(nums3, size3)); // Expected Output: 23

    return 0;
}
