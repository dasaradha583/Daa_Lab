#include <stdio.h>

int m, n;
int c = 0;
int sol = 0;
int g[10][10];
int x[10];

void nextValue(int k);
void graphColoring(int k);

int main() {
    int i, j;
    printf("\n enter the number of vertices in a graph: ");
    scanf("%d", &n);
    printf("\n enter graph edges\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    printf("\n All possible solutions are\n");
    for (m = 1; m <= n; m++) {
        if (c == 1)
            break;
        graphColoring(1);
    }
    printf("\n chromatic number is %d", m - 1);
    printf("\n total number of solutions is %d", sol);
}

void graphColoring(int k) {
    int i;
    while (1) {
        nextValue(k);
        if (x[k] == 0)
            return;
        if (k == n) {
            c = 1;
            for (i = 1; i <= n; i++)
                printf("%d ", x[i]);
            sol++;
            printf("\n");
        } else {
            graphColoring(k + 1);
        }
    }
}

void nextValue(int k) {
    int j;
    while (1) {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
            return;
        for (j = 1; j <= n; j++) {
            if (g[k][j] == 1 && x[k] == x[j])
                break;
        }
        if (j == (n + 1))
            return;
    }
}