#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};

Node *Head = NULL, *tambah, *tail, *after;

void insertAkhir();
void input();
void alokasi();
void show();
void masuk();
void inputAfter();
void insertAfter(int);

int main() {
    puts("Single Linked List - Insert akhir");
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
        while(tail->next != NULL)
            tail = tail->next;
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
    after->next = tambah;
}

void show(){
    Node *tampil = Head;
    puts("SLL yang sudah dimasukkan :");
    while (tampil != NULL){
        printf("%d\n", tampil->data);
        tampil = tampil->next;
    }
}