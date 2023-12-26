#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// @ Note : brute Force Approach
// @ Time Complexity : O(n^3)
// @ Space Complexity : O(1)
/* int isPalindrome(char * str, int left, int right)
{
    while(left < right)
    {
        if (str[left] == str[right])
        {
            left++;
            right--;
        }else{

            return 0;
        }
    }
    return 1;
}
char* longestPalindrome(char* s){
    int longest_palindrome = 0;
    int len =  strlen(s);

    int start=0;
    int end =0;
    for(int i=0;i<len;i++)
    {
        for(int j=i;j<len;j++)
        {
            int palindrome = isPalindrome(s,i,j);
            if (palindrome && ((j-i) > (end - start)))
            {
                // store the index and compare with the 
                // previously store
                start = i;
                end = j;
            }
        }
    }
    char * str =  (char *) malloc(sizeof(char) * (end - start + 2));
    strncpy(str,s+start, end-start + 1);
    str[end-start+1] = '\0';

    return str;
} */


// Expand Around Centre technique is the most effective technique
// Refer neet code logic
char* expandAroundCenter(char* s, int left, int right) {
    int len = strlen(s);
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    // Return a substring from 'left + 1' to 'right - 1' because we have decremented left and incremented right one step extra in the while loop
    char* str = (char *) malloc(sizeof(char) * (right - left));
    strncpy(str, s + left + 1, right - left - 1);
    str[right - left - 1] = '\0';
    return str;
}

char* longestPalindrome(char* s){
    //edge cases
    if (!s) {
        return NULL;
    }

    int len = strlen(s);
    if (len <2)
    {
        return s;
    }

    char * longest_palindrome  = "";
    int longest_palindrome_Len = 0;
    // traverse each characters for 
    for (int i = 0 ; i< len ; i++)
    {
        // for odd palindrome
        int left = i;
        int right = i;

        char * current_palindrome_odd = expandAroundCenter(s,left,right);
        int current_palindrome_odd_length = strlen(current_palindrome_odd);
        if (current_palindrome_odd_length > longest_palindrome_Len)
        {
            longest_palindrome_Len = current_palindrome_odd_length;
            longest_palindrome = current_palindrome_odd;
        }

        // even length
        left = i;
        right = i+1;
        char * current_palindrome_even = expandAroundCenter(s,left,right);
        int current_palindrome_even_length = strlen(current_palindrome_even);
        if (current_palindrome_even_length > longest_palindrome_Len)
        {
            longest_palindrome_Len = current_palindrome_even_length;
            longest_palindrome = current_palindrome_even;
        }
    }
    return longest_palindrome;
}

int main() {
    char test1[] = "babad";
    char test2[] = "cbbd";
    char test3[] = "a";
    char test4[] = "ac";

    char* result1 = longestPalindrome(test1);
    char* result2 = longestPalindrome(test2);
    char* result3 = longestPalindrome(test3);
    char* result4 = longestPalindrome(test4);

    printf("Longest Palindrome of %s: %s\n", test1, result1);
    printf("Longest Palindrome of %s: %s\n", test2, result2);
    printf("Longest Palindrome of %s: %s\n", test3, result3);
    printf("Longest Palindrome of %s: %s\n", test4, result4);

    // Remember to free the memory after using the result
    free(result1);
    free(result2);
    free(result3);
    free(result4);

    return 0;
}
