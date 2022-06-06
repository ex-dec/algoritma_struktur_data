#include <stdio.h>
#include <stdlib.h>

void Bubble(int [], int);
void tampil(int [], int);
void swap(int *, int *);

int main() {
    int n = 10;
    int arrA[] = {3,10,4,6,8,9,7,2,1,5};
    puts("Bubble Sort");
    puts("array sebelum sorting");
    tampil(arrA, n);
    puts("Proses sorting array");
    Bubble(arrA, n);
    puts("Array setelah sorting");
    tampil(arrA, n);
    return 0;
}

void Bubble(int arr[], int n){
    int konfirm = 1;
    int posAkhir = n-2;
    int i = 0;
    while (i <= posAkhir && konfirm) {
        konfirm = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                konfirm = 1;
            }
        }
        tampil(arr, n);
        i++;
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