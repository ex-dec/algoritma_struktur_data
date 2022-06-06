#include <stdio.h>
#include <stdlib.h>

typedef struct simpul DNode;
struct simpul{
    int data;
    DNode *next, *prev;
};

DNode *Head = NULL, *tambah;
void insertAwal();
void input();
void alokasi();
void show();
void masuk();

int main() {
    puts("Double Linked List - Insert awal");
    input();
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
        insertAwal();
        printf("Lagi (y/t)? ");
        getchar();
        scanf("%c", &confirm);
    } while (confirm == 'y' || confirm == 'Y');
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
    if (Head != NULL){
        tambah->next = Head;
        Head->prev = tambah;
    }
    Head = tambah;
}

void show(){
    DNode *tampil = Head;
    puts("DLL yang sudah dimasukkan :");
    while (tampil != NULL){
        printf("%d\n", tampil->data);
        tampil = tampil->next;
    }
}