#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s1[] = "This is a sentence";
    char *pblok;
    pblok = (char *) malloc(strlen(s1) + 1);
    if (pblok == NULL)
        printf("Error on malloc");
    else {
        strcpy(pblok,s1);
        printf("s1: %s\n", s1);
        printf("pblok: %s\n", pblok);
    }
    return 0;
}