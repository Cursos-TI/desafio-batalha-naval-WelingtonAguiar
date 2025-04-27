#include <stdio.h>

// Definindo constantes para o tamanho do tabuleiro e valores de identificação
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

int main() 
{
    // Matriz representando o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializando o tabuleiro com água
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas para posicionar navios
    int linha_navio_hor = 2, coluna_navio_hor = 4; // Horizontal
    int linha_navio_ver = 5, coluna_navio_ver = 1; // Vertical
    int linha_navio_diag1 = 0, coluna_navio_diag1 = 0; // Diagonal principal (↘)
    int linha_navio_diag2 = 0, coluna_navio_diag2 = 9; // Diagonal secundária (↙)

    // Posicionando navio horizontal
    if (coluna_navio_hor + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int colisao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_navio_hor][coluna_navio_hor + i] == NAVIO) {
                colisao = 1;
                break;
            }
        }
        if (!colisao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_navio_hor][coluna_navio_hor + i] = NAVIO;
            }
        }
    }

    // Posicionando navio vertical
    if (linha_navio_ver + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int colisao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_navio_ver + i][coluna_navio_ver] == NAVIO) {
                colisao = 1;
                break;
            }
        }
        if (!colisao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_navio_ver + i][coluna_navio_ver] = NAVIO;
            }
        }
    }

    // Posicionando navio diagonal principal (↘)
    if (linha_navio_diag1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        coluna_navio_diag1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        
        int colisao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_navio_diag1 + i][coluna_navio_diag1 + i] == NAVIO) {
                colisao = 1;
                break;
            }
        }
        if (!colisao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_navio_diag1 + i][coluna_navio_diag1 + i] = NAVIO;
            }
        }
    }

    // Posicionando navio diagonal secundária (↙)
    if (linha_navio_diag2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        coluna_navio_diag2 - (TAMANHO_NAVIO - 1) >= 0) {

        int colisao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_navio_diag2 + i][coluna_navio_diag2 - i] == NAVIO) {
                colisao = 1;
                break;
            }
        }
        if (!colisao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_navio_diag2 + i][coluna_navio_diag2 - i] = NAVIO;
            }
        }
    }

    // Exibindo o tabuleiro
    printf("\n      ***** BATALHA NAVAL - NIVEL AVENTUREIRO *****\n\n");

    // Cabeçalho de letras
    printf("    ");
    for (char letra = 'A'; letra < 'A' + TAMANHO_TABULEIRO; letra++) {
        printf(" %c ", letra);
    }
    printf("\n");

    // Corpo do tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d  ", i + 1); // Número da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
