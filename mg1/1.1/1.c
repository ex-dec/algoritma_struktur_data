#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
#define teks 20

struct dataNilai {
    char nama[teks];
    int nilaiTugas;
    int nilaiUts;
    int nilaiUas;
};

int hitungJumlah();
void masukan(struct dataNilai [], int);
void tampil(struct dataNilai [], int);
int hitungAkhir(struct dataNilai [], int);

int main() {
    int jumlahMahasiswa;
    int i;
    puts("MENGHTUNG NILAI AKHIR\n");
    puts("MATA KULIAH KONSEP PEMROGRAMAN\n\n");
    jumlahMahasiswa = hitungJumlah();
    struct dataNilai nilaiMahasiswa[jumlahMahasiswa];
    masukan(nilaiMahasiswa, jumlahMahasiswa);
    tampil(nilaiMahasiswa,jumlahMahasiswa);
    return 0;
}

int hitungJumlah(){
    int jumlah;
    printf("Berapa jumlah mahasiswa ? ");
    scanf("%d", &jumlah);
    return jumlah;
}

void masukan(struct dataNilai nilaiMahasiswa[max], int jumlahMahasiswa){
    puts("Masukkan DATA Mahasiswa");
    for(int i = 0;i < jumlahMahasiswa;i++){
        printf("Mahasiswa ke - %d\n", i+1);
        printf("Nama\t\t: ");
        getchar();
        gets(nilaiMahasiswa[i].nama);
        fflush(stdin);
        printf("Nilai tugas\t: ");
        scanf("%d", &nilaiMahasiswa[i].nilaiTugas);
        printf("Nilai UTS\t: ");
        scanf("%d", &nilaiMahasiswa[i].nilaiUts);
        printf("Nilai UAS\t: ");
        scanf("%d", &nilaiMahasiswa[i].nilaiUas);
    }
}

void tampil(struct dataNilai nilaiMahasiswa[max], int jumlahMahasiswa){
    int i;
    char grade;
    puts("DAFTAR NILAI");
    puts("MATAKULIAH KONSEP PEMROGRAMAN");
    puts("----------------------------------------------------------------------");
    puts("No\tNama Mahasiswa\t\tTugas\tUTS\tUAS\tAkhir\tGrade");
    puts("----------------------------------------------------------------------");
    for (i = 0; i < jumlahMahasiswa; i++) {
        int nilaiAkhir = hitungAkhir(nilaiMahasiswa,i);
        printf("%d\t%s\t\t\t%d\t%d\t%d\t%d\t", i+1, nilaiMahasiswa[i].nama, nilaiMahasiswa[i].nilaiTugas, nilaiMahasiswa[i].nilaiUts, nilaiMahasiswa[i].nilaiUas, nilaiAkhir);
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
    }
    puts("----------------------------------------------------------------------");
}

int hitungAkhir(struct dataNilai nilaiMahasiswa[max], int i) {
    return (nilaiMahasiswa[i].nilaiTugas * 20 /100) + (nilaiMahasiswa[i].nilaiUts * 40 / 100) + (nilaiMahasiswa[i].nilaiUas * 40 / 100);
}