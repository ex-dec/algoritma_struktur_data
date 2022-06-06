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

Node *Head = NULL, *tambah, *tail, *hapus, *after, *bef, *pbef, *pdel;

// fungsi insert
void insertAwal();
void insertAkhir();
void insertAfter();
void insertBefore();

// fungsi delete
void deleteAwal();
void deleteAkhir();
void deleteTertentu();

// menu
char menu(char);
void menuInsert();
void menuDelete();

// basic opertion sll
void alokasi();
void bebas();
void show();
void input();

int main(){
    char opsi = '1';
    while (opsi != '3')
        opsi = menu(opsi);
    puts("Terima kasih....");
    return 0;
}

char menu(char opsi){
    puts("Menu SLL");
    puts("1. Insert");
    puts("2. Delete");
    puts("3. Keluar");
    printf("Masukkan pilihan anda : ");
    scanf("%c", &opsi);
    switch (opsi) {
    case '1':
        menuInsert();
        break;
    case '2':
        menuDelete();
        break;
    case '3':
        puts("Keluar dari menu");
        break;
    default:
        puts("Opsi yang anda masukkan salah");
        break;
    }
    getchar();
    return opsi;
}

void menuInsert(){
    char opsi;
    puts("Menu Insert");
    puts("1. Awal");
    puts("2. Akhir");
    puts("3. After");
    puts("4. Before");
    printf("Silahkan dipilih : ");
    fflush(stdin);
    scanf("%c", &opsi);
    if (opsi == '1' || opsi == '2' || opsi == '3' || opsi == '4')
        input();
    switch (opsi) {
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
    default:
        puts("Opsi yang dipilih salah");
        break;
    }
    show();
}

void menuDelete(){
    char opsi;
    if (Head == NULL) {
        puts("SLL masih kosong!!!");
        return;
    }
    puts("Menu Delete");
    puts("1. Awal");
    puts("2. Akhir");
    puts("3. Tertentu");
    printf("Silahkan dipilih : ");
    fflush(stdin);
    scanf("%c", &opsi);
    switch (opsi) {
    case '1':
        deleteAwal();
        break;
    case '2':
        deleteAkhir();
        break;
    case '3':
        deleteTertentu();
        break;
    default:
        puts("Invalid Input");
        break;
    }
    show();
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
        puts("SLL ini masih kosong, tidak bisa melakukan insert");
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

void deleteAwal(){
    hapus = Head;
    if (Head->next == NULL)
        Head = NULL;
    else
        Head = Head->next;
    bebas();
}

void deleteAkhir(){
    hapus = Head;
    if (Head->next == NULL)
        Head = NULL;
    else {
        while (hapus->next != NULL){
            pdel = hapus;
            hapus = hapus->next;
        }
        pdel->next = NULL;
    }
    bebas();
}

void deleteTertentu(){
    int key;
    printf("Mau menghapus data apa? ");
    scanf("%d", &key);
    hapus = Head;
    while (hapus->no != key) {
        if (hapus->next == NULL) {
            puts("Data tidak ditemukan");
            return;
        } else {
            pdel = hapus;
            hapus = hapus->next;
        }
    }
    if (Head->no == key){
        deleteAwal();
        return;
    }
    pdel->next = hapus->next;
    bebas();
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

void bebas(){
    free(hapus);
    hapus = NULL;
}

void show(){
    Node *tampil = Head;
    puts("Data yang telah diinputkan :");
    if (Head != NULL) {
        puts("No\tNama\t\t\tNilai");
        while (tampil != NULL){
            printf("%d\t%-20s\t%.2f\n", tampil->no, tampil->nama, tampil->nilai);
            tampil = tampil->next;
        }
    } else
        puts("SLL Kosong");
}