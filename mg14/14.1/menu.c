#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 20

typedef char typeInfo;
typedef struct node tree;
struct node {
    tree *kiri;
    tree *kanan;
    typeInfo data;
};

void alokasi(typeInfo);
void generate();
char menu();
char find();
void preOrder(tree *);
void inOrder(tree *);
void postOrder(tree *);

tree *root = NULL, *tambah, *p, *q;
int n;

int main() {
    char pilihanMenu = 'y';
    puts("Membentuk dan mengunjungi sebuah binary tree");
    generate();
    while (pilihanMenu == 'y')
        pilihanMenu = menu();
    pilihanMenu = 'y';
    while (pilihanMenu == 'y')
        pilihanMenu = find();
    puts("Terima kasih...");
    return 0;
}

void generate(){
    char masuk[max];
    printf("Ketikkan sekumpulan data/infonya, pisahkan dengan spasi: ");
    fgets(masuk, sizeof(masuk), stdin);
    n = strlen(masuk);
    masuk[strcspn(masuk, "\n")] = '\0';
    for (int i = 0; i < n; i++) {
        if (masuk[i] != ' ') {
            alokasi(masuk[i]);
            if (root == NULL)
                root = tambah;
            else {
                p = root;
                q = root;
                while (q != NULL && tambah->data != p->data) {
                    p = q;
                    if (tambah->data < p->data)
                        q = p->kiri;
                    else
                        q = p->kanan;
                }
                if (tambah->data != p->data){
                    if (tambah->data < p->data)
                        p->kiri = tambah;
                    else 
                        p->kanan = tambah;
                }
            }            
        }
    }
}

char menu(){
    char pilihanMenu;
    char decission;
    puts("Pilih Mode kunjungan Tree");
    puts("1. PreOrder");
    puts("2. InOrder");
    puts("3. PostOrder");
    printf("Pilihan anda [1/2/3]? ");
    scanf("%c", &pilihanMenu);
    getchar();
    if (pilihanMenu == '1' || pilihanMenu == '2' || pilihanMenu == '3')
        p = root;
    switch (pilihanMenu) {
    case '1':
        printf("Hasil penulusuran menggunakan Preorder : ");
        preOrder(p);
        break;
    case '2':
        printf("Hasil penulusuran menggunakan Inorder : ");
        inOrder(p);
        break;
    case '3':
        printf("Hasil penulusuran menggunakan Postorder : ");
        postOrder(p);
        break;
    default:
        puts("Pilihan tidak tersedia");
        break;
    }
    printf("\n\nMencoba mode yang lain [y/t]? ");
    scanf("%c", &decission);
    getchar();
    return decission;
}

char find(){
    typeInfo cari;
    char decission;
    int konfirmasi = 0;
    puts("Mencari data dalam tree...");
    printf("Masukkan data yang ingin dicari : ");
    scanf("%c", &cari);
    getchar();
    p = root;
    if (p->data == cari)
        konfirmasi = 1;
    else {
        while (p != NULL && !konfirmasi) {
            if (p->data == cari)
                konfirmasi = 1;
            else {
                if (cari < p->data)
                    p = p->kiri;
                else
                    p = p->kanan;
            }
        }
    }
    if (konfirmasi)
        printf("Data %c ditemukan\n", cari);
    else
        printf("Data %c tidak ditemukan\n", cari);
    printf("\nMau mencari lagi [y/t]? ");
    scanf("%c", &decission);
    getchar();
    return decission;
}

void preOrder(tree *p){
    if (p != NULL) {
        printf("%c ", p->data);
        preOrder(p->kiri);
        preOrder(p->kanan);
    }
}

void inOrder(tree *p){
    if (p != NULL) {
        inOrder(p->kiri);
        printf("%c ", p->data);
        inOrder(p->kanan);
    }
}

void postOrder(tree *p){
    if (p != NULL) {
        postOrder(p->kiri);
        postOrder(p->kanan);
        printf("%c ", p->data);
    }
}

void alokasi(typeInfo data){
    tambah = (tree *) malloc(sizeof(tree));
    if (tambah == NULL) {
        puts("Alokasi gagal!!!");
        exit(0);
    } else {
        tambah->data = data;
        tambah->kiri = NULL;
        tambah->kanan = NULL;
    }
}