#include <stdio.h>
#include <string.h>

// Função para checar sobreposição
int check_sobreposicao(int tabuleiro[10][10], int x, int y, const char *move_type) {
    int collision = 0; // Inicializa como sem colisão

    // Loop para verificar as 3 posições
    for (int i = 0; i < 3; i++) {

        // Checar se há posições válidas dado que o movimento é horizontal
        if (strcmp(move_type, "h") == 0) {
            if (tabuleiro[y][x + i] == 3) { collision = 1; }

        // Checar se há posições válidas dado que o movimento é vertical
        } else if (strcmp(move_type, "v") == 0) {
            if (tabuleiro[y + i][x] == 3) { collision = 1; }

        // Checar se há posições válidas dado que o movimento é diagonal
        } else if (strcmp(move_type, "d") == 0) {
            if (tabuleiro[y + i][x + i] == 3) { collision = 1; }
        }
    }

    return collision;
}

void move_ship(int tabuleiro[10][10], int x, int y, const char *move_type) {

    // Verificar se existirá sobreposição dado a posição (x,y), em caso negativo irá mover/preencher as posições
    int collision = check_sobreposicao(tabuleiro, x, y, move_type);

    if (collision) {
        printf("Posição invalida, ocorreu colisão! \n");
        return;
    }
    else {
        // Comparar char p/ horizontal "h"
        if (strcmp(move_type, "h") == 0) {
            // Movimento horizontal
            if (x <= 7 && y < 10) {
                for (int i = 0; i < 3; i++) {
                    tabuleiro[y][x + i] = 3;
                }
            }
            else { printf("Posição invalida fora do limite do tabuleiro! \n"); }

        // Comparar char p/ vertical "v"
        } else if (strcmp(move_type, "v") == 0) {
            // Movimento vertical
            if (y <= 7 && x < 10) {
                for (int i = 0; i < 3; i++) {
                    tabuleiro[y + i][x] = 3;
                }
            }
            else { printf("Posição invalida fora do limite do tabuleiro! \n"); }

        // Comparar char p/ diagonal "d"
        } else if (strcmp(move_type, "d") == 0) {
            // Movimento diagonal
            if (y <= 7 && x < 7) {
                for (int i = 0; i < 3; i++) {
                    tabuleiro[y + i][x + i] = 3;
                }
            }
            else { printf("Posição invalida fora do limite do tabuleiro! \n"); }
        }
    }
}

void show_tabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[10][10] = {0};  // Inicializa tudo com zero

    // Mover navio na vertical
    move_ship(tabuleiro, 0, 0, "v");

    // Mover navio na horizontal
    move_ship(tabuleiro, 1, 2, "h");

    // Mover navio na diagonal
    move_ship(tabuleiro, 0, 5, "d");

    // Mostrar tabuleiro
    show_tabuleiro(tabuleiro);

    return 0;
}
