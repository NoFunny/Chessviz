#include <stdio.h>
#include "command.h"
#include "check.h"

int main()
{
	char board[8][8] = {
 		"rhbqkbhr",
 		"........",
 		"........",
 		"........",
 		"........",
 		"........",
 		"PPPPPPPP",
 		"RHBQKBHR" 
 	};

	int game_status = 1;

	showboard(board);

	while(game_status) {
		switch(game_status) {
		case 0:
			printf("Game over(case 0)\n");
			return 0;
		case 1:
			make_move(board);
			game_status = update_status(board);
		}
	}
	printf("Game over(end)\n");
	return 0;
}