#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int d, m, y;
}Date;

typedef struct {
    char name[60];
    Date dob;
} Student;

int isYounger(Student, Student);
void input(Student *);

int main(){
    Student stud1, stud2;
    puts("Masukan data mahasiswa 1");
    input(&stud1);
    puts("Masukan data mahasiswa 2");
    input(&stud2);
    if (isYounger(stud1,stud2))
        printf("%s lebih muda daripada %s\n", stud2.name, stud1.name);
    else
        printf("%s lebih muda daripada %s\n", stud1.name, stud2.name);
}

void input(Student *stud){
    fflush(stdin);
    printf("Nama\t\t: ");
    gets(stud->name);
    printf("Tanggal lahir\t: ");
    scanf("%d", &stud->dob.d);
    printf("Bulan lahir\t: ");
    scanf("%d", &stud->dob.m);
    printf("Tahun UAS\t: ");
    scanf("%d", &stud->dob.y);
}

int isYounger(Student stud1, Student stud2){
    if (stud1.dob.y<=stud2.dob.y) {
        if (stud1.dob.m<=stud2.dob.m) {
            if (stud1.dob.d<=stud2.dob.d) {
                return 1;
            }
            else
                return 0;
        } else
            return 0;
    } else
        return 0;
}