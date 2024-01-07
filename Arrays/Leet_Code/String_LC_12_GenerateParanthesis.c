#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ensureCapacity(char ***result, int *capacity, int returnSize) {
    if (returnSize >= *capacity) {
        *capacity *= 2;
        *result = realloc(*result, (*capacity) * sizeof(char *));
    }
}

void backtrack(char ***result, int *returnSize, char *current, int open, int close, int max, int pos, int *capacity) {
    if (pos == max * 2) {
        ensureCapacity(result, capacity, *returnSize);
        (*result)[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }

    if (open < max) {
        current[pos] = '(';
        backtrack(result, returnSize, current, open + 1, close, max, pos + 1, capacity);
    }

    if (close < open) {
        current[pos] = ')';
        backtrack(result, returnSize, current, open, close + 1, max, pos + 1, capacity);
    }
}

char **generateParenthesis(int n, int *returnSize) {
    *returnSize = 0;
    int capacity = 2048;  // Increase initial capacity
    char **result = malloc(capacity * sizeof(char *));
    char *current = malloc((2 * n + 1) * sizeof(char));
    current[2 * n] = '\0';

    backtrack(&result, returnSize, current, 0, 0, n, 0, &capacity);

    free(current);
    return result;
}

int main() {
    // Test cases
    int testCases[] = {1, 2, 3, 4, 5};
    int numberOfTestCases = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < numberOfTestCases; i++) {
        int returnSize;
        char **combinations = generateParenthesis(testCases[i], &returnSize);

        printf("All combinations of well-formed parentheses for n = %d are:\n", testCases[i]);
        for (int j = 0; j < returnSize; j++) {
            printf("%s\n", combinations[j]);
            free(combinations[j]); // Free each combination
        }
        free(combinations); // Free the array of combinations
        printf("\n"); // Print a new line for readability
    }

    return 0;
}
