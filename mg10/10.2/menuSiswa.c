#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 20

struct  siswa {
    int no;
    char nama[max];
    float nilai;
};

void generate(struct siswa []);
char menu(struct siswa []);
void dup(struct siswa [], struct siswa []);
void Insertion(struct siswa [], int);
void Selection(struct siswa [], int);
void tampil(struct siswa []);
int menuUrut();
void swap(struct siswa *, struct siswa *);

int n;

int main(){
    struct siswa data[10];
    char opsi = '1';
    puts("Menu siswa");
    generate(data);
    while (opsi != '3')
        opsi = menu(data);
    puts("terima kasih..");
    return 0;
}

char menu(struct siswa data[]) {
    char opsi, mode;
    struct siswa temp[n];
    dup(temp, data);
    puts("Menu Metode Sorting");
    puts("1. Insertion Sort");
    puts("2. Selection Sort");
    puts("3. Keluar");
    printf("Pilihan Anda [1/2/3] : ");
    scanf("%c", &opsi);
    getchar();
    switch (opsi) {
    case '1':
        Insertion(temp, menuUrut());
        break;
    case '2':
        Selection(temp, menuUrut());
        break;
    case '3':
        break;
    default:
        puts("Invalid input");
        break;
    }
    if (opsi == '1' || opsi == '2'){
        puts("sebelum");
        tampil(data);
        puts("sesudah");
        tampil(temp);
    }
    return opsi;
}

int menuUrut(){
    int mode;
    puts("Mode sort");
    puts("1. Ascending");
    puts("2. Descending");
    printf("Masukkan pilihan anda [1/2]: ");
    scanf("%d", &mode);
    getchar();
    if (mode != 1)
        mode = 0;
    return mode;
}

void dup(struct siswa x[], struct siswa y[]){
    for (int i = 0; i < n; i++) {
        x[i] = y[i];
    }
}

void generate(struct siswa data[]){
    printf("Mau memasukkan data berapa ? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Data mahasiswa ke-%d\n", i+1);
        printf("No\t: ");
        scanf("%d", &data[i].no);
        getchar();
        printf("Nama\t: ");
        fgets(data[i].nama, sizeof(data[i].nama), stdin);
        data[i].nama[strcspn(data[i].nama, "\n")] = '\0';
        printf("Nilai\t: ");
        scanf("%f", &data[i].nilai);
        getchar();
        puts("");
    }
}

// void generate(struct siswa data[]){
//     char opsi;
//     int i = 0;
//     puts("Generate data siswa (maks 10 data)");
//     do
//     {
//         printf("No\t: ");
//         scanf("%d", &data[i].no);
//         getchar();
//         printf("Nama\t: ");
//         fgets(data[i].nama, sizeof(data[i].nama), stdin);
//         data[i].nama[strcspn(data[i].nama, "\n")] = '\0';
//         printf("Nilai\t: ");
//         scanf("%f", &data[i].nilai);
//         getchar();
//         printf("mau masukkan data lagi [y/t]? ");
//         scanf("%c", &opsi);
//         getchar();
//         i++;
//     } while (opsi == 'y' || opsi == 'Y');
//     n = i;
// }

void Insertion(struct siswa arr[], int mode){
    int i = 1;
    int kondisi;
    while (i < n) {
        struct siswa key = arr[i];
        int j = i - 1;
        if (mode){
            while (j >= 0 && arr[j].no > key.no) {
                arr[j+1] = arr[j];
                j--;
            }
        } else {
            while (j >= 0 && arr[j].no < key.no) {
                arr[j+1] = arr[j];
                j--;
            }
        }
        arr[j+1] = key;
        i++;
    }
}

void Selection(struct siswa arr[], int mode){
    int i = 0;
    int kondisi;
    while (i < n - 1) {
        int min = i;
        int j = i + 1;
        while (j < n) {
            if (mode)
                kondisi = arr[j].no < arr[min].no;
            else
                kondisi = arr[j].no > arr[min].no;
            if (kondisi)
                min = j;
            j++;
        }
        swap(&arr[i], &arr[min]);
        i++;
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
        printf("%d\t%-17s%.2f\n", data[i].no, data[i].nama, data[i].nilai);
    puts("");
}