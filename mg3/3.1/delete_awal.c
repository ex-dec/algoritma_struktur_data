#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};

Node *Head = NULL, *tambah, *tail, *hapus;
void insertAkhir();
void deleteAwal();
void input();
void delete();
void alokasi();
void show();
void bebas();

int main() {
    puts("Single Linked List - Insert akhir");
    input();
    show();
    delete();
    puts("Terima kasih....");
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
        fflush(stdin);
    } while (confirm == 'y' || confirm == 'Y');
}

void delete(){
    while (Head != NULL) {
        puts("Menghapus data posisi awal");
        deleteAwal();
        show();
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

void insertAkhir(){
    tail = Head;
    if (tail == NULL)
        Head = tambah;
    else {
        if(tail->next != NULL)
            tail = tail->next;
        tail->next = tambah;
    }
}

void deleteAwal(){
    hapus = Head;
    if (Head->next == NULL)
        Head = NULL;
    else
        Head = Head->next;
    bebas();
}

void bebas(){
    free(hapus);
    hapus = NULL;
}

void show(){
    Node *tampil = Head;
    puts("Isi dari SLL :");
    if (Head != NULL) {
        while (tampil != NULL) {
            printf("%d\n", tampil->data);
            tampil = tampil->next;
        }
    } else
        puts("Kosong");
}