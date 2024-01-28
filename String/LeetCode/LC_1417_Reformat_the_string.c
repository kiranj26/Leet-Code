#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/**
 * Reformat the given string so that no two adjacent characters are of the same type.
 * 
 * Approach:
 * - Count the number of letters and digits in the string.
 * - If the difference between the number of letters and digits is more than 1, reformatting is impossible.
 * - Create two separate arrays to store letters and digits.
 * - Construct the result string by alternating between letters and digits, starting with the type that has greater count.
 * - If the counts are equal, start with a letter.
 * 
 * Time Complexity: O(n), where n is the length of the string.
 *    - O(n) for counting letters and digits.
 *    - O(n) for separating letters and digits.
 *    - O(n) for constructing the result string.
 * 
 * Space Complexity: O(n), where n is the length of the string.
 *    - O(n) for the arrays storing letters and digits.
 *    - O(n) for the result string.
 */

// Function to reformat the string
char* reformat(char* s) {
    int cntLetters = 0, cntDigits = 0;
    int strSize = strlen(s);

    // Temporary arrays to store letters and digits separately
    char *Letters = (char *)malloc((strSize + 1) * sizeof(char));
    char *Digits = (char *)malloc((strSize + 1) * sizeof(char));
    int letterIndex = 0, digitIndex = 0;

    // Separating letters and digits
    for (int i = 0; i < strSize; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            cntLetters++;
            Letters[letterIndex++] = s[i];
        } else if (s[i] >= '0' && s[i] <= '9') {
            cntDigits++;
            Digits[digitIndex++] = s[i];
        }
    }
    Letters[letterIndex] = '\0';
    Digits[digitIndex] = '\0';

    // Check if reformatting is possible
    if (abs(cntLetters - cntDigits) > 1) {
        free(Letters);
        free(Digits);
        char* empty = malloc(1 * sizeof(char));
        empty[0] = '\0';
        return empty;
    }

    // Allocate memory for the result
    char *result = malloc((strSize + 1) * sizeof(char));
    letterIndex = 0, digitIndex = 0;

    // Construct the result string
    for (int i = 0; i < strSize; i++) {
        if ((i % 2 == 0 && cntLetters >= cntDigits) || (i % 2 != 0 && cntLetters < cntDigits)) {
            result[i] = Letters[letterIndex++];
        } else {
            result[i] = Digits[digitIndex++];
        }
    }

    result[strSize] = '\0';
    free(Letters);
    free(Digits);
    return result;
}


void testReformat(char* s) {
    char* reformattedString = reformat(s);
    
    if (reformattedString[0] != '\0') {
        printf("Original String: %s, Reformatted String: %s\n", s, reformattedString);
    } else {
        printf("Original String: %s, Impossible to reformat\n", s);
    }

    free(reformattedString);
}

int main() {
    testReformat("a0b1c2");
    testReformat("leetcode");
    testReformat("1229857369");
    testReformat("ab123");
    testReformat("abc12");

    return 0;
}
