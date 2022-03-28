#include <stdio.h>
#include <stdlib.h>

typedef char typeName;
typedef struct simpul Node;
struct simpul{
    typeName data;
    Node *next;
};

Node *s, *tambah, *hapus;

void inisial();

// pengecekan stack
int empty();

// operasi stack
void push(typeName);
typeName pop();

// Fungsi dari SLL
void alokasi();
void bebas();

void masukan();
void keluaran();
void show();
char menu(char);

int main(){
    char pilih = '0';
    inisial();
    puts("Stack SLL");
    while (pilih != '4')
        pilih = menu(pilih);
    puts("Terima kasih....");
    return 0;
}

char menu(char opsi){
    puts("Menu");
    puts("1. Mengisi Stack (PUSH)");
    puts("2. Mengambil isi Stack (POP)");
    puts("3. Menampilkan isi Stack -> LIFO");
    puts("4. Keluar");
    printf("Masukkan pilihan anda : ");
    opsi = getchar();
    fflush(stdin);
    switch (opsi) {
    case '1':
        masukan();
        break;
    case '2':
        keluaran();
        break;
    case '3':
        show();
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

void inisial(){
    s = NULL;
}

int empty(){
    return s == NULL;
}

void push(typeName x){
    alokasi();
    tambah->data = x;
    if (s != NULL)
        tambah->next = s;
    s = tambah;
}

typeName pop(){
    typeName temp;
    if (s == NULL){
        puts("Stack kosong");
        return ' ';
    } else {
        temp = s->data;
        hapus = s;
        if (s->next == NULL)
            s = NULL;
        else
            s = s->next;
        bebas();
        return temp;
    }
}

void alokasi(){
    tambah = (Node *) malloc(sizeof(Node));
    if (tambah == NULL) {
        puts("Alokasi gagal!!!");
        exit(0);
    } else
        tambah->next = NULL;
}

void bebas(){
    free(hapus);
    hapus = NULL;
}

void masukan(){
    typeName x;
    printf("nilai yang akan disimpan : ");
    x = getchar();
    fflush(stdin);
    push(x);
}

void keluaran(){
    typeName x;
    x = pop(s);
    printf("%c\n", x);
}

void show(){
    Node *tampil = s;
    if (s == NULL)
        puts("stack kosong");
    else {
        puts("Isi dari stack");
        while (tampil != NULL){
            printf("%c\n", tampil->data);
            tampil = tampil->next;
        }
    }
}