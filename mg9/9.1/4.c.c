#include <stdio.h>
#include <stdlib.h>

int faktorialTail(int, int);

int main(){
    int n;
    int hasil = 1;
    printf("masukkan n : ");
    scanf("%d", &n);
    hasil = faktorialTail(hasil, n);
    printf("Hasil faktorial n : %d\n", hasil);
    return 0;
}

int faktorialTail(int hasil, int n){
    if (n == 1)
        return hasil;
    hasil = hasil * n;
    n--;
    faktorialTail(hasil, n);
}