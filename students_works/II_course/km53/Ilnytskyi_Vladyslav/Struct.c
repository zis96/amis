#include <conio.h>
#include <stdio.h>

#define max_length 20

struct Abiturient {
  char[] first_name;
  char[] last_name;
  char[] middle_name;
  int age;
  Rating * rating;
  Auth * authorization_info;
};

typedef struct Auth {
  char login[max_length];
  char password[max_length];
} Auth;

typedef struct Rating {
  int rating_of_abiturient;
  char[] privileges;
} Rating; 

struct ZNO_task {
  int num_of_questions;
  int time_for_writing;
  char[] text_of_tasks;
};

typedef struct University {
  char[] name_of_university;
  int rating;
} university;

int main () {
  Abiturient *abiturient = NULL;
  abiturient = (Abiturient*) malloc(sizeof(Abiturient));
  strcpy(abiturient->first_name, "Vlad");
  strcpy(abiturient->last_name,  "Ilnitskiy");
  strcpy(abiturient->age,  19);
  free(abiturient);
  return 0;
}
