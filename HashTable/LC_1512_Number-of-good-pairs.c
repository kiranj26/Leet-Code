#include <stdio.h>

/* 
Brute Force Approach
- Iterates through each pair of elements and checks if they are identical.
- Time Complexity: O(N^2), where N is the size of the array. This is because for each element, we potentially iterate over the rest of the array.
- Space Complexity: O(1), as no additional space is used apart from variables for iteration and counting.
*/
/* 
int numIdenticalPairs(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                count++;
            }
        }
    }
    return count;
} 
*/

/* 
Hash Table Approach 
- Utilizes a hash table to keep track of the frequency of each number in the array.
- Iterates through the array to populate the hash table.
- Then, for each unique number, calculates the number of good pairs it can form based on its frequency.
- If a number appears F times in the array, the number of good pairs formed is C(F, 2) = F * (F - 1) / 2.
- Time Complexity: O(N), where N is the size of the array. The array is iterated once to fill the hash table, and then the hash table is iterated to calculate the pairs.
- Space Complexity: O(K), where K is the range of the numbers (in this case, 1 to 100). The hash table size is constant and does not depend on the size of the input array.
*/
int numIdenticalPairs(int* nums, int numsSize) {
    int count  = 0;
    int hashTable[101] = {0}; // Hash table for frequencies of numbers in the range 1-100

    // Populate the frequency table
    for (int i = 0; i < numsSize; i++) {
        hashTable[nums[i]]++;
    }

    // Calculate the number of good pairs
    for (int i = 0; i < 101; i++) {
        if (hashTable[i] > 1) { // Check if the number appears more than once
            int C = hashTable[i] * (hashTable[i] - 1) / 2;
            count += C;
        }
    }
    return count;
}

int main() {
    int nums1[] = {1, 2, 3, 1, 1, 3};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Number of Good Pairs in [1,2,3,1,1,3]: %d\n", numIdenticalPairs(nums1, size1));

    int nums2[] = {1, 1, 1, 1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Number of Good Pairs in [1,1,1,1]: %d\n", numIdenticalPairs(nums2, size2));

    int nums3[] = {1, 2, 3};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Number of Good Pairs in [1,2,3]: %d\n", numIdenticalPairs(nums3, size3));

    return 0;
}
