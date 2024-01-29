#include <stdio.h>
#include <stdbool.h>

/**
 * Checks if 's' is a subsequence of 't'.
 * 
 * A subsequence maintains the relative order of characters but not necessarily contiguous.
 * 
 * Approach:
 *  - Iterate through both strings simultaneously.
 *  - For each character in 't', check if it matches the current character in 's'.
 *  - If it matches, move to the next character in 's'.
 *  - If the end of 's' is reached, all characters of 's' are found in 't' in order, hence return true.
 *  - If the end of 't' is reached first, 's' is not a subsequence of 't', return false.
 * 
 * Time Complexity: O(n) - where n is the length of string 't'.
 * Space Complexity: O(1) - no additional space used.
 */
bool isSubsequence(char* s, char* t) {
    while(*s || *t)
    {
        if (*s == *t)
        {
            s++;
        }
        t++;
    }
    return !*s;
}

int main() {
    // Test cases
    char *s1 = "abc", *t1 = "ahbgdc";
    printf("Test Case 1: %s\n", isSubsequence(s1, t1) ? "true" : "false");

    char *s2 = "axc", *t2 = "ahbgdc";
    printf("Test Case 2: %s\n", isSubsequence(s2, t2) ? "true" : "false");

    return 0;
}
