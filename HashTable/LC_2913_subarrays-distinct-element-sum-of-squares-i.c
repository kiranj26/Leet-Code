#include <stdio.h>
#include <string.h>

/* brute Force */
/* int computeNoofDistinctElement( int * arr, int left, int right)
{
    int freq[101] = {0};
    // load frequency array
    for (int i = left; i <= right; i++)
    {
        freq[arr[i]]++;
    }
    int count = 0;
    for(int i = 0; i < 101; i++)
    {
        if (freq[i] >= 1)
        {
            count++;
        }
    }
    return (count * count);
}
int sumCounts(int* nums, int numsSize){
    int result = 0; 
    for (int i = 0 ; i< numsSize ; i++)
    {
        for (int j = 0; j < numsSize; j++)
        {
            int localSquare = 0;
            if (i == j)
            {
                // single element arrays are distinct
                localSquare  = 1;
                result += localSquare;
                printf("Square  %d  for i = %d and j = %d \n", localSquare, i , j);
            }else{
                // but for array of greater than 1 element
                //  check if distant and return square
                localSquare = computeNoofDistinctElement(nums, i , j);
                result += localSquare;
                printf("Square  %d  for i = %d and j = %d \n", localSquare, i , j);
            }
        }
    }
    return result;
} */
/* Optamize Solution
    // try to eliminate one of the for loop
    // we have just two choices
    
*/

int main() {
    // Test case 1
    int nums1[] = {1, 2, 1};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Test Case 1 Result: %d\n", sumCounts(nums1, size1));

    // Test case 2
    int nums2[] = {1, 1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Test Case 2 Result: %d\n", sumCounts(nums2, size2));

    // Add more test cases as needed
    return 0;
}
