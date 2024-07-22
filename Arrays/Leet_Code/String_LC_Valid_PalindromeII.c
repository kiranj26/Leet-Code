/**
 * LeetCode Problem: Valid Palindrome II
 * Author: Kiran Jojare
 * 
 * Approach:
 * 1. Use a helper function `isPalindrome` to check if a substring is a palindrome by comparing characters from both ends moving towards the center.
 * 2. In the main function `validPalindrome`, initialize two pointers `left` and `right` to the start and end of the string.
 * 3. Loop through the string, comparing characters from both ends.
 *    - If characters at `left` and `right` are equal, move both pointers inward.
 *    - If they are not equal, check if skipping one character from either end results in a palindrome by calling `isPalindrome` on the two possible substrings.
 * 4. Return `true` if any one of the substrings is a palindrome, otherwise return `false`.
 * 
 * Time Complexity:
 * - O(n), where n is the length of the string. This is because we potentially traverse the string up to twice: once in `validPalindrome` and once in `isPalindrome`.
 * 
 * Space Complexity:
 * - O(1), as we are only using a few additional variables for the pointers and not allocating extra space proportional to the input size.
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a substring is a palindrome
bool isPalindrome(char *s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

// Function to check if the string can be a palindrome after deleting at most one character
bool validPalindrome(char *s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else {
            // Check if removing one character makes the string a palindrome
            return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
        }
    }
    return true;
}

// Main function to test the implementation
int main() {
    // Test Case 1
    char str1[] = "aba";
    printf("Is \"%s\" a valid palindrome? %s\n", str1, validPalindrome(str1) ? "Yes" : "No");

    // Test Case 2
    char str2[] = "abca";
    printf("Is \"%s\" a valid palindrome? %s\n", str2, validPalindrome(str2) ? "Yes" : "No");

    // Test Case 3
    char str3[] = "abc";
    printf("Is \"%s\" a valid palindrome? %s\n", str3, validPalindrome(str3) ? "Yes" : "No");

    // Test Case 4
    char str4[] = "deeee";
    printf("Is \"%s\" a valid palindrome? %s\n", str4, validPalindrome(str4) ? "Yes" : "No");

    // Test Case 5
    char str5[] = "racecar";
    printf("Is \"%s\" a valid palindrome? %s\n", str5, validPalindrome(str5) ? "Yes" : "No");

    return 0;
}

/**
 * Short Summary:
 * - Use a helper function to check palindromes.
 * - Two pointers traverse from both ends.
 * - Skip one character if mismatch occurs.
 * - Time Complexity: O(n).
 * - Space Complexity: O(1).
 */
