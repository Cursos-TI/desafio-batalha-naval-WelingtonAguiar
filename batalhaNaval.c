#include <stdio.h>

// Definindo constantes para facilitar mudanças futuras e legebilidade
#define tamanho_tabuleiro 10
#define tamanho_navio 3
#define navio 3
#define agua 0

int main() 
{
    int tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro];

    for (int i = 0 ; i < tamanho_tabuleiro ; i++)
    {
        for (int j = 0 ; j < tamanho_tabuleiro ; j++)
        {
            tabuleiro[i][j] = agua;
        }
    }

    int linha_navio_horizontal = 2,
        coluna_navio_horizontal = 4;

    int linha_navio_vertical = 5,
        coluna_navio_vertical = 1;    

        if (coluna_navio_horizontal + tamanho_navio <= tamanho_tabuleiro)
        {
            int colisao = 0;
            for (int i = 0 ; i < tamanho_navio ; i++)
            {
                if (tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] == navio)
                {
                    colisao = 1;
                    break;
                }
            }

            if (!colisao)
            {
                for (int i = 0 ; i < tamanho_navio ; i++)
                {
                    tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] = navio; 
                }
            }
        }

        if (linha_navio_vertical + tamanho_navio <= tamanho_tabuleiro)
        {
            int colisao = 0;
            for (int i = 0 ; i < tamanho_navio ; i++)
            {
                if (tabuleiro[linha_navio_vertical][coluna_navio_vertical + i] == navio)
                {
                    colisao = 1;
                    break;
                }
            }

            if (!colisao)
            {
                for (int i = 0 ; i < tamanho_navio ; i++)
                {
                    tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = navio; 
                }
            }
        }

        printf("\n     ");
        printf("\n      ***** BATALHA NAVAL *****\n\n");
        printf("    ");

        for (char letra = 'A' ; letra < 'A' + tamanho_tabuleiro ; letra++)
        {
            printf(" %c ", letra);
        }

        printf("\n");

        for (int i = 0 ; i < tamanho_tabuleiro ; i++)
        {
            printf("%2d  ", i + 1);

            for(int j = 0 ; j < tamanho_tabuleiro ; j++)
            {
                printf(" %d ", tabuleiro[i][j]);
            }

            printf("\n");
        }

    return 0;
}
