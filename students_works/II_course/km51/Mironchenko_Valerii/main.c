#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>

typedef struct{
 char teacher_name[20];
 char teacher_surname[20];
 char teacher_patronymic[20];
 char subject[20];
 char academic_degree[20];
} teacher;

typedef struct{
 char student_name[20];
 char student_surname[20];
 char student_patronymic[20];
 int student_course;
 char student_groupname[5];
 int student_groupnumber;
} student;

enum bal_mark{
    Fx, // <36
    F,  // <60
    E,  // 60-64
    D,  // 65-74
    C,  // 75-84
    B,  // 85-94
    A   // 95-100
};

typedef struct{
 int mark;
 enum bal_mark bal_mark;
 bool got_credit;
} credit;



int main()
{
 setlocale(LC_ALL,"Russian");
 system("cls");

 teacher *teach = NULL;
 student *stud = NULL;
 credit  *cred = NULL;

 teach = (teacher*) malloc(sizeof(teacher));
 stud = (student*) malloc(sizeof(student));
 cred = (credit*) malloc(sizeof(credit));

 free(teach);
 free(stud);
 free(cred);
 return 0;
}
