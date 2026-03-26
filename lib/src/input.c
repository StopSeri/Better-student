#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "input.h"

void readLine(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

int readInt() {
    char buffer[100];
    char *end;
    long value;

    while (1) {
        readLine(buffer, sizeof(buffer));

        value = strtol(buffer, &end, 10);

        if (end != buffer && *end == '\0') {
            return (int)value;
        }

        printf("Invalid input. Please enter a valid integer: ");
    }
}

float readFloat() {
    char buffer[100];
    char *end;
    float value;

    while (1) {
        readLine(buffer, sizeof(buffer));

        value = strtof(buffer, &end);

        if (end != buffer && *end == '\0') {
            return value;
        }

        printf("Invalid input. Please enter a valid number: ");
    }
}

int readIntRange(int min, int max){

    char buffer[100];
    char *end;
    long value;

    while (1){
        readLine(buffer, sizeof(buffer));

        value = strtol(buffer, &end, 10);

        if (end != buffer && *end == '\0'){
            if(value < min || value > max){
                printf("Invalid input, enter a value between %d and %d\n", min, max);
            }
            else{
                return (int)value;
            }
        }
        else{
        printf("Invalid input. Please enter a valid integer\n");
        }
    }

}

char readChar(){
    char buffer[10];

    while(1){
        readLine(buffer, sizeof(buffer));
        if(strlen(buffer) == 1){
            return buffer[0];
        }
        else{
            printf("Please enter a valid character\n");
        }
    }
}

bool readYesNo(){
    char buffer;

    while (1){
        buffer = readChar();
        buffer = tolower(buffer);
        if (buffer == 'y'){
            return true;
        }
        else if(buffer == 'n'){
            return false;
        }
        else{
            printf("Please enter Y/N\n");
        }
    }
}