#include <stdio.h>
#include <stdlib.h>

/**
 * My First Try
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int * freq = (int *)calloc(numsSize, sizeof(int));
    int * ans = (int *)calloc(numsSize, sizeof(int));
    int index = 0;
    for (int i=0 ; i< numsSize ; i++)
    {
        freq[nums[i] - 1]++;
    }

    for (int i= 1 ; i<=numsSize ; i++)
    {
        if (freq[i - 1] == 0)
        {
            ans[index++] = i;
        }
    }
    free(freq);
    *returnSize = index;
    return ans;

}

int main() {
    // Example 1
    int nums1[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int returnSize1;
    int* result1 = findDisappearedNumbers(nums1, numsSize1, &returnSize1);
    printf("Disappeared numbers in example 1: ");
    for (int i = 0; i < returnSize1; i++) {
        printf("%d ", result1[i]);
    }
    printf("\n");
    free(result1); // Free the allocated memory

    // Example 2
    int nums2[] = {1, 1};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize2;
    int* result2 = findDisappearedNumbers(nums2, numsSize2, &returnSize2);
    printf("Disappeared numbers in example 2: ");
    for (int i = 0; i < returnSize2; i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");
    free(result2); // Free the allocated memory

    return 0;
}
