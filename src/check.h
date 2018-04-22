#ifndef CHECKS_H
#define CHECKS_H

#include <stdio.h>

int data_checking(char *coordinates);

int move_checking(char m[8][8], int *c);

void moving(char m[8][8], int *c);

#endif