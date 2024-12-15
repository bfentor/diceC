#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include <sys/time.h>
#include <unistd.h> 

#include <string.h>

#include <sys/ioctl.h>

int *mkList(int list[], int num) {

    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand ( tv.tv_usec );
    for (int i = 0; i < num; i++) {
        list[i] = rand() % 6;
    }

    return list;
}
void draw(int num, char dice [][5][10], int list[]) {

    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < num; k++) {
            printf("%s  ", dice[list[k]][i]);
        }
        printf("\n");
    }
}

int getNumDice (void)
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    return (w.ws_col / 11);
}

int main(int argc, char **argv) {

    int num = 1;
    if (argc > 1 )
    	num = atoi(argv[1]);
            
	// List of generated random numbers
    char dice [6][5][10];
    strcpy(dice[0][0], "+-------+");
    strcpy(dice[0][1], "|       |");
    strcpy(dice[0][2], "|   O   |");
    strcpy(dice[0][3], "|       |");
    strcpy(dice[0][4], "+-------+");
    
    strcpy(dice[1][0], "+-------+");
    strcpy(dice[1][1], "| O     |");
    strcpy(dice[1][2], "|       |");
    strcpy(dice[1][3], "|     O |");
    strcpy(dice[1][4], "+-------+");

    strcpy(dice[2][0], "+-------+");
    strcpy(dice[2][1], "| O     |");
    strcpy(dice[2][2], "|   O   |");
    strcpy(dice[2][3], "|     O |");
    strcpy(dice[2][4], "+-------+");

    strcpy(dice[3][0], "+-------+");
    strcpy(dice[3][1], "| O   O |");
    strcpy(dice[3][2], "|       |");
    strcpy(dice[3][3], "| O   O |");
    strcpy(dice[3][4], "+-------+");

    strcpy(dice[4][0], "+-------+");
    strcpy(dice[4][1], "| O   O |");
    strcpy(dice[4][2], "|   O   |");
    strcpy(dice[4][3], "| O   O |");
    strcpy(dice[4][4], "+-------+");

    strcpy(dice[5][0], "+-------+");
    strcpy(dice[5][1], "| O   O |");
    strcpy(dice[5][2], "| O   O |");
    strcpy(dice[5][3], "| O   O |");
    strcpy(dice[5][4], "+-------+");

        //calculate number of dice per line and number of lines
        int dicePerLine = getNumDice();
        do
        {
            if (num < dicePerLine)
                dicePerLine = num;
            int randList [dicePerLine];
            draw(dicePerLine, dice, mkList(randList, dicePerLine));
            num -= dicePerLine;
            printf("\n");
        } while (num > 0);
    }