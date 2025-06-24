#include <stdio.h>

#define TAMANHO 10     // Tamanho do tabuleiro (10x10)
#define NAVIO 3        // Valor que representa um navio
#define AGUA 0         // Valor que representa água
#define TAM_NAVIO 3    // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa todas as posições com 0 (água)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ----- Coordenadas dos navios (definidas no código) -----
    // Navio horizontal (linha 2, começa na coluna 4)
    int linhaH = 2;
    int colunaH = 4;

    // Navio vertical (coluna 1, começa na linha 6)
    int linhaV = 6;
    int colunaV = 1;

    // ----- Validações de posicionamento -----
    // Verifica se o navio horizontal cabe no tabuleiro
    if (colunaH + TAM_NAVIO <= TAMANHO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = NAVIO;
        }
    } else {
        printf("Navio horizontal fora do tabuleiro!\n");
        return 1;
    }

    // Verifica se o navio vertical cabe no tabuleiro
    if (linhaV + TAM_NAVIO <= TAMANHO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            // Verifica se vai sobrepor o navio horizontal
            if (tabuleiro[linhaV + i][colunaV] == NAVIO) {
                printf("Navios se sobrepõem!\n");
                return 1;
            }
            tabuleiro[linhaV + i][colunaV] = NAVIO;
        }
    } else {
        printf("Navio vertical fora do tabuleiro!\n");
        return 1;
    }

    // ----- Exibe o tabuleiro -----
    printf("=== Tabuleiro Batalha Naval ===\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
