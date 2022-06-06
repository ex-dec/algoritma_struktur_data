#include <stdio.h>
#include <stdlib.h>

void Quick(int [], int, int);
int QuickPartition(int [], int, int);
void tampil(int [], int);
void swap(int *, int *);

int main() {
    int n = 10;
    int arrA[] = {3,10,4,6,8,9,7,2,1,5};
    puts("Quick Sort");
    puts("array sebelum sorting");
    tampil(arrA, n);
    puts("Proses sorting array");
    Quick(arrA, 0, n - 1);
    puts("Array setelah sorting");
    tampil(arrA, n);
    return 0;
}

void Quick(int arr[], int p, int r){
    if (p < r) {
        int q = QuickPartition(arr, p, r);
        Quick(arr, p, q);
        Quick(arr, q+1, r);
    }
}

int QuickPartition(int arr[], int p, int r){
    int i = p;
    int j = r;
    int x = arr[p];
    while (i < j) {
        while (arr[i] < x)
            i++;
        while (arr[j] > x)
            j--;
        if (i < j) {
            swap(&arr[i], &arr[j]);
            j--;
        } else
            return j;
    }
}

void tampil (int arr[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    puts("");
}

void swap(int *a, int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}