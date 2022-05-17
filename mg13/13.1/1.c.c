#include <stdio.h>
#include <stdlib.h>

void BinSearch(int [], int);
void Shell(int []);
void swap(int *, int *);

int n = 10;

int main() {
    int arrA[] = {3,10,4,6,8,9,7,2,1,5};
    int cari;
    puts("Binary Search - sorted");
    printf("Masukkan data yang ingin dicari : ");
    scanf("%d", &cari);
    BinSearch(arrA, cari);
    return 0;
}

void BinSearch(int arr[], int cari){
    int L = 0;
    int R = n - 1;
    int konfirm = 0;
    int M;
    puts("Mengurutkan array terlebih dahulu");
    Shell(arr);
    while (L <= R && !konfirm) {
        M = (L + R) / 2;
        if (arr[M] == cari)
            konfirm = 1;
        else if (cari < arr[M])
            R = M - 1;
        else
            L = M + 1;
    }
    if (konfirm)
        printf("Data %d ditemukan pada urutan ke %d\n", cari, M + 1);
    else
        printf("Data %d tidak ditemukan\n", cari);
}

void Shell(int arr[]){
    int key = n, konfirm;
    while (key > 1) {
        key = key / 2;
        konfirm = 1;
        while (konfirm) {
            konfirm = 0;
            for (int i = 0; i < n-key; i++) {
                if (arr[i] > arr[i+key]) {
                    swap(&arr[i],&arr[i+key]);
                    konfirm = 1;
                }
            }
        }
    }
}

void swap(int *a, int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}