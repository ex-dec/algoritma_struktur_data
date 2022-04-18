#include <stdio.h>
#include <stdlib.h>
int showReverse(int);

int main(){
    int n;
    puts("Tampilkan dari terbesar");
    printf("Masukkan n : ");
    scanf("%d", &n);
    showReverse(n);
    return 0;
}

/* 
    rekursi yang digunakan adalah rekursi tail. karena tidak membutuhkan return khusus dari proses yang sudah berjalan
*/

int showReverse(int n){
    if (n < 0) {
        return n;
    }
    printf("%d\n", n);
    n--;
    showReverse(n);
}