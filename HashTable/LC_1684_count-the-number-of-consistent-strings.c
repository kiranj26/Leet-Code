#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Approach and Complexity Analysis
   - This function counts the number of consistent strings in the array 'words'.
   - A string is consistent if all characters in it appear in the string 'allowed'.
   - The approach involves creating a frequency array 'allowedFreq' to mark which characters are allowed.
   - Time Complexity: 
     - O(N) for iterating over the 'allowed' string, where N is the length of 'allowed'.
     - O(M * K) for iterating over the 'words' array, where M is the number of words and K is the average length of the words.
     - Overall time complexity is O(N + M * K).
   - Space Complexity: 
     - O(1) as the size of the 'allowedFreq' array is constant (26 for all lowercase English letters).
*/

int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    int count = 0;
    bool allowedFreq[26] = {false};
    int allowedLen = strlen(allowed);

    // Marking allowed characters
    for (int i = 0; i < allowedLen; i++) {
        allowedFreq[allowed[i] - 'a'] = true;
    }

    // Checking each word
    for (int i = 0; i < wordsSize; i++) {
        bool isValidString = true;
        for (int j = 0; words[i][j] != '\0'; j++) {
            if (!allowedFreq[words[i][j] - 'a']) {
                isValidString = false;
                break;
            }
        }
        if (isValidString) {
            count++;
        }
    }

    return count;
}

int main() {
    // Test the function with example cases
    char *allowed = "ab";
    char *words[] = {"ad", "bd", "aaab", "baa", "badab"};
    int wordsSize = sizeof(words) / sizeof(words[0]);
    printf("Number of consistent strings: %d\n", countConsistentStrings(allowed, words, wordsSize));

    return 0;
}
