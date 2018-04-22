#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdio.h>

void showboard(char board[8][8]); 

int* interpretator(char* string);

int make_move(char board[8][8]);

void swap(int* from_to, char board[8][8]);

void chop_down(int* move, char board[8][8]);

int update_status(char board[8][8]);

#endif