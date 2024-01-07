#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Calculates the minimum number of operations to convert a binary string into an alternating binary string.
 *
 * Approach:
 * - The function iterates over each character in the string 's'.
 * - It counts the number of changes needed to make the string follow two patterns: "010101..." and "101010...".
 * - 'count0' is used to track the number of changes needed for the "010101..." pattern.
 *   - For even indices (0, 2, 4, ...), the expected character is '0'.
 *   - For odd indices (1, 3, 5, ...), the expected character is '1'.
 * - 'count1' is used to track the number of changes needed for the "101010..." pattern.
 *   - For even indices, the expected character is '1'.
 *   - For odd indices, the expected character is '0'.
 * - The function returns the minimum of 'count0' and 'count1', indicating the least number of changes needed.
 *
 * Time Complexity: O(n), where n is the length of the string 's'.
 * - The function performs a single pass over the string.
 *
 * Space Complexity: O(1)
 * - The space used is constant, only needing variables to count changes.
 *
 * @param s The input binary string.
 * @return The minimum number of changes to make 's' alternating.
 */

int minOperations(char* s) {
    int len  = strlen(s);
    int count0 = 0;
    int count1 = 0;

    for(int i = 0;i < len ; i++)
    {
        // for 01010101 format
        //  for odd index
        if (i % 2 != 0 && s[i] == '1')
        {
            count0++;
        }// for even index
        else if (i % 2 == 0 && s[i] == '0')
        {
            count0++;
        }

        // for 10101010 format
        if (i%2 != 0 && s[i] == '0')
        {
            count1++;
        }
        else if (i%2 == 0 && s[i] == '1')
        {
            count1++;
        }
    }

    return count0 < count1? count0: count1;
}



int main() {
    // Test cases
    char* testStrings[] = {"0100", "10", "1111"};
    int numberOfTests = sizeof(testStrings) / sizeof(testStrings[0]);

    for (int i = 0; i < numberOfTests; i++) {
        int result = minOperations(testStrings[i]);
        printf("Minimum operations to make '%s' alternating: %d\n", testStrings[i], result);
    }

    return 0;
}
