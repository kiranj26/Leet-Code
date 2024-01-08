#include <stdio.h>
#include <stdlib.h>

/*
 * Approach:
 * Detailed Approach:
 * The function rotates the matrix layer by layer, starting from the outermost layer and moving towards the inner layers.
 * It treats each layer as a ring and performs a cyclic rotation of the elements in that ring.
 *
 * For each layer, the rotation is achieved by moving elements in groups of four, 
 * corresponding to the four sides of the matrix (top, right, bottom, left):
 * 1. Save the elements of the top row in a temporary variable.
 * 2. Move the elements from the left column to the top row.
 * 3. Move the elements from the bottom row to the left column.
 * 4. Move the elements from the right column to the bottom row.
 * 5. Finally, move the elements saved in step 1 (original top row) to the right column.
 *
 * This process is repeated for each layer, with the left and right pointers moving closer towards the center after each layer is processed.
 *
 * The rotation is done in four steps to ensure that each element is moved to its correct rotated position. This method 
 * maintains the in-place requirement by not using any additional arrays for the rotation.
 *
 *
 * Time Complexity: O(N^2), where N is the number of rows/columns in the matrix.
 * Each element is visited once, leading to N^2 operations for an N x N matrix.
 *
 * Space Complexity: O(1).
 * The rotation is done in place without any additional allocation of large data structures.
 *
*/

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int left = 0;
    int right = (*matrixColSize) - 1;

    while (left < right)
    {
        for (int i = 0;i < (right - left); i++)
        {
            int top  = left; 
            int bottom  = right;

            int topLeft = matrix[top][left + i];

            // move bottom ,eft to top left
            matrix[top][left + i] = matrix[bottom - i][left];

            matrix[bottom - i][left] = matrix[bottom][right - i];

            matrix[bottom][right - i] = matrix[top + i][right];

            matrix[top + i][right] = topLeft;

        }
        left += 1;
        right -= 1;
    }
}

void printMatrix(int** matrix, int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example test case
    int matrixSize = 3;
    int matrixColSize = 3;
    int** matrix = (int**)malloc(matrixSize * sizeof(int*));

    for (int i = 0; i < matrixSize; i++) {
        matrix[i] = (int*)malloc(matrixColSize * sizeof(int));
    }

    // Initialize the matrix
    int counter = 1;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize; j++) {
            matrix[i][j] = counter++;
        }
    }

    // Print original matrix
    printf("Original Matrix:\n");
    printMatrix(matrix, matrixSize);

    // Rotate the matrix
    rotate(matrix, matrixSize, &matrixColSize);

    // Print rotated matrix
    printf("Rotated Matrix:\n");
    printMatrix(matrix, matrixSize);

    // Free the allocated memory
    for (int i = 0; i < matrixSize; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
