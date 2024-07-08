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

// my intital approach 
int compare (const void * a, const void * b)
{
    return (*(int *)a - *(int *)b);
}
int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int * result  = (int *)calloc(queriesSize, sizeof(int));

    for (int m = 0 ; m < queriesSize ; m++){
        int target = queries[m];

        int current_sum = 0;
        int current_longest_subsequence_length = 0;
        
        for (int i = 0 ; i < numsSize ; i++)
        {
            if (nums[i] + current_sum <= target)
            {
                current_sum += nums[i];
                current_longest_subsequence_length++;
            }
            else
            {
                
                break;
            }
        }
        // no subsequence greater than this so store in result at queries index
        result[m] = current_longest_subsequence_length;
    }
    *returnSize = queriesSize;
    return result;
}

int main() {
    // Test Case 1
    int nums1[] = {4, 5, 2, 1};
    int queries1[] = {3, 10, 21};
    int returnSize1;
    int* result1 = answerQueries(nums1, 4, queries1, 3, &returnSize1);
    printf("Test Case 1: ");
    printArray(result1, returnSize1);
    free(result1);

    /* // Test Case 2
    int nums2[] = {2, 3, 4, 5};
    int queries2[] = {1};
    int returnSize2;
    int* result2 = answerQueries(nums2, 4, queries2, 1, &returnSize2);
    printf("Test Case 2: ");
    printArray(result2, returnSize2);
    free(result2);

    // Additional Test Cases
    int nums3[] = {7, 4, 1, 8, 3};
    int queries3[] = {3, 10, 15};
    int returnSize3;
    int* result3 = answerQueries(nums3, 5, queries3, 3, &returnSize3);
    printf("Test Case 3: ");
    printArray(result3, returnSize3);
    free(result3);

    int nums4[] = {1, 1, 1, 1};
    int queries4[] = {2, 4, 6};
    int returnSize4;
    int* result4 = answerQueries(nums4, 4, queries4, 3, &returnSize4);
    printf("Test Case 4: ");
    printArray(result4, returnSize4);
    free(result4); */

    return 0;
}
