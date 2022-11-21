#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main()
{
    int board[SIZE][SIZE] = { 0 };
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if ((rand() % 100) < 30)
                board[i][j] = 1;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            if (board[i][j])
                printf("# ");
            else
                printf(". ");
        printf("\n");
    }
    return 0;
}