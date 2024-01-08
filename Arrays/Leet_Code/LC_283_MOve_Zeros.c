#include <stdio.h>

/**
 * Function to move all zeros in the array to the end while maintaining the order of non-zero elements.
 * 
 * Approach:
 * The function uses two pointers - 'left' and 'right'. 'left' is used to keep track of the position
 * where the next non-zero element should be placed, and 'right' is used to iterate through the array.
 * When a non-zero element is found, it is swapped with the element at the 'left' index, and 'left' is incremented.
 * Zeros are effectively moved to the end of the array, and the order of non-zero elements is maintained.
 * 
 * Time Complexity: O(n), where n is the size of the array. Each element is visited at most once.
 * Space Complexity: O(1), as the operation is done in-place with constant extra space.
 * 
 * @param nums The array of integers.
 * @param numsSize The size of the array.
 */
// Function to move all zeroes to the end of the array
void swap(int * nums, int left, int right)
{
    int temp = nums[left];
    nums[left] = nums[right];
    nums[right] = temp;
}
void moveZeroes(int* nums, int numsSize) {
    int left = 0;
    int right = 0;

    for (; right < numsSize; right++) {
        if (nums[right] > 0)
        {
            // if positive
            // swap nums[left] and nums[right]
            swap(nums,left,right);
            left++;

        }else{
            // do nothing if 0 or negative
        }
    
    }
}

// Function to print the array
void printArray(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("Original Array: ");
    printArray(nums, numsSize);

    moveZeroes(nums, numsSize);

    printf("Array after moving zeroes: ");
    printArray(nums, numsSize);

    return 0;
}
