#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int count = 0;
    int candidate = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        if (candidate == nums[i])
        {
            count += 1;;
        }else{
            count += -1;
        }
    }
    
    return candidate;
}

int main() {
    int nums1[] = {3, 2, 3};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Example 1: %d\n", majorityElement(nums1, numsSize1));

    int nums2[] = {2, 2, 1, 1, 1, 2, 2};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Example 2: %d\n", majorityElement(nums2, numsSize2));

    return 0;
}
