#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1. Mapping Setup:
   - Define a mapping from digits to corresponding letters, similar to a phone keypad.

2. Handling Edge Cases:
   - Check if the input `digits` string is empty or null. If so, return no combinations (NULL) and set `returnSize` to 0.

3. Calculating Total Combinations:
   - Determine the length of the input digits.
   - Iterate over each digit to calculate the total number of combinations by multiplying the lengths of the letter strings corresponding to each digit.

4. Memory Allocation for Result:
   - Allocate memory for an array of strings (`char**`) to hold all possible combinations, sized by the total number of combinations.
   - For each combination, allocate memory for a string to store the combination, sized by the length of the input digits plus one for the null terminator.

5. Generating Combinations:
   - Use nested loops to generate each combination.
   - For each combination (`i`):
     - Calculate the combination index (initially set to `i`).
     - For each character position (`j`) in the combination:
       - Determine the current digit from `digits`.
       - Find the corresponding letter string in the mapping array.
       - Calculate the correct letter for this position using modulo (`%`) and division operations, based on the combination index and the length of the letter string.
     - Update the combination index for the next digit.

6. Setting Return Size:
   - Set `*returnSize` to the total number of combinations.

7. Memory Cleanup Function:
   - Implement `freeLetterCombinations` to free the allocated memory for each combination and for the array of combinations.

8. Testing in Main Function:
   - The `main` function contains test cases demonstrating the use of `letterCombinations`.
   - It prints each combination and then frees the allocated memory.
*/
char* mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

char** letterCombinations(char* digits, int* returnSize) {
    if (digits == NULL || strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }

    int len = strlen(digits);
    int totalCombinations = 1;
    for (int i = 0; i < len; i++) {
        totalCombinations *= strlen(mapping[digits[i] - '0']);
    }

    char** result = (char**)malloc(totalCombinations * sizeof(char*));
    for (int i = 0; i < totalCombinations; i++) {
        result[i] = (char*)malloc((len + 1) * sizeof(char));
        result[i][len] = '\0';
    }

    int combinationIndex = 0;
    for (int i = 0; i < totalCombinations; i++) {
        combinationIndex = i;
        for (int j = 0; j < len; j++) {
            int digit = digits[j] - '0';
            int lettersLen = strlen(mapping[digit]);
            result[i][j] = mapping[digit][combinationIndex % lettersLen];
            combinationIndex /= lettersLen;
        }
    }

    *returnSize = totalCombinations;
    return result;
}

void freeLetterCombinations(char** combinations, int size) {
    for (int i = 0; i < size; i++) {
        free(combinations[i]);
    }
    free(combinations);
}

int main() {
    // Test cases
    char* testDigits1 = "23";
    int returnSize1;
    char** combinations1 = letterCombinations(testDigits1, &returnSize1);
    printf("Combinations for '%s':\n", testDigits1);
    for (int i = 0; i < returnSize1; i++) {
        printf("%s\n", combinations1[i]);
    }
    freeLetterCombinations(combinations1, returnSize1);

    char* testDigits2 = "";
    int returnSize2;
    char** combinations2 = letterCombinations(testDigits2, &returnSize2);
    printf("Combinations for '%s':\n", testDigits2);
    if (combinations2) {
        for (int i = 0; i < returnSize2; i++) {
            printf("%s\n", combinations2[i]);
        }
        freeLetterCombinations(combinations2, returnSize2);
    }

    char* testDigits3 = "2";
    int returnSize3;
    char** combinations3 = letterCombinations(testDigits3, &returnSize3);
    printf("Combinations for '%s':\n", testDigits3);
    for (int i = 0; i < returnSize3; i++) {
        printf("%s\n", combinations3[i]);
    }
    freeLetterCombinations(combinations3, returnSize3);

    return 0;
}