#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum Player { none, X, O };

void printBoard(enum Player board[3][3]);
void clear_screen();
char isGameOver(enum Player board[3][3], enum Player active);
char gameLoop();

int main()
{
    bool playing = true; 
    while(true)
    {
        if (playing)
        {
            char winner = gameLoop();

            clear_screen();
            if (winner == 'd') {
                printf("Draw! No-One Won!\n\n");
            }
            else printf("Player %c Won!\n\n", winner);

            playing = false;
        }
        else
        {
            char response;
            printf("Play Again? (y/n)\n");
            scanf(" %c", &response);

            if (response == 'n') break;
            else if (response == 'y') playing = true;
        }
    }
    
    clear_screen();
    return 0;
}

char gameLoop()
{
    clear_screen();

    enum Player activePlayer = X;

    enum Player board[3][3] = {
        {none, none, none},
        {none, none, none},
        {none, none, none}
    };

    char over;

    while(true)
    {
        int rInput;

        char p = (activePlayer == X) ? 'X' : 'O';

        printf("\n     Player %c's Turn\n\n", p);
        printBoard(board);

        printf("\n\nInput Coordinates (Col/Row, ex. \"12\"): \n");
        scanf("%i", &rInput);

        int x = (rInput / 10) - 1;
        int y = (rInput - 10*(x+1)) - 1;

        if (((x < 3 && x >= 0) && (y < 3 && y >= 0)) && board[y][x] == none)
        {
                board[y][x] = (activePlayer == X) ? X : O;

                over = isGameOver(board, activePlayer);
                if (over == 'y' || over == 'd') break;

                activePlayer = (activePlayer == X) ? O : X;
        }
        else
        {
            clear_screen();
            printf("\n    !! Invalid Move !!\n");
            continue;
        }

        clear_screen();
    } 

    char winner = (activePlayer == X) ? 'X' : 'O';
    if (over == 'y') return winner;
    else return 'd';
}

void printBoard(enum Player board[3][3])
{
    printf("      1     2     3\n");
    printf("   /-----|-----|-----\\\n1  |");

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
                printf("\n   |-----|-----|-----|\n%i  |", (i+2));
            }
        }
    }
    printf("\n   \\-----|-----|-----/");
}

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

char isGameOver(enum Player board[3][3], enum Player active)
{
    // Check rows
    int series = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == active) series++;
        }

        if (series == 3) return 'y';
        series = 0;
    }

    // Check columns
    series = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[j][i] == active) series++;
        }

        if (series == 3) return 'y';
        series = 0;
    }

    // Check diagonals
    series = 0;
    for (int i = 0; i < 3; i++)
    {
        if (board[i][i] == active) series++;
        if (series == 3) return 'y';
    }
    series = 0;
    for (int i = 2; i >= 0; i--)
    {
        if (board[i][i] == active) series++;
        if (series == 3) return 'y';
    }

    // Check for a draw
    series = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != none) series++;
        }
    }
    if (series == 9) return 'd';


    return 'f';
}