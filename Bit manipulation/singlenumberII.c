
#include<stdio.h>
#include<stdlib.h>

int singleNumber(int* nums, int numsSize) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int count = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] >> i & 1) {
                count++;
            }
        }
        ans |= (int) (count % 3) << i;
    }
    return ans;
}

int main(int argc, char** argv)
{

    int nums[] = {2,2,2,1};
    printf("nums: %lu\n", sizeof(nums));
    printf("Result = %d\n", singleNumber(nums, sizeof(nums)/sizeof(nums[0])));
}