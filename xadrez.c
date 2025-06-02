#include <stdio.h>

#define TAM 8

int main() {
    char tabuleiro[TAM][TAM];

    // ======================= CAVALO =======================
    // Inicializa o tabuleiro
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '.';

    int cavaloLinha = 2, cavaloColuna = 3;
    int passosBaixo = 2, passosDireita = 1;

    tabuleiro[cavaloLinha][cavaloColuna] = '*';

    printf("Movimento do Cavalo em 'L':\n");
    for (int i = 0; i < passosBaixo; i++) {
        cavaloLinha++;
        if (cavaloLinha < TAM) tabuleiro[cavaloLinha][cavaloColuna] = '*';
        printf("Baixo\n");
    }

    int j = 0;
    while (j < passosDireita) {
        cavaloColuna++;
        if (cavaloColuna < TAM) tabuleiro[cavaloLinha][cavaloColuna] = 'C';
        printf("Direita\n");
        j++;
    }

    printf("\nTabuleiro - Cavalo:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++)
            printf("%c ", tabuleiro[i][j]);
        printf("\n");
    }

    // ======================= BISPO =======================
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '.';

    int bispoLinha = 7, bispoColuna = 2;
    tabuleiro[bispoLinha][bispoColuna] = 'B';

    for (int i = 1; bispoLinha - i >= 0 && bispoColuna + i < TAM; i++)
        tabuleiro[bispoLinha - i][bispoColuna + i] = '*';

    printf("\nTabuleiro - Bispo (↗):\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++)
            printf("%c ", tabuleiro[i][j]);
        printf("\n");
    }

    // ======================= RAINHA =======================
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '.';

    int rainhaLinha = 4, rainhaColuna = 7;
    int passosRainha = 0;

    while (passosRainha < 8 && rainhaColuna >= 0) {
        tabuleiro[rainhaLinha][rainhaColuna] = '*';
        rainhaColuna--;
        passosRainha++;
    }
    tabuleiro[rainhaLinha][rainhaColuna + 1] = 'R';

    printf("\nTabuleiro - Rainha (←):\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++)
            printf("%c ", tabuleiro[i][j]);
        printf("\n");
    }

    // ======================= TORRE =======================
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '.';

    int torreLinha = 0, torreColuna = 0;
    int passosTorre = 0;

    do {
        tabuleiro[torreLinha][torreColuna] = '*';
        torreColuna++;
        passosTorre++;
    } while (passosTorre < 5 && torreColuna < TAM);

    tabuleiro[torreLinha][torreColuna] = 'T';

    printf("\nTabuleiro - Torre (→):\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++)
            printf("%c ", tabuleiro[i][j]);
        printf("\n");
    }

    return 0;
}