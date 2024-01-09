#include <stdio.h>
#include <stdlib.h>

/**
 * Brute Force Method for Two Sum Problem.
 * 
 * Approach:
 * Iterate through each element 'x' and find if there is another value that equals to 'target - x'.
 * 
 * Time Complexity: O(n^2)
 * For each element, we try to find its complement by looping through the rest of the array which takes O(n) time. 
 * Therefore, the time complexity is O(n^2).
 * 
 * Space Complexity: O(1)
 * The space required does not depend on the size of the input array, so it is constant space.
 */
/*
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 2;

    int * result = (int *)malloc(sizeof(int)*2);

    for (int i=0;i<numsSize;i++)
    {
        for(int j=0;j<numsSize;j++)
        {
            if (i == j)
            {
                continue;
            }
            if ((nums[i] + nums[j]) == target)
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;
}
*/

/**
 * Hashmap-based Solution for Two Sum Problem.
 * 
 * Approach:
 * Use an array to mimic a hash table. For each element, calculate its complement (target - current element).
 * Then, search for this complement in the array. If found, return their indices. 
 * If not found, store the element in the array.
 * 
 * Note: This implementation does not fully utilize the efficiency of a hash table, 
 * as it lacks direct key-value mapping and efficient collision handling.
 * 
 * Time Complexity: O(n^2)
 * The nested loop results in a quadratic time complexity, 
 * as for each element we potentially search the entire array for its complement.
 * 
 * Space Complexity: O(n)
 * We allocate an array (mimicking a hash table) of the same size as the input array.
 */

/* int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int * result;
    result = (int *)malloc(2 * sizeof(int));

    *returnSize = 2;

    int * hashmap;
    hashmap = (int *)malloc(numsSize * sizeof(int));

    for(int i=0;i<numsSize;i++)
    {
        int complement = target- nums[i];

        // search for the complement in an hashmap
        for(int j=0;j<numsSize;j++)
        {
            if (hashmap[j] == complement)
            {
                // return index of the complement
                result[0] = j;
                result[1] = i;
                return result;

            }
        }
        // if not found store the value in hashtable
        hashmap[i] = nums[i];
    }

    return NULL;
} */

/*
Even more efficent using Hash Table mimiced using Structure
*/

typedef struct {
    int key;
    int val;
} HashTable;

unsigned int hash(int key, int tableSize) {
    unsigned int hashVal = abs(key % tableSize);
    return hashVal;
}

void insert(HashTable *ht, int key, int val, int tableSize) {
    int index = hash(key, tableSize);
    while (ht[index].key != INT_MIN) {
        if (ht[index].key == key) {
            ht[index].val = val;
            return;
        }
        index = (index + 1) % tableSize;
    }
    ht[index].key = key;
    ht[index].val = val;
}

int search(HashTable *ht, int key, int tableSize) {
    int index = hash(key, tableSize);
    while (ht[index].key != INT_MIN) {
        if (ht[index].key == key) {
            return ht[index].val;
        }
        index = (index + 1) % tableSize;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
}

int main() {
    // Test cases
    int nums1[] = {2, 7, 11, 15};
    int target1 = 9;
    int returnSize1;
    int* result1 = twoSum(nums1, sizeof(nums1)/sizeof(nums1[0]), target1, &returnSize1);
    
    if (result1 != NULL) {
        printf("Test 1: [%d, %d]\n", result1[0], result1[1]);
        free(result1);
    } else {
        printf("No solution found for Test 1\n");
    }

    int nums2[] = {3, 2, 4};
    int target2 = 6;
    int returnSize2;
    int* result2 = twoSum(nums2, sizeof(nums2)/sizeof(nums2[0]), target2, &returnSize2);

    if (result2 != NULL) {
        printf("Test 2: [%d, %d]\n", result2[0], result2[1]);
        free(result2);
    } else {
        printf("No solution found for Test 2\n");
    }

    int nums3[] = {3, 3};
    int target3 = 6;
    int returnSize3;
    int* result3 = twoSum(nums3, sizeof(nums3)/sizeof(nums3[0]), target3, &returnSize3);

    if (result3 != NULL) {
        printf("Test 3: [%d, %d]\n", result3[0], result3[1]);
        free(result3);
    } else {
        printf("No solution found for Test 3\n");
    }

    return 0;
}
