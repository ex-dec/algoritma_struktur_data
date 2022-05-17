#include <stdio.h>
#include <stdlib.h>
#define max 1000000

// Fungsi pilihan menu
char menu(int []);
void dup(int [], int []);

// Fungsi general
void generate(int []);
void swap(int *, int *);

int main(){
    char pilihan = '0';
    int arrA[max];
    generate(arrA);
    while (pilihan != '4')
        pilihan = menu(arrA);
    puts("Terima kasih...");
    return 0;
}

char menu(int arr[]){

}