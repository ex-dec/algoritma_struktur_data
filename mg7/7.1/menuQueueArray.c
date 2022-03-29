#include <stdio.h>
#include <stdlib.h>
#define max 5

typedef char typeName;
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

// menu queue
char menu(char, queue *);
void masukan(queue *);
void keluaran(queue *);
void tampil(queue *);

int main(){
    char opsi = '0';
    queue q;
    inisialisasi(&q);
    while (opsi != '4')
        opsi = menu(opsi, &q);
    puts("Terima Kasih!!!");
    return 0;
}

char menu(char opsi, queue *q){
    puts("Menu Queue using ARRAY :");
    puts("1. Mengisi Queue <ENQUEUE>");
    puts("2. Mengambil isi Queue <DEQUEUE>");
    puts("3. Menampilkan isi Queue => FIFO");
    puts("4. Keluar");
    printf("Masukkan pilihan anda : ");
    fflush(stdin);
    scanf("%c", &opsi);
    switch (opsi) {
    case '1':
        masukan(q);
        break;
    case '2':
        keluaran(q);
        break;
    case '3':
        tampil(q);
        break;
    case '4':
        break;
    default:
        puts("Invalid Input!!!");
        break;
    }
    puts("");
    return opsi;
}

void masukan(queue *q){
    typeName temp;
    printf("Masukkan Data Anda : ");
    fflush(stdin);
    scanf("%c", &temp);
    enqueue(q, temp);
}

void keluaran(queue *q){
    typeName temp;
    temp = dequeue(q);
    if (temp != ' ')
        printf("Data yang diambil dari queue adalah \n%c\n", temp);
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

void tampil(queue *q) {
    int counter = q->front;
    if (empty(q))
        puts("queue kosong!!!");
    else {
        puts("Isi dari QUEUE : ");
        for (int i = 0; i < q->count ; i++) {
            printf("%c\n", q->data[counter%max]);
            counter++;
        }
        puts("");
    }
}