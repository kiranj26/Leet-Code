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

// Function prototype
// Approach 1 : My First try using Hashmap
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int map1[1000] = { 0 };
    int map2[1000] = { 0 };
    for (int i = 0; i < nums1Size; i++) {
        map1[nums1[i]] = 1;
    }
    for (int i = 0; i < nums2Size; i++) {
        map2[nums2[i]] = 1;
    }

    int* ans = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < 1000; i++) {
        if (map1[i] == 1 && map2[i] == 1) {
            ans[*returnSize] = i;
            *returnSize += 1;
        }
    }
    
    ans = (int*)realloc(ans, *returnSize * sizeof(int));
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

    return 0;
}

// Boilerplate for Approach 2
// Note: Uncomment and fill in the logic for Approach 2, comment out Approach 1 code

/*
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // Implement a different approach here (e.g., using sorting and two pointers)
}
*/

