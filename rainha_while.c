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

    int linha = 4, coluna = 7; // posição inicial da rainha 
    int passos = 0;

    // Move a rainha 8 casas para a esquerda usando while
    while (passos < 8 && coluna >= 0) {
        tabuleiro[linha][coluna] = '*'; // marca o caminho
        coluna--; // move para a esquerda
        passos++;
    }

    // Ajusta a última posição para 'R'
    tabuleiro[linha][coluna + 1] = 'R';

    // Exibe o tabuleiro final
    printf("Movimento da rainha 8 casas para a esquerda:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}