#include <stdio.h>
#include <stdlib.h>

typedef char typeName;
typedef struct simpul Node;
struct simpul{
    typeName data;
    Node *next;
};

Node *tambah, *hapus;

void inisial(Node *);

// pengecekan stack
int empty(Node *);

// operasi stack
void push(Node *, typeName);
typeName pop(Node *);

// Fungsi dari SLL
void alokasi();
void bebas();

void masukan(Node *);
void keluaran(Node *);
void show(Node *);
char menu(char,Node *);

int main(){
    char pilih = '0';
    Node *s;
    inisial(s);
    puts("Stack Array");
    while (pilih != '4')
        pilih = menu(pilih, s);
    puts("Terima kasih....");
    return 0;
}

char menu(char opsi, Node *s){
    puts("Menu");
    puts("1. Mengisi Stack (PUSH)");
    puts("2. Mengambil isi Stack (POP)");
    puts("3. Menampilkan isi Stack -> LIFO");
    puts("4. Keluar");
    printf("Masukkan pilihan anda : ");
    fflush(stdin);
    scanf("%c", &opsi);
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

void inisial(Node *s){
    s = NULL;
}

int empty(Node *s){
    return(s == NULL);
}

void push(Node *s, typeName x){
    alokasi();
    tambah->data = x;
    if (s != NULL)
        tambah->next = s;
    s = tambah;
}

typeName pop(Node *s){
    typeName temp;
    if (empty(s)){
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

void masukan(Node *s){
    typeName x;
    printf("nilai yang akan disimpan : ");
    fflush(stdin);
    x = getchar();
    push(s, x);
}

void keluaran(Node *s){
    typeName x;
    x = pop(s);
    printf("%c\n", x);
}

void show(Node *s){
    Node *tampil = s;
    if (empty(s))
        puts("stack kosong");
    else {
        puts("Isi dari stack");
        while (tampil != NULL){
            printf("%c\n", tampil->data);
            tampil = tampil->next;
        }
    }
}