#ifndef INPUT_H
#define INPUT_H
#include <stdbool.h>

void readLine(char *buffer, int size);
int readInt();
float readFloat();
int readIntRange(int min, int max);
char readChar();
bool readYesNo();

#endif