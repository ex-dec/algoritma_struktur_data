#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};

Node *Head = NULL, *tambah, *tail, *bef, *pbef;

void insertAkhir();
void insertAwal();
void input();
void alokasi();
void show();
void masuk();
void inputBefore();
void insertBefore(int);

int main() {
    puts("Single Linked List - Insert akhir");
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
    tambah = (Node *) malloc(sizeof(Node));
    if (tambah == NULL) {
        puts("Alokasi gagal!!!");
        exit(0);
    } else
        tambah->next = NULL;
}

void insertAwal(){
    if (Head != NULL)
        tambah->next = Head;
    Head = tambah;
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

void insertBefore(int key){
    if (Head->data == key) {
        insertAwal();
        return;
    } else {
        bef = Head;
        do {
            pbef = bef;
            if (bef->next == NULL) {
                puts("data tidak ditemukan");
                return;
            } else
                bef = bef->next;
        } while (bef->data != key);
    }
    tambah->next = bef;
    pbef->next = tambah;
}

void show(){
    Node *tampil = Head;
    puts("SLL yang sudah dimasukkan :");
    while (tampil != NULL){
        printf("%d\n", tampil->data);
        tampil = tampil->next;
    }
}