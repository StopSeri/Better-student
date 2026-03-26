#ifndef STUDENT_H
#define STUDENT_H
#include <stdbool.h>

typedef struct Student{
    char name[50];
    int id;
    float gpa;
    struct Student *next;
} Student;

void addStudent(Student **head);
void removeStudent(Student **head);
void searchStudent(Student *head);
void editStudent(Student *head);
void listStudent(Student *head);
void saveStudent(Student *head);
void loadStudent(Student **head);

#endif