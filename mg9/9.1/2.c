#include <stdio.h>
#include <stdlib.h>

int showForward(int, int);

int main(){
    int n;
    puts("Tampilkan dari terkecil");
    printf("Masukkan n : ");
    scanf("%d", &n);
    showForward(0, n);
    return 0;
}

int showForward(int i, int n){
    if (i > n) {
        return n;
    }
    printf("%d\n", i);
    i++;
    showForward(i, n);
}