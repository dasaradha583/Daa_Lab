//
// Created by Dasaradha on 14/02/25.
//
#include<stdio.h>



struct Object {
    int weight;
    int profit;
};


int max (int t1,int  t2) {
    return t1 > t2 ? t1 : t2;
}
int main() {
    int profit = 0;

    int maxWeight;
    int n;
    printf("Enter no of objects : ");
    scanf("%d", &n);
    printf("Enter knapsack weight : ");
    scanf("%d",&maxWeight);
    struct Object object[n];
    printf("Enter weight and profit : \n");
    for (int i = 0; i< n; i++) {
        scanf("%d %d", &object[i].weight,&object[i].profit);
    }
    int weight  =maxWeight;
    int dp[n+1][maxWeight+1];
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j <= maxWeight + 1; j++) {
            dp[i][j]  =0;
        }
        for (int k = 0; k <= n; k++) {
            dp[k][i] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= maxWeight; j++) {
            if (j - object[i-1].weight < 0) {
                dp[i][j] = dp[i-1][j];
                continue;
            }
            dp[i][j] = max(dp[i-1][j], object[i-1].profit
                + dp[i-1][j - object[i-1].weight] );
        }
    }
    int objects[n];
    for (int i = n; i >0 ; i--) {
        if (dp[i][maxWeight] != dp[i-1][maxWeight]) {
            objects[i-1] = 1;
            profit += object[i-1].profit;
            maxWeight = maxWeight - object[i-1].weight;
        } else {
            objects[i-1] = 0;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0;j <= weight; j++) {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    printf("(");
    for (int i =0; i < n-1; i++) {
        printf("x%d ",i+1);
    }
    printf("x%d) = (", n);
    for (int i = 0; i < n-1; i++) {
        printf("%d, ",objects[i]);
    }
    printf("%d \n)",objects[n-1]);
    printf("Total profit is : %d",profit);

}
