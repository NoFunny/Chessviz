#include <ctype.h>
#include "command.h"

int move(char board[8][8]) {
    int *move = get_move();
    if (move == NULL) {
        printf("Incorrect input\n");
        return 0;
    }
    if (check_possible(move, board) == 0) {
        chop_down(move, board);
       	 return 1; 
    }
    printf("Move not possible!");
    return 0;
}

int* convert(char *string) {
	static int reserv[4];
	int pr = 1, i;

	reserv[0] = string[0] - 'a';//Ввод Букв
	reserv[2] = string[2] - 'a';//

	reserv[1] = string[1] - '1';//Ввод цифр
	reserv[3] = string[3] - '1';//

	for(i = 0; i < 4; i++) {
		if(reserv[i] < 8) {	
			pr = pr + reserv[i];
			if(pr == 0) 
				return NULL;
			}
		}
	return reserv;//Конвертированное значение	
}

int* get_move(void) {
	char move_of[4];
	int i;
	printf("Enter move:");//Просит ввести ход
	for(i = 0; i < 4; i++) 
		move_of[i] = tolower(getchar());
	while(getchar() != '\n');
		return convert(move_of);
}

int swap(int* move, char board[8][8]) {

	char tmp = board[move[1]][move[0]];
	board[move[1]][move[0]] = board[move[3]][move[2]];
	board[move[3]][move[2]] = tmp;
	chessboard(board);//Выводит обновленную доску
	return 0;
}

void chessboard(char board[8][8]) {
    int i, j;
	printf("\n");
    for (i = 7; i >= 0; i--) {
        printf("%d|", i + 1);
        for (j = 0; j < 8; j++) {
            printf(" %c", board[i][j]);
        }
    printf("\n");
    }
	printf("   _______________\n");
	printf("   A B C D E F G H\n");
}


int play_status(char board[8][8])
{	
    int i, j, king = 0;
    for (i = 0; i < 8; i++){
        for (j = 0; j <8; j++){
            if (tolower(board[i][j]) == 'k'){
                king++;
                if (king == 2)
                return 1;
            } 
        }
    }
    return 0;
}

int check_pawn(int* move, char board[8][8]) {
    int can_back = 0;
    int possible = 0;
    if (check_place(move, can_back, board) 
        || check_pawn_kill(move, board)) {
        possible = 1;
        }
    return possible;
}    

int check_pawn_kill(int* move, char board[8][8]) {
    int possible = 0;
    return possible;
}

int check_place(int* move, int can_back, char board[8][8]) 	{
    int possible = 0;
    int i;
    if (move[0] == move[3]) {
        if (!can_back){
            if (tolower(board[move[0]][move[1]]) == board[move[0]][move[1]]) { //проверка цвета 1- белый, 0- чёрный
                for (i = move[1]; i <= move[3]; i++) {
                    
                }
            }else{
                for (i = move[3]; i >= move[1]; i--) {
                    
                }
            }
        }else{
            for (i = move[1]; i <= move[3]; i++) {
                
            }
        }
    }
    return possible;
}

int check_possible(int* move, char board[8][8])
{
    int possible = -1;
    switch(tolower(board[move[0]][move[1]])){
    default:
        possible = 0;
        break;
    }
    return possible;
}

void chop_down(int* move, char board[8][8]) {
    board[move[3]][move[2]] = '.';
    swap(move, board);
}
