#include <stdio.h>
#include <stdlib.h>

typedef char item;
typedef struct simpul Node;
struct simpul{
    item data;
    Node *next;
};

typedef struct {
    int count;
    Node *front, *rear;
} queue;

void inisialisasi(queue *);
int kosong(queue *);
void enqueue(queue *);
item dequeue(queue *);
void tampil(queue *);
char menu(char, queue *);

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
    item x;
    puts("Menu queue using Lingked List");
    puts("1. Mengisi Queue (ENQUEUE)");
    puts("2. Mengambil isi Queue (DEQUEUE)");
    puts("3. Menampilkan isi Queue -> FIFO");
    puts("4. Keluar");
    printf("Masukkan pilihan anda : ");
    fflush(stdin);
    scanf("%c", &opsi);
    switch (opsi ) {
    case '1':
        enqueue(q);
        break;
    case '2':
        if (!kosong(q)){
            x = dequeue(q);
            printf("Data yang diambil adalah %c\n", x);
        } else
            puts("Queue masih kosong!!!");
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
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

int kosong(queue *q) {
    return (q->front == NULL);
}

void enqueue(queue *q){
    Node *p;
    p =(Node *)malloc(sizeof(Node));
    printf("Masukkan data anda : ");
    fflush(stdin);
    scanf("%c", &p->data);
    if (kosong(q)){
        q->front = q->rear = p;
    } else {
        q->rear->next = p;
        q->rear = p;
        q->count++;
    }
}

item dequeue(queue *q){
    Node *hapus;
    item a;
    if (kosong(q)) {
        puts("Queue kosong!!!");
        return ' ';
    }
    a = q->front->data;
    hapus = q->front;
    if (q->front->next == NULL)
        q->front = NULL;
    else
        q->front = q->front->next;
    q->count--;
    free(hapus);
    hapus = NULL;
    return a;
}

void tampil(queue *q){
    Node *p = q->front;
    if (kosong(q))
        puts("Queue masih kosong!!");
    else {
        puts("Isi dari queue");
        do
        {
            printf("%c\n", p->data);
            p = p->next;
        } while (p->next != NULL);
        puts("");
    }
}