#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype
/* My first approach */
/* char* removeDigit(char* number, char digit)
{
    int len = strlen(number);
    char * largest  = (char*)malloc(sizeof(char) * len + 1);
    strcpy(largest, "0"); // initialising largest number with 0
    for (int  i = 0; i< len; i++)
    {
        if (number[i] == digit)
        {
            char * tempNumber = (char*)malloc(sizeof(char) * len);
            strncpy(tempNumber, number, i);
            tempNumber[i] = '\0';
            strcat(tempNumber, number + i + 1);

            // check with largest number
            if (strcmp(tempNumber, largest) > 0)
            {
                strcpy(largest, tempNumber);
            }
            free(tempNumber);
        }
    }
    return largest;
} */

char* removeDigit(char* number, char digit)
{
    
}

int main() {
    // Example usage of removeDigit function
    char number[] = "123";
    char digit = '3';
    char* result = removeDigit(number, digit);
    printf("Resulting number: %s\n", result);
    free(result); // Remember to free the allocated memory
    return 0;
}