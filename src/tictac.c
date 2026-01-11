#include <math.h>
#include <stdio.h>
#include <stdlib.h>

enum Player { none, X, O };

void printBoard(enum Player board[3][3]);
void clear_screen();

int main()
{
    int game = 1;
    
    enum Player activePlayer = X;
    enum Player board[3][3] = {
        {none, none, none},
        {none, none, none},
        {none, none, none}
    };

    while(game)
    {
        int rInput;
        char p;

        p = (activePlayer == X) ? 'X' : 'O';
        
        printBoard(board);
        printf("Player %c input ##: \n", p);
        scanf("%i", &rInput);

        int x = (rInput / 10);
        int y = (rInput - 10*x);

        if (board[y][x] == none)
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
            printf("\nInvalid Move!\n");
            continue;
        }

        clear_screen();
        printf("\n");
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