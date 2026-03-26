#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include "input.h"
#include "student.h"

int main(){

    Student *head = NULL;
    int option = 0;
    int choice = 0;
    bool goBack = false;
    bool closeProgram = false;

    printf("Welcome to the Student Database!\nWhat would you like to do today?\n");

    while(1){
        printf("1. Student options\n2. Save/Load options\n3. Exit\nEnter option: ");
        option = readIntRange(1, 3);

        switch(option){
            case 1:
                while (1){
                    printf("Student options!\n");
                    printf("1. Add student\n2. Remove student\n3. Edit student info\n4. List students\n5. Search student\n6. Exit\nEnter option: ");
                    choice = readIntRange(1, 6);
                    goBack = false;

                    switch(choice){
                        case 1:
                            addStudent(&head);
                            break;
                        case 2:
                            removeStudent(&head);
                            break;
                        case 3:
                            editStudent(head);
                            break;
                        case 4:
                            listStudent(head);
                            break;
                        case 5:
                            searchStudent(head);
                            break;
                        case 6:
                            printf("Goodbye!\n");
                            goBack = true;
                            break;
                    
                    }
                    if(goBack) break;
                }
                break;
            case 2:
                while(1){
                    printf("Save/Load options\n");
                printf("1. Save students to file\n2. Load students from file\n3. Exit\nEnter option: ");
                choice = readIntRange(1, 3);
                goBack = false;

                switch(choice){
                    case 1:
                        saveStudent(head);
                        break;
                    case 2:
                        loadStudent(&head);
                        break;
                    case 3:
                        printf("Goodbye!\n");
                        goBack = true;
                        break;
                }
                if(goBack) break;
                }
                break;
            case 3: 
                printf("Closing program any unsaved progress will not be saved!");
                printf("Do you wish to proceed? (Y/N): ");
                closeProgram = readYesNo();

                if(closeProgram){
                    printf("Goodbye\n");
                    Sleep(1000);
                    return 0;
                }
                else{
                    break;
                }
        }
    }

}