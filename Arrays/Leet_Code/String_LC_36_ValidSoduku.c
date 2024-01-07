#include <stdbool.h>
#include <stdio.h>
#include <string.h>


// Function: isValidSudoku
// This function checks if a given 9x9 Sudoku board is valid.
//
// Approach:
// 1. Use three 2D arrays (rows, colm, and box) to track the numbers present in each row, column, and 3x3 sub-box.
// 2. Iterate through each cell in the board.
//    - Convert the character at board[i][j] to an integer index (0-8) if it's not '.'.
//    - Calculate the index of the 3x3 sub-box.
//    - Check if the number already exists in the corresponding row, column, and sub-box.
//      - If it does, return false (invalid Sudoku).
//    - Otherwise, mark the number as seen in the corresponding row, column, and sub-box.
// 3. If no duplicates are found, return true (valid Sudoku).
//
// Time Complexity: O(1) - The board size is fixed at 9x9, leading to a constant number of operations.
// Space Complexity: O(1) - The additional space used (three 9x9 arrays) is also constant.


bool isValidSudoku(char board[9][9]) {
    bool rows[9][9] = {false};
    bool colm[9][9] = {false};
    bool box[9][9] = {false};
    int n;
    int boxIndex;
    for (int i = 0;i <9 ; i++)
    {
        for (int j = 0; j < 9 ; j++)
        {
            n = board[i][j] - '1';
            if (board[i][j] != '.')
            {
                boxIndex = ((i/3) * 3) + (j/3);
                // check if its already in a hashmaps
                if (rows[i][n]|| colm[j][n] || box[boxIndex][n])
                {
                    return false;
                }
                rows[i][n] = colm[j][n] = box[boxIndex][n] = true;
            }
        }
    }
    return true;
}

int main() {
    char board[9][9] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    if (isValidSudoku(board)) {
        printf("Valid Sudoku\n");
    } else {
        printf("Invalid Sudoku\n");
    }

    return 0;
}
