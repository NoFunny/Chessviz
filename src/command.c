#include <string.h>
#include <ctype.h>
#include "commands.h"
#include "check.h"


void showboard(char board[8][8])
{
    int i,j;
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

int* interpretator(char* moves)
{
    static int result[4];  
    
    result[0] = moves[0] - 'a';
    result[1] = moves[1] - '1';
    result[2] = moves[2] - 'a';
    result[3] = moves[3] - '1';
    
    return result;
}
 
int make_move(char board[8][8])
{
    int i, move;
    char coordinates[4];
    int *res;

    printf("Сделайте ход:"); 

    for ( i = 0; i < 4; i++ ) {
        coordinates[i] = tolower(getchar());
    }
    while(getchar() != '\n');
    ////////////////Проверка ввода путей//////////////////////
    if( data_checking(coordinates) == 0 ) {
        res = interpretator(coordinates);
        if ( res != NULL) {
            move = move_checking(board, res);
        }
        if( data_checking(coordinates) == -1 ) {
            printf("Error#101(data_checking)\n");
        }
    }

    if( move == 1 ){
        printf("Error#102(move_checking)\n");
        return -1;
    }
    if( move == 0 ){
        moving(board, res);
        printf("Correct coordinates(3)\n");
        return 0;
    }
    return -1;
}

int update_status(char board[8][8])
{
    int i,j;
    int king = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (tolower(board[i][j]) == 'k') {
                king++;
                if (king == 2)
                return 1;
            } 
        }
    }
    return 0;
}
