#include <stdio.h>
#include <stdlib.h>
#define max 1000000

// Fungsi pilihan menu
char menu(int []);
void dup(int [], int []);

// Fungsi general
void generate(int []);
void swap(int *, int *);

int main(){
    char pilihan = '0';
    int arrA[max];
    generate(arrA);
    while (pilihan != '4')
        pilihan = menu(arrA);
    puts("Terima kasih...");
    return 0;
}

char menu(int arr[]){
    char pilihan;
    puts("Menu Search");
    puts("1. Sequential Search - unsorted");
    puts("2. Sequential Search - sorted");
    puts("3. Binary Search - sorted");
    printf("Masukkan pilihan anda : ");
    scanf("");
}

void dup(int x[], int y[]){
    for (int i = 0; i < n; i++) {
        x[i] = y[i];
    }
}

void generate(int arr[]) {
    printf("Masukkan n : ");
    scanf("%d", &n);
    getchar();
    puts("Melakukan generate...");
    for (int i = 0; i < n; i++)
        arr[i] = random() / 1000000;
}
