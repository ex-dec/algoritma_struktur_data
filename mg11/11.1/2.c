#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 1000000

char menu(int []);
void generate(int []);
void Bubble(int [], char);
void Shell(int [], char);
void dup(int [], int []);
void swap(int *, int *);
void resetCSM();

int n;

int main(){
    char opsi = '1';
    int arrA[max];
    puts("Menu Sorting");
    generate(arrA);
    while (opsi != '3')
        opsi = menu(arrA);
    puts("Terima kasih...");
    return 0;
}

char menu(int arr[]){
    int temp[n];
    char opsi;
    char mode;
    clock_t start, end;
    double waktu;
    dup(temp, arr);
    puts("Menu Metode Sorting");
    puts("1. Bubble Sort");
    puts("2. Shell Sort");
    puts("3. Keluar");
    printf("Pilihan Anda [1/2/3] : ");
    scanf("%c", &opsi);
    getchar();
    if (opsi == '1' || opsi == '2') {
        puts("Mode sort");
        puts("1. Ascending");
        puts("2. Descending");
        printf("Masukkan pilihan anda [1/2]: ");
        scanf("%c", &mode);
        getchar();
        start = clock();
        if (mode != '2')
            mode = '1';
    }
    switch (opsi) {
    case '1':
        Bubble(temp, mode);
        break;
    case '2':
        Shell(temp, mode);
        break;
    case '3':
        break;
    default:
        puts("Invalid input");
        break;
    }
    if (opsi == '1' || opsi == '2'){
        puts("Pengurutan selesai");
        end = clock();
        waktu = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Waktu komputasi : %lf\n", waktu);
    }
    return opsi;
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

void Bubble(int arr[], char mode){
    int konfirm = 1;
    int posAkhir = n-2;
    int i = 0;
    int kondisi;
    while (i <= posAkhir && konfirm) {
        konfirm = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (mode == '1')
                kondisi = arr[j] > arr[j+1];
            else
                kondisi = arr[j] < arr[j+1];
            if (kondisi) {
                swap(&arr[j], &arr[j+1]);
                konfirm = 1;
            }
        }
        i++;
    }
}

void Shell(int arr[], char mode){
    int key = n, konfirm, kondisi;
    while (key > 1) {
        key = key / 2;
        konfirm = 1;
        while (konfirm) {
            konfirm = 0;
            for (int i = 0; i < n-key; i++) {
                if (mode == '1')
                    kondisi = arr[i] > arr[i+key];
                else 
                    kondisi = arr[i] < arr[i+key];
                if (kondisi) {
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