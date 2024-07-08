#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize);

void printArray(int* array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%d", array[i]);
    }
    printf("]\n");
}

int** createMatrix(int rows, int cols, int values[]) {
    int** mat = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mat[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            mat[i][j] = values[i * cols + j];
        }
    }
    return mat;
}

void freeMatrix(int** mat, int rows) {
    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);
}

int main() {
    int mat1_values[] = {
        1, 1, 0, 0, 0,
        1, 1, 1, 1, 0,
        1, 0, 0, 0, 0,
        1, 1, 0, 0, 0,
        1, 1, 1, 1, 1
    };
    int* matColSize1 = (int*)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) matColSize1[i] = 5;
    int** mat1 = createMatrix(5, 5, mat1_values);
    int returnSize1;
    int* result1 = kWeakestRows(mat1, 5, matColSize1, 3, &returnSize1);
    printf("Test Case 1: ");
    printArray(result1, returnSize1);
    free(result1);
    free(matColSize1);
    freeMatrix(mat1, 5);

    int mat2_values[] = {
        1, 0, 0, 0,
        1, 1, 1, 1,
        1, 0, 0, 0,
        1, 0, 0, 0
    };
    int* matColSize2 = (int*)malloc(4 * sizeof(int));
    for (int i = 0; i < 4; i++) matColSize2[i] = 4;
    int** mat2 = createMatrix(4, 4, mat2_values);
    int returnSize2;
    int* result2 = kWeakestRows(mat2, 4, matColSize2, 2, &returnSize2);
    printf("Test Case 2: ");
    printArray(result2, returnSize2);
    free(result2);
    free(matColSize2);
    freeMatrix(mat2, 4);

    // Additional Test Cases
    int mat3_values[] = {
        1, 1, 1, 1, 0,
        1, 1, 1, 0, 0,
        1, 1, 0, 0, 0,
        1, 0, 0, 0, 0,
        1, 1, 1, 1, 1
    };
    int* matColSize3 = (int*)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) matColSize3[i] = 5;
    int** mat3 = createMatrix(5, 5, mat3_values);
    int returnSize3;
    int* result3 = kWeakestRows(mat3, 5, matColSize3, 3, &returnSize3);
    printf("Test Case 3: ");
    printArray(result3, returnSize3);
    free(result3);
    free(matColSize3);
    freeMatrix(mat3, 5);

    int mat4_values[] = {
        0, 0, 0, 0,
        0, 0, 0, 0,
        1, 1, 1, 1,
        1, 1, 1, 1,
        1, 0, 0, 0
    };
    int* matColSize4 = (int*)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) matColSize4[i] = 4;
    int** mat4 = createMatrix(5, 4, mat4_values);
    int returnSize4;
    int* result4 = kWeakestRows(mat4, 5, matColSize4, 4, &returnSize4);
    printf("Test Case 4: ");
    printArray(result4, returnSize4);
    free(result4);
    free(matColSize4);
    freeMatrix(mat4, 5);

    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    // Implement the main logic here
    
}
