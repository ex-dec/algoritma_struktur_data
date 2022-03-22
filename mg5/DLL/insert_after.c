#include <stdio.h>
#include <stdlib.h>

typedef struct simpul DNode;
struct simpul{
    int data;
    DNode *next, *prev;
};

DNode *Head = NULL, *tambah, *tail, *after;

void insertAkhir();
void input();
void alokasi();
void show();
void masuk();
void inputAfter();
void insertAfter(int);

int main() {
    puts("Double Linked List - Insert akhir");
    input();
    show();
    inputAfter();
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

void inputAfter(){
    int key;
    alokasi();
    printf("nilai yang akan disimpan : ");
    scanf("%d", &tambah->data);
    printf("Disisipkan setelah data ke berapa? ");
    scanf("%d", &key);
    insertAfter(key);
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

void insertAfter(int key){
    after = Head;
    while (after->data != key) {
        if (after->next == NULL) {
            puts("data tidak ditemukan");
            return;
        } else {
            after = after->next;
        }
    }
    tambah->next = after->next;
    tambah->prev = after;
    if (after->next != NULL)
        after->next->prev = tambah;
    after->next = tambah;
}

void show(){
    DNode *tampil = Head;
    puts("DLL yang sudah dimasukkan :");
    while (tampil != NULL){
        printf("%d\n", tampil->data);
        tampil = tampil->next;
    }
}