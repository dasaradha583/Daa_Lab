//
// Created by Dasaradha on 19/03/25.
//


#include <stdio.h>

double profit = 0;

int total;
struct Item {
    int number;
    int weight;
    int profits;
    double ratio;
    int fraction;
};

void sortKnapSack(struct Item *items, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

void knapSack(struct Item *items, int n, int max_weight) {
    int currentWeight = 0;
    sortKnapSack(items, n);
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= max_weight) {
            currentWeight += items[i].weight;
            profit += items[i].profits;
            items[i].fraction = 1;
            total++;
        } else {
            int remainingWeight = max_weight - currentWeight;
            profit += ((double) remainingWeight / items[i].weight) * items[i].profits;
            if (remainingWeight == 1) {
                items[i].fraction = -1  ;
            }else {
                items[i].fraction = remainingWeight;
            }
            total++;
            break;
        }
    }
}

void sortNumber(struct Item *items, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].number > items[j + 1].number) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    printf("Enter the weight and profits of each item: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].profits);
        items[i].ratio = (double) items[i].profits / items[i].weight;
        // printf("%f\n",items[i].ratio);
        items[i].number = i + 1;
        items[i].fraction = 0;
    }

    int maxWeight;
    printf("Enter the maximum weight: ");
    scanf("%d", &maxWeight);

    knapSack(items, n, maxWeight);
    sortNumber(items,n);//sort the items to get in order
    printf("Maximum profit: %f\n", profit);
    printf("(");
    int count = 0;
    for (int i =0; i < n-1; i++) {
        printf("x%d, ",i+1);
    }
    printf("x%d",n);
    printf(") = (");
    for (int i = 0; i < n-1; i++) {
        if (items[i].fraction == 1) {
            printf("%d ,",items[i].fraction);
        } else if (items[i].fraction == -1) {
            printf(" 1 / %d ,",items[i].weight);
        } else if (items[i].fraction > 1) {
            printf("%d / %d,", items[i].fraction,items[i].weight);
        } else {
            printf("0.00,");
        }
    }
    printf("%d",items[n-1].fraction);
    printf(")");
    return 0;
}
