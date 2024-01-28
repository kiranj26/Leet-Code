#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * getFrequency(const char * str, int * freq)
{
    for (int i = 0; i< strlen(str) ; i++)
    {
        freq[str[i]- 'a']++;
    }
}
// Function prototype
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    int ** freq = (int **)calloc(strsSize, sizeof(int *));
    // Array of storing frequencies of each string
    for (int i = 0; i< strsSize ; i++)
    {
        freq[i] = (int *)calloc(26, sizeof(int));
        getFrequency(strs[i], freq[i]);
    }

    /* // printing all the frequencies
    for (int i = 0; i< strsSize ; i++)
    {
        printf("Frequency %d : \n", i);
        for (int j = 0; j < 26; j++)
        {
            printf("%d  ", freq[i][j]);
        }
    } */
    int * used  = (int *) malloc(strsSize * sizeof(int));
    char *** result = (char ***) malloc(strsSize * sizeof(char ***));
    *returnColumnSizes = (char *)malloc(strsSize * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < strsSize; i++)
    {

    }



}

void printResult(char*** result, int returnSize, int* returnColumnSizes) {
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%s ", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Test cases
    char* test1[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    char* test2[] = {""};
    char* test3[] = {"a"};

    int testSizes[] = {6, 1, 1};
    char** tests[] = {test1, test2, test3};
    int numTests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < numTests; i++) {
        int returnSize;
        int* returnColumnSizes;

        // Call the function for each test
        char*** result = groupAnagrams(tests[i], testSizes[i], &returnSize, &returnColumnSizes);

        // Print the result
        printf("Test Case %d:\n", i + 1);
        printResult(result, returnSize, returnColumnSizes);
        printf("\n");

        // Free the allocated memory (assuming groupAnagrams allocates memory)
        for (int j = 0; j < returnSize; j++) {
            free(result[j]);
        }
        free(result);
        free(returnColumnSizes);
    }

    return 0;
}
