#include <stdio.h>
#include <stdlib.h>

int faktorial(int);

int main(){
    int n;
    int hasil = 1;
    printf("masukkan n : ");
    scanf("%d", &n);
    hasil = faktorial(n);
    printf("Hasil faktorial n : %d\n", hasil);
    return 0;
}

int faktorial(int n){
    if (n == 1)
        return 1;
    return n * (faktorial(n - 1));
}