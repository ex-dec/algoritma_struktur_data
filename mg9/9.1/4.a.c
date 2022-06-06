#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int hasil = 1;
    printf("masukkan n : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        hasil = hasil * i;
    printf("Hasil faktorial n : %d\n", hasil);
    return 0;
}