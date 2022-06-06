#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char a[] = "uwu";
    char b[] = "uwu";
    int hasil = strcasecmp(a, b);
    printf("hasil tes %d\n", hasil);
    return 0;
}