/**
 * LeetCode Problem: Best Time to Buy and Sell Stock
 * Author: Kiran Jojare
 *
 * Approach:
 * - We use a dynamic programming approach to solve the problem.
 * - Create an array `map` where each element at index `i` represents the maximum stock price from day `i` to the last day.
 * - Fill the `map` array by traversing the prices array from the end to the beginning, updating `map` with the maximum stock price encountered so far.
 * - Calculate the maximum profit by iterating through the prices array and, for each day, calculating the potential profit by subtracting the current day's price from the maximum future price recorded in `map`.
 * - The maximum profit is returned as the result.
 *
 * Time Complexity:
 * - O(n): We traverse the array twice, resulting in linear time complexity.
 *
 * Space Complexity:
 * - O(n): We use an additional array `map` of the same size as the input array.
 */

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;
    
    // Create a map of max profit we can make by selling any day till last day from current day
    int* map = (int *)malloc(pricesSize * sizeof(int));
    if (!map) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    map[pricesSize - 1] = prices[pricesSize - 1];
    int maxsofar = prices[pricesSize - 1];
    
    // Fill in the map: the max value to the right from ith index will be the value at ith key
    for (int i = pricesSize - 2; i >= 0; i--) {
        if (prices[i] > maxsofar) {
            maxsofar = prices[i];
        }
        map[i] = maxsofar;
    }
    
    // Calculate max profit we can make in the future to the current valuation
    int max_profit = 0;
    for (int i = 0; i < pricesSize - 1; i++) {
        int current_profit = map[i + 1] - prices[i];
        if (current_profit > max_profit) {
            max_profit = current_profit;
        }
    }

    free(map);

    return max_profit;
}

// Main function to test the implementation
int main() {
    // Test Case 1
    int prices1[] = {7, 1, 5, 3, 6, 4};
    int pricesSize1 = sizeof(prices1) / sizeof(prices1[0]);
    printf("Max profit for prices1: %d\n", maxProfit(prices1, pricesSize1));

    // Test Case 2
    int prices2[] = {7, 6, 4, 3, 1};
    int pricesSize2 = sizeof(prices2) / sizeof(prices2[0]);
    printf("Max profit for prices2: %d\n", maxProfit(prices2, pricesSize2));

    // Test Case 3
    int prices3[] = {1, 2, 3, 4, 5};
    int pricesSize3 = sizeof(prices3) / sizeof(prices3[0]);
    printf("Max profit for prices3: %d\n", maxProfit(prices3, pricesSize3));

    // Test Case 4
    int prices4[] = {2, 4, 1};
    int pricesSize4 = sizeof(prices4) / sizeof(prices4[0]);
    printf("Max profit for prices4: %d\n", maxProfit(prices4, pricesSize4));

    // Test Case 5
    int prices5[] = {2, 1, 4};
    int pricesSize5 = sizeof(prices5) / sizeof(prices5[0]);
    printf("Max profit for prices5: %d\n", maxProfit(prices5, pricesSize5));

    return 0;
}
