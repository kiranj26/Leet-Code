#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Note: Brute Force or Ugly Approach
 * Time Complexity: O(n * m) n being wordSize and m being max no of element in any string
 * Space Complexity: O(n) only one array of size fo wordSize
 */

bool equalFrequency(char* word) {
    // Keep an hash table of frequency of each letter
    int frequency[26] = {0};
    int len = strlen(word);

    // Create hash map of frequency of characters in word
    for(int i=0; i< len; i++) {
        frequency[word[i]- 'a']++;
    }
    for(int i=0; i< 26; i++) {
        printf("%d ", frequency[i]);
    }

}

int main()
{
    char * word1 = "abcc";
    bool result = equalFrequency(word1);
    printf("Result = %d\n", result);

    char * word2 = "aazz";
    bool result1 = equalFrequency(word2);
    printf("Result1 = %d\n", result1);

    char * word3 = "cccaa";
    bool result2 = equalFrequency(word3);
    printf("Result2 = %d\n", result2);

}