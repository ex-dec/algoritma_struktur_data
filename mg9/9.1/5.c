#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int permutasi(int, int);
int kombinasi(int, int);
int faktorial(int );

int main(){
    int n, r, hasil;
    char opsi ;
    puts("Kalkulator permutasi dan kombinasi");
    printf("Masukkan n : ");
    scanf("%d", &n);
    getchar();
    printf("Masukkan r : ");
    scanf("%d", &r);
    getchar();
    if (n < r) {
        puts("Input r kurang tepat");
        exit(0);
    } else if (n <= 0) {
        puts("Input n kurang tepat");
        exit(0);
    } else if (r <= 0) {
        puts("Input r kurang tepat");
        exit(0);
    }
    printf("Ingin menghitung apa (a. permutasi, b. kombinasi) ? ");
    scanf("%c", &opsi);
    if (opsi == 'a')
        hasil = permutasi(n, r);
    else if (opsi == 'b')
        hasil = kombinasi(n, r);
    else {
        puts("Invalid input");
        return 0;
    }
    printf("Hasil perhitungan : %d\n", hasil);
    return 0;
}

int permutasi(int n, int r){
    return faktorial(n) / faktorial (n-r);
}

int kombinasi(int n, int r){
    return faktorial(n) / (faktorial (n-r) * faktorial (r));
}

int faktorial(int n){
    if (n == 1)
        return 1;
    return n * (faktorial(n - 1));
}