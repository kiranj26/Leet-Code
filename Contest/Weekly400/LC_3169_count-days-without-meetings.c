#include <stdio.h>
#include <stdlib.h>

// Function prototype
int countDaysWithoutMeetings(int days, int** meetings, int meetingsSize, int* meetingsColSize);

int main() {
    // Example 1
    int days1 = 10;
    int meetings1[3][2] = {{5, 7}, {1, 3}, {9, 10}};
    int* meetings1Ptrs[3];
    for (int i = 0; i < 3; i++) {
        meetings1Ptrs[i] = meetings1[i];
    }
    int meetings1ColSize[3] = {2, 2, 2};

    printf("Test Case 1: days = %d, meetings = [[5, 7], [1, 3], [9, 10]]\n", days1);
    printf("Output: %d\n", countDaysWithoutMeetings(days1, meetings1Ptrs, 3, meetings1ColSize));

    // Example 2
    int days2 = 5;
    int meetings2[2][2] = {{2, 4}, {1, 3}};
    int* meetings2Ptrs[2];
    for (int i = 0; i < 2; i++) {
        meetings2Ptrs[i] = meetings2[i];
    }
    int meetings2ColSize[2] = {2, 2};

    printf("Test Case 2: days = %d, meetings = [[2, 4], [1, 3]]\n", days2);
    printf("Output: %d\n", countDaysWithoutMeetings(days2, meetings2Ptrs, 2, meetings2ColSize));

    // Example 3
    int days3 = 6;
    int meetings3[1][2] = {{1, 6}};
    int* meetings3Ptrs[1];
    meetings3Ptrs[0] = meetings3[0];
    int meetings3ColSize[1] = {2};

    printf("Test Case 3: days = %d, meetings = [[1, 6]]\n", days3);
    printf("Output: %d\n", countDaysWithoutMeetings(days3, meetings3Ptrs, 1, meetings3ColSize));

    return 0;
}

/*
 * Initial Approach: Hash Map
 * --------------------------
 * Approach:
 * 1. We use an array (acting as a hash map) to keep track of the days on which meetings are scheduled.
 * 2. Allocate memory for an array of size `days + 1` to account for 1-based indexing.
 * 3. Initialize the array to zero using `calloc`.
 * 4. For each meeting, mark the days in the range [start, end] as having a meeting by incrementing the array values.
 * 5. After marking all meeting days, count the number of days where the array value is zero (indicating no meetings).
 * 6. Free the allocated memory and return the count of days without meetings.
 *
 * Time Complexity: O(n + m)
 * - We iterate through the meetings array (n meetings).
 * - For each meeting, we iterate through the days in the range [start, end] (m days in total).
 * - Finally, we iterate through the `days` array to count the free days.
 *
 * Space Complexity: O(days)
 * - We use an array of size `days + 1` to keep track of the meeting days.
 */
int countDaysWithoutMeetings(int days, int** meetings, int meetingsSize, int* meetingsColSize) {
    int * map = (int *)calloc((days + 1), sizeof(int));
    
    for (int i = 0 ; i < meetingsSize ; i++) {
        for (int j = meetings[i][0]; j <= meetings[i][1]; j++ ) {
            map[j]++;
        }
    }
    
    int count = 0;
    for (int i = 1; i <= days; i++) {
        if (map[i] == 0) {
            count++;
        }
    }
    
    free(map);
    return count;
}
