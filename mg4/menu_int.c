#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};

Node *Head = NULL, *tambah, *tail, *hapus, *after, *bef, *pbef, *pdel, *p;

// fungsi insert
void insertAwal();
void insertAkhir();
void insertBefore(int);

// pilihan menu
void masukan();
void find();
void del();

// fungsi delete
void deleteAwal();
void deleteAkhir();
void deleteTertentu(int);

// menu
char menu(char);

// basic opertion sll
void alokasi();
void bebas();
void show();
void input();

int main(){
    char opsi = '1';
    puts("Review SLL \n");
    while (opsi != '4')
        opsi = menu(opsi);
    puts("Terima kasih....");
    return 0;
}

char menu(char opsi){
    puts("Menu Utama");
    puts("1. Penambahan data secara ter-urut");
    puts("2. Pencarian data");
    puts("3. Hapus data");
    puts("4. Keluar");
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
    if (Head == NULL || Head->data > tambah->data) {
        insertAwal();
    } else if (p->next == NULL) {
        insertAkhir();
    } else {
        while (p->data < tambah->data) {
            if (p->next == NULL) {
                insertAkhir();
                return;
            }
            p = p->next;
        }
        insertBefore(p->data);
    }
}

void find(){
    int counter = 0;
    int key;
    printf("Masukkan data yang mau dicari : ");
    scanf("%d", &key);
    p = Head;
    while (p != NULL) {
        if (p->data == key)
            counter++;
        p = p->next;
    }
    if (counter != 0)
        printf("Data %d ketemu sebanyak %d kali\n\n", key, counter);
    else
        printf("Data %d tidak ada didalam SLL\n\n", key);
}

void del(){
    int key;
    if (Head == NULL) {
        puts("SLL ini masih kosong");
        return;
    }
    printf("Mau menghapus data apa? ");
    scanf("%d", &key);
    p = Head;
    if (Head->data == key) {
        deleteAwal();
    } else {
        while (p->data != key) {
            if (p->next == NULL) {
                puts("Data tidak ditemukan");
                return;
            }
            p = p->next;
        }
        if (p->next == NULL) {
            deleteAkhir();
        } else
            deleteTertentu(key);
    }
    bebas();
    show();
}

void insertAwal(){
    if (Head != NULL)
        tambah->next = Head;
    Head = tambah;
}

void insertAkhir(){
    p->next = tambah;
}

void insertBefore(int key){
    bef = Head;
    do
    {
        pbef = bef;
        bef = bef->next;
    } while (bef->data != key);
    tambah->next = bef;
    pbef->next = tambah;
}

void deleteAwal(){
    hapus = Head;
    if (Head->next == NULL)
        Head = NULL;
    else
        Head = Head->next;
}

void deleteAkhir(){
    hapus = Head;
    while (hapus->next != NULL){
        pdel = hapus;
        hapus = hapus->next;
    }
    pdel->next = NULL;
}

void deleteTertentu(int key){
    hapus = Head;
    while (hapus->data != key) {
        pdel = hapus;
        hapus = hapus->next;
    }
    pdel->next = hapus->next;
}

void input(){
    alokasi();
    printf("Nilai yang akan disimpan : ");
    scanf("%d", &tambah->data);
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
    puts("Data yang ada di dalam SLL :");
    if (Head != NULL) {
        while (tampil != NULL){
            printf("%d\n", tampil->data);
            tampil = tampil->next;
        }
    } else
        puts("SLL Kosong");
}