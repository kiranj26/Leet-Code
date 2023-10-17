#include <stdio.h>
#include <string.h>
#include <ctype.h>
// Function prototype
// Brute Force Method
// each string has n(n+1)/2 substrings
// each has n substring of 1 char
// each has n-1 of 2 character
// each has n-2 of three characters
// and finally one substring fo n characters
// we will traverse each of them and we will see which has the longest length where all the characters
// in that substring are unique

// @ Time Complexity : O(n^3)
// @ Space Complexity : O(n)
/* int uniqueString(char * s, int start, int end) {
    int frequency[256] = {0};

    for(int i = start; i <= end; i++) {
        int index = (unsigned char) s[i];  // Using ASCII value of character
        frequency[index]++;

        if(frequency[index] > 1) {
            return 0;  // Not unique
        }
    }
    return 1;  // Unique
}

int lengthOfLongestSubstring(char * s)
{
    int max_length = 0;
    int len = strlen(s);

    for(int i=0;i<len;i++)
    {
        for(int j=i;j<len;j++)
        {
            // now for string s[i] to s[j] should have unique characters
            int unique = uniqueString(s,i,j);
            // if unique
            if(unique)
            {
                // if unique e check if the current substring length is greater than max length
                if(max_length <= (j-i+1))
                {
                    // update max length
                    max_length = j-i+1;
                }else{
                    // no need to update max length
                }
            }
        }
    }
    return max_length;
} */
// ------------------------------------------------------------------------------------------
// @ Note : Using Sliding Window Problems 1
// @ trick is we have to dynamically adjust the window
//          - current windows expands : is all characters are unique move end to right
//          - current windows contracts : if all characters are not unique move start to right
// Another trick : 
//          - Dealing with the repeating characters
//                -> if characters repeats withing windows, then contracts till there 
//                   are no repeating characters (sliding past concept)
//
// @ Time Complexity : While loop moved O(2n) i.e start goes from 0 to n end goes from 0 to n
//                     uniqueString (On)
//             Total : O(n^2)
// @ Space Complexity : O(1)
/* 
int uniqueString(char * s, int start, int end) {
    int frequency[256] = {0};

    for(int i = start; i <= end; i++) {
        int index = (unsigned char) s[i];  // Using ASCII value of character
        frequency[index]++;

        if(frequency[index] > 1) {
            return 0;  // Not unique
        }
    }
    return 1;  // Unique
}

int lengthOfLongestSubstring(char * s){

    int len = strlen(s);
    int windows_size = 1;
    int start = 0;
    int end = windows_size-1;

    printf("Actual String: %s\n", s);
    printf("Windows Start: %c\n", s[start]);
    printf("Windows End: %c\n", s[end]);

    int max_length = 0;
    
    // Traverse till my end is not pointing to the last element of main string
    while(end < len)
    {
        int unique = uniqueString(s,start,end);
        if(unique)
        {
            // if uniqueue move window or broden window
            max_length = ((end - start + 1) > max_length) ? (end - start + 1): max_length;
            end ++;
        }
        else{
            // else shorten window
            start ++;
        }
        
    }

    return max_length;
} */

// Note : More Optamised Version
// @ Time Complexity : O(n)
int lengthOfLongestSubstring(char * s){
    int len = strlen(s);
    int start = 0, end = 0;
    int max_length = 0;

    // Using a hash map (or a set) to track characters in the current window.
    int frequency[256] = {0};

    while(end < len) {
        if(frequency[(unsigned char)s[end]] == 0) {
            // Character not in current window. Add to frequency and extend window.
            frequency[(unsigned char)s[end]]++;
            end++;
            max_length = (end - start) > max_length ? (end - start) : max_length;
        } else {
            // Character already in current window. Reduce window size.
            frequency[(unsigned char)s[start]]--;
            start++;
        }
    }

    return max_length;
}


int main() {
    // Test cases
    char *test1 = "abcabcbb";
    char *test2 = "bbbbb";
    char *test3 = "pwwkew";

    int result1 = lengthOfLongestSubstring(test1);
    int result2 = lengthOfLongestSubstring(test2);
    int result3 = lengthOfLongestSubstring(test3);

    printf("Input: %s, Expected: 3, Result: %d\n", test1, result1);
    printf("Input: %s, Expected: 1, Result: %d\n", test2, result2);
    printf("Input: %s, Expected: 3, Result: %d\n", test3, result3);
    return 0;
}
