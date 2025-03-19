//
// Created by Dasaradha on 17/03/25.
//

#include <stdio.h>
int count = 0;
void print(int * partial, int size,int* vector) {
    printf("values are : [");
    for (int i = 0; i < size -1; i++) {
        printf("%d,",partial[i]);
    }
    printf("%d] = [",partial[size-1]);
    for (int i = 0; i < size -1; i++) {
        printf("x%d,",vector[i]);
    }
    printf("x%d]\n",vector[size-1]);
}


void sumOfSubSet(int arr[], int n, int m, int partial[],int sum, int size, int index,int* vector) {
    if (sum == m) {
        count++;
        print(partial,size,vector);
        return;
    }
    if ( index >=n || sum > m) {
        return;
    }
    partial[size] = arr[index];
    vector[size] = index + 1;
    sumOfSubSet(arr,n,m,partial,sum + arr[index],size+1,index+1,vector);
    vector[index] = 0;
    sumOfSubSet(arr,n,m,partial,sum ,size,index+1,vector);
}

int main() {

    int n;
    printf("Enter no of elements : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements : ");
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    int sum;
    printf("Enter the sub set sum value : ");
    scanf("%d", &sum);
    int partial[n];
    int vector[n];

    sumOfSubSet(arr,n,sum,partial,0,0,0,vector);
    printf(count ? "Total number of subsets : %d\n" : "No subset found\n", count);
}


