#include <stdio.h>
#include <stdlib.h>
#define max 20

typedef char typeName;
typedef struct {
    typeName data[max];
    int count;
} stack;

int bil;

// inisialisasi stack
void inisial(stack *);

// pengecekan stack
int full(stack *);
int empty(stack *);

// operasi stack
void push(stack *, typeName);
typeName pop(stack *);

// menu
char menu(char, stack *);
void input();
void biner(stack *, int);
void oktal(stack *, int);
void hexa(stack *, int);

void show(stack *);


int main(){
    stack s;
    char pilih = '0';
    puts("Konversi Bilangan Desimal");
    input();
    while (pilih != '4')
        pilih = menu(pilih, &s);
    puts("Terima kasih....");
    return 0;
}

char menu(char opsi, stack *s){
    int temp = bil;
    inisial(s);
    puts("Menu konversi");
    puts("1. Biner");
    puts("2. Oktal");
    puts("3. Heksa Desimal");
    puts("4. Keluar");
    printf("Masukkan pilihan anda : ");
    scanf("%c", &opsi);
    getchar();
    switch (opsi) {
    case '1':
        biner(s, temp);
        break;
    case '2':
        oktal(s, temp);
        break;
    case '3':
        hexa(s, temp);
        break;
    case '4':
        break;
    default:
        puts("Opsi yang anda masukkan salah");
        break;
    }
    puts("");
    if (opsi == '1' || opsi == '2' || opsi == '3')
        show(s);
    puts("");
    return opsi;
}

void input(){
    printf("Masukkan bil desimal yang akan dikonversi : ");
    scanf("%d", &bil);
    getchar();
}

void biner(stack *s, int temp){
    while (temp != 0) {
        if (temp % 2 == 1) {
            push(s, '1');
        } else
            push(s, '0');
        temp = temp / 2;
    }
}

void oktal(stack *s, int temp){
    while (temp != 0) {
        if (temp % 8 == 1)
            push(s, '1');
        else if (temp % 8 == 2)
            push(s, '2');
        else if (temp % 8 == 3)
            push(s, '3');
        else if (temp % 8 == 4)
            push(s, '4');
        else if (temp % 8 == 5)
            push(s, '5');
        else if (temp % 8 == 6)
            push(s, '6');
        else if (temp % 8 == 7)
            push(s, '7');
        else
            push(s, '0');
        temp = temp / 8;
    }
}

void hexa(stack *s, int temp){
    while (temp != 0) {
        if (temp % 16 == 1)
            push(s, '1');
        else if (temp % 16 == 2)
            push(s, '2');
        else if (temp % 16 == 3)
            push(s, '3');
        else if (temp % 16 == 4)
            push(s, '4');
        else if (temp % 16 == 5)
            push(s, '5');
        else if (temp % 16 == 6)
            push(s, '6');
        else if (temp % 16 == 7)
            push(s, '7');
        else if (temp % 16 == 8)
            push(s, '8');
        else if (temp % 16 == 9)
            push(s, '9');
        else if (temp % 16 == 10)
            push(s, 'A');
        else if (temp % 16 == 11)
            push(s, 'B');
        else if (temp % 16 == 12)
            push(s, 'C');
        else if (temp % 16 == 13)
            push(s, 'D');
        else if (temp % 16 == 14)
            push(s, 'E');
        else if (temp % 16 == 15)
            push(s, 'F');
        else
            push(s, '0');
        temp = temp / 16;
    }
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

void show(stack *s){
    printf("Hasil konversi : ");
    for (int i = s->count; i > 0; i--)
        printf("%c", s->data[i]);
    puts("");
}