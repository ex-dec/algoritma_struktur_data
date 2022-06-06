#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 100

char menu(char);
void fiboIterasi(int [],int);
void fiboRekursi(int [], int, int);
void cetak(int [], int);

clock_t t1, t2;
int a[max];

int main(){
    char opsi = '1';
    puts("Program Menu Fibonacci\n");
    while (opsi != '3')
        opsi = menu(opsi);
    puts("Terima kasih...");
    return 0;
}

char menu(char opsi){
    int n;
    double waktuKomputasi;
    puts("Menu Fibonacci");
    puts("1. Iterasi");
    puts("2. Rekursi");
    puts("3. Keluar");
    printf("Masukkan pilihan anda : ");
    scanf("%c", &opsi);
    getchar();
    if (opsi == '1'|| opsi == '2') {
        printf("Masukkan n : ");
        scanf("%d", &n);
        getchar();
        t1 = clock();
    }
    switch (opsi) {
    case '1':
        fiboIterasi(a,n);
        break;
    case '2':
        fiboRekursi(a,0,n);
        break;
    case '3':
        break;
    default:
        puts("Invalid Option");
        break;
    }
    if (opsi == '1'|| opsi == '2') {
        t2 = clock();
        waktuKomputasi = ((double) (t2 - t1))/CLOCKS_PER_SEC;
        cetak(a, n);
        printf("waktu komputasi : %f\n", waktuKomputasi);
    }
    return opsi;
}

void fiboIterasi(int a[], int n){
    for (int i = 0; i < n; i++) {
        if (i == 0)
            a[i] = 0;
        else if (i == 1)
            a[i] = 1;
        else
            a[i] = a[i-1] + a[i-2];
    }    
}

void fiboRekursi(int a[], int i, int n){
    if (i == n)
        return;
    else {
        if (i == 0) {
            a[i] = 0;
            i++;
            fiboRekursi(a, i, n);
        } else if (i == 1) {
            a[i] = 1;
            i++;
            fiboRekursi(a, i, n);
        } else {
            a[i] = a[i-1] + a[i-2];
            i++;
            fiboRekursi(a, i, n);
        }
    }
}

void cetak(int a[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    puts("");
}