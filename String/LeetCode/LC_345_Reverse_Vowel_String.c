#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Declare the function prototype
// My Ugly Logic
// @ Time Complexity  :
//  O(n)
// @ Space Complexity : 
// O(1)
/* bool isVowel(char c)
{
    if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) =='i' || tolower(c) == 'o' || tolower(c) == 'u')
    {
        printf("Character %c is vowel\n", c);
        return true;
    }else{
        return false;
    }
}
char* reverseVowels(char* s)
{
    char * L = s;
    char * R = (s + strlen(s) - 1);

    char * return_str = s;
    printf("Start = %c\n", L[0]);
    printf("End = %c\n", R[0]);
    while(L<R)
    {
        if ((isVowel(*L) == 1) && (isVowel(*R) == 1))
        {
            printf("replacing %c and %c\n", *L,*R);
            // reverse Vowels
            char temp = *R;
            *R = *L;
            *L= temp;

            // both are vowel
            L++;
            R--;

        }else if (!isVowel(*L))
        {
            L++;

        }else if (!isVowel(*R)){
            R--;
        }   
    }
    return return_str;
} */

// @Note : Online Approach
// @ Time Complexity :  Same but faster due to switch case
// @ Space Complexity : Same
bool isVowel(char c) {
    c = tolower(c);
    switch(c)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
    }
}

char* reverseVowels(char* s) {
    int length = strlen(s);
    int L = 0;
    int R = length - 1;

    while(L < R) {
        // Move L pointer until a vowel is found or L >= R
        while(L < R && !isVowel(s[L])) {
            L++;
        }
        
        // Move R pointer until a vowel is found or L >= R
        while(L < R && !isVowel(s[R])) {
            R--;
        }

        // Swap the vowels
        if(L < R) {
            char temp = s[L];
            s[L] = s[R];
            s[R] = temp;
            L++;
            R--;
        }
    }

    return s;
}


// Main Function
int main() {
    // Test cases
    char test1[] = "hello";
    printf("Test 1:\nInput: %s\nOutput: %s\nExpected Output: holle\n\n", test1, reverseVowels(test1));

    char test2[] = "leetcode";
    printf("Test 2:\nInput: %s\nOutput: %s\nExpected Output: leotcede\n\n", test2, reverseVowels(test2));

    // Add more tests as needed
    
    return 0;
}
