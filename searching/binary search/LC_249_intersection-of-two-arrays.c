#include <stdio.h>
#include <stdlib.h>

/**
 * Approach 1: Using Hashmap
 * 
 * This approach uses two hashmaps (implemented as arrays) to store the presence of elements 
 * from the two input arrays. We iterate through the first array and mark its elements in the first hashmap. 
 * Then, we iterate through the second array and mark its elements in the second hashmap.
 * Finally, we find the intersection by checking which elements are marked in both hashmaps.
 * 
 * Steps:
 * 1. Initialize two arrays (hashmaps) of size 1000 to zero.
 * 2. Traverse the first input array (nums1) and mark its elements in the first hashmap.
 * 3. Traverse the second input array (nums2) and mark its elements in the second hashmap.
 * 4. Initialize an array to store the intersection result and a variable to keep track of the size.
 * 5. Check which elements are marked in both hashmaps and add them to the result array.
 * 6. Reallocate the result array to the size of the intersection.
 * 
 * Time Complexity: O(n + m), where n is the size of nums1 and m is the size of nums2. 
 * This is because we iterate through each array once.
 * 
 * Space Complexity: O(1), since the size of the hashmap is constant (1000).
 */

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

// Approach 1: Using Hashmap
/*
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int map1[1001] = { 0 };
    int map2[1001] = { 0 };
    for (int i = 0; i < nums1Size; i++) {
        map1[nums1[i]] = 1;
    }
    for (int i = 0; i < nums2Size; i++) {
        map2[nums2[i]] = 1;
    }

    int* ans = (int*)malloc(1001 * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < 1001; i++) {
        if (map1[i] == 1 && map2[i] == 1) {
            ans[*returnSize] = i;
            *returnSize += 1;
        }
    }
    
    ans = (int*)realloc(ans, *returnSize * sizeof(int));
    return ans;
}
*/

/**
 * Approach 2: Using Sorting and Two Pointers
 * 
 * This approach involves sorting both input arrays and then using two pointers to find the intersection.
 * 
 * Steps:
 * 1. Sort both input arrays (nums1 and nums2).
 * 2. Initialize two pointers (i and j) to 0.
 * 3. Traverse both arrays using the pointers:
 *    - If nums1[i] < nums2[j], increment pointer i.
 *    - If nums1[i] > nums2[j], increment pointer j.
 *    - If nums1[i] == nums2[j], add the element to the result array if it's not already present, and increment both pointers.
 * 4. Return the result array.
 * 
 * Time Complexity: O(n log n + m log m), where n is the size of nums1 and m is the size of nums2. 
 * This includes the time to sort both arrays.
 * 
 * Space Complexity: O(1) for sorting in place, plus O(min(n, m)) for the result array.
 */

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);
    int *result = (int *)malloc(sizeof(int) * 1001);
    int i = 0;
    int j = 0;
    *returnSize = 0;
    while(i < nums1Size && j < nums2Size) {
        if(nums1[i] == nums2[j]) {
            // Add only if it's not already in the result
            if(*returnSize == 0 || result[*returnSize - 1] != nums1[i]) {
                result[*returnSize] = nums1[i];
                *returnSize += 1;
            }
            i++;
            j++;
        } else if(nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return result;
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

    // Additional Test Cases
    int nums1_3[] = {1, 2, 3, 4, 5};
    int nums2_3[] = {3, 4, 5, 6, 7};
    int returnSize3;
    int* result3 = intersection(nums1_3, 5, nums2_3, 5, &returnSize3);
    printf("Test Case 3: ");
    printArray(result3, returnSize3);
    free(result3);

    int nums1_4[] = {0, 1, 2, 3};
    int nums2_4[] = {3, 2, 1, 0};
    int returnSize4;
    int* result4 = intersection(nums1_4, 4, nums2_4, 4, &returnSize4);
    printf("Test Case 4: ");
    printArray(result4, returnSize4);
    free(result4);

    int nums1_5[] = {7, 8, 9};
    int nums2_5[] = {10, 11, 12};
    int returnSize5;
    int* result5 = intersection(nums1_5, 3, nums2_5, 3, &returnSize5);
    printf("Test Case 5: ");
    printArray(result5, returnSize5);
    free(result5);
    
    int nums1_6[] = {1000, 2, 2, 1000};
    int nums2_6[] = {1000, 1000, 2};
    int returnSize6;
    int* result6 = intersection(nums1_6, 4, nums2_6, 3, &returnSize6);
    printf("Test Case 6: ");
    printArray(result6, returnSize6);
    free(result6);

    return 0;
}
