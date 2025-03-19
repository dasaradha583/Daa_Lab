
#include <stdio.h>
#include <stdlib.h>

struct tapes {
    int programLength;
    struct  tapes * next;
};

struct tapes * insertAtEnd(struct tapes *head, int value) {
    struct tapes *node = malloc(sizeof(struct tapes));
    node->programLength = value;
    node->next = NULL;
    if (head == NULL) {
        head = node;
        return head;
    }
    struct tapes *temp = head;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = node;
    return head;
}


int add(struct  tapes * head) {
    int totalSum = 0;
    int currentSum = 0;
    while (head != NULL) {
        currentSum += head->programLength;
        totalSum += currentSum;
        head = head -> next;
    }
    return  totalSum;
}

int print(struct  tapes * head, int i) {
    int sum = add(head);
    printf("tapes%d : ",i);
    while (head != NULL) {
        printf("%d ",head->programLength);
        head = head->next;
    }
    printf("Sum : %d",sum);
    printf("\n");
    return  sum;
}


int main() {
    int n;
    printf("Enter no of programs : ");
    scanf("%d" , &n);
    int arr[n];
    printf("Enter the lengths of the programs : ");
    for (int i = 0; i < n; i++ ) {
        scanf("%d",&arr[i]);
    }
    int noOfTapes;
    int originalMeanTime = 0;
    printf("Enter no of tapes : ");
    scanf("%d",&noOfTapes);
    struct tapes * Tapes[noOfTapes];
    for (int i = 0; i < noOfTapes; i++) {
        Tapes[i] = NULL;
    }
    int j = 0;
    for (int i = 0; i < n ;i++) {
        int val = j % noOfTapes;
        Tapes[val] = insertAtEnd(Tapes[val],arr[i]);
        originalMeanTime += arr[i];
        j++;
    }
    int sumArray[noOfTapes];
    int totalSum = 0;
    for (int i =0; i < noOfTapes; i++) {
        sumArray[i] = add(Tapes[i]);
        totalSum += sumArray[i];
        print(Tapes[i],i+1);
    }
    printf("Total mean time = %d\n" , totalSum);
    printf("Original Mean time = %d", originalMeanTime);
}
