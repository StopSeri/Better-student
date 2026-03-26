#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include "input.h"
#include "student.h"

static int nextID = 1000;

void addStudent(Student **head){

    Student *newNode = malloc(sizeof(Student));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->id = nextID;
    nextID += 1;

    printf("Enter students name: ");
    readLine(newNode->name, sizeof(newNode->name));

    printf("Enter students gpa: ");
    newNode->gpa = readFloat();

    if (*head == NULL){
        *head = newNode;
        return;
    }

    Student *current = *head;
    while (current->next != NULL){
        current = current->next;
    }

    current->next = newNode;

}

void removeStudent(Student **head){
    int tempID = 0;

    if (*head == NULL){
        printf("No students to remove!\n");
        return;
    }
    
    printf("Enter Student ID to be removed or enter '-1' to cancel: ");
    tempID = readInt();
    if(tempID == -1){
        printf("Student removal cancelled!\n");
        return;
    }

    Student *current = *head;
    Student *previous = NULL;
    while (current != NULL){
        if (current->id == tempID){
            if (*head == current){
                *head = current->next;
                free(current);
                printf("Student %d has been removed!\n", tempID);
                return;
            }
            else{
                previous->next = current->next;
                free(current);
                printf("Student %d has been removed!\n", tempID);
                return;
            }

        }
        previous = current;
        current = current->next;
    }
    printf("Student ID not found!\n");

}

void searchStudent(Student *head){
    char input[50];
    bool found = false;

    if (head == NULL){
        printf("No students to Search!\n");
        return;
    }

    while (1) {

        printf("Enter student name/ID to search or enter 'X' to cancel: ");
        readLine(input, sizeof(input));

        int pSID = atoi(input);

        if(strcmp(input, "x") == 0 || strcmp(input, "X") == 0){
            printf("Student search cancelled!\n");
            return;
        }

        Student *current = head;
        found = false;

        while(current != NULL){
            if (current->id == pSID || strcmp(input, current->name) == 0){
                found = true;
                printf("Name: %s\nSID: %d\nGPA: %.2f\n", current->name, current->id, current->gpa);
                break;
            }
            current = current->next;
        }
        if(!found){
            printf("Student not found!\n");
        }
    }

}

void editStudent(Student *head){
    
    bool found = false;
    int tempID = 0; 
    float tGpa = 0;
    char name[50];  
    bool confirmation = true; 
    
    if (head == NULL){
        printf("No students to Search!\n");
        return;
    }

    while (1){
        printf("Enter student ID to edit or enter '-1' to cancel: ");
        tempID = readInt();

        if(tempID == -1){
            printf("Student editor cancelled!\n");
            return;
        }

        Student *current = head;
        found = false;

        while(current != NULL){
            if(current->id == tempID){
                confirmation = false;
                do{
                    found = true;
                    printf("Enter new name or leave blank to leave unchanged: ");
                    readLine(name, sizeof(name));

                    if(strlen(name) == 0){

                    }
                    else{
                        strcpy(current->name, name);
                    }
                    printf("Enter new gpa or enter '-1' to leave unchanged: ");
                    tGpa = readFloat();
                    if(tGpa == -1){

                    }
                    else{
                        current->gpa = tGpa;
                    }
                    printf("Name: %s\nSID: %d\nGpa: %.2f\n", current->name, current->id, current->gpa);
                    printf("Does this information look correct? (Y/N): ");
                    confirmation = readYesNo();

                    }while(!confirmation);
                break;
            }
            current = current->next;
        }
        if(!found){
            printf("Student %d not found!\n", tempID);
        }
    }

}

void listStudent(Student *head){

    if (head == NULL){
        printf("No students to Search!\n");
        return;
    }

    Student *current = head;

    while(current != NULL){
        printf("--------------------\n");
        printf("Name: %s\nSID: %d\nGPA: %.2f\n", current->name, current->id, current->gpa);
        current = current->next;
        Sleep(700);
    }
}

void saveStudent(Student *head){

    if (head == NULL){
        printf("No students to Save!\n");
        return;
    }

    FILE *fp = fopen("student.txt", "w");

    if(fp == NULL){
        printf("error creating file");
        return;
    }

    Student *current = head;

    while(current != NULL){
        fprintf(fp, "%s,%d,%.2f\n", current->name, current->id, current->gpa);
        current = current->next;
    }

    fclose(fp);
    return;

}

void loadStudent(Student **head){

    Student *current = *head;
    while (current != NULL) {
        Student *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;

    char buffer[60];

    FILE *fp = fopen("student.txt", "r");

    if(fp == NULL){
        printf("error opening file");
        return;
    }

    while(fgets(buffer, sizeof(buffer), fp) != NULL){

        buffer[strcspn(buffer, "\n")] = '\0';

        char *name = strtok(buffer, ",");
        char *id = strtok(NULL, ",");
        char *gpa = strtok(NULL, ",");

        Student *newNode = malloc(sizeof(Student));

        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            fclose(fp);
            return;
        }

        newNode->next = NULL;

        if (name && id && gpa){
            strcpy(newNode->name, name);
            newNode->id = atoi(id);
            newNode->gpa = atof(gpa);
        }
        else{
            printf("Warning skipping malformed line.\n");
            free(newNode);
            continue;
        }

        if(*head == NULL){
            *head = newNode;
        }
        else{
            Student *current = *head;
            while (current->next != NULL){
                current = current->next;
            }
            current->next = newNode;
        }
    }
    fclose(fp);
    printf("Student info loaded!\n");
    return;

}