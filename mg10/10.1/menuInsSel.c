#include <stdio.h>
#include <stdlib.h>
#define max 100

char menu(int []);
// void generate(int []);
void Insertion(int [], char);
void Selection(int [], char);
void tampil(int []);
void dup(int [], int []);

int n = 10;

int main(){
    char opsi = '1';
    int arrA[] = {3,10,4,6,8,9,7,2,1,5};
    // int arrA[max];
    puts("Menu Sorting");
    // generate(arrA);
    while (opsi != '3')
        opsi = menu(arrA);
    puts("Terima kasih...");
    return 0;
}

char menu(int arr[]){
    int temp[n];
    char opsi;
    char mode;
    dup(temp, arr);
    puts("Menu Metode Sorting");
    puts("1. Insertion Sort");
    puts("2. Selection Sort");
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
        if (mode != '2')
            mode = '1';
    }
    switch (opsi) {
    case '1':
        Insertion(temp, mode);
        break;
    case '2':
        Selection(temp, mode);
        break;
    case '3':
        break;
    default:
        puts("Invalid input");
        break;
    }
    if (opsi == '1' || opsi == '2'){
        puts("sebelum");
        tampil(arr);
        puts("sesudah");
        tampil(temp);
    }
    return opsi;
}

void dup(int x[], int y[]){
    for (int i = 0; i < n; i++) {
        x[i] = y[i];
    }
}

// void generate(int arr[]) {
    // printf("Masukkan n : ");
    // scanf("%d", &n);
    // getchar();
    // n = 10;
    // puts("Melakukan generate...");
    // arr[] = {3,10,4,6,8,9,7,2,1,5};
    // for (int i = 0; i < n; i++)
    //     arr[i] = random();
// }

void Insertion(int arr[], char mode){
    int i = 1;
    int kondisi;
    while (i < n) {
        int key = arr[i];
        int j = i - 1;
        if (mode == '1'){
            while (j >= 0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
        } else {
            while (j >= 0 && arr[j] < key) {
                arr[j+1] = arr[j];
                j--;
            }
        }
        arr[j+1] = key;
        i++;
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
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        i++;
    }
}

void tampil (int arr[]){
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    puts("");
}