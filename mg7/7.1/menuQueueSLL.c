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

// Operasi queue SLL
void inisialisasi(queue *);
int kosong(queue *);
void enqueue(queue *, Node *);
typeName dequeue(queue *);
void alokasi(Node *);
void bebas(Node *);

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

void enqueue(queue *q, Node *p){
    if (kosong(q))
        q->front = q->rear = p;
    else{
        q->rear->next = p;
        q->rear = p;
    }
}

typeName dequeue(queue *q){
    Node *hapus;
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
        bebas(hapus);
        return temp;
    }
}

void alokasi(Node *p){
    p = (Node *) malloc(sizeof(Node));
    if (p == NULL) {
        puts("alokasi gagal");
        exit(0);
    } else
        p->next = NULL;
}

void bebas(Node *hapus) {
    free(hapus);
    hapus = NULL;
}

void masukan(queue *q){
    Node *p;
    alokasi(p);
    printf("Masukkan data anda : ");
    fflush(stdin);
    scanf("%c", &p->data);
    enqueue(q, p);
}

void keluaran(queue *q){
    typeName temp;
    temp = dequeue(q);
    if (temp != ' ')
        printf("Data yang diambil adalah \n%c\n", temp);
}

void tampil(queue *q){
    Node *p;
    p = q->front;
    if (kosong(q))
        puts("Queue masih kosong!!");
    else {
        puts("Isi dari queue");
        while (p->next != NULL) {
            printf("%c\n", p->data);
            p = p->next;
        }
        puts("");
    }
}