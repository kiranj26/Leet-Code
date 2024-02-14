#include <stdio.h>
#include <stdlib.h>

// Function to find the next greater element for each element of nums1 in nums2
/* int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = nums1Size;
    int index = 0;
    int * ans = (int *)malloc(nums1Size * sizeof(int));
    // traverse nums1
    for (int i = 0 ; i < nums1Size ; i++) {
        // traverse nums2
        int found = 0;
        for(int j = 0 ; j < nums2Size ; j++) {
            if (nums1[i] == nums2[j])
            {
                printf("At Index %d\n", j+1);
                if ( ( j != (nums2Size - 1) )  && (nums2[j] < nums2[j+1] )){
                    // we have to store the value and exit the loop
                    ans[index++] = nums2[j + 1];
                    found = 1;
                    j = nums2Size;
                }else{
                    ans[index++] = -1;
                    found = 1;
                    j = nums2Size;
                }
            }
        }
        if (found != 1)
        {
            ans[index++] = -1;
        }
    }
    return ans;
} */

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = nums1Size;
    int index = 0;
    int * ans = (int *)malloc(nums1Size * sizeof(int));
    // traverse nums1
    for (int i = 0 ; i < nums1Size ; i++) {
        int index = -1;
        int newNum = -1;
        for(int j = 0 ; j < nums2Size ; j++) {
            if (nums1[i] == nums2[j])
            {
                index = j;
                break;
            }
        }

        for (int j = index ; j < nums2Size ; j++)
        {
            if (nums2[j] > nums1[i])
            {
                newNum = nums2[j];
            }
        }

        ans[i] = newNum;
    }
    return ans;
}


int main() {
    int nums1[] = {4, 1, 2};
    int nums2[] = {1, 3, 4, 2};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize;

    int* ans = nextGreaterElement(nums1, nums1Size, nums2, nums2Size, &returnSize);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", ans[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    free(ans);
    return 0;
}
