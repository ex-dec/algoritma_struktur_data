#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef int typeName;
typedef struct {
    typeName data[max];
    int count;
    int front;
    int rear;
} queue;

// Operasi umum queue
void inisialisasi(queue *);
int full(queue *);
int empty(queue *);
void enqueue(queue *, typeName);
typeName dequeue(queue *);

char menu(char,queue *);
void masukan(queue *);
void keluaran(queue *);
void minmax(queue *);
void find(queue *);
void tampil(queue *);

int main(){
    char opsi = '0';
    queue q;
    inisialisasi(&q);
    while (opsi != '6')
        opsi = menu(opsi, &q);
    puts("Terima Kasih!!!");
    return 0;
}

char menu(char opsi, queue *q){
    puts("Menu QUEUE using Array");
    puts("1. Tambah Data");
    puts("2. Hapus Data");
    puts("3. Tampilkan data min & max");
    puts("4. Cari data");
    puts("5. Cetak isi Queue");
    puts("6. Keluar");
    printf("Masukkan pilihan anda : ");
    scanf("%c", &opsi);
    getchar();
    switch (opsi) {
        case '1':
            masukan(q);
            break;
        case '2':
            keluaran(q);
            break;
        case '3':
            minmax(q);
            break;
        case '4':
            find(q);
            break;
        case '5':
            tampil(q);
            break;
        case '6':
            break;
        default:
            puts("Invalid input!!!!");
            break;
    }
    puts("");
    return opsi;
}

void masukan(queue *q){
    typeName temp;
    printf("Masukkan Data Anda : ");
    scanf("%d", &temp);
    getchar();
    enqueue(q, temp);
}

void keluaran(queue *q){
    typeName temp;
    temp = dequeue(q);
    if (temp != ' ')
        printf("Data yang diambil dari queue adalah \n%d\n", temp);
}

void minmax(queue *q){
    int counter = q->front;
    int kecil = 100, besar = 0;
    if (empty(q))
        puts("queue kosong!!!");
    else {
        for (int i = 0; i < q->count ; i++) {
            if (q->data[counter % max] <= kecil)
                kecil = q->data[counter % max];
            if (q->data[counter % max] >= besar)
                besar = q->data[counter % max];
            counter++;
        }
        puts("");
        printf("Data terkecil = %d\n", kecil);
        printf("Data terBESAR = %d\n", besar);
    }
}

void find(queue *q){
    int counter = q->front;
    int temp;
    if (empty(q))
        puts("queue kosong!!!");
    else {
        printf("Data yang dicari : ");
        scanf("%d", &temp);
        getchar();
        for (int i = 0; i < q->count ; i++) {
            if (q->data[counter%max] == temp) {
                printf("%d ada di dalam queue\n", temp);
                return;
            }
            counter++;
        }
        printf("%d tidak ada di dalam queue\n", temp);
    }
}

void tampil(queue *q) {
    int counter = q->front;
    if (empty(q))
        puts("queue kosong!!!");
    else {
        puts("Isi dari QUEUE saat ini : ");
        for (int i = 0; i < q->count ; i++) {
            printf("%d\n", q->data[counter%max]);
            counter++;
        }
        puts("");
    }
}

void inisialisasi(queue *q) {
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}

int full(queue *q) {
    return(q->count == max);
}

int empty(queue *q) {
    return(q->count == 0);
}

void enqueue(queue *q, typeName a) {
    if (full(q))
        puts("Queue penuh!");
    else {
        q->data[q->rear] = a;
        q->rear = (q->rear + 1) % max;
        q->count++;
    }
}

typeName dequeue(queue *q) {
    typeName temp;
    if (empty(q)) {
        puts("Queue kosong!");
        return ' ';
    }
    else {
        temp = q->data[q->front];
        q->front = (q->front + 1) % max;
        q->count--;
        return temp;
    }
}