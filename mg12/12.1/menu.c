#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 1000000

// Fungsi pilihan menu
char menu(int []);
void dup(int [], int []);
void swap(int *, int *);

// Fungsi general
void generate(int []);

// Fungsi SOrting
void Bubble(int [], char);
void Shell(int [], char);
void Insertion(int [], char);
void Selection(int [], char);
void MergeRekursif(int , int , int [], char );
void Merge(int , int , int , int [], char );
void Quick(int [], int, int , char);
int QuickPartition(int [], int, int, char);

int n;

int main(){
    char opsi = '1';
    int arrA[max];
    puts("Menu Sorting");
    generate(arrA);
    while (opsi != '7')
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
    puts("3. Insertion Sort");
    puts("4. Selection Sort");
    puts("5. Merge Sort");
    puts("6. Quick Sort");
    puts("7. Keluar");
    printf("Pilihan Anda [1/2/3] : ");
    scanf("%c", &opsi);
    getchar();
    if (opsi == '1' || opsi == '2' || opsi == '3' || opsi == '4' || opsi == '5' || opsi == '6') {
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
        Insertion(temp, mode);
        break;
    case '4':
        Selection(temp, mode);
        break;
    case '5':
        MergeRekursif(0, n-1, temp, mode);
        break;
    case '6':
        Quick(temp, 0, n-1, mode);
        break;
    case '7':
        break;
    default:
        puts("Invalid input");
        break;
    }
    if (opsi == '1' || opsi == '2' || opsi == '3' || opsi == '4' || opsi == '5' || opsi == '6') {
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

void Insertion(int arr[], char mode){
    int i;
    int kondisi;
    for (i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        if (mode == '1')
            kondisi = arr[j] > key;
        else
            kondisi = arr[j] < key;
        while (j >= 0 && kondisi) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void Selection(int arr[], char mode){
    int i = 0;
    int kondisi;
    while (i < n - 1) {
        int min = i;
        int j = i + 1;
        while (j < n) {
            if (mode == '1')
                kondisi = arr[j] < arr[min];
            else
                kondisi = arr[j] > arr[min];
            if (kondisi)
                min = j;
            j++;
        }
        swap(&arr[i], &arr[min]);
        i++;
    }
}

void MergeRekursif(int l, int r, int arr[], char mode){
    if (l < r) {
        int med = (l + r) / 2;
        MergeRekursif(l, med, arr, mode);
        MergeRekursif(med + 1, r, arr, mode);
        Merge(l, med, r, arr, mode);
    }
}

void Merge(int l, int med, int r, int arr[], char mode){
    int kiri1 = l, kanan1 = med, kiri2 = med + 1, kanan2 = r;
    int i = l, j;
    int hasil[n];
    int kondisi;
    while (kiri1 <= kanan1 && kiri2 <= kanan2) {
        if (mode == '1')
            kondisi = arr[kiri1] <= arr[kiri2];
        else
            kondisi = arr[kiri1] >= arr[kiri2];
        if (kondisi) {
            hasil[i] = arr[kiri1];
            kiri1++;
        } else {
            hasil[i] = arr[kiri2];
            kiri2++;
        }
        i++;
    }
    while(kiri1 <= kanan1) {
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

void Quick(int arr[], int p, int r, char mode){
    if (p < r) {
        int q = QuickPartition(arr, p, r, mode);
        Quick(arr, p, q, mode);
        Quick(arr, q+1, r, mode);
    }
}

int QuickPartition(int arr[], int p, int r, char mode){
    int i = p;
    int j = r;
    int x = arr[p];
    int kondisi1, kondisi2;
    while (i < j) {
        do {
            if (mode == '1'){
                kondisi1 = arr[i] < x;
                kondisi2 = arr[j] > x;
            } else {
                kondisi1 = arr[i] > x;
                kondisi2 = arr[j] < x;
            }
            if (kondisi1)
                i++;
            if (kondisi2)
                j--;
        } while (kondisi1 || kondisi2);
        if (i < j) {
            swap(&arr[i], &arr[j]);
            j--;

        } else
            return j;
    }
}

void swap(int *a, int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}