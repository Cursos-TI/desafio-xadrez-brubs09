#include <stdio.h>

#define TAM 8

// Função recursiva para movimentar a torre para a direita
void moverTorre(char tab[TAM][TAM], int linha, int coluna, int passos) {
    if (passos == 0 || coluna >= TAM) return;
    tab[linha][coluna] = '*';
    printf("Direita\n");
    moverTorre(tab, linha, coluna + 1, passos - 1);
}

// Função recursiva para movimentar a rainha para a esquerda
void moverRainha(char tab[TAM][TAM], int linha, int coluna, int passos) {
    if (passos == 0 || coluna < 0) return;
    tab[linha][coluna] = '*';
    printf("Esquerda\n");
    moverRainha(tab, linha, coluna - 1, passos - 1);
}

// Função recursiva para o movimento diagonal do bispo (↗)
void moverBispo(char tab[TAM][TAM], int linha, int coluna) {
    if (linha < 0 || coluna >= TAM) return;
    tab[linha][coluna] = '*';
    printf("Diagonal Cima Direita\n");
    moverBispo(tab, linha - 1, coluna + 1);
}

int main() {
    char tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com '.'
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '.';

    // Torre
    int linhaT = 0, colunaT = 0;
    moverTorre(tabuleiro, linhaT, colunaT, 5);
    tabuleiro[linhaT][colunaT + 5] = 'T';

    printf("\nTabuleiro - Torre:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) printf("%c ", tabuleiro[i][j]);
        printf("\n");
    }

    // Reinicia o tabuleiro
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '.';

    // Rainha
    int linhaR = 4, colunaR = 7;
    moverRainha(tabuleiro, linhaR, colunaR, 8);
    tabuleiro[linhaR][colunaR - 8 + 1] = 'R';

    printf("\nTabuleiro - Rainha:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) printf("%c ", tabuleiro[i][j]);
        printf("\n");
    }

    // Reinicia o tabuleiro
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '.';

    // Bispo com recursao
    int linhaB = 7, colunaB = 2;
    moverBispo(tabuleiro, linhaB, colunaB);
    tabuleiro[linhaB - 5][colunaB + 5] = 'B'; // posição final

    printf("\nTabuleiro - Bispo:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) printf("%c ", tabuleiro[i][j]);
        printf("\n");
    }

    // Reinicia o tabuleiro
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '.';

    // Cavalo
    int linhaC = 4, colunaC = 4;
    tabuleiro[linhaC][colunaC] = '*';
    printf("\nMovimento do Cavalo em 'L' (Cima, Cima, Direita):\n");
    for (int i = 0; i < 2; i++) {
        linhaC--;
        if (linhaC >= 0) {
            tabuleiro[linhaC][colunaC] = '*';
            printf("Cima\n");
        }
    }
    int k = 0;
    while (k < 1) {
        colunaC++;
        if (colunaC < TAM) {
            tabuleiro[linhaC][colunaC] = 'C';
            printf("Direita\n");
        }
        k++;
    }

    printf("\nTabuleiro - Cavalo:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) printf("%c ", tabuleiro[i][j]);
        printf("\n");
    }

    return 0;
}
