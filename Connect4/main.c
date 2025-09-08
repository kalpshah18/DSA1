#include <stdio.h>

#define ROWS 4
#define COLS 5

// Check if an array of 5 has at least 4 consecutive of num
int connected4(int arr[COLS], int num) {
    int count = 0;
    for (int i = 0; i < COLS; i++) {
        if (arr[i] == num) {
            count++;
            if (count == 4) return 1;
        } else {
            count = 0;
        }
    }
    return 0;
}

// Check win condition for given playerId
int check_winner(int grid[ROWS][COLS], int playerId) {
    // Columns
    for (int j = 0; j < COLS; j++) {
        int count = 0;
        for (int i = 0; i < ROWS; i++) {
            if (grid[i][j] == playerId) {
                count++;
                if (count == 4) return 1;
            } else count = 0;
        }
    }
    // Rows
    for (int i = 0; i < ROWS; i++) {
        if (connected4(grid[i], playerId)) return 1;
    }
    // Diagonals (\)
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (grid[i][j] == playerId &&
                grid[i+1][j+1] == playerId &&
                grid[i+2][j+2] == playerId &&
                grid[i+3][j+3] == playerId)
                return 1;
        }
    }
    // Diagonals (/)
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 3; j < COLS; j++) {
            if (grid[i][j] == playerId &&
                grid[i+1][j-1] == playerId &&
                grid[i+2][j-2] == playerId &&
                grid[i+3][j-3] == playerId)
                return 1;
        }
    }
    return 0;
}

int dropCoin(int grid[ROWS][COLS], int col, int playerId) {
    if (col < 0 || col >= COLS) return -1;
    for (int i = ROWS - 1; i >= 0; i--) {
        if (grid[i][col] == -1) {
            grid[i][col] = playerId;
            return i;
        }
    }
    return -1;
}

int isDraw(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == -1) return 0;
        }
    }
    return 1;
}


int main() {
    char initColor;
    scanf(" %c", &initColor);
    int myId = (initColor == 'Y') ? 0 : 1;
    int grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            grid[i][j] = -1;

    char color;
    int col;
    while (scanf(" %c %d", &color, &col) == 2) {
        int playerId = (color == 'Y') ? 0 : 1;
        int placed = dropCoin(grid, col-1, playerId);
        if(check_winner(grid, playerId)) {
            printf("%c won", color);
            break;
        }
        if(isDraw(grid)){
            printf("draw");
            break;
        }
    }
    return 0;
}