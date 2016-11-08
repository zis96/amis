#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>



typedef struct timeS{
    int day;
    int hour;
}TIMES;

typedef struct student {
    char name[20];
    char surname[20];
    int  course;
    char group[10];
    TIMES * timeS_info;
}STUDENT;



typedef struct timeL{
    int day;
    int hour;
}TIMEL;

typedef struct lector {
    char name[20];
    char surname[20];
    char   ready_for_lection[5];
    TIMEL * timeL_info;
}LECTOR;



typedef struct timeR{
    int day;
    int hour;
}TIMER;

typedef struct room {
    int  number_of_room;
    int  number_of_building;
    int  quantaty_of_chairs;
    char existance_of_desk[5];
    char existance_of_chalk[5];
    TIMER * timeR_info;
}ROOM;



main()
{
    system("cls");

    STUDENT * student = NULL;
    TIMES   * timeS   = NULL;
    LECTOR  * lector  = NULL;
    TIMEL   * timeL   = NULL;
    ROOM    * room    = NULL;
    TIMER   * timeR   = NULL;

    student = ( STUDENT *)malloc(sizeof( STUDENT));
    timeS   = ( TIMES *)malloc(sizeof(   TIMES));
    lector  = ( LECTOR *) malloc(sizeof( LECTOR));
    timeL   = ( TIMEL *)malloc(sizeof(   TIMEL));
    room    = ( ROOM *)malloc(sizeof(    ROOM));
    timeR   = ( TIMER *)malloc(sizeof(   TIMER));

    strcpy( student -> name, "Sasha");
    strcpy( student -> surname, "Kharytonchyk");
    student -> course = 2;
    strcpy( student -> group, "KM-53");
    timeS -> day  = 1;
    timeS -> hour = 2;

    strcpy( lector -> name, "Igor");
    strcpy( lector -> surname, "Tereshchenko");
    strcpy( lector -> ready_for_lection, "True");
    timeL -> day  = 3;
    timeL -> hour = 4;

    room -> number_of_room     = 72;
    room -> number_of_building = 14;
    room -> quantaty_of_chairs = 26;
    strcpy( room -> existance_of_desk,  "True");
    strcpy( room -> existance_of_chalk, "False");
    timeR -> day  = 5;
    timeR -> hour = 6;

    printf("Student : %s %s ; Course : %d ; Gruoup : %s \n",
           student->name, student->surname, student->course, student->group);
    printf("Comfortable day and hour for student : %d    %d \n\n", timeS->day, timeS->hour);
    printf("Lector : %s %s ; Is he ready for the lection : %s \n",lector->name,
           lector->surname, lector->ready_for_lection);
    printf("Comfortable day and hour for lector : %d    %d \n\n", timeL->day, timeL->hour);
    printf("Number of room : %d ; Number of building : %d ; Quantaty of chairs : %d ; Does there exist a desk : %s ; Does there exist a chalk : %s\n",
           room->number_of_room, room->number_of_building, room->quantaty_of_chairs, room->existance_of_desk, room->existance_of_chalk);
    printf("Comfortable day and hour for room : %d    %d \n\n", timeR->day, timeR->hour);
    system("pause");

    free(student);
    free(timeS);
    free(lector);
    free(timeL);
    free(room);
    free(timeR);

    return 0;
}