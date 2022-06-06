#include <stdio.h>
#include <stdlib.h>

void Shell(int [], int);
void tampil(int [], int);
void swap(int *, int *);
void resetCSM();

int c, s, m;

int main() {
    // int n = 10;
    int n = 5;
    // int arrA[] = {3,10,4,6,8,9,7,2,1,5};
    // int arrA[] = {1,2,3,4,5};
    int arrA[] = {5,4,3,2,1};
    resetCSM();
    puts("Shell Sort");
    puts("array sebelum sorting");
    tampil(arrA, n);
    puts("proses sorting array");
    Shell(arrA, n);
    puts("Array setelah sorting");
    tampil(arrA, n);
    printf("C : %d\nS : %d\nM : %d\n", c, s, m);
    return 0;
}

void Shell(int arr[], int n){
    int key = n, konfirm;
    while (key > 1) {
        key = key / 2;
        konfirm = 1;
        while (konfirm) {
            konfirm = 0;
            for (int i = 0; i < n-key; i++) {
                c++;
                if (arr[i] > arr[i+key]) {
                    swap(&arr[i],&arr[i+key]);
                    konfirm = 1;
                    s++;
                    m += 3;
                }
            }
        }
        tampil(arr, n);
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

void resetCSM(){
    c = m = s = 0;
}