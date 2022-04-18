#include <stdio.h>
#include <stdlib.h>

void Insertion(int [], int);
void tampil(int [], int);

int main() {
    int n = 10;
    int arrA[] = {3,10,4,6,8,9,7,2,1,5};
    puts("Insertion Sort - descending");
    puts("array sebelum sorting");
    tampil(arrA, n);
    Insertion(arrA, n);
    puts("Array setelah sorting");
    tampil(arrA, n);
    return 0;
}

void Insertion(int arr[], int n){
    int i = 1;
    while (i < n) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        i++;
    }
}

void tampil (int arr[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    puts("");
}