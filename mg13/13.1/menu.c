#include <stdio.h>
#include <stdlib.h>
#define max 1000000

// Fungsi pilihan menu
char menu(int []);
void dup(int [], int []);

// Fungsi general
void generate(int []);
void swap(int *, int *);

void Shell(int []);
void swap(int *, int *);

int n;
clock_t start, end;

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
    int cari;
    double waktu;
    int temp[n];
    dup(temp, arr);
    puts("Menu Search");
    puts("1. Sequential Search - unsorted");
    puts("2. Sequential Search - sorted");
    puts("3. Binary Search - sorted");
    puts("4. Keluar");
    printf("Masukkan pilihan anda : ");
    scanf("%d", &pilihan);
    getchar();
    if (pilihan != '1' || pilihan != '2' || pilihan != '3') {
        printf("Masukkan data yang ingin dicari : ");
        scanf("%d", &cari);
    }
    switch() {
    case '1':
        SeqSearchUnsort(arr, cari);
        break;
    case '2':
        SeqSearch(arr, cari);
        break;
    case '3':
        BinSearch(arr, cari);
        break;
    case '4':
        break;
    default:
        printf("Pilihan tidak ada");
        break;
    }
    if (pilihan != '1' || pilihan != '2' || pilihan != '3') {
        end = clock();
        waktu = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Waktu komputasi : %lf\n", waktu);
    }
    return pilihan;
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

void SeqSearchUnsort(int arr[], int cari){
    int konfirm = 0;
    int i = 0;
    start = clock();
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

void SeqSearch(int arr[], int cari){
    int konfirm = 0;
    int i = 0;
    Shell(arr);
    start = clock();
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

void BinSearch(int arr[], int cari){
    int L = 0;
    int R = n - 1;
    int konfirm = 0;
    int M;
    Shell(arr);
    start = clock();
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