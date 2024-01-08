#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Brute Firce Checking if each word dict word is available in main string
 */
bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int len = strlen(s);
    
    // DP array to store the subproblem results. DP[i] will be true if the substring s[0..i] can be segmented
    // into dictionary words, false otherwise.
    bool *DP = (bool *)calloc(len + 1, sizeof(bool));
    DP[len] = true; // Base case: An empty string can always be segmented.

    // Iterate from the end of the string to the beginning.
    for (int i = len - 1; i >= 0; i--) {
        // Check each word in the dictionary.
        for (int w = 0; w < wordDictSize; w++) {
            int wordLen = strlen(wordDict[w]);

            // Check if the current position plus the length of the word is within the bounds of s.
            // Also check if the substring of s starting from this position matches the word.
            if (len - i >= wordLen && strncmp(s + i, wordDict[w], wordLen) == 0) {
                // If the word matches, set DP[i] to true if DP[i + wordLen] is true.
                if (DP[i + wordLen]) {
                    DP[i] = true;
                    break; // No need to check further words as we found a valid segmentation.
                }
            }
        }
    }

    bool result = DP[0]; // The result is the value for the entire string.
    free(DP); // Free the allocated memory for the DP array.
    return result;
}

int main() {
    // Example test case 1
    char s1[] = "leetcode";
    char* wordDict1[] = {"leet", "code"};
    int wordDictSize1 = sizeof(wordDict1) / sizeof(wordDict1[0]);
    
    bool result1 = wordBreak(s1, wordDict1, wordDictSize1);
    printf("Result 1: %s\n", result1 ? "true" : "false");

    // Example test case 2
    char s2[] = "applepenapple";
    char* wordDict2[] = {"apple", "pen"};
    int wordDictSize2 = sizeof(wordDict2) / sizeof(wordDict2[0]);
    
    bool result2 = wordBreak(s2, wordDict2, wordDictSize2);
    printf("Result 2: %s\n", result2 ? "true" : "false");

    // Example test case 3
    char s3[] = "catsandog";
    char* wordDict3[] = {"cats", "dog", "sand", "and", "cat"};
    int wordDictSize3 = sizeof(wordDict3) / sizeof(wordDict3[0]);
    
    bool result3 = wordBreak(s3, wordDict3, wordDictSize3);
    printf("Result 3: %s\n", result3 ? "true" : "false");

    return 0;
}
