#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char v[3][3];

void startGame() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int c = 0; c < 3; c++) {
            v[i][c] = num++;
        }
    }
}

void printBoard() {
    printf("+---+---+---+\n");
    for (int i = 0; i < 3; i++) {
        for (int c = 0; c < 3; c++) {
            if (c == 0) {
                printf("|");
            }
            printf(" %c |", v[i][c]);
        }
        printf("\n+---+---+---+\n");
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (v[i][0] == v[i][1] && v[i][1] == v[i][2]) return true;
        if (v[0][i] == v[1][i] && v[1][i] == v[2][i]) return true;
    }
    if (v[0][0] == v[1][1] && v[1][1] == v[2][2]) return true;
    if (v[0][2] == v[1][1] && v[1][1] == v[2][0]) return true;

    return false;
}

int main() {
    int count = 0;
    int position;
    int currentPlayer = 1;
    char symbol;
    bool validPosition;
    bool victory = false;

    startGame();

    do {
        system("cls");

        printf("Jogador numero 1 = X \n");
        printf("Jogador numero 2 = O \n\n");

        printBoard();

        symbol = (currentPlayer == 1) ? 'X' : 'O';

        do {
            validPosition = false;
            printf("Vai jogar [%c] em qual posicao? ", symbol);
            scanf("%d", &position);

            if (position >= 1 && position <= 9) {
                int i = (position - 1) / 3;
                int c = (position - 1) % 3;

                if (v[i][c] != 'X' && v[i][c] != 'O') {
                    v[i][c] = symbol;
                    validPosition = true;
                    count++;
                } else {
                    printf("JOGADA INVALIDA! Posicao ja ocupada.\n");
                }
            } else {
                printf("JOGADA INVALIDA! Escolha a posicao de 1 a 9.\n");
            }
        } while (!validPosition);

        victory = checkWin();

        if (!victory && count < 9) {
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }

    }while (!victory && count < 9);

    system("cls");
    printf("Jogador numero 1 = X \n");
    printf("Jogador numero 2 = O \n\n");
    printBoard();

    if (victory) {
        printf("\nJOGADOR %d VENCEU!\n", currentPlayer);
    } else {
        printf("\nEMPATE\n");
    }

    printf("JOGO FINALIZADO\n");
    return 0;
}