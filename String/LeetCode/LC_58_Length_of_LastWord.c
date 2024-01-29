#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Approach 1: Ugly Approach
 * 
 * This approach iterates through the string to find the index of the start of the last word.
 * Then, it counts the characters of the last word from this index.
 * 
 * Steps:
 *  - Iterate through the string.
 *  - If a space followed by an English letter is found, update the index of the last word.
 *  - After finding the index, count the length of the last word.
 * 
 * Time Complexity: O(n) - where n is the length of the string.
 * Space Complexity: O(1) - no additional space used.
 */
/* int isEnglish(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        return true;   
    }else{
        return false;
    }
}

int lengthOfLastWord(char *s) {
    int length = strlen(s);
    int indexofLastWord = 0;
    for (int i = 0; i < length - 1; i++)
    {
        if (s[i] == ' ' && isEnglish(s[i + 1]))
        {
            indexofLastWord = i + 1; 
        }
    }
    int wordSize = 0;
    for (int i = indexofLastWord; i < length; i++)
    {
        if (isEnglish(s[i]))
        {
            wordSize++;
        }
    }
    return wordSize;
} */

/**
 * Approach 2: Counting from Last
 * 
 * This approach starts from the end of the string and moves backwards.
 * It first skips the trailing spaces, then counts the length of the last word.
 * 
 * Steps:
 *  - Traverse the string in reverse until a non-space character is found.
 *  - Then, continue traversing and count the non-space characters until a space is encountered.
 * 
 * Time Complexity: O(n) - where n is the length of the string.
 * Space Complexity: O(1) - no additional space used.
 */
int lengthOfLastWord(char *s) {
    int length = strlen(s) - 1;
    int lastwordSize = 0;

    // Skip trailing spaces
    while (length >= 0 && s[length] == ' ') {
        length--;
    }

    // Count the length of the last word
    while (length >= 0 && s[length] != ' ') {
        length--;
        lastwordSize++;
    }
    return lastwordSize;
}

int main() {
    // Test cases
    char *s1 = "Hello World";
    printf("Test Case 1: %d\n", lengthOfLastWord(s1));

    char *s2 = "   fly me   to   the moon  ";
    printf("Test Case 2: %d\n", lengthOfLastWord(s2));

    char *s3 = "luffy is still joyboy";
    printf("Test Case 3: %d\n", lengthOfLastWord(s3));

    return 0;
}
