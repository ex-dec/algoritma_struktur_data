#include <stdio.h>
#include <stdlib.h>

void fiboRekursi(int [], int, int);
void cetak(int [], int);

int main(){
    int n;
    int i = 0;
    puts("Fibonacci rekursi");
    printf("Masukkan n : ");
    scanf("%d", &n);
    int a[n];
    fiboRekursi(a,i,n);
    cetak(a, n);
    return 0;
}

void fiboRekursi(int a[], int i, int n){
    if (i == n)
        return;
    else {
        if (i == 0) {
            a[i] = 0;
            i++;
            fiboRekursi(a, i, n);
        } else if (i == 1) {
            a[i] = 1;
            i++;
            fiboRekursi(a, i, n);
        } else {
            a[i] = a[i-1] + a[i-2];
            i++;
            fiboRekursi(a, i, n);
        }
    }
}

void cetak(int a[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}