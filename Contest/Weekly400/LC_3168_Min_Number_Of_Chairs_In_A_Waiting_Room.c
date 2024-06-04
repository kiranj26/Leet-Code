#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minChairsRequired(char* s);

int main() {
    char s1[] = "EEEEEEE";
    char s2[] = "ELELEEL";
    char s3[] = "ELEELEELLL";

    printf("Test Case 1: %s\n", s1);
    printf("Output: %d\n", minChairsRequired(s1));

    printf("Test Case 2: %s\n", s2);
    printf("Output: %d\n", minChairsRequired(s2));

    printf("Test Case 3: %s\n", s3);
    printf("Output: %d\n", minChairsRequired(s3));
    return 0;
}

/* My initial Approach
 * Function: minChairsRequired
 * ---------------------------
 * Computes the minimum number of chairs required in a waiting room
 * based on a string representing events of people entering ('E') and
 * leaving ('L') the room.
 *
 * Approach:
 * - Initialize two variables: max_chair and chair. max_chair keeps
 *   track of the maximum number of chairs needed at any time, while
 *   chair keeps track of the current number of occupied chairs.
 * - Iterate through each character in the string:
 *   - If the character is 'E', increment the chair count.
 *   - Update max_chair if the current chair count exceeds max_chair.
 *   - If the character is 'L', decrement the chair count.
 * - Return max_chair as the result.
 *
 * Time Complexity: O(n)
 * - We iterate through the string once, where n is the length of the string.
 *
 * Space Complexity: O(1)
 * - We use a constant amount of extra space regardless of the input size.
 */

int minChairsRequired(char* s) {
    int max_chair = 0;
    int chair = 0;

    for (int i = 0; i < strlen(s); i++) {
        if(s[i] == 'E') {
            chair++;
            if (max_chair < chair){
                max_chair = chair;
            }
        } else {
            chair--;
        }
    }
    return max_chair;
}

