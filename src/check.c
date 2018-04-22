#include "check.h"
#include "commands.h"

int data_checking(char *coordinates) {

        int i, flag = 0;
        char abc[8] = {'a','b','c','d','e','f','g','h'};
        char numb[8] = {'1','2','3','4','5','6','7','8'};
       	
        for (i = 0; i < 8; i++) {
                if (coordinates[0] == abc[i]) 
                        flag++;
                if (coordinates[1] == numb[i])
                        flag++;
                if  (coordinates[2] == abc[i])
                        flag++;
                if (coordinates[3] == numb[i])
                        flag++;
        }
        if (flag != 4) {
        	printf("flag = %d\nОшибка данных\n", flag);
           return -1;      
        }
        if (flag == 4) {
            return 0;
        }
        return -1;
}

int move_checking(char m[8][8], int *c) {

    int i, j;
    if (m[c[1]][c[0]] == m[c[3]][c[2]])
        return 1;
    
//Пешка
    if(m[c[1]][c[0]] == 'p' && (m[c[3]][c[2]] == '.')) {
            if(((c[0] - c[2]) == 0) && ((c[3] - c[1]) < 0)) {
                return 1;
            }
            if(((c[0] - c[2]) == 0) && ((c[3] - c[1]) > 2)) {
                return 1;
            }
            if(((c[2] - c[0]) != 0) && ((c[3] - c[1]) > 0)) {
                return 1;
            }
    }

    if(m[c[1]][c[0]] == 'P' && (m[c[3]][c[2]] == '.')) {
        if(((c[0] - c[2]) == 0) && ((c[1] - c[3]) < 0)) {
            return 1;
        }
        if(((c[0] - c[2]) == 0) && ((c[1] - c[3]) > 2)) {
            return 1;
        }
        if(((c[2] - c[0]) != 0) && ((c[3] - c[1]) < 0)) {
            return 1;
        }
    }
    if (m[c[1]][c[0]] == 'p' || m[c[1]][c[0]] == 'P') {
        if((m[c[1]][c[0]] == 'p' && m[c[3]][c[2]] == 'P') || (m[c[1]][c[0]] == 'P' && m[c[3]][c[2]] == 'p')) { 
       
            if (((c[0] + 1) == c[2]) && ((c[1] - 1) == c[3]))
                return 0;
            if (((c[0] + 1) == c[2]) && ((c[1] + 1) == c[3]))
                return 0;
            if (((c[0] - 1) == c[2]) && ((c[1] - 1) == c[3]))
                return 0;
            if (((c[0] - 1) == c[2]) && ((c[1] + 1) == c[3]))
                return 0;
        }


        if (m[c[3]][c[2]] == '.') {
            if (c[1] == 1 && c[3] < 4 && c[3] > 1 && c[0] == c[2] && m[c[1]+1][c[0]] == '.')
                return 0;
            if (c[1] == 6 && c[3] > 3 && c[3] < 6 && c[0] == c[2] && m[c[1]-1][c[0]] == '.')
                return 0;
            if (m[c[1]][c[0]] == 'p' && c[1] != 6 && c[3] == (c[1] - 1) && c[0] == c[2]) 
                return 0;
            if (m[c[1]][c[0]] == 'P' && c[1] != 1 && c[3] == (c[1] + 1) && c[0] == c[2])
                return 0;
        }
         return 0;
    } 