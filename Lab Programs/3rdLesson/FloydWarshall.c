//
// Created by Dasaradha on 17/03/25.
//


#include <stdio.h>
#define INF 999

void FloydWarshall(int A[100][100], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][k] + A[k][j] < A[i][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }
    }
}
int main() {
    int n, A[100][100];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix \n(enter %d if no edge) :\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    FloydWarshall(A, n);

    printf("Shortest distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            printf((A[i][j] == INF) ? "INF " : "%d ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}