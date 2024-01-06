#include <stdio.h>
#include <stdlib.h>

/* Brute Force Approach
 * 
 * Approach:
 * - Iterate through every possible pair of lines.
 * - For each pair, calculate the area formed between them.
 * - The area is calculated as min(height[i], height[j]) * (j - i), where i and j are the indices of the two lines.
 * - Keep track of the maximum area found.
 *
 * Time Complexity: O(n^2), where n is the number of lines. This is because we check every pair of lines.
 * Space Complexity: O(1), as no additional space is required apart from variables for iteration and storing the maximum area.
 */
/*
/*
int maxArea(int* height, int heightSize) {
    int max_area = 0;
    for(int i=0;i<heightSize;i++)
    {

        for(int j=0;j<heightSize;j++)
        {
            if (i == j)
            {
                continue;
            }
            // Now check for the length and breadth
            int length = (height[i] < height[j]) ? (height[i]) : (height[j]) ;
            int breadth = j - i;
            int local_area = length * breadth;
            if (local_area > max_area)
            {
                // update max area
                max_area = local_area;
            }
        // printf("i= %d, j= %d, local_area = %d and max_area = %d\n", i, j, local_area, max_area);
        }
        
    }
    return max_area;
} 
*/

/* Using Double Pointers Approach
 * 
 * Approach:
 * - Initialize two pointers, one at the start (left) and one at the end (right) of the array.
 * - Move the pointers towards each other, at each step calculating the area formed between the lines at the pointers.
 * - The area is calculated as min(height[left], height[right]) * (right - left).
 * - If the height at the left pointer is less than the height at the right pointer, move the left pointer to the right (i.e., increment it).
 * - If the height at the right pointer is less than or equal to the height at the left pointer, move the right pointer to the left (i.e., decrement it).
 * - Continue this process until the left and right pointers meet.
 * - Keep track of the maximum area found.
 *
 * Time Complexity: O(n), where n is the number of lines. Each line is accessed at most once.
 * Space Complexity: O(1), as the space used does not depend on the input size and is limited to a few variables.
 */
int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;

    int max_area = 0;

    while(left < right){
        // calculate area and update max_area
        int length = (height[left] < height[right]) ? (height[left]) : (height[right]);
        int breadth = abs(left - right);
        int local_area = length * breadth;

        if (local_area > max_area)
        {
            max_area = local_area;
        }

        // Update left and right pointer accordingly ot the smallest height
        if(height[left] < height[right])
        {
            // if right height is larger we keep right height and increment left pointer
            left++;
        }else{
            // if left height is larger decrement right pointer
            right--;
        }
    }
    return max_area;
}
int main() {
    // Test Case : 1
    int heights1[] = {1,8,6,2,5,4,8,3,7};
    int size1 = sizeof(heights1) / sizeof(heights1[0]);
    int result1 = maxArea(heights1, size1);
    printf("Test Case 1: Max Area = %d\n", result1);

    // Test Case : 2
    int heights2[] = {1, 1};
    int size2 = sizeof(heights2) / sizeof(heights2[0]);
    int result2 = maxArea(heights2, size2);
    printf("Test Case 2: Max Area = %d\n", result2);

    return 0;
}


