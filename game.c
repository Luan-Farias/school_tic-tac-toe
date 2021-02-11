#include <stdio.h>
#include <locale.h>

void tabGame(char positions[3][3], int invalid);
char verifyX (char positions[3][3]);
char verifyY (char positions[3][3]);
char verifyXY (char positions[3][3]);
void initialGame (char *positions[3][3]);
int catchPosition(char catch[16]);
char verifyGame(char positions[3][3]);

int main () {
    char positions[3][3], winner = '-';
    int positionX, positionY, i, j, playAgain = 1;

    do {
        system("cls");
        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                positions[i][j] = '-';
            }
        }
        tabGame(positions, 0);

        for (i = 0; i < 9; i++) {
            if(i % 2 == 0) {
                printf("\nX, is your turn \n");
            } else {
                printf("\nO, is your turn\n");
            }
            positionX = catchPosition("line");
            positionY = catchPosition("column");
            if (positions[positionX][positionY] == '-') {
                if(i % 2 == 0) {
                    positions[positionX][positionY] = 'X';
                } else {
                    positions[positionX][positionY] = 'O';
                }
                winner = verifyGame(positions);
                
                if (winner != '-') break;
                tabGame(positions, 0);
            } else {
                tabGame(positions, 1);
                i--;
            }
        }
        system("cls");
        if (winner == '-') {
            printf("Game Tied\n\n");
        } else {
            printf("The Winner is %c\n\n", winner); 
        }
        printf("Would you like to play again (Type 0 to No and any number to yes):    ");
        scanf("%i", &playAgain);
    } while(playAgain != 0);

    return 0;
}

char verifyY (char positions[3][3]) {
    int i;
    for (i = 0; i < 3; i++) {
        if (positions[0][i] == positions[1][i] && positions[1][i] == positions[2][i]) {
            if (positions[0][i] == 'X') {
                return 'X';
            }
            if (positions[0][i] == 'O') {
                return 'O';
            }
        }
    }
    return '-';
}

char verifyX (char positions[3][3]) {
    int i;
    for (i = 0; i < 3; i++) {
        if (positions[i][0] == positions[i][1] && positions[i][1] == positions[i][2]) {
            if (positions[i][0] == 'X') {
                return 'X';
            }
            if (positions[i][0] == 'O') {
                return 'O';
            }
        }
    }
    return '-';
}

char verifyXY (char positions[3][3]) {
    if (positions[0][0] == positions[1][1] && positions[1][1] == positions[2][2]) {
        if (positions[0][0] == 'X') {
            return 'X';
        }
        if (positions[0][0] == 'O') {
            return 'O';
        }
    }
    return '-';
} 

void tabGame(char positions[3][3], int invalid) {
    system("cls");
    if(invalid == 1) {
       printf("Invalidn play, play again \n \n"); 
    }
    printf("  %c | %c | %c \n--------------\n", positions[0][0], positions[0][1], positions[0][2] );
    printf("  %c | %c | %c \n--------------\n", positions[1][0], positions[1][1], positions[1][2] );
    printf("  %c | %c | %c \n", positions[2][0], positions[2][1], positions[2][2] );
}

int catchPosition(char catch[16]) {
    int position;
    do {
        printf("Informe the %s (0 to 2):   ", catch);
        scanf("%i", &position);
    } while(position < 0 || position > 3);
    return position;
}

char verifyGame(char positions[3][3]) {
    char winner = '-';
    winner = verifyX(positions);
    if (winner != '-') return winner;
    winner = verifyY(positions);
    if (winner != '-') return winner;
    winner = verifyXY(positions);
    if (winner != '-') return winner;

    return '-';
}
