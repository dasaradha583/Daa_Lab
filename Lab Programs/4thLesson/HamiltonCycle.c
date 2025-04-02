//
// Created by Dasaradha on 22/03/25.
//


#include<stdio.h>

int graph[100][100];
int path[100];
int count = 0;
int visited[100];
int n;
void print() {
    printf("Solution %d : ",count);
    for (int i = 0; i < n; i++) {
        printf("%d ",path[i]);
    }
    printf("\n");
}
void hamiltonCycle(int source) {
    if (count == n) {
        print();
        return;
    }
    for (int i = 0; i < n; i++) {
        if (graph[source][i] == 1 && visited[i] == 0) {
            visited[i] = 1;
            path[count] = source;
            count++;
            hamiltonCycle(i);
            count--;
            visited[i] = 0;
        }
    }
}
int main() {
    printf("Enter the no of vertices : ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix : \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int source;
    printf("Enter source vertex : ");
    scanf("%d",&source);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    visited[source] = 1;
    hamiltonCycle(source);
}
