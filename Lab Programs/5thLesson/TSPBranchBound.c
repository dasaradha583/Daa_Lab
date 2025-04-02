//
// Created by Dasaradha on 28/03/25.
//


#include <stdio.h>
#define INF 999

int graph[100][100];
int path[100];
int rowVisited[100];
int colVisited[100];
int n;
int costArray[999];
int count =0;
int cost = 0;
int source;


int rowLow(int row) {
    int min = INF;
    for (int i = 0; i< n; i++) {
        if (graph[row][i] == 0) {
            return 0;
        }
        min = graph[row][i] < min ? graph[row][i] : min;
    }
    return min;
 }


int colLow(int col) {
    int min = INF;
    for (int i = 0; i< n; i++) {
        if (graph[i][col] == 0) {
            return 0;
        }
        min = graph[i][col] < min ? graph[i][col] : min;
    }
    return min;
}
//find the  cost for individual row cost
int findRowMin(int fixed, int col, int row) {
    int min = INF;
    for (int i = 0; i < n; i++) {
        /*
         *
         *if the ith vertex and row are equal skip it
         *Since  Graph[J,Source] should be infinity we skip the value
         */
        if (i == col || (col == fixed && i == source)) {
            continue;
        }
        //Since there is a vertex with value 0 then the minimum value is 0
        if (graph[fixed][i] == 0) {
            return 0;
        }
        min = graph[fixed][i] < min ? graph[fixed][i] : min;
    }
    return  min == INF ? 0 : min;

}


int findRowCost(int row, int col) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        /*
         *if the row is already in the path skip it
         *if the ith vertex and row are equal skip it
         */
        if (i == row || rowVisited[i] == 1) {
            continue;
        }
        sum += findRowMin(i,col,row);
    }
    return sum;
}

int findColMin(int fixed, int col, int row) {//find the  cost for individual row cost
    int min = INF;
    for (int i = 0; i < n; i++) {
        /*
         *
         *if the ith vertex and row are equal skip it
         *Since  Graph[J,Source] should be infinity we skip the value
         */
        if (i == row || (fixed == source && i == col)) {
            continue;
        }
        //Since there is a vertex with value 0 then the minimum value is 0
        if (graph[i][fixed] == 0) {
            return 0;
        }
        min = graph[i][fixed] < min ? graph[i][fixed] : min;
    }
    return min == INF ? 0 : min;
}

int findColCost(int row, int col) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        /*
         *if the column is already in the path skip it
         *if the ith vertex and row are equal skip it
         */
        if (i == col || colVisited[i] == 1)
            continue;
        sum += findColMin(i,col,row);
    }
    return sum;
}

int findIndividualCost(int row, int col) {
    int rowSum = findRowCost(row, col);//finds the cost for row reduction for the whole matrix
    int colSum = findColCost(row, col);//finds the cost for column reduction for the whole matrix
    return    rowSum + colSum;
}
//Find the next vertex with minimum Cost value
int findMinVertex() {
    int min = 999;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if ((rowVisited[i] == 0)) {
            if (min > costArray[i]) {
                min = costArray[i];
                index = i;
            }
        }
    }

    return index;
}
void updateMatrix(int source, int index) {
    for (int i = 0; i < n; i++) {
        graph[source][i] = INF;
    }
    for (int i = 0; i < n; i++) {
        graph[i][index] = INF;
    }
    graph[index][source] = 0;
}

void print(int index) {

    printf("Updated matrix for %d\n",index);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

//Recursive Function
void TSPBranchAndBound(int source) {

    //base condition

    for (int i = 0; i < n; i++) {
        if (i == source || rowVisited[i] == 1) {//eliminating the row if already visited
            continue;
        }
        costArray[i] = findIndividualCost(source, i)+ cost + graph[source][i];//finding the C(S)
    }
    rowVisited[source] = 1;
    colVisited[source] = 1;
    int index = findMinVertex();//Finding the next vertex to  be visited
    path[count++] = source;
    if (count == n) return;
    cost = costArray[index];
    updateMatrix(source, index);//updating the adjacency matrix with source row and index column making INF

    print(index);
    TSPBranchAndBound(index);//Recursion
}



//main function
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix : \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d",&graph[i][j]);
        }
    }
    //Row Reduction
    int rowSum = 0;
    for (int i = 0;i < n; i++) {
        int low = rowLow(i);
        for (int j = 0; j < n; j++) {
            if (!(graph[i][j] == 0)&& graph[i][j] != INF) {
                graph[i][j] = graph[i][j] - low >=0 ? graph[i][j] - low : graph[i][j];
            }
        }
        rowSum += low;
    }
    //Column Reduction
    int colSum = 0;
    for (int j = 0;j< n; j++) {
        int low = colLow(j);
        for (int i = 0; i < n; i++) {
            if (!(graph[i][j] == 0)&& graph[i][j] != INF) {
                graph[i][j] = graph[i][j] - low >=0 ? graph[i][j] - low : graph[i][j];
            }
        }
        colSum += low;
    }
    for (int i = 0;i < n; i++) {
        rowVisited[i] = 0;
        colVisited[i] = 0;
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);
    path[0] = source;;
    cost = colSum + rowSum;//Cost reduction for source vertex
    TSPBranchAndBound(source);
    for (int i = 0; i < n; i++) {
        if (rowVisited[i] == 0) {
            path[count++] = i;
        }
    }
    path[count++] = source;
    for (int i = 0; i <= n; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
    printf("%d\n", cost);
}
