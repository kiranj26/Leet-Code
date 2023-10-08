// Includes
#include <stdio.h>
#include <stdlib.h>

// Function Declarations
char ** cellsInRange(char * s, int* returnSize);

// The main function
int main(){
    // You can test your cellsInRange function here

    // Sample input
    char *s = "K1:L2";
    int returnSize = 0;

    // Calling cellsInRange
    char **result = cellsInRange(s, &returnSize);

    // Printing the result (for testing purposes)
    for (int i = 0; i < returnSize; i++) {
        printf("%s ", result[i]);
        free(result[i]); // Free each string in the result array
    }
    
    // Free the result array itself
    free(result);
    
    return 0;
}

// Additional helper functions can be added here, if needed.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** cellsInRange(char * s, int* returnSize){
    // lets spit given string into required variable
    char row1;
    char row2;
    char col1;
    char col2;

    col1 = s[0];
    row1 = s[1];
    col2 = s[3];
    row2 = s[4];
    printf("%c %c %c %c \n", col1, row1, col2, row2);

    printf("%d %d %d %d \n", col1, row1, col2, row2);
    // convert the colom to integers using base 26 format A=1 Z = 26 and AA is 27

    int r1,c1;
    int r2,c2;

    r1 = (row1) - 48;
    r2 = (row2) - 48;

    c1 = (col1) - 64;
    c2 = (col2) - 64;
    
    printf("%d %d %d %d \n", c1, r1, c2, r2);

    int r = (r1>r2)?r1:r2;
    int c = (c1>>c2)?c2:c1;
    
    printf("%d %d \n",r, c);
    *returnSize = (r2-r1+1) * (c2-c1+1);
    char ** returnArray = (char **) malloc((*returnSize)* sizeof(char*));

    int idx = 0;
    for(int i=c1;i<=c2;i++)
    {
        for(int j=r1;j<=r2;j++)
        {
            returnArray[idx] = (char *)malloc(sizeof(char)*4);
            printf("%c %d\n",i + 64, j);
            sprintf(returnArray[idx], "%c%d", i +64, j);
            idx++;

        }
    }
    return returnArray;
}

//MODIFIED __VERSION__
char ** cellsInRange(char * s, int* returnSize){
    char row1, row2, col1, col2;

    col1 = s[0];
    row1 = s[1];
    col2 = s[3];
    row2 = s[4];

    int r1 = row1 - '0'; // Convert char to int
    int r2 = row2 - '0';
    int c1 = col1 - 'A' + 1; // Convert char to column number
    int c2 = col2 - 'A' + 1;

    *returnSize = (c2 - c1 + 1) * (r2 - r1 + 1); // Calculate total number of cells
    char **result = (char **)malloc((*returnSize) * sizeof(char *)); // Allocate memory for the result

    int idx = 0;
    for(int i = c1; i <= c2; i++) {
        for(int j = r1; j <= r2; j++) {
            result[idx] = (char *)malloc(4 * sizeof(char)); // Allocate memory for each cell string
            sprintf(result[idx], "%c%d", i + 'A' - 1, j); // Convert int and char to desired format and store
            idx++;
        }
    }
    
    return result;
}
// Time Complexity: O(n * m), where n is the number of rows (r2 - r1 + 1) and m is the number of columns (c2 - c1 + 1).
// Space Complexity: O(n * m), for the same reasons as above


// Least time taking 0 ms
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** cellsInRange(char * s, int* returnSize){
    *returnSize = (1 + s[3] - s[0]) * (1 + s[4] - s[1]);
    char** result_list = calloc(*returnSize, sizeof(char*));
    int result_idx = 0;
    for (int a = 0; a < 1 + s[3] - s[0]; a++) {
        for (int n = 0; n < 1 + s[4] - s[1]; n++) {
            result_list[result_idx] = calloc(3, sizeof(char));
            result_list[result_idx][0] = s[0] + a;
            result_list[result_idx][1] = s[1] + n;
            result_list[result_idx][2] = '\0';
            result_idx++;
        }
    }
    return result_list;
}
// Least memory taking 6.5 MB
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** cellsInRange(char * s, int* returnSize){
    *returnSize = 0;
    int c0 = s[0] - 'A', c1 = s[3] - 'A';
    int r0 = s[1] - '1', r1 = s[4] - '1';
    char** ans = malloc((c1 - c0 + 1) * (r1 - r0 + 1) * sizeof(char*));
    for(int i = c0; i <= c1; i++){
        for(int j = r0; j <= r1; j++){
            ans[*returnSize] = calloc(3, sizeof(char));
            ans[*returnSize][0] = i + 'A';
            ans[*returnSize][1] = j + '1';
            (*returnSize)++;
        }
    }
    return ans;
}