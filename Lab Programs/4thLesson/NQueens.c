//
// Created by Dasaradha on 17/03/25.
//

#include <stdio.h>

int N;
int count = 0;
int solVector[100];

void print(int board[N+1][N+1]) {
    printf("Solution %d:\n", count);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            printf((board[i][j] == 1) ? "Q " : "_ ");
        printf("\n");
    }
    printf("Solution vector is : [");
    for (int i = 1;i < N; i++) {
        printf("%d,",solVector[i]);
    }
    printf("%d]\n",solVector[N]);
}

int isSafe(int r, int col,int board[N+1][N+1]) {
    for (int i = 1; i < r; i++)
        if (board[i][col] == 1)
            return 0;

    for (int i = r - 1, j = col - 1; i >= 1 && j >= 1; i--, j--)
        if (board[i][j] == 1)
            return 0;

    for (int i = r - 1, j = col + 1; i >= 1 && j <= N; i--, j++)
        if (board[i][j] == 1)
            return 0;
    return 1;
}

void nQueen(int r,int board[N+1][N+1]) {
    if (r > N) {
        count++;
        print(board);
        return;
    }

    for (int col = 1; col <= N; col++) {
        if (isSafe(r, col,board)) {
            board[r][col] = 1;
            solVector[r] = col;
            nQueen(r + 1,board);
            solVector[r] = 0;
            board[r][col] = 0;
        }
    }
}

int main() {
    printf("Enter N value:");
    scanf("%d",&N);
    int board[N+1][N+1];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            board[i][j] = 0;
        }
    }

    nQueen(1,board);
    printf("Total solutions: %d\n", count);
    return 0;
}

