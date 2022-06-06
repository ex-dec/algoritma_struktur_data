#include <stdio.h>
#include <stdlib.h>
#define max 20

typedef struct siswa Node;
struct siswa{
    int no;
    char nama[max];
    float nilai;
    Node *next;
};

Node *Head = NULL, *tambah;
void insertAwal();
void input();
void alokasi();
void show();
void masuk();

int main() {
    puts("Single Linked List untuk aplikasi di awal");
    input();
    show();
    return 0;
}

void input(){
    char confirm;
    do
    {
        alokasi();
        printf("No\t: ");
        scanf("%d", &tambah->no);
        printf("Nama\t: ");
        getchar();
        gets(tambah->nama);
        fflush(stdin);
        printf("Nilai\t: ");
        scanf("%f", &tambah->nilai);
        insertAwal();
        printf("Ada data lagi (y/t)? ");
        getchar();
        scanf("%c", &confirm);
    } while (confirm == 'y' || confirm == 'Y');
}

void alokasi(){
    tambah = (Node *) malloc(sizeof(Node));
    tambah->next = NULL;
}

void insertAwal(){
    if (Head != NULL)
        tambah->next = Head;
    Head = tambah;
}

void show(){
    Node *tampil = Head;
    puts("Data yang telah diinputkan :");
    puts("No\tNama\t\t\tNilai");
    while (tampil != NULL){
        printf("%d\t%-20s\t%.2f\n", tampil->no, tampil->nama, tampil->nilai);
        tampil = tampil->next;
    }
}