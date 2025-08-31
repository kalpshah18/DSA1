#include <stdio.h>

int directions[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

void printBoard(int n, int m, int board[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

int isValid(int x, int y, int n, int m, int board[n][m]) {
    return (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 0);
}

int countOnwardMoves(int x, int y, int n, int m, int board[n][m]) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];
        if (isValid(nx, ny, n, m, board)) cnt++;
    }
    return cnt;
}

// solve using Warnsdorff’s heuristic
int solve(int x, int y, int move, int n, int m, int board[n][m], int startX, int startY) {
    if (move == n * m) {
        for (int i = 0; i < 8; i++) {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx == startX && ny == startY) {
                printBoard(n, m, board);
                return 1;
            }
        }
        return 0;
    }
    int nextMoves[8][3];
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];
        if (isValid(nx, ny, n, m, board)) {
            nextMoves[cnt][0] = nx;
            nextMoves[cnt][1] = ny;
            nextMoves[cnt][2] = countOnwardMoves(nx, ny, n, m, board);
            cnt++;
        }
    }
    for (int i = 0; i < cnt; i++) {
        for (int j = i + 1; j < cnt; j++) {
            if (nextMoves[j][2] < nextMoves[i][2]) {
                int tmp0 = nextMoves[i][0], tmp1 = nextMoves[i][1], tmp2 = nextMoves[i][2];
                nextMoves[i][0] = nextMoves[j][0];
                nextMoves[i][1] = nextMoves[j][1];
                nextMoves[i][2] = nextMoves[j][2];
                nextMoves[j][0] = tmp0; nextMoves[j][1] = tmp1; nextMoves[j][2] = tmp2;
            }
        }
    }
    for (int i = 0; i < cnt; i++) {
        int nx = nextMoves[i][0];
        int ny = nextMoves[i][1];
        board[nx][ny] = move + 1;
        if (solve(nx, ny, move + 1, n, m, board, startX, startY)) return 1;
        board[nx][ny] = 0;
    }
    return 0;
}

int main() {
    int n, m, r, c;
    scanf("%d %d %d %d", &n, &m, &r, &c);
    int board[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            board[i][j] = 0;
    board[r][c] = 1;
    if (!solve(r, c, 1, n, m, board, r, c)) {
        printf("-1\n");
    }
    return 0;
}