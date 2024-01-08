#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Determines if a string can be segmented into a sequence of dictionary words.
 *
 * Approach:
 * The function uses dynamic programming to build up a solution in a bottom-up manner.
 * It creates a boolean DP array where DP[i] represents whether the substring s[0...i] 
 * can be segmented into dictionary words. The DP array is iterated backward.
 *
 * For each position i in the string s, the function iterates through all dictionary words.
 * It checks if the word can fit in the substring starting from i and compares the word
 * with the substring. If a word matches and the rest of the substring (after the word) 
 * can also be segmented (indicated by DP[i + word length]), DP[i] is marked true.
 *
 * This process continues until the start of the string is reached. The value at DP[0] gives
 * the final result, indicating whether the entire string s can be segmented into dictionary words.
 *
 * Time Complexity:
 * O(n * m * l), where n is the length of the string s, m is the number of words in the dictionary,
 * and l is the average length of the words in the dictionary. This complexity arises as for each 
 * position in s (n), the function potentially iterates through all words (m) and compares a substring
 * of length up to l.
 *
 * Space Complexity:
 * O(n), where n is the length of the string s. This is needed for the DP array. The space is used 
 * to keep track of the segmentation status of each substring of s.
 *
 * @param s The string to be segmented.
 * @param wordDict Array of word dictionary strings.
 * @param wordDictSize Size of the word dictionary.
 * @return true if the string can be segmented, false otherwise.
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
