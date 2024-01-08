#include <stdio.h>


/**
 * Approach:
 * The function minJumps finds the minimum number of jumps to reach the end of the array.
 * Each element in the array represents the maximum jump length from that index.
 * 
 * The algorithm uses a greedy approach with a sliding window technique.
 * - 'left' and 'right' pointers define the current window, indicating the range of indices reachable in the current jump.
 * - Within each window, iterate to find the 'farthest' position that can be reached in the next jump.
 * - After examining the current window, update 'left' to be one more than 'right' (the start of the next window),
 *   and 'right' to be the 'farthest' reachable index.
 * - Increment 'result' each time the window is updated, representing a jump.
 * - Continue this process until 'right' reaches or surpasses the last index of the array.
 * 
 * Time Complexity:
 * O(n), where n is the length of the input array. Each element is considered exactly once when updating the 'farthest' position.
 * 
 * Space Complexity:
 * O(1), as the algorithm uses a constant amount of space regardless of the input array size.
 */

// Function to find the minimum number of jumps to reach the end
int minJumps(int nums[], int numsSize) {
    int result = 0;
    int left = 0,right = 0; // window stars at 0 and 0

    while (right < (numsSize - 1)) // right pointer within the array size
    {
        int farthest  = 0;
        for (int i = left; i< right + 1; i++)
        {
            if (farthest > (i + nums[i]))
            {
                // dot update farthest
            }else{
                farthest = i+ nums[i];
            }
        }

        left = right + 1;
        right = farthest;
        result++;
    }
    return result;
}

int main() {
    // Example test cases
    int nums1[] = {2, 3, 1, 1, 4};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Example 1: %d\n", minJumps(nums1, size1));

    int nums2[] = {2, 3, 0, 1, 4};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Example 2: %d\n", minJumps(nums2, size2));

    return 0;
}
