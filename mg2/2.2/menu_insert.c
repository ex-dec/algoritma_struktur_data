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

Node *Head = NULL, *tambah, *tail, *after, *bef, *pbef;
void insertAwal();
void insertAkhir();
void insertAfter();
void insertBefore();
void input();
void alokasi();
void show();
void masuk();
char menu(char);

int main() {
    char pilih = '0';
    puts("Single Linked List - Operasi Insert");
    while (pilih != '5')
        pilih = menu(pilih);
    puts("Terima kasih....");
    return 0;
}

char menu(char pilih){
    int key;
    puts("Menu Insert");
    puts("1. Insert Awal");
    puts("2. Insert Akhir");
    puts("3. Insert After");
    puts("4. Insert Before");
    puts("5. Keluar");
    printf("Masukkan pilihan anda : ");
    scanf("%c", &pilih);
    if (pilih == '1' || pilih == '2' || pilih == '3' || pilih == '4')
        input();
    switch (pilih) {
    case '1':
        insertAwal();
        break;
    case '2':
        insertAkhir();
        break;
    case '3':
        insertAfter();
        break;
    case '4':
        insertBefore();
        break;
    case '5':
        puts("keluar dari menu");
        break;
    default:
        puts("Opsi yang dipilih salah");
        break;
    }
    getchar();
    show();
    return pilih;
}

void input(){
    alokasi();
    printf("No\t: ");
    scanf("%d", &tambah->no);
    printf("Nama\t: ");
    getchar();
    gets(tambah->nama);
    fflush(stdin);
    printf("Nilai\t: ");
    scanf("%f", &tambah->nilai);
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

void insertAfter(){
    int key;
    if (Head == NULL) {
        puts("SLL ini masih kosong, tidak bisa melakukan insert after");
        return;
    }
    printf("Disisipkan setelah data berapa? ");
    scanf("%d", &key);
    after = Head;
    while (after->no != key) {
        if (after->next == NULL) {
            printf("Key tidak sesuai\n");
            return;
        } else
            after = after->next;
    }
    tambah->next = after->next;
    after->next = tambah;
}

void insertBefore(){
    int key;
    if (Head == NULL) {
        printf("SLL ini masih kosong, tidak bisa melakukan insert akhir");
        return;
    }
    printf("Disisipkan sebelum data berapa? ");
    scanf("%d", &key);
    if (Head->no == key) {
        insertAwal();
        return;
    }
    bef = Head;
    do
    {
        pbef = bef;
        if (bef->next == NULL) {
            printf("Key tidak ditemukan.\n");
            return;
        } else
            bef = bef->next;
    } while (bef->no != key);
    tambah->next = bef;
    pbef->next = tambah;
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