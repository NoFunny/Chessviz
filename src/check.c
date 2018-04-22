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