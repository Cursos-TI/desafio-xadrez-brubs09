#include <stdio.h>

#define TAM 8

int main() {
    char tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com '.'
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = '.';
        }
    }

    int linha = 0, coluna = 0; // posição inicial da torre
    int passos = 0;

    // Marca o caminho com '*'
    do {
        tabuleiro[linha][coluna] = '*'; // marca o caminho
        coluna++; // move para a direita
        passos++;
    } while (passos < 5 && coluna < TAM);

    // Marca a posição final da torre com 'T'
    tabuleiro[linha][coluna] = 'T';

    // Exibe o tabuleiro
    printf("Caminho da torre ('*') e posição final ('T'):\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}