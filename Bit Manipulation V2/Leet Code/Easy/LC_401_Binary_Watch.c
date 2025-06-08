#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * =========================================================================
 * LeetCode Problem: Binary Watch (401)
 * =========================================================================
 * 
 * Problem:
 * A binary watch has 4 LEDs for hours (0-11) and 6 LEDs for minutes (0-59).
 * Each LED represents a bit (0 or 1). You are given an integer "turnedOn"
 * representing how many LEDs are currently on. Return all possible valid times.
 * 
 * Example 1:
 * Input: turnedOn = 1
 * Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
 * 
 * =========================================================================
 * COMPLETE LEARNING OBJECTIVES (for future detailed revision):
 * 
 * 1️⃣ Key Bit Manipulation Insight:
 *     - Each valid time is simply a combination of bits being set for hours & minutes.
 *     - For each possible hour (0-11) and minute (0-59), count set bits.
 *     - If total set bits == turnedOn, store the formatted time.
 * 
 * 2️⃣ Counting Set Bits (Hamming Weight):
 *     - Use Brian Kernighan's algorithm to efficiently count number of 1's.
 *     - `v = v & (v-1)` removes the rightmost set bit in each iteration.
 * 
 * 3️⃣ Optimization:
 *     - Maximum total combinations: 12 (hours) * 60 (minutes) = 720.
 *     - Preallocate memory for maximum possibilities to simplify storage.
 * 
 * 4️⃣ String Formatting in C:
 *     - Use sprintf to format "h:mm" where minutes always have leading zeros.
 *     - Allocate 6 characters per string: max format is "10:59" + null terminator.
 */

/**
 * -------------------------------------------------------------------------
 * Helper function to count set bits using Brian Kernighan's algorithm
 * -------------------------------------------------------------------------
 */
unsigned int count_set_bits(unsigned int v) {
    unsigned int count = 0;
    while (v) {
        v = v & (v - 1);
        count++;
    }
    return count;
}

/**
 * -------------------------------------------------------------------------
 * Core Bit Manipulation Solution
 * -------------------------------------------------------------------------
 * 
 * Time Complexity: O(12 * 60) -> O(1)
 * Space Complexity: O(720)
 *
 * Approach:
 * - Iterate through all valid hours and minutes.
 * - For each (hour, minute), count total bits lit.
 * - If total bits == turnedOn, store as valid time string.
 */
char** readBinaryWatch(int turnedOn, int* returnSize) {
    char** result = (char**)malloc(sizeof(char*) * 720);
    *returnSize = 0;

    for (int hours = 0; hours < 12; hours++) {
        for (int min = 0; min < 60; min++) {
            if ((count_set_bits(hours) + count_set_bits(min)) == turnedOn) {
                char* timeStr = (char*)malloc(6);
                sprintf(timeStr, "%d:%02d", hours, min);
                result[*returnSize] = timeStr;
                (*returnSize)++;
            }
        }
    }
    return result;
}

/**
 * -------------------------------------------------------------------------
 * Test Driver Code
 * -------------------------------------------------------------------------
 */
int main() {
    int turnedOn = 1;
    int returnSize;
    char** result = readBinaryWatch(turnedOn, &returnSize);

    printf("Possible times for turnedOn = %d:\n", turnedOn);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);

    // Additional test case
    turnedOn = 2;
    result = readBinaryWatch(turnedOn, &returnSize);

    printf("\nPossible times for turnedOn = %d:\n", turnedOn);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);

    return 0;
}
