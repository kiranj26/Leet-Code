/**
 * @file LC_70_climbStairs.c
 * @brief Solution to LeetCode Problem 70: Climbing Stairs
 *
 * Detailed explanation and implementation of the algorithm to determine the number
 * of ways to climb a staircase when you can take either 1 step or 2 steps at a time.
 *
 * Author: Kiran Jojare
 * 
 * Time Complexity: O(n) - We iterate through a loop from 3 to n, performing a constant amount of work in each iteration.
 * Space Complexity: O(1) - We use a constant amount of extra space regardless of the input size n.
 */

#include <stdio.h>
#include <assert.h> // Include the assert library for testing

/**
 * @brief Calculates the number of distinct ways to climb a staircase with `n` steps
 *        when you can take either 1 step or 2 steps at a time.
 *
 * This problem can be modeled as a Fibonacci sequence where each state `n` can be 
 * reached either from the state `n-1` (by taking a single step) or from the state 
 * `n-2` (by taking two steps).
 *
 * @param n Number of steps in the staircase.
 * @return The number of distinct ways to reach the top of the staircase.
 */
int climbStairs(int n) {
    // Base case: If there's only 1 step, there's only 1 way to climb it.
    if (n == 1) return 1;
    
    // Base case: If there are 2 steps, there are 2 ways to climb it:
    // 1. Take two 1-steps.
    // 2. Take one 2-step.
    if (n == 2) return 2;

    // Initialize the first two steps:
    // `fn_1` represents f(n-1) which is the number of ways to reach the (n-1)th step.
    // `fn_2` represents f(n-2) which is the number of ways to reach the (n-2)th step.
    int fn_1 = 1; // Ways to reach step 1
    int fn_2 = 2; // Ways to reach step 2

    // Variable to store the number of ways to reach the current step.
    int steps = 0;

    // Loop through from the 3rd step to the nth step.
    for (int i = 3; i <= n; i++) {
        // Calculate the number of ways to reach the current step `i`.
        // The number of ways to reach step `i` is the sum of the ways to reach
        // the previous step `i-1` and the ways to reach the step before that `i-2`.
        // This is based on the recurrence relation: f(n) = f(n-1) + f(n-2).
        steps = fn_1 + fn_2;

        // Update `fn_1` to be the value of `fn_2`, i.e., move the window of the last two steps forward.
        fn_1 = fn_2;

        // Update `fn_2` to be the current number of ways to reach step `i`.
        fn_2 = steps;
    }

    // Return the total number of ways to reach the nth step.
    return steps;
}

/**
 * @brief Test function to validate the `climbStairs` function with various test cases.
 */
void test_climbStairs() {
    // Test case 1
    int n1 = 1;
    int expected1 = 1;
    int result1 = climbStairs(n1);
    printf("Test Case 1: climbStairs(%d) = %d\n", n1, result1);
    assert(result1 == expected1); // Expected output: 1

    // Test case 2
    int n2 = 2;
    int expected2 = 2;
    int result2 = climbStairs(n2);
    printf("Test Case 2: climbStairs(%d) = %d\n", n2, result2);
    assert(result2 == expected2); // Expected output: 2

    // Test case 3
    int n3 = 3;
    int expected3 = 3;
    int result3 = climbStairs(n3);
    printf("Test Case 3: climbStairs(%d) = %d\n", n3, result3);
    assert(result3 == expected3); // Expected output: 3

    // Test case 4
    int n4 = 4;
    int expected4 = 5;
    int result4 = climbStairs(n4);
    printf("Test Case 4: climbStairs(%d) = %d\n", n4, result4);
    assert(result4 == expected4); // Expected output: 5

    // Test case 5
    int n5 = 5;
    int expected5 = 8;
    int result5 = climbStairs(n5);
    printf("Test Case 5: climbStairs(%d) = %d\n", n5, result5);
    assert(result5 == expected5); // Expected output: 8

    // Test case 6
    int n10 = 10;
    int expected10 = 89;
    int result10 = climbStairs(n10);
    printf("Test Case 6: climbStairs(%d) = %d\n", n10, result10);
    assert(result10 == expected10); // Expected output: 89

    // Test case 7
    int n20 = 20;
    int expected20 = 10946;
    int result20 = climbStairs(n20);
    printf("Test Case 7: climbStairs(%d) = %d\n", n20, result20);
    assert(result20 == expected20); // Expected output: 10946

    // Test case 8
    int n30 = 30;
    int expected30 = 1346269;
    int result30 = climbStairs(n30);
    printf("Test Case 8: climbStairs(%d) = %d\n", n30, result30);
    assert(result30 == expected30); // Expected output: 1346269
}

/**
 * @brief Main function to execute the test cases for the `climbStairs` function.
 */
int main() {
    // Run the test cases to validate the `climbStairs` function.
    test_climbStairs();
    printf("All test cases passed!\n");
    return 0;
}
