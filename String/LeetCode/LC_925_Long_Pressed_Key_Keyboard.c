#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
 * Function: isLongPressedName
 * ----------------------------
 * Checks if the string typed is a result of the string name being typed,
 * possibly with some characters being long-pressed.
 *
 * This function iterates over the typed string and compares it against the name string.
 * For each character in name, it must appear in typed. Characters in typed may be repeated
 * due to long pressing. This function validates that the sequence in typed could come from
 * correctly typing (and possibly long-pressing) the characters in name.
 *
 * Parameters:
 * name - the original name string to be typed.
 * typed - the resulting string after typing, including possible long presses.
 *
 * Returns:
 * true if typed is a valid result of typing name with long presses;
 * false otherwise.
 *
 * Time Complexity: O(m), where m is the length of the typed string.
 * Each character in typed is visited exactly once, making the iteration linear with respect to its length.
 *
 * Space Complexity: O(1).
 * The space used does not depend on the input size. Only a fixed number of integer variables are used,
 * which means the space complexity is constant.
 */
bool isLongPressedName(char* name, char* typed) {
    int n = strlen(name), m = strlen(typed);
    int i = 0, j = 0;
    
    while (j < m) {
        if (i < n && name[i] == typed[j]) {
            i++; j++;
        } else if (j > 0 && typed[j] == typed[j-1]) {
            j++;
        } else {
            return false;
        }
    }
    return i == n;
}

int main() {
    // Example 1
    char* name1 = "alex";
    char* typed1 = "aaleex";
    printf("Test 1: %s\n", isLongPressedName(name1, typed1) ? "true" : "false");

    // Example 2
    char* name2 = "saeed";
    char* typed2 = "ssaaedd";
    printf("Test 2: %s\n", isLongPressedName(name2, typed2) ? "true" : "false");

    return 0;
}
