#include <stdio.h>
#include <stdlib.h>

typedef struct simpul DNode;
struct simpul{
    int data;
    DNode *next, *prev;
};

DNode *Head = NULL, *tambah, *tail, *after, *bef, *hapus;

// Fungsi Insert
void insertAwal();
void insertAkhir();
void insertAfter();
void insertBefore();

// Fungsi Delete
void deleteAwal();
void deleteAkhir();
void deleteTertentu();

// Menu
char menu(char);
void menuInsert();
void menuDelete();

// Basic operation DLL
void input();
void alokasi();
void show();
void bebas();


int main() {
    char pilih = '0';
    puts("Double Linked List - Operasi Insert dan Delete");
    while (pilih != '3')
        pilih = menu(pilih);
    puts("Terima kasih....");
    return 0;
}

char menu(char opsi){
    puts("Menu DLL");
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
        puts("DLL masih kosong!!!");
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
    if (Head != NULL){
        tambah->next = Head;
        Head->prev = tambah;
    }
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

void insertAfter(){
    int key;
    if (Head == NULL) {
        puts("DLL ini masih kosong, tidak bisa melakukan insert after");
        return;
    }
    printf("Disisipkan setelah data berapa? ");
    scanf("%d", &key);
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

void insertBefore(){
    int key;
    if (Head == NULL) {
        printf("DLL ini masih kosong, tidak bisa melakukan insert akhir");
        return;
    } else {
        printf("Disisipkan sebelum data berapa? ");
        scanf("%d", &key);
        if (Head->data == key) {
            insertAwal();
        } else {
            bef = Head;
            do {
                if (bef->next == NULL) {
                    puts("data tidak ditemukan");
                    break;
                } else
                    bef = bef->next;
            } while (bef->data != key);
            if (bef->data == key) {
                tambah->next = bef;
                tambah->prev = bef->prev;
                bef->prev->next = tambah;
                bef->prev = tambah;
            }
        }
    }
}

void deleteAwal(){
    hapus = Head;
    if (Head->next == NULL)
        Head = NULL;
    else {
        Head->prev = NULL;
        Head = Head->next;
    }
    bebas();
}

void deleteAkhir(){
    hapus = Head;
    if (Head->next == NULL)
        Head = NULL;
    else {
        while (hapus->next != NULL)
            hapus = hapus->next;
        hapus->prev->next = NULL;
    }
    bebas();
}

void deleteTertentu(){
    int key;
    printf("Mau menghapus data apa? ");
    scanf("%d", &key);
    hapus = Head;
    if (Head->data == key){
        deleteAwal();
        return;
    } else {
        while (hapus->data != key) {
            if (hapus->next == NULL) {
                puts("Data tidak ditemukan");
                break;
            } else
                hapus = hapus->next;
        }
        if (hapus->data == key) {
            hapus->prev->next = hapus->next;
            if (hapus->next != NULL)
                hapus->next->prev = hapus->prev;
            bebas();
        }
    }
}

void input(){
    alokasi();
    printf("Nilai yang akan disimpan : ");
    scanf("%d", &tambah->data);
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

void show(){
    DNode *tampil = Head;
    puts("Data yang ada di dalam DLL :");
    if (Head != NULL) {
        while (tampil != NULL){
            printf("%d\n", tampil->data);
            tampil = tampil->next;
        }
    } else
        puts("DLL Kosong");
}

void bebas(){
    free(hapus);
    hapus = NULL;
}