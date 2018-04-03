#include <stdio.h>
#include "command.h"

int main() {

char board[8][8] = {
		"rnbqkbnr", // 1 
		"pppppppp", // 2
		"........", // 3
		"........", // 4
		"........", // 5
		"........", // 6
		"PPPPPPPP", // 7
		"RNBQKBNR"  // 8
       //ABCDEFGH
};

	int game_status = 1;

	chessboard(board);

	while(game_status) {
		switch(game_status) {
			case 0:
				printf("Game Ended\n");
				return 0;
			default:		
				move(board);
				game_status = play_status(board);
		}
	}
	printf("Game Ended\n");
	return 0;
}
