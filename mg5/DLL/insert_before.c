#include <stdio.h>
#include <stdlib.h>

typedef struct simpul DNode;
struct simpul{
    int data;
    DNode *next, *prev;
};

DNode *Head = NULL, *tambah, *tail, *bef;

void insertAkhir();
void insertAwal();
void input();
void alokasi();
void show();
void masuk();
void inputBefore();
void insertBefore(int);

int main() {
    puts("Double Linked List - Insert akhir");
    input();
    show();
    inputBefore();
    show();
    return 0;
}

void input(){
    char confirm;
    do
    {
        alokasi();
        printf("nilai yang akan disimpan : ");
        scanf("%d", &tambah->data);
        insertAkhir();
        printf("Lagi (y/t)? ");
        getchar();
        scanf("%c", &confirm);
    } while (confirm == 'y' || confirm == 'Y');
}

void inputBefore(){
    int key;
    alokasi();
    printf("nilai yang akan disimpan : ");
    scanf("%d", &tambah->data);
    printf("Disisipkan sebelum data ke berapa? ");
    scanf("%d", &key);
    insertBefore(key);
}

void alokasi(){
    tambah = (DNode *) malloc(sizeof(DNode));
    if (tambah == NULL) {
        puts("Alokasi gagal!!!");
        exit(0);
    } else {
        tambah->next = NULL;
        tambah->prev = NULL;
    }
}

void insertAwal(){
    if (Head != NULL)
        tambah->next = Head;
    Head = tambah;
}

void insertAkhir(){
    tail = Head;
    if (Head == NULL)
        Head = tambah;
    else {
        while(tail->next != NULL)
            tail = tail->next;
        tambah->prev = tail;
        tail->next = tambah;
    }
}

void insertBefore(int key){
    if (Head->data == key) {
        insertAwal();
        return;
    } else {
        bef = Head;
        do {
            if (bef->next == NULL) {
                puts("data tidak ditemukan");
                return;
            } else
                bef = bef->next;
        } while (bef->data != key);
    }
    tambah->next = bef;
    tambah->prev = bef->prev;
    bef->prev->next = tambah;
    bef->prev = tambah;
}

void show(){
    DNode *tampil = Head;
    puts("DLL yang sudah dimasukkan :");
    while (tampil != NULL){
        printf("%d\n", tampil->data);
        tampil = tampil->next;
    }
}