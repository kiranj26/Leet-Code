#include <stdio.h>
#include <stdlib.h>
/*   BRUTE FORCE ABROACH */
/**
 * Merges a set of intervals using a brute force approach.
 * 
 * @ Brute Force Approach:
 * - Iterate through each interval in the input array.
 * - For each interval, compare it with every other interval to check for any overlaps.
 * - If two intervals overlap, merge them into one interval.
 * - The process is repeated until no more overlapping intervals can be found.
 * - During each iteration, overlapping intervals are merged and removed from the list of intervals to be checked.
 *
 * Time Complexity:
 * - O(n^2), where n is the number of intervals.
 * - In the worst case, each interval is compared with every other interval, leading to quadratic time complexity.
 *
 * Space Complexity:
 * - O(n), where n is the number of intervals.
 * - Additional space is used to store the merged intervals. In the worst case, if no intervals are merged,
 *   this equals the space of the original intervals array.
 *
 * @param intervals 2D array of intervals where intervals[i] = [start, end].
 * @param intervalsSize Size of the intervals array.
 * @param intervalsColSize Size of each interval (always 2).
 * @param returnSize Pointer to store the size of the returned array.
 * @param returnColumnSizes Pointer to store the sizes of the columns of the returned array.
 * @return A pointer to the merged intervals array.
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    // if no input o empty input
    if (intervalsSize <= 0)
    {
        *returnSize = 0;
        return NULL;
    }

    // alocate memory for th case where no intervals can be merged
    int ** mergedIntervals  = (int **)malloc(intervalsSize * sizeof(int *));

    *returnColumnSizes = (int *)malloc(intervalsSize * sizeof(int));
    for (int i = 0; i < intervalsSize; i++)
    {
        mergedIntervals[i] = (int *)malloc(2 * sizeof(int));
        (*returnColumnSizes)[i] = 2;
    }

    int mergedCount = 0;
    int merged = 0;

    do {
        merged  = 0;
        for (int i = 0; i< intervalsSize; i++)
        {
            if (intervals[i] == NULL) continue;

            for (int j = i+1; j < intervalsSize; j++)
            {
                if (intervals[j] != NULL && !( intervals[i][1] < intervals[j][0] || intervals[i][0] > intervals[j][1]))
                {
                    // merge interval i and j 
                    intervals[i][0] = (intervals[i][0] < intervals[j][0]) ? intervals[i][0]: intervals[j][0];
                    intervals[i][1] = (intervals[i][1] > intervals[j][1]) ? intervals[i][1]: intervals[j][1];

                    free(intervals[j]);
                    intervals[j] = NULL;

                    merged  = 1; 
                }
                if (merged)
                {
                    break;
                }
            }

        }
        if (!merged)
        {
            for (int i = 0; i<  intervalsSize ; i++)
            {
                if (intervals[i] != NULL)
                {
                    mergedIntervals[mergedCount][0] =  intervals[i][0] ; 
                    mergedIntervals[mergedCount][1] =  intervals[i][1];
                    mergedCount++;
                }
            }
        }
    }
    while(merged);

    *returnSize = mergedCount;
    return mergedIntervals;
}

int main() {
    // Example test case
    int intervalsSize = 4;
    int intervalsColSize = 2;
    int returnSize;
    int* returnColumnSizes;

    // Allocating memory for intervals
    int** intervals = (int**)malloc(intervalsSize * sizeof(int*));
    for (int i = 0; i < intervalsSize; i++) {
        intervals[i] = (int*)malloc(intervalsColSize * sizeof(int));
    }

    // Initializing intervals
    // [[1,3],[2,6],[8,10],[15,18]]
    intervals[0][0] = 1; intervals[0][1] = 3;
    intervals[1][0] = 2; intervals[1][1] = 6;
    intervals[2][0] = 8; intervals[2][1] = 10;
    intervals[3][0] = 15; intervals[3][1] = 18;

    // Call merge function
    int** mergedIntervals = merge(intervals, intervalsSize, &intervalsColSize, &returnSize, &returnColumnSizes);

    // Print merged intervals
    printf("Merged Intervals:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d]\n", mergedIntervals[i][0], mergedIntervals[i][1]);
    }

    // Free allocated memory
    for (int i = 0; i < intervalsSize; i++) {
        free(intervals[i]);
    }
    free(intervals);
    for (int i = 0; i < returnSize; i++) {
        free(mergedIntervals[i]);
    }
    free(mergedIntervals);
    free(returnColumnSizes);

    return 0;
}
