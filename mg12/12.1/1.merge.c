#include <stdio.h>
#include <stdlib.h>

void MergeRekursif(int, int, int []);
void Merge(int ,int ,int ,int []);
void tampil(int [], int);
void swap(int *, int *);

int n = 10;

int main() {
    int arrA[] = {3,10,4,6,8,9,7,2,1,5};
    puts("Merge Sort");
    puts("array sebelum sorting");
    tampil(arrA, n);
    puts("Proses sorting array");
    MergeRekursif(0, n - 1, arrA);
    puts("Array setelah sorting");
    tampil(arrA, n);
    return 0;
}

void MergeRekursif(int l, int r, int arr[]){
    if (l < r) {
        int med = (l + r) / 2;
        MergeRekursif(l, med, arr);
        MergeRekursif(med + 1, r, arr);
        Merge(l, med, r, arr);
    }
}

void Merge(int l, int med, int r, int arr[]){
    int kiri1 = l, kanan1 = med, kiri2 = med + 1, kanan2 = r;
    int i = l, j;
    int hasil[n];
    while (kiri1 <= kanan1 && kiri2 <= kanan2) {
        if (arr[kiri1] <= arr[kiri2]) {
            hasil[i] = arr[kiri1];
            kiri1++;
        } else {
            hasil[i] = arr[kiri2];
            kiri2++;
        }
        i++;
    }
    while (kiri1 <= kanan1) {
        hasil[i] = arr[kiri1];
        kiri1++;
        i++;
    }
    while (kiri2 <= kanan2) {
        hasil[i] = arr[kiri2];
        kiri2++;
        i++;
    }
    j = l;
    while (j <= r) {
        arr[j] = hasil[j];
        j++;
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