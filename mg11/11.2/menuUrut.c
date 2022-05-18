#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define max 20

struct  siswa {
    int no;
    char nama[max];
    float nilai;
};

void generate(struct siswa []);
char menu(struct siswa []);
void dup(struct siswa [], struct siswa []);
void Insertion(struct siswa [], char, char);
void Selection(struct siswa [], char, char);
void Shell(struct siswa [], char, char);
void Bubble(struct siswa [], char, char);
void tampil(struct siswa []);
char menuUrut();
char urut();
void swap(struct siswa *, struct siswa *);

int n;

int main(){
    struct siswa data[10];
    char opsi = '1';
    puts("Menu siswa");
    generate(data);
    while (opsi != '5')
        opsi = menu(data);
    puts("terima kasih..");
    return 0;
}

char menu(struct siswa data[]) {
    char opsi;
    struct siswa temp[n];
    dup(temp, data);
    puts("Menu Metode Sorting");
    puts("1. Insertion Sort");
    puts("2. Selection Sort");
    puts("3. Shell Sort");
    puts("4. Bubble Sort");
    puts("5. Keluar");
    printf("Pilihan Anda [1/2/3/4/5] : ");
    scanf("%c", &opsi);
    getchar();
    switch (opsi) {
    case '1':
        Insertion(temp, menuUrut(), urut());
        break;
    case '2':
        Selection(temp, menuUrut(), urut());
        break;
    case '3':
        Shell(temp, menuUrut(), urut());
        break;
    case '4':
        Bubble(temp, menuUrut(), urut());
        break;
    case '5':
        break;
    default:
        puts("Invalid input");
        break;
    }
    if (opsi == '1' || opsi == '2' || opsi == '3' || opsi == '4'){
        puts("sebelum");
        tampil(data);
        puts("sesudah");
        tampil(temp);
    }
    return opsi;
}

char menuUrut(){
    char mode;
    puts("Mode sort");
    puts("1. Ascending");
    puts("2. Descending");
    printf("Masukkan pilihan anda [1/2]: ");
    scanf("%c", &mode);
    getchar();
    return mode;
}

char urut(){
    char mode;
    puts("Pengurutan berdasarkan");
    puts("1. No");
    puts("2. Nama");
    puts("3. Nilai");
    printf("Masukkan pilihan anda [1/2/3]: ");
    scanf("%c", &mode);
    getchar();
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
        scanf("%f", &data[i].nilai);
        getchar();
        puts("");
    }
}

void Insertion(struct siswa arr[], char mode, char dasarUrut){
    int i = 1;
    int kondisi = 0;
    while (i < n) {
        struct siswa key = arr[i];
        int j = i - 1;
        if (dasarUrut == '1') {
            if (mode == '1')
                kondisi = arr[j].no > key.no;
            else
                kondisi = arr[j].no < key.no;
        } else if(dasarUrut == '2'){
            if (mode == '1')
                kondisi = strcasecmp(arr[j].nama, key.nama) < 0;
            else
                kondisi = strcasecmp(arr[j].nama, key.nama) > 0;
        } else if(dasarUrut == '3'){
            if (mode == '1')
                kondisi = arr[j].nilai > key.nilai;
            else
                kondisi = arr[j].nilai < key.nilai;
        }
        while (j >= 0 && kondisi) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        i++;
    }
}

void Selection(struct siswa arr[], char mode, char dasarUrut){
    int i = 0;
    int kondisi;
    while (i < n - 1) {
        int min = i;
        int j = i + 1;
        while (j < n) {
            if (dasarUrut == '1') {
                if (mode == '1')
                    kondisi = arr[j].no < arr[min].no;
                else
                    kondisi = arr[j].no > arr[min].no;
            } else if(dasarUrut == '2'){
                if (mode == '1')
                    kondisi = strcasecmp(arr[j].nama, arr[min].nama) < 0;
                else
                    kondisi = strcasecmp(arr[j].nama, arr[min].nama) > 0;
            } else if(dasarUrut == '3'){
                if (mode == '1')
                    kondisi = arr[j].nilai < arr[min].nilai;
                else
                    kondisi = arr[j].nilai > arr[min].nilai;
            }
            if (kondisi)
                min = j;
            j++;
        }
        swap(&arr[i], &arr[min]);
        i++;
    }
}

void Shell(struct siswa arr[], char mode, char dasarUrut){
    int key = n, konfirm;
    int kondisi;
    while (key > 1) {
        key = key / 2;
        konfirm = 1;
        while (konfirm) {
            konfirm = 0;
            for (int i = 0; i < n-key; i++) {
                if (dasarUrut == '1') {
                    if (mode == '1')
                        kondisi = arr[i].no > arr[i+key].no;
                    else
                        kondisi = arr[i].no < arr[i+key].no;
                } else if(dasarUrut == '2'){
                    if (mode == '2')
                        kondisi = strcasecmp(arr[i].nama, arr[i+key].nama) < 0;
                    else
                        kondisi = strcasecmp(arr[i].nama, arr[i+key].nama) > 0;
                } else if(dasarUrut == '3'){
                    if (mode == '1')
                        kondisi = arr[i].nilai > arr[i+key].nilai;
                    else
                        kondisi = arr[i].nilai < arr[i+key].nilai;
                }
                if (kondisi) {
                    swap(&arr[i],&arr[i+key]);
                    konfirm = 1;
                }
            }
        }
    }
}

void Bubble(struct siswa arr[], char mode, char dasarUrut){
    int konfirm = 1;
    int posAkhir = n-2;
    int i = 0;
    int kondisi;
    int j;
    while (i <= posAkhir && konfirm) {
        konfirm = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (dasarUrut == '1') {
                if (mode == '1')
                    kondisi = arr[j].no > arr[j+1].no;
                else
                    kondisi = arr[j].no < arr[j+1].no;
            } else if(dasarUrut == '2'){
                if (mode == '1')
                    kondisi = strcasecmp(arr[j].nama, arr[j+1].nama) > 0;
                else
                    kondisi = strcasecmp(arr[j].nama, arr[j+1].nama) < 0;
            } else if(dasarUrut == '3'){
                if (mode == '1')
                    kondisi = arr[j].nilai > arr[j+1].nilai;
                else
                    kondisi = arr[j].nilai < arr[j+1].nilai;
            }
            if (kondisi) {
                swap(&arr[j], &arr[j+1]);
                konfirm = 1;
            }
        }
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