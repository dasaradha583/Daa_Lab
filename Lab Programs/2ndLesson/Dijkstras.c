

#include <stdio.h>
int distance[8];
int minDistance(int distance[], int visited[], int n) {
    int min = 999;
    int min_index = -1;
    for (size_t i = 0; i < n; i++)
    {
        if(visited[i] == 0 && distance[i] <= min) {
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

int* dijkstra(int graph[][5], int n, int start) {


    int visited[n];
    for(int i = 0; i < n; i++) {
        distance[i] = 999;
        visited[i] = 0;
    }
    distance[start] = 0;
    for (size_t i = 0; i < n; i++)
    {
        int u = minDistance(distance, visited, n);
        visited[u] = 1;
        for (size_t v = 0; v < n; v++)
        {
            if(!visited[v] && graph[u][v] && distance[u] != 999 && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }
    printf("%p",&distance[0]);
    return &distance;
}


int main() {

    int graph[5][5] = {
            {0, 2, 0, 4, 0},
            {0, 0, 5, 0, 8},
            {0, 0, 0, 3, 0},
            {0, 0, 0, 0, 0},
            {6, 0, 0, 0, 0}
    };
    int n = 5;
    int start = 0;
    int* address = dijkstra(graph, n, start);
    //printf("%p",address);
    for (int i = 0; i < n; i++) {
        printf("%d ",*(address + i));

        printf("\n");
    }
}
