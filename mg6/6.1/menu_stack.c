#include <stdio.h>
#include <stdlib.h>
#define max 5

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
char menu(char,stack *);

int main(){
    char pilih = '0';
    stack s;
    inisial(&s);
    puts("Stack Array");
    while (pilih != '4')
        pilih = menu(pilih, &s);
    puts("Terima kasih....");
    return 0;
}

char menu(char opsi, stack *s){
    puts("Menu");
    puts("1. Mengisi Stack (PUSH)");
    puts("2. Mengambil isi Stack (POP)");
    puts("3. Menampilkan isi Stack -> LIFO");
    puts("4. Keluar");
    printf("Masukkan pilihan anda : ");
    scanf("%c", &opsi);
    getchar();
    switch (opsi) {
    case '1':
        masukan(s);
        break;
    case '2':
        keluaran(s);
        break;
    case '3':
        show(s);
        break;
    case '4':
        break;
    default:
        puts("Opsi yang anda masukkan salah");
        break;
    }
    puts("");
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

void masukan(stack *s){
    typeName x;
    printf("nilai yang akan disimpan : ");
    scanf("%c", &x);
    getchar();
    push(s, x);
}

void keluaran(stack *s){
    typeName x;
    x = pop(s);
    printf("%c\n", x);
}

void show(stack *s){
    if (empty(s))
        puts("stack kosong");
    else {
        puts("Isi dari stack");
        for (int i = s->count; i > 0; i--)
            printf("%c\n", s->data[i]);
    }
}