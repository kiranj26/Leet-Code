/**
 * @file LC_118_PascalsTriangle.c
 * @brief Solution to LeetCode Problem 118: Pascal's Triangle
 *
 * Detailed explanation and implementation of the algorithm to generate the first numRows of Pascal's triangle.
 *
 * Author: Kiran Jojare
 * 
 * Time Complexity: O(numRows^2) - We iterate through each row and each element in the row.
 * Space Complexity: O(numRows^2) - We allocate space for each element in the triangle.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h> // Include the assert library for testing

/**
 * @brief Generates the first numRows of Pascal's triangle.
 * 
 * @param numRows The number of rows of Pascal's triangle to generate.
 * @param returnSize A pointer to store the size of the returned array (numRows).
 * @param returnColumnSizes A pointer to an array to store the size of each row.
 * @return A dynamically allocated array of arrays representing Pascal's triangle.
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;

    // Allocate memory for the result array and the column sizes array
    int** result = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    // Generate each row of Pascal's triangle
    for (int i = 0; i < numRows; i++) {
        // Allocate memory for the current row
        result[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;

        // Set the first and last elements of the row to 1
        result[i][0] = 1;
        result[i][i] = 1;

        // Calculate the inner elements of the row
        for (int j = 1; j < i; j++) {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }

    return result;
}

/**
 * @brief Helper function to print Pascal's triangle.
 * 
 * @param triangle The triangle array to print.
 * @param numRows The number of rows in the triangle.
 * @param columnSizes The array containing the sizes of each row.
 */
void printTriangle(int** triangle, int numRows, int* columnSizes) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Frees the memory allocated for Pascal's triangle.
 * 
 * @param triangle The triangle array to free.
 * @param numRows The number of rows in the triangle.
 */
void freeTriangle(int** triangle, int numRows) {
    for (int i = 0; i < numRows; i++) {
        free(triangle[i]);
    }
    free(triangle);
}

/**
 * @brief Test function to validate the `generate` function with various test cases.
 */
void test_generate() {
    // Test case 1
    int numRows1 = 5;
    int* returnSize1;
    int* returnColumnSizes1;
    int** result1 = generate(numRows1, &returnSize1, &returnColumnSizes1);
    int expected1[5][5] = {
        {1},
        {1, 1},
        {1, 2, 1},
        {1, 3, 3, 1},
        {1, 4, 6, 4, 1}
    };
    for (int i = 0; i < numRows1; i++) {
        for (int j = 0; j < returnColumnSizes1[i]; j++) {
            assert(result1[i][j] == expected1[i][j]);
        }
    }
    free(returnColumnSizes1);
    freeTriangle(result1, numRows1);

    // Test case 2
    int numRows2 = 1;
    int* returnSize2;
    int* returnColumnSizes2;
    int** result2 = generate(numRows2, &returnSize2, &returnColumnSizes2);
    int expected2[1][1] = {
        {1}
    };
    for (int i = 0; i < numRows2; i++) {
        for (int j = 0; j < returnColumnSizes2[i]; j++) {
            assert(result2[i][j] == expected2[i][j]);
        }
    }
    free(returnColumnSizes2);
    freeTriangle(result2, numRows2);

    // Additional test cases
    // Test case 3
    int numRows3 = 3;
    int* returnSize3;
    int* returnColumnSizes3;
    int** result3 = generate(numRows3, &returnSize3, &returnColumnSizes3);
    int expected3[3][3] = {
        {1},
        {1, 1},
        {1, 2, 1}
    };
    for (int i = 0; i < numRows3; i++) {
        for (int j = 0; j < returnColumnSizes3[i]; j++) {
            assert(result3[i][j] == expected3[i][j]);
        }
    }
    free(returnColumnSizes3);
    freeTriangle(result3, numRows3);

    // Test case 4
    int numRows4 = 6;
    int* returnSize4;
    int* returnColumnSizes4;
    int** result4 = generate(numRows4, &returnSize4, &returnColumnSizes4);
    int expected4[6][6] = {
        {1},
        {1, 1},
        {1, 2, 1},
        {1, 3, 3, 1},
        {1, 4, 6, 4, 1},
        {1, 5, 10, 10, 5, 1}
    };
    for (int i = 0; i < numRows4; i++) {
        for (int j = 0; j < returnColumnSizes4[i]; j++) {
            assert(result4[i][j] == expected4[i][j]);
        }
    }
    free(returnColumnSizes4);
    freeTriangle(result4, numRows4);

    printf("All test cases passed!\n");
}

/**
 * @brief Main function to execute the test cases for the `generate` function.
 */
int main() {
    // Run the test cases to validate the `generate` function.
    test_generate();
    printf("All test cases passed!\n");
    return 0;
}
