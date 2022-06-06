#include <stdio.h>
#include <stdlib.h>
#define max 100

void fiboIterasi(int [],int);
void cetak(int [], int);

int main(){
    int n;
    int a[max];
    puts("Fibonacci Iterasi");
    printf("Masukkan n : ");
    scanf("%d", &n);
    fiboIterasi(a,n);
    cetak(a, n);
    return 0;
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

void cetak(int a[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}