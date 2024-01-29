#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/* Brute Force Approach:
   - Iterate over each element.
   - Find the maximum element to the right of the current element.
   - Time Complexity: O(n^2) [For each element, iterate through all elements to its right]
   - Space Complexity: O(n) [For the result array]

int greatestElement(int *arr, int left, int right) {
    if (left == right) {
        return -1;
    }
    int greatest = INT_MIN;
    for (int i = left; i < right; i++) {
        if (arr[i] > greatest) {
            greatest = arr[i];
        }
    }
    return greatest;
}

int* replaceElements(int* arr, int arrSize, int* returnSize) {
    int *result = (int *)malloc(arrSize * sizeof(int));
    *returnSize = arrSize;

    for (int i = 0; i < arrSize; i++) {
        result[i] = greatestElement(arr, i + 1, arrSize);
    }

    return result;
} */

/* Efficient Approach:
   - The goal is to replace each element with the greatest element among the elements to its right.
   - Instead of checking all elements to the right of each element (as in brute force), 
     this approach maintains a running maximum from right to left.
   - Formula: result[i] = max(arr[i+1], result[i+1])
     - result[i] is the maximum element to the right of arr[i].
     - max(arr[i+1], result[i+1]) compares the next element in the array (arr[i+1]) 
       with the current known maximum to the right (result[i+1]).
   - The last element is always replaced with -1.
   - Time Complexity: O(n) [Single traversal from right to left]
     - n: Number of elements in the array.
   - Space Complexity: O(n) [For the result array]
   - This approach significantly reduces the time complexity by avoiding redundant comparisons.
*/
int max(int a, int b) {
    return ((a>=b) ? a:b);
}
int* replaceElements(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;
    int * result  = (int *)malloc(arrSize * sizeof(int));
    result[arrSize -1] = -1;
    for (int i = arrSize - 2 ; i>= 0 ; i--)
    {
        result[i] = max(arr[i+1], result[i+1]);
    }
    return result;
}
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Test case 1
    int arr1[] = {17, 18, 5, 4, 6, 1};
    int arrSize1 = sizeof(arr1) / sizeof(arr1[0]);
    int returnSize1;
    int* replacedArr1 = replaceElements(arr1, arrSize1, &returnSize1);
    printf("Test Case 1: ");
    printArray(replacedArr1, returnSize1);
    free(replacedArr1); // Free the allocated memory

    // Test case 2
    int arr2[] = {400};
    int arrSize2 = sizeof(arr2) / sizeof(arr2[0]);
    int returnSize2;
    int* replacedArr2 = replaceElements(arr2, arrSize2, &returnSize2);
    printf("Test Case 2: ");
    printArray(replacedArr2, returnSize2);
    free(replacedArr2); // Free the allocated memory

    return 0;
}