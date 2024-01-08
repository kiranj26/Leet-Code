#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Function to find the maximum number of instances of the word "balloon" that can be formed
 * from the characters of the given string.
 *
 * Approach:
 * 1. Create a frequency array to count occurrences of each letter in the input string.
 * 2. Iterate through the input string and update the frequency array.
 * 3. Extract the frequency of specific letters needed to form "balloon" (b, a, l, o, n).
 *    - Note: Since "balloon" requires two 'l's and two 'o's, their counts are effectively halved.
 * 4. Find the minimum count among these frequencies, which will be the maximum number of times
 *    "balloon" can be formed.
 *
 * Time Complexity:
 * - O(n) for iterating through the input string, where n is the length of the string.
 * - O(1) for processing the frequency array and finding the minimum count (constant time operations).
 * Overall Time Complexity: O(n).
 *
 * Space Complexity:
 * - O(1) for the frequency array (constant space as the size of the array is fixed and does not depend on input size).
 */
int min (int a , int b)
{
    return (a < b) ? a : b;
}

int maxNumberOfBalloons(char* text) {
    int freq[26] = {false};
    // lets load frequency;

    for (int i = 0 ;i <strlen(text) ; i++)
    {
        int index = text[i] - 'a';
        freq[index]++;
    }
    for(int i = 0;i <26 ;i++)
    {
        printf("%d ", freq[i]);

    }
    printf("\n");

    int b = freq['b' - 'a'];
    int a = freq['a' - 'a'];
    int l = freq['l' - 'a'];
    int o = freq['o' - 'a'];
    int n = freq['n' - 'a'];

    printf("%d %d %d %d %d \n", b, a, l, o, n);

    int min_b_a = min(a,b);
    int min_l_o = min (l,o);
    int min_count = min((min_b_a),(min(min_l_o, n)));


    return min_count;
}

int main() {
    char text1[] = "nlaebolko";
    printf("Maximum number of 'balloon' from \"%s\": %d\n", text1, maxNumberOfBalloons(text1));

    char text2[] = "loonbalxballpoon";
    printf("Maximum number of 'balloon' from \"%s\": %d\n", text2, maxNumberOfBalloons(text2));

    char text3[] = "leetcode";
    printf("Maximum number of 'balloon' from \"%s\": %d\n", text3, maxNumberOfBalloons(text3));

    return 0;
}
