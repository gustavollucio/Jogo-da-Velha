#include <stdio.h>

char v[3][3];

void startGame() {
    char posicao = '1';
    for (int i = 0; i < 3; i++) {
        for (int c = 0; c < 3; c++) {
            v[i][c] = posicao++;
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

int main() {
    startGame();
    printBoard();
    return 0;
}