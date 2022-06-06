#include <stdio.h>
#include <stdlib.h>

void SeqSearch(int [], int);
void Shell(int []);
void swap(int *, int *);


int n = 10;

int main() {
    int arrA[] = {3,10,4,6,8,9,7,2,1,5};
    int cari;
    puts("Sequential Search - sorted");
    printf("Masukkan data yang ingin dicari : ");
    scanf("%d", &cari);
    SeqSearch(arrA, cari);
    return 0;
}

void SeqSearch(int arr[], int cari){
    int konfirm = 0;
    int i = 0;
    puts("Mengurutkan array terlebih dahulu");
    Shell(arr);
    while (i < n && !konfirm) {
        if (arr[i] == cari)
            konfirm = 1;
        else
            i++;
    }
    if (konfirm)
        printf("Data %d ditemukan pada urutan ke %d\n", cari, i+1);
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