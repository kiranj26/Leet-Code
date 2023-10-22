#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// @ Note : Sliding Windows Approach
// @ Time Complexity
// @ Space Complexity
int divisorSubstrings(int num, int k) {
    char str[12]; // 1 <= num <= 10^9 => at most 10 digits, +1 for null-terminator.
    sprintf(str, "%d", num);

    int len = strlen(str);
    int left = 0;
    int right = k-1;

    int k_beauty = 0;

    while(right < len) {
        int calculate_num = 0;

        // Convert substring of length k back to a number
        for (int j = left; j <= right; j++) {
            calculate_num = calculate_num * 10 + (str[j] - '0');
        }

        if (calculate_num != 0 && num % calculate_num == 0) {
            k_beauty++;
        }

        left++;
        right++;
    }

    return k_beauty;
}


int main() {
    int num, k, result;

    // Sample test cases for verification
    num = 240;
    k = 2;
    result = divisorSubstrings(num, k);
    printf("For num = %d and k = %d, k-beauty is: %d\n", num, k, result);

    num = 430043;
    k = 2;
    result = divisorSubstrings(num, k);
    printf("For num = %d and k = %d, k-beauty is: %d\n", num, k, result);

    // You can add more test cases or even ask user for input as per your need.

    return 0;
}
