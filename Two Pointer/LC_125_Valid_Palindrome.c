#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// @ Note : Online 1 (Using Pointer Arithmatics)
// @Time Complexity: O(n)
// @Space Complexity: O(1)
//    Pointers like L and R, and local variables used in the function, 
//    occupy constant space irrespective of the input string's 
//    length. Thus, their space complexity is O(1). 
bool isAlphanumeric(char ch)
{
    if (((ch>='0')&&(ch<='9')) || 
    ((ch>='a')&&(ch<='z')) || 
    ((ch>='A')&&(ch<='Z')) )
    {
        return true;
    }else{
        return false;
    }
}
bool isPalindrome(char *s) {
    char * L = &s[0];
    char * R = &s[strlen(s)-1];
    // while address of L is less than address of R
    while(L <= R)
    {
        // chek =ck for alphanumeric
        if (!isAlphanumeric(*L))
        {
            L++;
            continue;
        }
        if(!isAlphanumeric(*R))
        {
            R--;
            continue;
        }

        if( tolower(*L) == tolower(*R) ){
            // do nothing
        }else{
            return false;
        }
        L++;
        R--;
    }

    return true;
}
/* // @ Note : Chat GPT (Most Optamised)
// Use isalnum and tolower from ctype.h
bool isPalindrome(char *s) {
    char *L = s;
    char *R = &s[strlen(s) - 1];

    while (L <= R) {
        // Move L and R pointers to next alphanumeric characters
        while (L < R && !isalnum(*L)) {
            L++;
        }
        while (L < R && !isalnum(*R)) {
            R--;
        }

        // Compare the lowercase versions of the characters
        if (tolower(*L) != tolower(*R)) {
            return false;
        }

        L++;
        R--;
    }

    return true;
} */

int main() {
    char test1[] = "A man, a plan, a canal: Panama";
    char test2[] = "race a car";
    char test3[] = " ";

    printf("Test 1: %s\n", isPalindrome(test1) ? "true" : "false"); // Should print true
    printf("Test 2: %s\n", isPalindrome(test2) ? "true" : "false"); // Should print false
    printf("Test 3: %s\n", isPalindrome(test3) ? "true" : "false"); // Should print true

    return 0;
}
