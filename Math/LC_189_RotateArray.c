#include <stdio.h>
#include <stdlib.h>

// Function to reverse a section of the array
void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

/**
 * Rotates the array to the right by k steps using the reverse method.
 * This algorithm has a time complexity of O(n) and space complexity of O(1).
 */
void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;  // Handle cases where k is greater than numsSize
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

/**
 * Rotates the array to the right by k steps using the extra array method.
 * This algorithm has a time complexity of O(n) and space complexity of O(n).
 */
/*
void rotateExtraArray(int* nums, int numsSize, int k) {
    k = k % numsSize;
    int* temp = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        temp[(i + k) % numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        nums[i] = temp[i];
    }
    free(temp);
}
*/

/**
 * Rotates the array to the right by k steps using the cyclic replacements method.
 * This algorithm has a time complexity of O(n) and space complexity of O(1).
 */
/*
void rotateCyclicReplacements(int* nums, int numsSize, int k) {
    k = k % numsSize;
    int count = 0;
    for (int start = 0; count < numsSize; start++) {
        int current = start;
        int prev = nums[start];
        do {
            int next = (current + k) % numsSize;
            int temp = nums[next];
            nums[next] = prev;
            prev = temp;
            current = next;
            count++;
        } while (start != current);
    }
}
*/

int main() {
    // Test Case 1
    int nums1[] = {1, 2, 3, 4, 5, 6, 7};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int k1 = 3;
    rotate(nums1, numsSize1, k1);
    printf("Output for Test Case 1: ");
    for (int i = 0; i < numsSize1; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    // Test Case 2
    int nums2[] = {-1, -100, 3, 99};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    int k2 = 2;
    rotate(nums2, numsSize2, k2);
    printf("Output for Test Case 2: ");
    for (int i = 0; i < numsSize2; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    // Uncomment to test the extra array method
    /*
    int nums3[] = {1, 2, 3, 4, 5, 6, 7};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    int k3 = 3;
    rotateExtraArray(nums3, numsSize3, k3);
    printf("Output for Test Case 3: ");
    for (int i = 0; i < numsSize3; i++) {
        printf("%d ", nums3[i]);
    }
    printf("\n");
    */

    // Uncomment to test the cyclic replacements method
    /*
    int nums4[] = {1, 2, 3, 4, 5, 6, 7};
    int numsSize4 = sizeof(nums4) / sizeof(nums4[0]);
    int k4 = 3;
    rotateCyclicReplacements(nums4, numsSize4, k4);
    printf("Output for Test Case 4: ");
    for (int i = 0; i < numsSize4; i++) {
        printf("%d ", nums4[i]);
    }
    printf("\n");
    */

    return 0;
}
