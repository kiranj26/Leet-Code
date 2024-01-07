#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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