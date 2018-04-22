#include <stdio.h>
#include <ctest.h>
#include "commands.h"
#include "check.h"

CTEST(move_suite, move_pawn) // Ход пешки 
{	
	//GIVEN
	char board[8][8] = {
		"rhbqkbhr",
		"pppppppp",
		"........",
		"........",
		"........",
		"........",
		"PPPPPPPP",
		"RHBQKBHR" 
	};
	
	//WHEN
	int coordinates[4];
	////////Проверка хода вперёд////////////

	coordinates[0] = 1;
	coordinates[1] = 1;
	coordinates[2] = 1;
	coordinates[3] = 2;

	int check1 = move_checking(board, coordinates); 

	///////Проверка хода по диагонали//////////
	coordinates[0] = 2;
	coordinates[1] = 1;    
	coordinates[2] = 3;
	coordinates[3] = 2;
	
	int check3 = move_checking(board, coordinates);

	/////////Проверка хода назад////////
	coordinates[0] = 4;
	coordinates[1] = 1;     
	coordinates[2] = 4;
	coordinates[3] = 3;

	moving(board, coordinates);

	coordinates[0] = 4;
	coordinates[1] = 3;    
	coordinates[2] = 4;
	coordinates[3] = 2;

	int check2 = move_checking(board, coordinates);
	
	//////проверка на возможность рубить пешкой////
	coordinates[0] = 5;
	coordinates[1] = 1;   
	coordinates[2] = 5;
	coordinates[3] = 3;

	moving (board, coordinates); 

	coordinates[0] = 6;
	coordinates[1] = 6;    
	coordinates[2] = 6;
	coordinates[3] = 4;

	moving (board, coordinates); 

	coordinates[0] = 5;
	coordinates[1] = 3;   
	coordinates[2] = 6;
	coordinates[3] = 4;

	int check4 = move_checking(board, coordinates); 

	//THEN//
	const int expected1 = 0;
	const int expected2 = 1;
	const int expected3 = 1;
	const int expected4 = 0;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
	ASSERT_EQUAL(expected4, check4);
}