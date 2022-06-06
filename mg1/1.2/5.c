#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int d, m, y;
} Date;

void input(Date *, int);
int sameday(Date, Date);

int main() {
    Date day1, day2;
    input(&day1, 1);
    input(&day2, 2);
    if (sameday(day1,day2))
        printf("It is the same day\n\n");
    else
        printf("It is not same day\n\n");
    puts("");
    return 0;
}

void input(Date *date, int i){
    printf("Masukkan tanggal %d\n", i);
    printf("Tanggal\t: ");
    scanf("%d", &date->d);
    printf("Bulan\t: ");
    scanf("%d", &date->m);
    printf("Tahun\t: ");
    scanf("%d", &date->y);
}

int sameday(Date a, Date b) {
    if (a.y == b.y) {
        if (a.m == b.m) {
            if (a.d == b.d)
                return 1;
            else
                return 0;
        } else
            return 0;
    } else
        return 0;
}