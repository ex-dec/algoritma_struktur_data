#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char menu(char);
long long int iterasi(int);
long long int rekursi(int);
long long int rekursiTail(long long int, int);
clock_t t1, t2;

int main(){
    char opsi = '1';
    puts("Program variasi Faktorial\n");
    while (opsi != '4')
        opsi = menu(opsi);
    puts("Terima kasih...");
    return 0;
}

char menu(char opsi){
    int n;
    long long int hasil = 1;
    double waktuKomputasi;
    puts("Menu Faktorial");
    puts("1. Iterasi");
    puts("2. Rekursi");
    puts("3. Rekursi Tail");
    puts("4. Keluar");
    printf("Masukkan pilihan anda : ");
    scanf("%c", &opsi);
    getchar();
    if (opsi == '1'|| opsi == '2' || opsi == '3') {
        printf("Masukkan n : ");
        scanf("%d", &n);
        getchar();
        t1 = clock();
    }
    switch (opsi) {
    case '1':
        hasil = iterasi(n);
        break;
    case '2':
        hasil = rekursi(n);
        break;
    case '3':
        hasil = rekursiTail(hasil, n);
        break;
    case '4':
        break;
    default:
        puts("Invalid Option");
        break;
    }
    if (opsi == '1'|| opsi == '2' || opsi == '3') {
        t2 = clock();
        waktuKomputasi = ((double) (t2 - t1)) / CLOCKS_PER_SEC;
        printf("hasil faktorial : %lld\n", hasil);
        printf("waktu komputasi : %f\n", waktuKomputasi);
    }
    return opsi;
}

long long int iterasi(int n){
    long long int hasil = 1;
    for (; n > 0; n--)
        hasil = hasil * n;
    return hasil;
}

long long int rekursi(int n){
    if (n == 1)
        return 1;
    return n * (rekursi(n - 1));
}

long long int rekursiTail(long long int hasil, int n){
    if (n == 1)
        return hasil;
    hasil = hasil * n;
    n--;
    rekursiTail(hasil, n);
}