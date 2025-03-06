//
// Created by Dasaradha on 18/02/25.
//


#include <stdio.h>
#define max 1000
#define INF 9999
int distance[max];
int n;

void bellmanFord(int a[][n], int source,int n) {
    distance[source] = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (a[j][k] != 0) {
                    if (distance[k] > distance[j] + a[j][k]) {
                        distance[k] = distance[j] + a[j][k];
                    }
                }
            }
        }
    }
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            if (a[j][k] != 0) {
                if (distance[k] > distance[j] + a[j][k]) {
                    distance[k] = distance[j] + a[j][k];
                    printf("Negative cycle detected\n");
                    return;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("Distance from %d to %d is %d\n",source,i,distance[i]);
    }
}
int main() {
    printf("Enter no of edges : ");
    scanf("%d", &n);
    printf("Enter adjacency matrix : ");
    int a[n][n];
    for (int i =0;i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        distance[i] = INF;
    }
    int source;
    printf("Enter source vertex : ");
    scanf("%d",&source);
    bellmanFord(a, source,n);
    return 0;
}