#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// My First Try...
// Very Ugly Approach
/* char* maxValue(char* n, int x) {

    int len = strlen(n);
    char num = x + '0';
    char * result = (char *)malloc(sizeof(char) * (len + 2));
    if (result == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    if (n[0] == '-')
    {
        int j = 0; 
        int i = 0;
        int flag = 0;
        result[0] = n[0];
        for(i = 1, j = 1; i<len; i++,j++)
        {
            if (n[i] > num)
            {
                flag = 1;
                // add before this index
                result[j] = num;
                j = j + 1;
                result[j] = n[i];
                break;

            }else{
                // load straight into the buffer
                result[j] = n[i];
            }
        }
        if (flag == 0)
        {
            printf("Adding at the last place %d \n",i);
            result[j] = num;
            j= j+1;
        }
        result[j] = '\0';
    }else
    {
        // Positive Number
        int Positive_number = atoi(n);
        printf("Positive Number = %d\n", Positive_number);
        int i = 0;
        int j = 0;
        int flag = 0;
        for(i = 0, j = 0; i<len; i++,j++)
        {
            if (n[i] < num)
            {
                printf("Time to add at placed %d\n", i);
                flag = 1;
                // add before this index
                result[j] = num;
                j = j+1;
                result[j] = n[i];
                break;
            }else{
                // load straight into the buffer
                result[j] = n[i];
            }
        }
        if (flag == 0)
        {
            printf("Adding at the last place %d \n",i);
            result[j] = num;
            j= j+1;
        }
        result[j] = '\0';
    }
    printf("Final result = %s\n", result);
    return result;
} */


/*
 * Concept:
 * - The function iterates over the string 'n' to find the optimal position for the digit 'x'.
 * - For positive numbers, 'x' is inserted before the first digit that is less than 'x'.
 * - For negative numbers, 'x' is inserted before the first digit that is greater than 'x'.
 * - The string manipulation is done considering 'n' as an array of characters.
 *
 * Time Complexity: O(n), where n is the length of the string 'n'.
 * - The function performs a single pass over the string to find the insertion point.
 * - Copying operations (`memcpy` and `strcpy`) also take O(n) time.
 *
 * Space Complexity: O(n)
 * - Additional space is allocated for the result string, which is one character longer than the input string.
*/
char* maxValue(char* n, int x) {
    unsigned int len = strlen(n);
    char * result = (char *)malloc(sizeof(char) * (len+2));

    int i = 0;

    if (n[0] == '-')
    {
        // Take i to the point where we know we have to add a element
        for(i =1;  ( i<len ) && ( (n[i] - '0') <= x );i++);
    }else{
        for(i =0;  ( i<len ) && ( (n[i] - '0') >= x );i++);
    }
    // now we know that we have came to the point where we have to add a new element 
    memcpy(result, n ,i); // i ke pehle ka pura data into result
    result[i] = x + '0';
    strcpy(result + i + 1, n+i) ; // copy string from n+i i ke baad ka into result ke bad ke data me
    result[len+1] = '\0';

    return result;
}

int main() {
    // Test cases
    char* testNumbers[] = {"99", "-13", "28824579515", "-132"};
    int testDigits[] = {9, 2, 3, 3};
    int numberOfTests = sizeof(testNumbers) / sizeof(testNumbers[0]);

    for (int i = 0; i < numberOfTests; i++) {
        char* result = maxValue(testNumbers[i], testDigits[i]);
        printf("n = %s, x = %d -> %s\n", testNumbers[i], testDigits[i], result);
        free(result);
    }

    return 0;
}
