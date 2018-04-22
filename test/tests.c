#include <stdio.h>
#include <ctest.h>
#include "command.h"
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

CTEST(move_suite, move_rook) // Ход Ладьи
{
	//GIVEN
	char board[8][8] = {
		"rhbqkbhr",
		"........",
		".....P..",
		"........",
		"........",
		"........",
		"PPPPP.PP",
		"RHBQKBHR" 
	};
	
	
	//WHEN//
	int coordinates[4];

	//Ход вперёд 
	coordinates[0] = 7;
	coordinates[1] = 0;     
	coordinates[2] = 7;
	coordinates[3] = 3;
	
	int check1 = move_checking(board, coordinates); 
	moving(board, coordinates); 	

	//Ход назад
	coordinates[0] = 7;
	coordinates[1] = 3;    
	coordinates[2] = 7;
	coordinates[3] = 2;

	int check2 = move_checking(board, coordinates); 
	moving(board, coordinates); 	

	//Ход влево
	coordinates[0] = 7;
	coordinates[1] = 2;     
	coordinates[2] = 6;
	coordinates[3] = 2;

	int check3 = move_checking(board, coordinates); 
	moving(board, coordinates); 	

	//Атака
	coordinates[0] = 6;
	coordinates[1] = 2;     
	coordinates[2] = 5;
	coordinates[3] = 2;

	int check4 = move_checking(board, coordinates);
	moving(board, coordinates);

	//Ход по диагонале 
	coordinates[0] = 5;
	coordinates[1] = 2;     
	coordinates[2] = 4;
	coordinates[3] = 3;

	int check5 = move_checking(board, coordinates); 

	//THEN//
	const int expected1 = 0;
	const int expected2 = 0;
	const int expected3 = 0;
	const int expected4 = 0;
	const int expected5 = 1;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
	ASSERT_EQUAL(expected4, check4);
	ASSERT_EQUAL(expected5, check5);
}

CTEST(move_suite, move_hourse) // Ход коня
{
	//GIVEN
	char board[8][8] = {
		"rhbqkbhr",
		"pppppppp",
		"........",
		"........",
		"....P...",
		"........",
		"PPPP.PPP",
		"RHBQKBHR" 
	};
	
	//WHEN//

	int coordinates[4];

	//ход Г(перевернутой)
	coordinates[0] = 6;
	coordinates[1] = 0;     
	coordinates[2] = 5;
	coordinates[3] = 2;

	int check1 = move_checking(board, coordinates); 
	moving(board, coordinates);

	//ход Г
	coordinates[0] = 1;
	coordinates[1] = 0;    
	coordinates[2] = 2;
	coordinates[3] = 2;

	int check2 = move_checking(board, coordinates); 
	moving(board, coordinates);

	//Атака
	coordinates[0] = 5;
	coordinates[1] = 2;    
	coordinates[2] = 4;
	coordinates[3] = 4;

	int check3 = move_checking(board, coordinates); 
	moving(board, coordinates);

	//ложный ход #1
	coordinates[0] = 4;
	coordinates[1] = 4;    
	coordinates[2] = 4;
	coordinates[3] = 5;

	int check4 = move_checking(board, coordinates); 

	//ложный ход #2
	coordinates[0] = 4;
	coordinates[1] = 4;     
	coordinates[2] = 4;
	coordinates[3] = 3;

	int check5 = move_checking(board, coordinates); 
	
	//THEN
	const int expected1 = 0;
	const int expected2 = 0;
	const int expected3 = 0;
	const int expected4 = 1;
	const int expected5 = 1;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
	ASSERT_EQUAL(expected4, check4);
	ASSERT_EQUAL(expected5, check5);
}