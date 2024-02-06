#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
int compareStrings(const void *a, const void *b) {
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);
}

int uniqueMorseRepresentations(char** words, int wordsSize) {
    char* morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
                     "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
                     "..-","...-",".--","-..-","-.--","--.."};
    char * transformedString[101] = {NULL};

    for (int i = 0; i < wordsSize; i++) {
        // Allocate enough space for the transformed string (assuming max length of Morse code per character is 4)
        transformedString[i] = malloc(strlen(words[i]) * 4 + 1);
        if (transformedString[i] == NULL) {
            // Handle memory allocation failure
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        transformedString[i][0] = '\0'; // Initialize the string

        for (int j = 0; j < strlen(words[i]); j++) {
            int index = words[i][j] - 'a';
            char * currentMorse = morse[index];

            strcat(transformedString[i], currentMorse);
        }
    }

    // now sort the transformed string array
    // and count how many elements have uniqueue neighbours
    qsort(transformedString, wordsSize, sizeof(char *), compareStrings);
    printf("Sorted Transformed String::::::::::::::::\n");
    int uniqueueString  = 1;
    for (int i = 1; i < wordsSize ; i++) {
        // 
        if (strcmp(transformedString[i-1] , transformedString[i]) != 0)
        {
            uniqueueString++;
        }
    }
    return uniqueueString;
} */

/* Using Custom Hash Table */


int main() {
    char* words[] = {"gin", "zen", "gig", "msg"};
    int wordsSize = sizeof(words) / sizeof(words[0]);

    int result = uniqueMorseRepresentations(words, wordsSize);
    printf("Unique Morse Representations: %d\n", result);

    return 0;
}
