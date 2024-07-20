#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Approach:
 * This function, commonChars, aims to find all characters that appear in each string of the given array 'words'.
 * The approach involves using a hashmap (array of size 26) to count character occurrences.
 *
 * Steps:
 * 1. Initialize the hashmap using the character counts from the first word.
 * 2. For each subsequent word, update the hashmap to keep the minimum count of each character.
 * 3. After processing all words, the hashmap will contain the minimum count of each character across all words.
 * 4. Prepare the result array with characters that have a non-zero count in the hashmap.
 *
 * Time Complexity:
 * - O(n * m), where n is the number of words and m is the length of the longest word.
 * - Each word is processed individually, and character counting is done in O(m) time.
 *
 * Space Complexity:
 * - O(1), since the size of the hashmap (26) is constant, and additional space used is proportional to the number of common characters.
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** words, int wordsSize, int* returnSize) {
    // Initialize a hashmap to count occurrences of each character in the first word
    int hashmap[26] = {0};
    int tempHashmap[26];

    // Populate the hashmap with the character counts from the first word
    for (int j = 0; j < strlen(words[0]); j++) {
        hashmap[words[0][j] - 'a']++;
    }

    // Update the hashmap for each subsequent word
    for (int i = 1; i < wordsSize; i++) {
        // Reset tempHashmap for the current word
        memset(tempHashmap, 0, sizeof(tempHashmap));
        // Count the occurrences of each character in the current word
        for (int j = 0; j < strlen(words[i]); j++) {
            tempHashmap[words[i][j] - 'a']++;
        }
        // Update the original hashmap to keep the minimum count of each character
        for (int k = 0; k < 26; k++) {
            if (hashmap[k] > tempHashmap[k]) {
                hashmap[k] = tempHashmap[k];
            }
        }
    }

    // Count how many characters are common across all words
    *returnSize = 0;
    for (int i = 0; i < 26; i++) {
        if (hashmap[i] > 0) {
            *returnSize += hashmap[i];
        }
    }

    // Allocate memory for the result array
    char **result = (char **)malloc((*returnSize) * sizeof(char *));
    int idx = 0;

    // Populate the result array with the common characters
    for (int i = 0; i < 26; i++) {
        while (hashmap[i] > 0) {
            result[idx] = (char *)malloc(2 * sizeof(char));
            result[idx][0] = 'a' + i;
            result[idx][1] = '\0';
            hashmap[i]--;
            idx++;
        }
    }

    return result;
}

int main() {
    // Example test case
    char *words[] = {"bella", "label", "roller"};
    int wordsSize = sizeof(words) / sizeof(words[0]);
    int returnSize;

    // Call commonChars function to find common characters in all words
    char **commonCharacters = commonChars(words, wordsSize, &returnSize);

    // Print the common characters
    printf("Common characters:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s ", commonCharacters[i]);
        free(commonCharacters[i]); // Free each individual string
    }
    printf("\n");

    // Free the array of strings
    free(commonCharacters);

    return 0;
}
