#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 20

typedef char typeName;
typedef struct {
    typeName data[max];
    int count;
} stack;

// Inisialisasi stack
void inisial(stack *);

// pengecekan stack
int full(stack *);
int empty(stack *);

// operasi stack
void push(stack *, typeName);
typeName pop(stack *);

int derajat(typeName);
void operasi(stack *, typeName []);
char menu(char,stack *);

int main(){
    char pilih = 'y';
    stack s;
    puts("Mengubah Notasi Infix menjadi Postfix");
    puts("Dengan Memanfaatkan struktur stack\n");
    while (pilih != 't')
        pilih = menu(pilih, &s);
    puts("Terima kasih....");
    return 0;
}

char menu(char opsi, stack *s){
    typeName x[max];
    inisial(s);
    fflush(stdin);
    printf("Masukkan ekspresi dalam bentuk notasi infix : ");
    fgets(x, sizeof(x), stdin);
    operasi(s, x);
    printf("\nLagi (y/t)? ");
    opsi = getchar();
    fflush(stdin);
    return opsi;
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

int derajat(typeName x) { 
    if (x == '(') 
        return 0; 
    else if (x == '+' || x == '-') 
        return 1; 
    else if (x == '*' || x == '/') 
        return 2; 
    else if (x == '^') 
        return 3; 
    else
        return -1;
}

void operasi(stack *s, typeName x[]){
    int leght = strlen(x)-1;
    typeName temp;
    printf("Ungkapan postfixnya : ");
    for (int i = 0; i < leght; i++) {
        switch (x[i]) {
        case '(':
            push(s, x[i]);
            break;
        case '1': case '2': case '3': case '4': case '5' : case '6' : case '7' : case '8' : case '9' : case '0' :
            printf("%c", x[i]);
            break;
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
            if ( empty(s) || derajat(x[i]) > derajat(s->data[s->count])) 
                push(s, x[i]);
            else {
                do {
                    temp = pop(s); 
                    printf("%c", temp); 
                } while (derajat(x[i]) < derajat(s->data[s->count])); 
                push(s, x[i]);
            }
            break;
        case ')':
            while (s->data[s->count] != '(') {
                temp = pop(s);
                printf("%c", temp);
            }
            pop(s);
            break;
        default:
            break;
        }
    }
    while (!empty(s)) {
        temp = pop(s);
        printf("%c", temp);
    }
}