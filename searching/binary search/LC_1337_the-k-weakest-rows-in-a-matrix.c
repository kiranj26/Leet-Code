#include <stdio.h>
#include <stdlib.h>

/**
 * Approach 1: Sorting and Iterative Check
 * 
 * This approach involves sorting the input array and iterating through it to find the
 * longest subsequence with sum less than or equal to each query.
 * 
 * Steps:
 * 1. Sort the input array.
 * 2. For each query, iterate through the sorted array and accumulate the sum of elements
 *    until the sum exceeds the target specified by the query.
 * 3. Track the length of the longest subsequence for each query.
 * 
 * Time Complexity: O(n log n + q * n), where n is the size of the input array and q is the number of queries.
 * This includes the time to sort the array (O(n log n)) and to process each query (O(q * n)).
 * 
 * Space Complexity: O(q), for storing the result array.
 */

// Function to print an array
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

// Comparator function for qsort
// This function compares two integers and is used for sorting the array in ascending order
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to find the longest subsequence with sum less than or equal to each query in the queries array
// nums: the main array
// numsSize: size of the main array
// queries: the queries array
// queriesSize: size of the queries array
// returnSize: pointer to an integer where the size of the result array will be stored
int* answerQueriesApproach1(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {
    // Step 1: Sort the nums array in ascending order
    qsort(nums, numsSize, sizeof(int), compare);

    // Allocate memory for the result array which will store the lengths of the longest subsequences
    int *result = (int *)calloc(queriesSize, sizeof(int));

    // Iterate through each query in the queries array
    for (int m = 0; m < queriesSize; m++) {
        int target = queries[m];  // Current target sum from the queries array

        int current_sum = 0;  // Sum of the current subsequence
        int current_longest_subsequence_length = 0;  // Length of the current longest subsequence

        // Iterate through the sorted nums array to find the longest subsequence for the current target
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] + current_sum <= target) {
                // If adding the current element to the subsequence does not exceed the target sum, add it
                current_sum += nums[i];
                current_longest_subsequence_length++;
            } else {
                // If adding the current element exceeds the target sum, break the loop
                break;
            }
        }
        // Store the length of the longest subsequence for the current query in the result array
        result[m] = current_longest_subsequence_length;
    }

    *returnSize = queriesSize;  // Set the size of the result array
    return result;  // Return the result array
}


/**
 * Approach 2: Sorting plus Two Pointers
 * 
 * This approach also starts with sorting the input array. Then, for each query, it uses 
 * the two-pointer technique to find the longest subsequence with sum less than or equal 
 * to the target value of each query.
 * 
 * Steps:
 * 1. Sort the input array.
 * 2. For each query, use two pointers to traverse the sorted array and maintain a 
 *    window of elements that form a valid subsequence with sum less than or equal to 
 *    the target value.
 * 3. Track the length of the longest subsequence for each query.
 * 
 * Time Complexity: O(n log n + q * n), where n is the size of the input array and q is 
 * the number of queries. This includes the time to sort the array (O(n log n)) and to 
 * process each query (O(q * n)).
 * 
 * Space Complexity: O(q), for storing the result array.
 */

// Function to find the longest subsequence with sum <= target_sum using the two-pointer technique
int findLongestSubsequenceWithSum(int* nums, int numsSize, int target_sum) {
    int start = 0;
    int current_sum = 0;
    int max_length = 0;

    for (int end = 0; end < numsSize; end++) {
        current_sum += nums[end];

        // If the current sum exceeds the target, move the start pointer
        while (current_sum > target_sum && start <= end) {
            current_sum -= nums[start];
            start++;
        }

        // Update max_length if the current subsequence is valid
        if (current_sum <= target_sum) {
            int current_length = end - start + 1;
            if (current_length > max_length) {
                max_length = current_length;
            }
        }
    }

    return max_length;
}

// Function to process queries using the two-pointer technique
int* answerQueriesApproach2(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {
    // Sort the nums array in ascending order
    qsort(nums, numsSize, sizeof(int), compare);

    // Allocate memory for the result array which will store the lengths of the longest subsequences
    int *result = (int *)malloc(queriesSize * sizeof(int));

    // Iterate through each query in the queries array
    for (int i = 0; i < queriesSize; i++) {
        int target_sum = queries[i];

        // Use two pointers start and end for each query to compute the longest subsequence 
        result[i] = findLongestSubsequenceWithSum(nums, numsSize, target_sum);
    }

    *returnSize = queriesSize;
    return result;
}

int main() {
    // Test Case 1
    int nums1[] = {4, 5, 2, 1};
    int queries1[] = {3, 10, 21};
    int returnSize1;
    int* result1 = answerQueriesApproach2(nums1, 4, queries1, 3, &returnSize1);
    printf("Test Case 1: ");
    printArray(result1, returnSize1);
    free(result1);

    // Uncomment to use additional test cases
    /*
    // Test Case 2
    int nums2[] = {2, 3, 4, 5};
    int queries2[] = {1};
    int returnSize2;
    int* result2 = answerQueriesApproach2(nums2, 4, queries2, 1, &returnSize2);
    printf("Test Case 2: ");
    printArray(result2, returnSize2);
    free(result2);

    // Test Case 3
    int nums3[] = {7, 4, 1, 8, 3};
    int queries3[] = {3, 10, 15};
    int returnSize3;
    int* result3 = answerQueriesApproach2(nums3, 5, queries3, 3, &returnSize3);
    printf("Test Case 3: ");
    printArray(result3, returnSize3);
    free(result3);

    // Test Case 4
    int nums4[] = {1, 1, 1, 1};
    int queries4[] = {2, 4, 6};
    int returnSize4;
    int* result4 = answerQueriesApproach2(nums4, 4, queries4, 3, &returnSize4);
    printf("Test Case 4: ");
    printArray(result4, returnSize4);
    free(result4);
    */

    return 0;
}
