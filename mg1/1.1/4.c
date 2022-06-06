#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

typedef struct {
    char nama[max];
    int nilaiTugas;
    int nilaiUts;
    int nilaiUas;
}data;

struct maks {
    char nama[max];
    int nilai;
};

void hitungJumlah(int *);
void masukan(data *, int);
void tampil(data *, int);
int hitungAkhir(data *);

int main() {
    int jumlahMahasiswa;
    int i;
    puts("MENGHTUNG NILAI AKHIR\n");
    puts("MATA KULIAH KONSEP PEMROGRAMAN\n\n");
    hitungJumlah(&jumlahMahasiswa);
    data nilaiMahasiswa[jumlahMahasiswa];
    masukan(nilaiMahasiswa,jumlahMahasiswa);
    tampil(nilaiMahasiswa,jumlahMahasiswa);
    return 0;
}

void hitungJumlah(int *jumlah){
    printf("Berapa jumlah mahasiswa ? ");
    scanf("%d", jumlah);
}

void masukan(data *nilaiMahasiswa, int jumlahMahasiswa){
    puts("Masukkan DATA Mahasiswa");
    for(int i = 0;i < jumlahMahasiswa;i++){
        printf("Mahasiswa ke - %d\n", i+1);
        printf("Nama\t\t: ");
        getchar();
        gets(nilaiMahasiswa->nama);
        fflush(stdin);
        printf("Nilai tugas\t: ");
        scanf("%d", &nilaiMahasiswa->nilaiTugas);
        printf("Nilai UTS\t: ");
        scanf("%d", &nilaiMahasiswa->nilaiUts);
        printf("Nilai UAS\t: ");
        scanf("%d", &nilaiMahasiswa->nilaiUas);
        nilaiMahasiswa++;
    }
}

void tampil(data *nilaiMahasiswa, int jumlahMahasiswa){
    int i;
    char grade;
    struct maks terTinggi;
    terTinggi.nilai = 0;
    puts("DAFTAR NILAI");
    puts("MATAKULIAH KONSEP PEMROGRAMAN\n");
    puts("----------------------------------------------------------------------");
    puts("No\tNama Mahasiswa\t\tTugas\tUTS\tUAS\tAkhir\tGrade");
    puts("----------------------------------------------------------------------");
    for (i = 0; i < jumlahMahasiswa; i++) {
        int nilaiAkhir = hitungAkhir(nilaiMahasiswa);
        printf("%d\t%s\t\t\t%d\t%d\t%d\t%d\t", i+1, nilaiMahasiswa->nama, nilaiMahasiswa->nilaiTugas, nilaiMahasiswa->nilaiUts, nilaiMahasiswa->nilaiUas, nilaiAkhir);
        if (nilaiAkhir >= 80) {
            grade = 'A';
        } else if (nilaiAkhir >= 70) {
            grade = 'B';
        } else if (nilaiAkhir >= 60) {
            grade = 'C';
        } else if (nilaiAkhir >= 50 ) {
            grade = 'D';
        } else {
            grade = 'E';
        }
        printf("%c\n", grade);
        if (nilaiAkhir >= terTinggi.nilai) {
            terTinggi.nilai = nilaiAkhir;
            strcpy(terTinggi.nama, nilaiMahasiswa->nama);
        }
        nilaiMahasiswa++;
    }
    puts("----------------------------------------------------------------------");
    printf("\nJumlah Mahasiswa\t: %d\n", jumlahMahasiswa);
    puts("\nNilai tertinggi");
    printf("Nama\t: %s\n", terTinggi.nama);
    printf("Nilai\t: %d\n", terTinggi.nilai);
}

int hitungAkhir(data *nilaiMahasiswa) {
    return (nilaiMahasiswa->nilaiTugas * 20 /100) + (nilaiMahasiswa->nilaiUts * 40 / 100) + (nilaiMahasiswa->nilaiUas * 40 / 100);
}