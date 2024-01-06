#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Brute Force Approach
 * Time Complexity: O(n^3) - Because of three nested loops each going through the array.
 * Space Complexity: O(n^3 / 6) - Maximum possible unique triplets, where n is the size of the array.
 * Steps:
 * 1. Iterate over all possible triplets in the array.
 * 2. For each triplet, check if it sums up to zero.
 * 3. If it sums to zero, check if this triplet is already found (to avoid duplicates).
 * 4. If not a duplicate, add it to the result.
 */
/* bool isDuplicate(int **result, int returnSize, int a, int b, int c) {
    for (int i = 0; i < returnSize; i++) {
        if ((result[i][0] == a || result[i][0] == b || result[i][0] == c) &&
            (result[i][1] == a || result[i][1] == b || result[i][1] == c) &&
            (result[i][2] == a || result[i][2] == b || result[i][2] == c)) {
            return true;
        }
    }
    return false;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    // this comes from combination from permutation and combination
    // mostly combination for unique triplets from array of size numsSize
    int maxPossibleTriplets = (numsSize * (numsSize - 1) * (numsSize - 2)) / 6;

    int** result = (int**)malloc(maxPossibleTriplets * sizeof(int*));

    if (nums == NULL || numsSize < 3) {
        free(result);
        return NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            for (int k = j + 1; k < numsSize; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    if (!isDuplicate(result, *returnSize, nums[i], nums[j], nums[k])) {
                        result[*returnSize] = (int*)malloc(3 * sizeof(int));
                        result[*returnSize][0] = nums[i];
                        result[*returnSize][1] = nums[j];
                        result[*returnSize][2] = nums[k];
                        (*returnSize)++;
                    }
                }
            }
        }
    }

    // Adjust memory allocation for returnColumnSizes
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 3;
    }

    // Reallocate result to trim excess space
    result = (int**)realloc(result, (*returnSize) * sizeof(int*));

    return result;

} */


/*
 * Optimized Two Pointer Approach
 * Time Complexity: O(n^2) - Sorting the array takes O(n log n), then the two-pointer approach takes O(n^2).
 * Space Complexity: O(n) - Space for the result, with dynamic allocation to manage memory efficiently.
 * Steps:
 * 1. Sort the array.
 * 2. Use a for loop with one pointer (i) to iterate through the array.
 * 3. For each element at i, use two additional pointers (left and right) to find pairs that sum up to -nums[i].
 * 4. If a valid pair is found, add the triplet to the result.
 * 5. Skip over duplicate elements to ensure uniqueness of the triplets.
 */
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);

    int **result = NULL;
    *returnSize = 0;
    int capacity = 0; // To keep track of allocated memory

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates

        int left = i + 1, right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                if (*returnSize == capacity) {
                    capacity = capacity == 0 ? 1 : capacity * 2;
                    result = (int **)realloc(result, capacity * sizeof(int *));
                    *returnColumnSizes = (int *)realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                result[*returnSize] = (int *)malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while (left < right && nums[left] == nums[left + 1]) left++; // Skip duplicates
                while (left < right && nums[right] == nums[right - 1]) right--; // Skip duplicates
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

void printResult(int** result, int returnSize, int* returnColumnSizes) {
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) {
                printf(", ");
            }
        }
        printf("]\n");
        free(result[i]); // Free each subarray
    }
    free(result); // Free the main array
    free(returnColumnSizes);
}

int main() {
    // Test Case 1
    int nums1[] = {-1, 0, 1, 2, -1, -4};
    int returnSize1;
    int* returnColumnSizes1;
    int** result1 = threeSum(nums1, sizeof(nums1) / sizeof(nums1[0]), &returnSize1, &returnColumnSizes1);
    printf("Test Case 1:\n");
    printResult(result1, returnSize1, returnColumnSizes1);

    // Test Case 2
    int nums2[] = {0, 1, 1};
    int returnSize2;
    int* returnColumnSizes2;
    int** result2 = threeSum(nums2, sizeof(nums2) / sizeof(nums2[0]), &returnSize2, &returnColumnSizes2);
    printf("Test Case 2:\n");
    printResult(result2, returnSize2, returnColumnSizes2);

    // Test Case 3
    int nums3[] = {0, 0, 0};
    int returnSize3;
    int* returnColumnSizes3;
    int** result3 = threeSum(nums3, sizeof(nums3) / sizeof(nums3[0]), &returnSize3, &returnColumnSizes3);
    printf("Test Case 3:\n");
    printResult(result3, returnSize3, returnColumnSizes3);

    return 0;
}

