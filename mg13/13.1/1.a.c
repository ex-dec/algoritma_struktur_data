#include <stdio.h>
#include <stdlib.h>

void SeqSearch(int [], int);

int n = 10;

int main() {
    int arrA[] = {3,10,4,6,8,9,7,2,1,5};
    int cari;
    puts("Sequential Search");
    
    printf("Masukkan data yang ingin dicari : ");
    scanf("%d", &cari);
    SeqSearch(arrA, cari);
    return 0;
}

void SeqSearch(int arr[], int cari){
    int konfirm = 0;
    int i = 0;
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