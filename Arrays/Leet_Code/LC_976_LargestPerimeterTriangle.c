#include <stdio.h>
#include <stdlib.h>
/*
Brute Force : 
*/
int largestPerimeter(int* nums, int numsSize){
    int max_perimeter = 0;
    for(int i = 0;i<numsSize;i++){
        for(int j= i+1;j<numsSize;j++){
            for(int k= j+1;k<numsSize;k++){
            
            // check if triangle is valid by checking 
            int a = nums[i]; 
            int b = nums[j];
            int c = nums[k];

            if (
                ((a+b) > c) &&
                ((b+c) > a) &&
                ((c+a) > b)
            ){
                // UPDATE MAX_PERIMETER
                max_perimeter = (a+b+c) > max_perimeter ? (a+b+c): max_perimeter;
            }
            }
        }
    }
    return max_perimeter;
}

int main() {
    // Test Case 1
    int nums1[] = {2, 1, 2};
    int result1 = largestPerimeter(nums1, sizeof(nums1) / sizeof(nums1[0]));
    printf("Test Case 1: Largest Perimeter = %d\n", result1);

    // Test Case 2
    int nums2[] = {1, 2, 1, 10};
    int result2 = largestPerimeter(nums2, sizeof(nums2) / sizeof(nums2[0]));
    printf("Test Case 2: Largest Perimeter = %d\n", result2);

    return 0;
}
