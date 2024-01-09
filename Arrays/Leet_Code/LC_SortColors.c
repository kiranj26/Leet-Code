#include <stdio.h>

/*
Sort Colors (Brute Force Approach)

Approach:
- Count the number of 0s, 1s, and 2s in the array.
- Overwrite the original array with the counted number of 0s, then 1s, and finally 2s.

Time Complexity: O(n), where n is the size of the array.
Space Complexity: O(1), as it uses a fixed-size array for counting.
*/
void sortColorsBruteForce(int* nums, int numsSize) {
    int count[3] = {0, 0, 0};

    // Count the number of 0s, 1s, and 2s
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }

    // Overwrite the original array with the correct count of each color
    int index = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < count[i]; j++) {
            nums[index++] = i;
        }
    }
}
/*
Sort Colors (Dutch National Flag / Three Pointers Approach)

Approach:
- Use three pointers: low, mid, and high.
- Arrange 0s before the low pointer, 1s between low and high, and 2s after high.
- Iterate through the array using the mid pointer and swap elements to place them in the correct partition.

Time Complexity: O(n), where n is the size of the array.
Space Complexity: O(1), as it sorts the array in place without using additional memory.
*/
/* Three Pointers */
void sortColors(int* nums, int numsSize) {
    int low = 0, mid = 0, high = numsSize - 1, temp;

    while (mid <= high) {
        switch (nums[mid]) {
            case 0:
                temp = nums[low];
                nums[low++] = nums[mid];
                nums[mid++] = temp;
                break;
            case 1:
                mid++;
                break;
            case 2:
                temp = nums[mid];
                nums[mid] = nums[high];
                nums[high--] = temp;
                break;
        }
    }   
}