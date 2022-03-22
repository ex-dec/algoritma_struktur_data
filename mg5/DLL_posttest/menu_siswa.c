#include <stdio.h>
#include <stdlib.h>
#define max 20

typedef struct siswa DNode;
struct siswa{
    int no;
    char nama[max];
    float nilai;
    DNode *next, *prev;
};

DNode *Head = NULL, *tambah, *tail, *after, *bef, *hapus, *p;

// menu
char menu(char);

// pilihan menu
void masukan();
void find();
void del();
void mean();

// Fungsi Insert
void insertAwal();
void insertAkhir();
void insertBefore(int);

// Fungsi Delete
void deleteAwal();
void deleteAkhir();
void deleteTertentu(int);

// basic opertion sll
void alokasi();
void bebas();
void show();
void input();

int main(){
    char opsi = '1';
    puts("Review DLL data Struct\n");
    while (opsi != '5')
        opsi = menu(opsi);
    puts("Terima kasih....");
    return 0;
}

char menu(char opsi){
    puts("Menu Utama");
    puts("1. Penambahan data secara ter-urut");
    puts("2. Pencarian data");
    puts("3. Hapus data");
    puts("4. rata rata");
    puts("5. Keluar");
    printf("Masukkan pilihan anda : ");
    fflush(stdin);
    scanf("%c", &opsi);
    switch (opsi) {
    case '1':
        masukan();
        show();
        break;
    case '2':
        find();
        break;
    case '3':
        del();
        break;
    case '4':
        mean();
        break;
    case '5':
        break;
    default:
        puts("Opsi yang anda masukkan salah");
        break;
    }
    return opsi;
}

void masukan(){
    input();
    p = Head;
    if (Head == NULL || Head->no > tambah->no)
        insertAwal();
    else if (p->next == NULL)
        insertAkhir();
    else {
        while (p->no < tambah->no) {
            if (p->next == NULL) {
                insertAkhir();
                break;
            }
            p = p->next;
        }
        if (p->no >= tambah->no)
            insertBefore(p->no);
    }
}

void find(){
    int counter = 0;
    int key;
    printf("Masukkan data yang mau dicari : ");
    scanf("%d", &key);
    p = Head;
    while (p != NULL) {
        if (p->no == key)
            counter++;
        p = p->next;
    }
    if (counter != 0)
        printf("Data %d ketemu sebanyak %d kali\n\n", key, counter);
    else
        printf("Data %d tidak ada didalam DLL\n\n", key);
}

void del(){
    int key;
    if (Head == NULL) {
        puts("DLL ini masih kosong");
    } else {
        printf("Mau menghapus data apa? ");
        scanf("%d", &key);
        p = Head;
        if (Head->no == key) {
            deleteAwal();
        } else {
            while (p->no != key) {
                if (p->next == NULL) {
                    puts("Data tidak ditemukan");
                    break;
                }
                p = p->next;
            }
            if (p->no == key) {
                if (p->next == NULL)
                    deleteAkhir();
                else
                    deleteTertentu(key);
            }
        }
        bebas();
        show();
    }
}

void mean(){
    float rata = 0;
    int counter = 0;
    tail = Head;
    if (Head == NULL) {
        puts("DLL nya kosong");
    } else {
        do
        {
            rata = rata + tail->nilai;
            tail = tail->next;
            counter++;
        } while (tail != NULL);
        rata = rata / counter;
        printf("Nilai rata-rata : %.2f\n", rata);
    }
}

void insertAwal(){
    if (Head != NULL){
        tambah->next = Head;
        Head->prev = tambah;
    }
    Head = tambah;
}

void insertAkhir(){
    tambah->prev = p;
    p->next = tambah;
}

void insertBefore(int key){
    bef = Head;
    do
    {
        bef = bef->next;
    } while (bef->no != key);
    tambah->next = bef;
    tambah->prev = bef->prev;
    bef->prev->next = tambah;
    bef->prev = tambah;
}

void deleteAwal(){
    hapus = Head;
    if (Head->next == NULL)
        Head = NULL;
    else{
        Head->prev = NULL;
        Head = Head->next;
    }
}

void deleteAkhir(){
    hapus = Head;
    while (hapus->next != NULL)
        hapus = hapus->next;
    hapus->prev->next = NULL;
}

void deleteTertentu(int key){
    hapus = Head;
    while (hapus->no != key)
        hapus = hapus->next;
    hapus->prev->next = hapus->next;
    hapus->next->prev = hapus->prev;
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
    tambah = (DNode *) malloc(sizeof(DNode));
    if (tambah == NULL) {
        puts("Alokasi gagal!!!");
        exit(0);
    } else
        tambah->next = NULL;
        tambah->prev = NULL;
}

void bebas(){
    free(hapus);
    hapus = NULL;
}

void show(){
    DNode *tampil = Head;
    puts("Data yang ada di dalam DLL :");
    if (Head != NULL) {
        puts("No\tNama\t\t\tNilai");
        while (tampil != NULL){
            printf("%d\t%-20s\t%.2f\n", tampil->no, tampil->nama, tampil->nilai);
            tampil = tampil->next;
        }
    } else
        puts("SLL Kosong");
}