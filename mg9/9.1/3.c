#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int balik(char [], int);

int main(){
    char kata[20];
    int length;
    puts("Balik kata");
    printf("input kata : ");
    fgets(kata, sizeof(kata), stdin);
    printf("Kata sebenarnya : %s", kata);
    length = strlen(kata);
    printf("Hasil kebalikan : ");
    balik(kata, length);
    puts("");
    return 0;
}

int balik(char kata[], int length){
    if (length < 0)
        return length;
    printf("%c", kata[length]);
    length--;
    balik(kata, length);
}