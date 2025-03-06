//
// Created by Dasaradha on 14/02/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int maxWeight;
struct Set {
    int weight;
    int profit;
    struct Set *next;
};


struct SubSet {
    int weight;
    int profit;
    struct SubSet *next;
};


struct Set *createSet(struct Set *set, struct SubSet *subs) {


    struct Set * head = malloc(sizeof(struct Set));
    struct Set *temp = head;
    while (set != NULL) {
        struct Set *newNode = malloc(sizeof(struct Set));
        newNode->profit = set->profit;
        newNode->weight = set->weight;
        newNode-> next = NULL;
        temp -> next = newNode;
        temp = newNode;
        set = set -> next;
    }
    while (subs != NULL) {
        struct Set *newNode = malloc(sizeof(struct Set));
        newNode->profit = subs->profit;
        newNode->weight = subs->weight;
        newNode->next = NULL;
        temp -> next = newNode;
        temp = newNode;
        subs = subs -> next;
    }
    struct Set *newHead = head->next;
    free(head);
    return newHead;
}
struct SubSet *createSubSet(struct Set *set, int profit, int weight) {
    struct SubSet *head = malloc(sizeof(struct SubSet));
    struct SubSet *temp = head;
    while (set != NULL) {
        if (set->weight + weight <= maxWeight) {
            struct SubSet *newNode = malloc(sizeof(struct SubSet));
            newNode->profit = set->profit + profit;
            newNode->weight = set->weight + weight;
            newNode->next = NULL;
            temp->next = newNode;
            temp = newNode;
        }
        set = set->next;
    }
    struct SubSet *newHead = head->next;
    free(head);
    return newHead;
}

struct Set *Maximum(struct Set *set) {
    struct Set *temp = set;
    struct Set *max = malloc(sizeof(struct Set));
    max->profit = 0;
    max->weight = 0;
    max->next = NULL;
    while (temp != NULL) {
        if (temp->profit > max->profit) {
            max = temp;
        }
        temp = temp->next;
    }
    return max;
}

bool inclusion(struct Set * maximum, struct Set * set1) {
    while (set1 != NULL) {
        if (set1 -> profit == maximum -> profit &&
            set1 -> weight == maximum -> weight) {
            return 0;
        }
        set1 = set1 -> next;
    }
    return 1;
}
int main() {
    int n;
    printf("Enter no of objects : ");
    scanf("%d" , &n);
    struct Set *set[n+1];
    struct SubSet *subSet[n+1];
    for (size_t i = 0;i <=n ;i++) {
        set[i] = malloc(sizeof(struct Set));
        subSet[i+1] = malloc(sizeof(struct SubSet));
    }
    printf("Enter knapsack weight : ");
    scanf("%d",&maxWeight);
    int array[n][2];
    printf("Enter profits and weights : ");
    for (size_t i = 0; i < n;i++) {
        scanf("%d %d", &array[i][0], &array[i][1]);
    }
    struct  Set *temp = malloc(sizeof(struct Set)) ;
    temp -> profit = 0;
    temp -> weight = 0;
    temp -> next = NULL;
    set[0] = temp;
    struct SubSet *temp2 = malloc(sizeof(struct SubSet));
    if (array[0][1] <= maxWeight) {
        temp2 -> profit = array[0][0];
        temp2 -> weight = array[0][1];
    } else {
        temp2 -> profit = 0;
        temp2 -> weight = 0;
    }
    temp2 -> next = NULL;
    subSet[0] = temp2;
    for (int i = 1; i <= n; i++) {
        set[i] = createSet(set[i-1],subSet[i-1]);
        subSet[i] = createSubSet(set[i],array[i][0],array[i][1]);
    }
    struct Set *maximum = Maximum(set[n]);

    int result[n];
    for (int i = 0; i < n; i++) {
        result[i] = 0;
    }
    for (int i= n; i > 0;i--) {
       if (inclusion(maximum,set[i-1])) {
           result[i-1] = 1;
           maximum -> weight -= array[i-1][1];
           maximum -> profit -= array[i-1][0];
       }
    }
    printf("(");
    for (int i = 1; i < n; i++) {
        printf("x%d, ",i);
    }
    printf("x%d) = (",n);
    for (int i = 0;i < n-1; i++) {
        printf("%d, ",result[i]);
    }
    printf("%d)\n",result[n-1]);
}




// for (int i =0; i <= n; i++) {
//     printf("Set%d : ",i);
//     print(set[i]);
// }
//
// for (int i = 0; i <=n ;i++) {
//     printf("SubSet%d : ",i);
//     print1(subSet[i]);
// }

// if a set contains a value and previous set contains the same value
// the set is not added to knapsack
//if a set is added to the result then the profit and weight are subtracted from the set which is added
// void print(struct Set *set) {
//     while (set!= NULL) {
//         printf("( %d %d ) ,",set->profit, set->weight);
//         set = set->next;
//     }
//     printf("\n");
// }
//
//
// void print1(struct SubSet *subs) {
//     while (subs != NULL) {
//         printf("( %d %d ) ,", subs->profit, subs->weight);
//         subs = subs->next;
//     }
//     printf("\n");
// }

// printf("%d %d\n",maximum->profit,maximum->weight);