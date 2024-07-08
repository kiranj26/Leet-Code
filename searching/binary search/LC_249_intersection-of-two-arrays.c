#include <stdio.h>
#include <stdlib.h>
void printArray(int* array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%d", array[i]);
    }
    printf("]\n");
}
// Function prototype
// Aprroach 1 : My First try using Hashmap
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int map1[1000] = { 0 };
    int map2[1000]= { 0 };
    for (int i = 0; i < nums1Size; i++)
    {
        map1[nums1[i]] = 1;
    }
    for (int i = 0; i < nums2Size; i++)
    {
        map2[nums2[i]] = 1;
    }
    // print both maps till 10 
    printArray(map1, 10);
    printArray(map2, 10);
    int * ans = (int *)malloc(1001 * sizeof(int));
    *returnSize = 0 ;

    for (int i = 1; i < 1000; i++)
    {
        if (map1[i] == 1 && map2[i] == 1)
        {
            ans[*returnSize] = i;
            *returnSize += 1;
        }
    }
    // reallocate answer array t final size
    ans = realloc(ans, *returnSize);
    
    return ans;
}



int main() {
    int nums1_1[] = {1, 2, 2, 1};
    int nums2_1[] = {2, 2};
    int returnSize1;
    int* result1 = intersection(nums1_1, 4, nums2_1, 2, &returnSize1);
    printf("Test Case 1: ");
    printArray(result1, returnSize1);
    free(result1); // Remember to free the memory

    int nums1_2[] = {4, 9, 5};
    int nums2_2[] = {9, 4, 9, 8, 4};
    int returnSize2;
    int* result2 = intersection(nums1_2, 3, nums2_2, 5, &returnSize2);
    printf("Test Case 2: ");
    printArray(result2, returnSize2);
    free(result2); // Remember to free the memory

    return 0;
}
