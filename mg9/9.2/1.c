#include <stdio.h>
#include <stdlib.h>

int fpbRekursi(int, int);

int main(){
    int m, n, i;
    int hasil = 1;
    puts("FPB Rekursi");
    printf("Masukkan m : ");
    scanf("%d", &m);
    getchar();
    printf("Masukkan n : ");
    scanf("%d", &n);
    getchar();
    printf("%d %d\n", m, n);
    hasil = fpbRekursi(m, n);
    printf("FPB dari m dan n : %d\n", hasil);
    return 0;
}

int fpbRekursi(int m, int n){
    if (m % n == 0) {
        return n;
    } else
        fpbRekursi(n, m % n);
}