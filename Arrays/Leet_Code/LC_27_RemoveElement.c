#include <stdio.h>

/**
 * Removes all instances of 'val' from the array 'nums' in-place and returns the new length.
 * 
 * Approach:
 *  - Use two pointers: one for iterating over the array ('i') and another for tracking the position of the next non-'val' element ('newLen').
 *  - When an element not equal to 'val' is found, it's moved to the position indicated by 'newLen', and 'newLen' is incremented.
 *  - This effectively overwrites 'val' elements and maintains non-'val' elements in 'nums'.
 * 
 * Time Complexity: O(n), where n is the length of 'nums'.
 * Space Complexity: O(1), in-place modification with no extra space.
 */

int removeElement(int* nums, int numsSize, int val) {
    int newLen = 0;
    for (int i = 0; i< numsSize; i++) {
        if (nums[i] != val)
        {
            // we have a value which is val
            // we need to remove it 
            nums[newLen++] = nums[i];
        }
    }
    return newLen;
}

int main() {
    // Test Case 1
    int nums1[] = {3, 2, 2, 3};
    int val1 = 3;
    int newLength1 = removeElement(nums1, 4, val1);
    printf("Test Case 1: New Length = %d, Array = ", newLength1);
    for (int i = 0; i < newLength1; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    // Test Case 2
    int nums2[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int newLength2 = removeElement(nums2, 8, val2);
    printf("Test Case 2: New Length = %d, Array = ", newLength2);
    for (int i = 0; i < newLength2; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    return 0;
}
