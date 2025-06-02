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

    // Posição inicial do bispo
    int linha = 7;  
    int coluna = 2; 
    tabuleiro[linha][coluna] = 'B';

    // Movimento do bispo para cima e direita (↗)
    for (int i = 1; linha - i >= 0 && coluna + i < TAM; i++) {
        tabuleiro[linha - i][coluna + i] = '*'; // Marca o caminho
    }

    // Exibe o tabuleiro
    printf("Movimento do bispo (↗):\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}