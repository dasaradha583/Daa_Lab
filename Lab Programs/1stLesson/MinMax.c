

#include <stdio.h>

int arr[100];

int min = 99999;
int max = -99999;

void minMax(int i, int j) {
    if (i == j) {
        min = arr[i];
        max = arr[i];
    } else if (i == j -1) {
        max = (arr[i] > arr[j]) ? arr[i] : arr[j];
        min = (arr[i] > arr[j]) ? arr[j] : arr[i];
    } else {
        const int mid = (i + j) / 2;
        minMax(i, mid);
        int min1 = min;
        int max1 = max;
        minMax(mid + 1, j);
        if (min > min1) {
            min = min1;
        }
        if (max < max1) {
            max = max1;
        }
    }
}


int main () {

    int n;
    printf("Enter no of elements : ");
    scanf("%d", &n);
    printf("Enter the elements : ");
    for (int i =0;i  < n; i++) {
        scanf("%d", &arr[i]);
    }
    minMax(0, n-1);
    printf("Min : %d\n",min);
    printf("Max : %d",max);

    return 0;
}