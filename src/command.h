#ifndef COMMAND_H
#define COMMAND_H

#include <stdio.h>

// typedef struct {
//     char x;
//     char y;
// } piece ;


int move(char board[8][8]);

int* convert(char *string);

int swap(int* move, char board[8][8]); 

int* get_move(void);

int play_status(char board[8][8]);

int check_pawn(int* move, char board[8][8]);

int check_pawn_kill(int* move, char board[8][8]);

int check_place(int* move, int can_back, char board[8][8]);

int check_possible(int* move, char board[8][8]);

void chessboard(char board[8][8]);

void chop_down(int* move, char board[8][8]);



#endif
