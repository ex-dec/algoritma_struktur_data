#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 30

typedef char typeName;
typedef struct {
    typeName data[max];
    int count;
} stack;

void inisial(stack *);

// pengecekan stack
int full(stack *);
int empty(stack *);

// operasi stack
void push(stack *, typeName);
typeName pop(stack *);

void masukan(stack *);
void keluaran(stack *);
void show(stack *);
char menu(stack *);
int palindrom(stack *, char []);

// void deleteEnter(char []);

int main(){
    char confirm = 'y';
    stack tampung;
    puts("Mengecek palindrom\n");
    while (confirm != 't')
        confirm = menu(&tampung);
    puts("Terima kasih...");
    return 0;
}

char menu(stack *s){
    char confirm;
    char temp[max];
    inisial(s);
    printf("Masukkan kata yang dicek (maksimal 30 karakter) : ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = 0;
    fflush(stdin);
    if (palindrom(s, temp))
        printf("%s adalah palindrom", temp);
    else
        printf("%s bukan palindrom", temp);
    puts("\n");
    printf("Lagi (y/t)? ");
    scanf("%c", &confirm);
    getchar();
    puts("");
    return confirm;
}

int palindrom(stack *s, char temp[]){
    int lenght = strlen(temp);
    int i;
    for (i = 0; i < lenght; i++)
        push(s, temp[i]);
    i = 0;
    while (!empty(s))
        if (pop(s) != temp[i])
            return 0;
        else
            i++;
    return 1;
}

void inisial(stack *s){
    s->count = 0;
}

int full(stack *s){
    return(s->count == max);
}

int empty(stack *s){
    return(s->count == 0);
}

void push(stack *s, typeName x){
    if(full(s))
        puts("Stack penuh");
    else {
        s->count++;
        s->data[s->count] = x;
    }
}

typeName pop(stack *s){
    typeName temp;
    if (empty(s)){
        puts("Stack kosong");
        return ' ';
    } else {
        temp = s->data[s->count];
        s->count--;
        return temp;
    }
}