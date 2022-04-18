#include <stdio.h>
#include <stdlib.h>

int isPrime(int, int, int);

int main(){
    int n;
    int i = 1;
    int faktor = 0;
    puts("Aplikasi bilangan prima");
    printf("Masukkan n : ");
    scanf("%d", &n);
    if (isPrime(i, n, faktor) == 2)
        printf("Bilangan %d adalah bilangan prima\n", n);
    else
        printf("Bilangan %d bukan bilangan prima\n", n);
    return 0;
}

int isPrime(int i, int n, int faktor){
    if (i > n) {
        return faktor;
    } else {
        if (n % i == 0)
            faktor++;
        i++;
        isPrime(i, n, faktor);
    }
}