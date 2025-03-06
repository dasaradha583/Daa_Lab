


#include<stdio.h>



int binarySearch(int* a,int l, int f, int x) {
    if (f == l) {
        if (x == a[l]) {
            return l;
        }
        return 0;
    }
    int mid = (l + f) / 2;
    if ( x == a[mid]) {
        return mid;
    } else if (x < a[mid]) {
        return binarySearch(a,l,mid-1,x);
    } else {
        return binarySearch(a,mid+1, f,x);
    }
}

int main() {
    int n;

    printf("Enter no of elements : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements : ");
    for (int i =0;i  < n; i++) {
        scanf("%d", &arr[i]);
    }
    int x;
    printf("Enter element to serach : ");
    scanf("%d",&x);
    if (binarySearch(arr, 0,5,x)) {
        printf("Element is found");
    } else {
        printf("Element is not found");
    }
}