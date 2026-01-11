#include <math.h>
#include <stdio.h>
#include <stdlib.h>

enum Player { none, X, O };

void printBoard(enum Player board[3][3]);
void clear_screen();
int isGameOver(enum Player board[3][3]);

int main()
{
    clear_screen();
    enum Player activePlayer = X;
    enum Player board[3][3] = {
        {none, none, none},
        {none, none, none},
        {none, none, none}
    };

    while(1)
    {
        int rInput;
        char p = (activePlayer == X) ? 'X' : 'O';

        printf("\n  Player %c's turn\n\n", p);
        printBoard(board);

        printf("\n\nPlayer input ##: \n");
        scanf("%i", &rInput);

        int x = (rInput / 10) - 1;
        int y = (rInput - 10*(x+1)) - 1;

        if (((x < 3 && x >= 0) && (y < 3 && y >= 0)) && board[y][x] == none)
        {
            if (activePlayer == X) 
            {
                board[y][x] = X;
                activePlayer = O; 
            } 
            else 
            {
                board[y][x] = O;
                activePlayer = X;
            }
        }
        else
        {
            clear_screen();
            printf("\n !! Invalid Move !!\n");
            continue;
        }

        clear_screen();
        if (isGameOver(board)) break;
    } 



    return 0;
}

/*
/-----|-----|-----\
|  X  |     |     |
|-----|-----|-----|
|  O  |  X  |     |
|-----|-----|-----|
|     |     |  X  |
\-----|-----|-----/
*/
void printBoard(enum Player board[3][3])
{
    printf("/-----|-----|-----\\\n|");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == X) {
                printf("  X  |");
            }
            else if (board[i][j] == O)
            {
                printf("  O  |");
            }
            else
            {
                printf("     |");
            }
            if (i <2 && j == 2)
            {
                printf("\n|-----|-----|-----|\n|");
            }
        }
    }
    printf("\n\\-----|-----|-----/");
}

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int isGameOver(enum Player board[3][3])
{
    return 0;
}