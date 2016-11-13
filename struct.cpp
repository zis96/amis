#include "windows.h"
#include<conio.h>
#include<stdio.h>

typedef char student_status_type;
typedef char work_status_type;

struct Student
{
	char surname[80];
	char name[80];
	char father_name[80];
	student_status_type *student_status;           //  склав/не склав
	unsigned short mark_quantity;                               //  0-100
	char mark;                                                  //  A, B, C, D, E
};

struct Examiner
{
	char surname[80];
	char name[80];
	char father_name[80];
};

struct Examination_work
{
	int variant;
	work_status_type *work_status;   //  написана/не написана
};

int main()
{
	SetConsoleOutputCP(1251);
	struct Examiner *examiner;
	examiner=(Examiner*)malloc(sizeof(Examiner));
	strcpy(examiner->surname,"Чертов");
	strcpy(examiner->name,"Олег");
	strcpy(examiner->father_name,"Романович");
	printf("Екзаменатор: %s %s %s",examiner->surname,examiner->name,examiner->father_name);
	getch();
	free(examiner);
	return(0);
}
