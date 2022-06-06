#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct {
    int noId;
    char nama[max];
    char tglLahir[max];
    char jenisKelamin;
    float gaji;
} pegawai;

void input(pegawai *, int);
void tampil(pegawai *, int );

int main(){
    int jumlahPegawai;
    puts("DATA PEGAWAI");
    printf("Berapa jumlah pegawai : ");
    scanf("%d", &jumlahPegawai);
    pegawai data[jumlahPegawai];
    input(data, jumlahPegawai);
    tampil(data, jumlahPegawai);
    return 0;
}

void input(pegawai *data, int jumlah_pegawai){
    for (int i = 0; i < jumlah_pegawai; i++) {
        puts("");
        printf("Data pegawai ke-%d\n", i+1);
        data->noId = i + 1;
        printf("Nama Lengkap\t\t: ");
        getchar();
        gets(data->nama);
        fflush(stdin);
        printf("Tgl lahir <dd-mm-yyyy>\t: ");
        gets(data->tglLahir);
        printf("Jenis kelamin [L/P]\t: ");
        scanf("%c", &data->jenisKelamin);
        fflush(stdin);
        printf("Gaji/bln\t\t: ");
        scanf("%f", &data->gaji);
        data++;
    }
}

void tampil(pegawai *data, int jumlah_pegawai){
    puts("\nData pegawai yang telah diinputkan\n");
    for (int i = 0; i < jumlah_pegawai; i++) {
        printf("No id\t\t: %d\n", i+1);
        printf("Nama\t\t: %s\n", data->nama);
        printf("Tgl lahir\t: %s\n", data->tglLahir);
        printf("Jenis Kelamin\t: %c\n", data->jenisKelamin);
        printf("Gaji/bln\t: Rp %.2f\n\n", data->gaji);
        data++;
    }
}