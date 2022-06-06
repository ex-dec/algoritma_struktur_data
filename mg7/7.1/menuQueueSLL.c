#include <stdio.h>
#include <stdlib.h>

typedef char typeName;
typedef struct simpul Node;
struct simpul{
    typeName data;
    Node *next;
};

typedef struct {
    Node *front, *rear;
} queue;

Node *p, *hapus;

// Operasi queue SLL
void inisialisasi(queue *);
int kosong(queue *);
// void enqueue(queue *);
void enqueue(queue *);
typeName dequeue(queue *);
void alokasi();
void bebas();

// Menu
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
    puts("Terima kasih!!!");
    return 0;
}

char menu(char opsi, queue *q){
    puts("Menu queue using Lingked List");
    puts("1. Mengisi Queue (ENQUEUE)");
    puts("2. Mengambil isi Queue (DEQUEUE)");
    puts("3. Menampilkan isi Queue -> FIFO");
    puts("4. Keluar");
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
        tampil(q);
        break;
    case '4':
        break;
    default:
        puts("Invalid Input!!!!");
        break;
    }
    puts("");
    return opsi;
}

void inisialisasi(queue *q){
    q->front = NULL;
    q->rear = NULL;
}

int kosong(queue *q) {
    return (q->front == NULL);
}

void enqueue(queue *q){
    if (kosong(q))
        q->front = q->rear = p;
    else{
        q->rear->next = p;
        q->rear = p;
    }
}

typeName dequeue(queue *q){
    typeName temp;
    if (kosong(q)) {
        puts("Queue kosong!!!");
        return ' ';
    } else {
        temp = q->front->data;
        hapus = q->front;
        if (q->front->next == NULL)
            q->front = NULL;
        else
            q->front = q->front->next;
        bebas();
        return temp;
    }
}

void alokasi(){
    p = (Node *) malloc(sizeof(Node));
    if (p == NULL) {
        puts("alokasi gagal");
        exit(0);
    } else
        p->next = NULL;
}

void bebas() {
    free(hapus);
    hapus = NULL;
}

void masukan(queue *q){
    alokasi();
    printf("Masukkan data anda : ");
    scanf("%c", &p->data);
    getchar();
    enqueue(q);
}

void keluaran(queue *q){
    typeName temp;
    temp = dequeue(q);
    if (temp != ' ')
        printf("Data yang diambil adalah \n%c\n", temp);
}

void tampil(queue *q){
    p = q->front;
    if (kosong(q))
        puts("Queue kosong!!");
    else {
        puts("Isi dari queue");
        while (p != NULL) {
            printf("%c\n", p->data);
            p = p->next;
        }
        puts("");
    }
}