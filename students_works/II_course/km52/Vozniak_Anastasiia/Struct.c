#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
typedef struct human { 
    char first_name[20];
	char last_name[20];
	char speciality[30];
    int age;
    char sex[6];
	int phone;
    struct human *next;
} human;
  
 
 void gotoxy(short x,short y)
{
 HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD coord = {x,y};
     SetConsoleCursorPosition(StdOut, coord);
}

  
  void show(human *tmp, int l) {
    int i;
    human *temp;
    temp=tmp;
    system("cls");
    printf("___________________________________________________________________________________________________________________\n");
    printf("|                         |                     |                               |        |        |                |\n");
    printf("|          First name     |        Last name    |           Speciality          |  Age   |   Sex  |     Phone      |\n");
    printf("|_________________________|_____________________|_______________________________|________|________|________________|");
    for (i=0; i<l; i++) {
        char *taken=strtok(temp->first_name,"\n");
        while (taken!=NULL) {
            printf("\n|%2d.%-21s ", i+1, taken);
            taken=strtok(NULL,"\n");
        }
        taken=strtok(temp->last_name,"\n");
        while (taken!=NULL) {
            printf("|%-21s", taken);
            taken=strtok(NULL,"\n");
        }
         taken=strtok(temp->speciality,"\n");
        while (taken!=NULL) {
            printf("|%-31s", taken);
            taken=strtok(NULL,"\n");
        }
        printf("|%-8d",temp->age);
        taken=strtok(temp->sex,"\n");
        while (taken!=NULL) {
            printf("|%-8s", taken);
            taken=strtok(NULL,"\n");
        }
        printf("|%-16d|",temp->phone);
        temp=temp->next;
    }
}

  int input(human *tmp, human *temp, human *ptr, int k) { 
    int i;
    char c,p,res,s;
    ptr=tmp;
    for (i=0;i<k-1;i++) {
        ptr=ptr->next;
    }
    while (1) { //нескінченний цикл
    system("cls");
    printf("\n\t\t \tPress ESC to exit or \n");
    printf("\t\t     press any key to continue ");
    c=getch();
    if (c==27) break;
    else
    temp=malloc(sizeof(human));
    
    printf("\n\n\tFirst name: ");
    scanf("%s", temp->first_name);
    while (strlen(temp->first_name) <2 || strlen (temp->first_name)>20){
    	printf("\n\tFirst name: ");
    scanf("%s", temp->first_name);
	}
    strcat(temp->first_name,"\n");
    
    printf("\n\tLast name: ");
    scanf("%s", temp->last_name);
    while (strlen(temp->last_name) <2 || strlen (temp->last_name)>20){
   	printf("\n\tLast name: ");
    scanf("%s", temp->last_name);
   }
    strcat(temp->last_name,"\n");
    
    printf("\n\tSpeciality: ");
    scanf("%s", temp->speciality);
    while (strlen(temp->speciality) <2 || strlen (temp->speciality)>30){
   	printf("\n\tSpeciality: ");
    scanf("%s", temp->speciality);
   }
    strcat(temp->speciality,"\n");
    
     do
  {
  	printf("\n\tAge: ");
    res=scanf("%d", &temp->age);
    fflush(stdin);
    if(res!=1)printf("\t\t Invalid input. Try again.\n");
  } while(res!=1 || (temp->age)<0);

     printf("\n\tSex (male or female): ");
    	 s=gets(temp->sex);
	while (s!='male' || s!='female'){
    	 printf("\n\tSex (male or female): ");
    	 gets(temp->sex);
	}

		strcat(temp->sex,"\n");
    
         do
  {
  	printf("\n\tPhone: ");
    res=scanf("%d", &temp->phone);
    fflush(stdin);
    if(res!=1)printf("\t\t Invalid input. Try again.\n");
  } while(res!=1 || (temp->phone)<0);
    
    ptr->next=temp;
    ptr=temp;
    ptr->next=NULL;
    k++;
    }
    return k;
}
 
 void fdelete (human *temp, int s) {//функція видалення елемента із списку
    human *tmp, *tmp1;
    int i;
    tmp=temp;
    if (s>1) {
        for (i=1; i<s-1; i++)
		 {
		 tmp=tmp->next;
		 }
        tmp1=tmp->next;
        tmp->next=tmp1->next;
    }
    printf("\n\t\t\tElement is deleted\n");
    printf("\t\tPress amy key");
    getch();
}

void save (human *temp, int k, char *name) {
    FILE *ftmp;
    human *tmp;
    int i;
    tmp=temp;
    ftmp=fopen(name, "w");
    for (i=0;i<k;i++) {
        fprintf(ftmp,"%s\n", tmp->first_name);
        fprintf(ftmp, "%s\n", tmp->last_name);
        fprintf(ftmp, "%s\n", tmp->speciality);
        fprintf(ftmp,"%d\n",tmp->age);
        fprintf(ftmp,"%s\n",tmp->sex);
        fprintf(ftmp,"%d\n",tmp->phone);
        tmp=tmp->next;
    }
    fclose(ftmp);
}

int main()
{
	setlocale(LC_ALL,"rus");
	system ("mode con cols=140 lines=80");
    char tmp[20],temp[15],l,p,t;
    human *begin, *act, *add;
    FILE *file;
    int k,m, c;
    while (1){
	 system("cls");
    gotoxy(20,3);printf("1.Download file");
    gotoxy(20,4);printf("2.Show list");
    gotoxy(20,5);printf("3.Add element");
    gotoxy(20,6);printf("4.Delete element");
    gotoxy(20,7);printf("5.Save");
    gotoxy(20,8);printf("6.Exit");
    l=getch();
    switch (l) {
		case '1': {    while(1){
        system("cls");
       char *t="file.txt";
        file=fopen(t,"r");
        if (file!=NULL) {
		 gotoxy (10,10); printf("Press ane key");
			getch();
		}
			break;
   }
    k=0;
    while (!feof(file)) {
        if (k==0) {
           begin=malloc(sizeof(human));
           begin->next=NULL;
           fgets(begin->first_name,21,file);
           fgets(begin->last_name,21,file);
           fgets(begin->speciality,31,file);
           fgets(temp,4,file);
           begin->age=atoi(temp);
           fgets(begin->sex,7,file);
           fgets(temp,15,file);
           begin->phone=atoi(temp);
           act=begin;
        }
        else {
            add=malloc(sizeof(human));
            add->next=NULL;
            fgets(add->first_name,21,file);
            fgets(add->last_name,21,file);
            fgets(add->speciality,31,file);
           fgets(temp,4,file);
           add->age=atoi(temp);
           fgets(add->sex,8,file);
           fgets(temp,15,file);
           add->phone=atoi(temp);
            act->next=add;
            if (k==1) {
                begin=act;
            }
            act=add;
        }
        k++;
    }
    fclose(file);
        } 
        case '2':
            system("cls");
            show(begin, k);
            printf("\n\n\t\t\t\tPress any key");
            getch();
            break;
            
        case '3':
            k=input(begin,add,act,k);
            break;
            
			case '4':
            system("cls");
            printf("\n\n\n\n\t\t What item you want to delete?  ");
            scanf("%d",&m);
            if (m==1) {begin=begin->next;}
            fdelete(begin,m);
            k--;
            break;
            
        case '5':
            save(begin,k,tmp);
            system("cls");
           printf("\n\n\n \t\t\t Data save. Press any key");
            getch();
            break;
			 
        case '6':
            return 0;
           }
       }
return 0;
}


  

