#include <stdio.h>
#include <stdlib.h>
#define max 5

typedef int typeName;
typedef struct {
    typeName data[max];
    int count;
    int front;
    int rear;
} queue;

typedef struct {
    typeName data[max];
    int count;
} stack;

typeName urutan;

// Operasi queue
void inisialisasiQueue(queue *);
int fullQueue(queue *);
int emptyQueue(queue *);
void enqueue(queue *);
typeName dequeue(queue *);

//operasi stack
void inisialisasiStack(stack *);
int fullStack(stack *);
int emptyStack(stack *);
void push(stack *, typeName);
typeName pop(stack *);

// menu
char menu(char, queue *, stack *);
int find(queue *, typeName);
void mobilKeluar(stack *, queue *, typeName);
typeName inputanKey();
void tampil(queue *);

int main() {
    char opsi = '0';
    queue q;
    stack s;
    inisialisasiQueue(&q);
    inisialisasiStack(&s);
    while (opsi != '4')
        opsi = menu(opsi, &q, &s);
    puts("Terima Kasih!!!");
    return 0;
}

char menu(char opsi, queue *q, stack *s){
    typeName key;
    puts("Menu parkir mobil using array :");
    puts("1. Mobil masuk");
    puts("2. Mobil keluar");
    puts("3. Tampilkan parkir mobil");
    puts("4. Selesai");
    printf("Masukkan pilihan anda : ");
    scanf("%c", &opsi);
    getchar();
    switch (opsi) {
    case '1':
        enqueue(q);
        break;
    case '2':
        key = inputanKey();
        if (find(q, key))
            mobilKeluar(s, q, key);
        else
            printf("Mobil %d tidak ada di parkiran\n", key);
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

typeName inputanKey(){
    typeName key;
    printf("Masukkan data : ");
    scanf("%d", &key);
    getchar();
    return key;
}

void mobilKeluar(stack *s, queue *q, typeName key){
    typeName temp;
    while(key != q->data[q->front]){
        push(s,q->data[q->front]);
        q->front = (q->front + 1) % max;
    }
    temp = q->data[q->front];
    if(!emptyStack(s)) {
        while(!emptyStack(s) ){
            q->data[q->front] = pop(s);
            if(!emptyStack(s))
                q->front = (q->front - 1) % max;
        }
        q->count--;
    } else
        dequeue(q);
    printf("Mobil nomor %d telah keluar dari parkiran\n", temp);
}

int find (queue *q, typeName key){
    typeName depan = q->front;
    do{
        if(q->data[depan] == key)
            return 1;
        depan = (depan + 1) % max;
    }while(depan != q->rear);
    return 0;
}

void tampil(queue *q){
    int counter = q->front;
    puts("");
    puts("Isi Parkiran Mobil : ");
    puts("==============================================================");
    if(emptyQueue(q)){
        printf("Parkiran Kosong");
    }else{
        for(int i = 0; i < q->count; i++){
            printf("\t%d",q->data[counter%max]);
            counter++;
        }
    }
    puts("\n==============================================================");
}

void inisialisasiQueue(queue *q) {
    q->count = 0;
    q->front = 0;
    q->rear = 0;
    urutan = 1;
}

int fullQueue(queue *q) {
    return(q->count == max);
}

int emptyQueue(queue *q) {
    return(q->count == 0);
}

void enqueue(queue *q) {
    if (fullQueue(q))
        puts("parkir penuh!");
    else {
        printf("Mobil nomor %d masuk\n", urutan);
        q->data[q->rear] = urutan;
        q->rear = (q->rear + 1) % max;
        q->count++;
        urutan++;
    }
}

typeName dequeue(queue *q) {
    typeName temp;
    if (emptyQueue(q)) {
        puts("Queue kosong!");
        return 0;
    }
    else {
        temp = q->data[q->front];
        q->front = (q->front + 1) % max;
        q->count--;
        return temp;
    }
}

void inisialisasiStack(stack *s){
    s->count = 0;
}

int fullStack(stack *s){
    return(s->count == max);
}

int emptyStack(stack *s){
    return(s->count == 0);
}

void push(stack *s, typeName x){
    if(fullStack(s))
        puts("Stack penuh");
    else {
        s->count++;
        s->data[s->count] = x;
    }
}

typeName pop(stack *s){
    typeName temp;
    if (emptyStack(s)){
        puts("Stack kosong");
        return 0;
    } else {
        temp = s->data[s->count];
        s->count--;
        return temp;
    }
}