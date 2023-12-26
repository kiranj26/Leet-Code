#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: Brute Force or Ugly Approach
 * Time Complexity: O(n * m) n being wordSize and m being max no of element in any string
 * Space Complexity: O(n) only one array of size fo wordSize
 */
/* int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {

    // allocate an array of integer of length 1

    int * result = (int *)malloc(sizeof(int)* wordsSize);
    int index = 0;
    *returnSize = 0;
    if(result == NULL) {return NULL;}
    for (int i=0;i<wordsSize;i++)
    {
        int substring_len  = strlen(words[i]);
        // printf("Size of %dth String: %d\n", i, substring_len);
        // Check if char is matched
        int already_found = 0;
        for(int j=0;j<substring_len;j++)
        {
            
            if(words[i][j] == x)
            {
               // save and reallocate length 
               if (already_found == 0)
               {
                result[index++]= i;
                printf("Matched! in %dth String at Index %d\n",i,j);
                already_found = 1;
                (*returnSize)++;
               }

            }
        }    
    }
    return result;

} */

/**
 * Note: Optimized Approach
 * Optimisation : 
 *  - TC : We are checking character x with eah and every character in substring. We can break as soon as we see the first match
 *  - TC : instead of manually checking character we can use strchr
 *  - SC : We can realloc the sze of final result array based on matched or not matched with x
 * Time Complexity: 
 * Space Complexity: 
 */
int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
    // allocate an array of integer of length 1

    int * result = (int *)malloc(sizeof(int));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = 0;

    for (int i=0;i<wordsSize;i++)
    {
        // Using strchr
        if (strchr(words[i], x) != NULL)
        {

            int * temp = realloc(result, ((*returnSize)+1) * sizeof(int)); // Space Optimisation
            if (temp == NULL) {
                free(result);
                *returnSize = 0;
                return NULL;
            }
            result = temp;
            result[(*returnSize)++] = i; 
        }
    }
    return result;

}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    // Test case 1
    char* words1[] = {"leet", "code"};
    int wordsSize1 = 2;
    char x1 = 'e';
    int returnSize1;
    int* result1 = findWordsContaining(words1, wordsSize1, x1, &returnSize1);
    printf("Returned Size = %d\n", returnSize1);
    printArray(result1, returnSize1);
    //free(result1);

    // Test case 2
    char* words2[] = {"abc", "bcd", "aaaa", "cbc"};
    int wordsSize2 = 4;
    char x2 = 'a';
    int returnSize2;
    int* result2 = findWordsContaining(words2, wordsSize2, x2, &returnSize2);
    printArray(result2, returnSize2);
    //free(result2);

    // Test case 3
    char* words3[] = {"abc", "bcd", "aaaa", "cbc"};
    int wordsSize3 = 4;
    char x3 = 'z';
    int returnSize3;
    int* result3 = findWordsContaining(words3, wordsSize3, x3, &returnSize3);
    printArray(result3, returnSize3);
    //free(result3);

    return 0;
}
