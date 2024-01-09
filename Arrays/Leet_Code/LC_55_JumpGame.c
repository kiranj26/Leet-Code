#include <stdio.h>
#include <stdbool.h>
/* Brute Force
*/
/* 
bool canJump(int* nums, int numsSize) {
    if (numsSize == 1) return true;

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == 0) continue;
        for (int j = 1; j <= nums[i] && i + j < numsSize; j++) {
            if (i + j == numsSize - 1) return true;
        }
    }

    return false;
} 
*/

/* Greedy Approach Explanation:
 * The function canJump uses a greedy approach to solve the "Jump Game" problem. 
 * It iterates through each element of the array 'nums', each element representing the maximum jump length from that position.
 * The goal is to determine whether the end of the array can be reached.
 * 
 * At each step, the function calculates the furthest position that can be reached (longest_jump) from the current or previous steps. 
 * If at any point, the current index is greater than the longest_jump, it means there's a gap that cannot be crossed, and the function returns false.
 * If the longest_jump reaches or exceeds the last index of the array, it means the end is reachable, and the function returns true.
 * 
 * Time Complexity: O(n), where n is the size of the input array. Each element is visited exactly once.
 * Space Complexity: O(1), as no additional space is used that scales with the input size.
 */
bool canJump(int* nums, int numsSize) {
    // Implementation of this function is needed
    int longest_jump = 0;

    for (int i = 0; i< numsSize ; i++){
        if (i > longest_jump)
        {
            return false;
        }

        int currentJump  = i + nums[i];

        // update furthest
        if (currentJump > longest_jump)
        {
            longest_jump = currentJump;
        }
        // check if we have reached the end of beyond array
        if (longest_jump >= numsSize - 1) 
        {
            return true;
        }

    }    
    return false; // Placeholder return
}

int main() {
    // Example test cases
    int nums1[] = {2, 3, 1, 1, 4};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);

    int nums2[] = {3, 2, 1, 0, 4};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);

    // Testing the function with the first example
    if (canJump(nums1, size1)) {
        printf("Example 1: true\n");
    } else {
        printf("Example 1: false\n");
    }

    // Testing the function with the second example
    if (canJump(nums2, size2)) {
        printf("Example 2: true\n");
    } else {
        printf("Example 2: false\n");
    }

    return 0;
}
