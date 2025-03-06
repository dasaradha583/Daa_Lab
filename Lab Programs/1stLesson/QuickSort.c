


#include<stdio.h>



int partition(int *arr, int first, int last) {

    int pivot = arr[first];
    int i = first;
    int j = last;
    while(i < j) {
        while(arr[i] <= pivot && i < j) {
            i++;
        }
        while ( arr[j] > pivot){
            j--;
        }
        if(i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }


    }
    arr[first] = arr[j];
    arr[j] = pivot;

    return j;

}
void quickSort(int* arr, int first, int last) {

    if(first < last) {
        int j = partition(arr, first, last);
        quickSort(arr, first, j -1 );
        quickSort(arr, j+1, last);
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}




int main() {
    int n;
    printf("Enter no of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements : ");
    for (int i =0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,n-1);
    return 0;
}

