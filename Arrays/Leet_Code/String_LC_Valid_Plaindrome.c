#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isAlphanumeric(char ch)
{
    if ((ch >= 'a' && ch <= 'z') ||
        (ch >= '0' && ch <= '9') )
    {
        return true;
    }
    return false;
}

bool isPalindrome(char *s) {
    if (strlen(s) == 1)
    {
        return true;
    }
    char * start  = s;
    int i = 0;
    char * validString = (char *)malloc(sizeof(char) * strlen(s));
    char * startvalidString  = validString; 
    while(*s != '\0')
    {
        if (isAlphanumeric(tolower(*s)))
        {
            // if the current character is alphanumeric
            // load into new string
            validString[i] = tolower(*s);
            i++;
        }
        s++;
    }
    validString[i] = '\0';
    printf("Valid String: %s\n", startvalidString);

    int l = 0;
    int r = strlen(startvalidString) - 1;

    while(l < r)
    {
        if (startvalidString[l] == startvalidString[r])
        {
            // continue
        }else
        {
            //
            printf("returnnig false bacuse element %c and %c is different at l =%d and r = %d\n", startvalidString[l], startvalidString[r], l ,r);
            return false;
        }
        l++;
        r--;
        // startvalidString++;
    }
    return true;

}

int main() {
    char test1[] = "A man, a plan, a canal: Panama";
    char test2[] = "race a car";
    char test3[] = " ";

    printf("Test 1: %s\n", isPalindrome(test1) ? "true" : "false"); // Should print true
    printf("Test 2: %s\n", isPalindrome(test2) ? "true" : "false"); // Should print false
    printf("Test 3: %s\n", isPalindrome(test3) ? "true" : "false"); // Should print true

    return 0;
}
