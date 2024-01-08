#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Determines the winner of a Tic Tac Toe game or if the game is still ongoing or a draw.
 *
 * Approach:
 * 1. Use two arrays, A and B, to track the count of marks by Player A and Player B in each row, column, 
 *    and diagonal. The first three elements are for rows, the next three for columns, the seventh for 
 *    the primary diagonal, and the eighth for the secondary diagonal.
 * 2. Traverse the moves array. For each move, update the corresponding count in either A or B based on 
 *    the player (Player A for even i, Player B for odd i).
 * 3. After each move, check the arrays A and B:
 *    - If any index in A reaches 3, Player A wins.
 *    - If any index in B reaches 3, Player B wins.
 * 4. If all moves are played and no winner is found, the game is a draw if movesSize is 9, otherwise pending.
 *
 * Time Complexity:
 * - O(n), where n is the number of moves. The function iterates through each move once.
 *
 * Space Complexity:
 * - O(1), as the space used for the arrays A and B is constant, independent of the input size.
 */
char* tictactoe(int** moves, int movesSize, int* movesColSize) {
    int A[8] = {0};  // Array for Player A
    int B[8] = {0};  // Array for Player B
    int r, c;

    // Traverse and update the A and B arrays
    for (int i = 0; i < movesSize; i++) {
        r = moves[i][0];
        c = moves[i][1];

        // Update counts for Player A or B
        if (i % 2 == 0) {
            // Player A's move
            A[r]++;
            A[c+3]++;
            if (r == c) A[6]++;
            if (r == 2 - c) A[7]++;
        } else {
            // Player B's move
            B[r]++;
            B[c+3]++;
            if (r == c) B[6]++;
            if (r == 2 - c) B[7]++;
        }
    }

    // Check for a winner
    for (int i = 0; i < 8; i++) {
        if (A[i] == 3) return "A";
        if (B[i] == 3) return "B";
    }

    // Check if the game is a draw or pending
    return (movesSize == 9) ? "Draw" : "Pending";
}

int main() {
    // Example test case
    int moves1[][2] = {{0,0}, {2,0}, {1,1}, {2,1}, {2,2}};
    int movesSize1 = sizeof(moves1) / sizeof(moves1[0]);
    int* movesPtrs1[movesSize1];
    for (int i = 0; i < movesSize1; i++) {
        movesPtrs1[i] = moves1[i];
    }
    printf("Game result: %s\n", tictactoe(movesPtrs1, movesSize1, NULL));

    // Additional test cases can be added here

    return 0;
}
