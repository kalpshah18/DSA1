#include <stdio.h>
#include <stdlib.h>

int isSafe(int grid[9][9], int row, int col, int num) {
    for (int x = 0; x < 9; x++) {
        if (grid[row][x] == num) return 0;
        if (grid[x][col] == num) return 0;
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num) return 0;
        }
    }
    return 1;
}

int solveSudoku(int grid[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (solveSudoku(grid)) return 1;
                        grid[row][col] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

void printGrid(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int grid[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    if (solveSudoku(grid)) {
        printGrid(grid);
    } else {
        printf("No solution exists\n");
    }
    return 0;
}