#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define max 20

struct  siswa {
    int no;
    char nama[max];
    int nilai;
};

void generate(struct siswa []);
char menu(struct siswa []);
void dup(struct siswa [], struct siswa []);
void Shell(struct siswa [], char);
void SeqSearch(struct siswa [], char);
void BinSearch(struct siswa [], char);
void tampil(struct siswa []);
char menuTampil();
char Find();
char urut();
void swap(struct siswa *, struct siswa *);

int n;
int keyNo;
char keyNama[max];
int konfirm;
int j;

int main(){
    struct siswa data[10];
    char opsi = '1';
    puts("Menu siswa");
    generate(data);
    while (opsi != '4')
        opsi = menu(data);
    puts("terima kasih..");
    return 0;
}

char menu(struct siswa data[]) {
    char opsi;
    struct siswa temp[n];
    dup(temp, data);
    puts("Menu Metode Searching");
    puts("1. Tampilkan Data");
    puts("2. Sequential Search");
    puts("3. Binary Search");
    puts("4. Keluar");
    printf("Pilihan Anda [1/2/3/4] : ");    
    scanf("%c", &opsi);
    getchar();
    switch (opsi) {
    case '1':
        if (menuTampil() == '2')
            Shell(temp, '1');
        tampil(temp);
        break;
    case '2':
        SeqSearch(temp, Find());
        break;
    case '3':
        BinSearch(temp, Find());
        break;
    case '4':
        break;
    default:
        puts("Invalid input");
        break;
    }
    if (opsi == '2' || opsi == '3'){
        if (konfirm)
            printf("Data ditemukan pada indeks ke %d\n", j);
        else
            printf("Data tidak ditemukan\n");
    }
    return opsi;
}

char menuTampil(){
    char mode;
    puts("Bentuk data");
    puts("1. Tidak terurut");
    puts("2. Ter-urut berdasarkan No");
    printf("Masukkan pilihan anda [1/2] :");
    scanf("%c", &mode);
    getchar();
    return mode;
}

char Find(){
    char mode;
    puts("Pencarian berdasarkan");
    puts("1. No");
    puts("2. Nama");
    printf("Masukkan pilihan anda [1/2]: ");
    scanf("%c", &mode);
    getchar();
    switch (mode) {
    case '1':
        printf("Masukkan no mahasiswa yang akan dicari : ");
        scanf("%d", &keyNo);
        getchar();
        break;
    case '2':
        printf("Masukkan nama mahasiswa yang akan dicari : ");
        fgets(keyNama, sizeof(keyNama), stdin);
        keyNama[strcspn(keyNama, "\n")] = '\0';
        break;
    default:
        break;
    }
    return mode;
}

void SeqSearch(struct siswa arr[], char Mode){
    konfirm = 0;
    j = 0;
    int kondisi;
    while (j < n && !konfirm) {
        if (Mode == '1')
            kondisi = arr[j].no == keyNo;
        else
            kondisi = strcasecmp(arr[j].nama, keyNama) == 0;
        if (kondisi)
            konfirm = 1;
        else
            j++;
    }
}

void BinSearch(struct siswa arr[], char mode){
    int L = 0;
    int R = n - 1;
    int M;
    int kondisi;
    konfirm = 0;
    Shell(arr, mode);
    while (L <= R && !konfirm) {
        M = (L + R) / 2;
        if (mode == '1')
            kondisi = arr[M].no == keyNo;
        else
            kondisi = strcasecmp(arr[M].nama, keyNama) == 0;
        if (kondisi) {
            konfirm = 1;
            j = M;
        } else if (keyNo < arr[M].no)
            R = M - 1;
        else
            L = M + 1;
    }
}

void dup(struct siswa x[], struct siswa y[]){
    for (int i = 0; i < n; i++) {
        x[i] = y[i];
    }
}

void generate(struct siswa data[]){
    printf("Mau memasukkan data berapa ? ");
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        printf("Data mahasiswa ke-%d\n", i+1);
        printf("No\t: ");
        scanf("%d", &data[i].no);
        getchar();
        printf("Nama\t: ");
        fgets(data[i].nama, sizeof(data[i].nama), stdin);
        data[i].nama[strcspn(data[i].nama, "\n")] = '\0';
        printf("Nilai\t: ");
        scanf("%d", &data[i].nilai);
        getchar();
        puts("");
    }
}

void Shell(struct siswa arr[], char mode){
    int key = n, konfirm;
    int kondisi;
    while (key > 1) {
        key = key / 2;
        konfirm = 1;
        while (konfirm) {
            konfirm = 0;
            for (int i = 0; i < n-key; i++) {
                if (mode == '2')
                    kondisi = strcasecmp(arr[i].nama, arr[i+key].nama) < 0;
                else
                    kondisi = arr[i].no > arr[i+key].no;
                if (kondisi) {
                    swap(&arr[i],&arr[i+key]);
                    konfirm = 1;
                }
            }
        }
    }
}

void swap(struct siswa *a, struct siswa *b){
    struct siswa c;
    c = *a;
    *a = *b;
    *b = c;
}

void tampil(struct siswa data[]){
    puts("No\tNama\t\tNilai");
    for (int i = 0; i < n; i++)
        printf("%d\t%-17s%d\n", data[i].no, data[i].nama, data[i].nilai);
    puts("");
}