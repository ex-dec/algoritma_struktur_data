#include <stdio.h>
#include <stdlib.h>

void Selection(int [], int);
void tampil(int [], int);

int main() {
    int n = 10;
    int arrA[] = {3,10,4,6,8,9,7,2,1,5};
    puts("Selection Sort");
    puts("array sebelum sorting");
    tampil(arrA, n);
    Selection(arrA, n);
    puts("Array setelah sorting");
    tampil(arrA, n);
    return 0;
}

void Selection(int arr[], int n){
    int i = 0;
    while (i < n - 1) {
        int min = i;
        int j = i + 1;
        while (j < n) {
            if (arr[j] < arr[min])
                min = j;
            j++;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        i++;
    }
}

void tampil (int arr[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    puts("");
}