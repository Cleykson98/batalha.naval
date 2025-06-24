#include <stdio.h>

#define TAMANHO 10     // Tamanho do tabuleiro (10x10)
#define NAVIO 3        // Valor que representa um navio
#define AGUA 0         // Valor que representa água
#define TAM_NAVIO 3    // Tamanho fixo dos navios

// Função para verificar se uma posição está dentro dos limites do tabuleiro
int dentro_do_tabuleiro(int linha, int coluna) {
    return linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO;
}

// Função para verificar se há sobreposição nas posições indicadas para um navio
int verifica_sobreposicao(int tabuleiro[TAMANHO][TAMANHO], int posicoes[TAM_NAVIO][2]) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int linha = posicoes[i][0];
        int coluna = posicoes[i][1];
        if (tabuleiro[linha][coluna] == NAVIO) {
            return 1; // Sobreposição detectada
        }
    }
    return 0; // Sem sobreposição
}

// Função para posicionar um navio dado as posições das partes no tabuleiro
void posiciona_navio(int tabuleiro[TAMANHO][TAMANHO], int posicoes[TAM_NAVIO][2]) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int linha = posicoes[i][0];
        int coluna = posicoes[i][1];
        tabuleiro[linha][coluna] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Navios horizontais/verticais: posições iniciais fixas
    int linhaH = 2, colunaH = 4;  // Navio horizontal: linha 2, coluna 4
    int linhaV = 6, colunaV = 1;  // Navio vertical: linha 6, coluna 1

    // Define as posições do navio horizontal
    int navio_horizontal[TAM_NAVIO][2];
    for (int i = 0; i < TAM_NAVIO; i++) {
        navio_horizontal[i][0] = linhaH;
        navio_horizontal[i][1] = colunaH + i;
    }

    // Define as posições do navio vertical
    int navio_vertical[TAM_NAVIO][2];
    for (int i = 0; i < TAM_NAVIO; i++) {
        navio_vertical[i][0] = linhaV + i;
        navio_vertical[i][1] = colunaV;
    }

    // Navios diagonais: posições iniciais fixas
    // Diagonal principal descendente (linha e coluna aumentam)
    int linhaD1 = 0, colunaD1 = 0;
    int navio_diagonal1[TAM_NAVIO][2];
    for (int i = 0; i < TAM_NAVIO; i++) {
        navio_diagonal1[i][0] = linhaD1 + i;
        navio_diagonal1[i][1] = colunaD1 + i;
    }

    // Diagonal principal ascendente (linha aumenta, coluna diminui)
    int linhaD2 = 9, colunaD2 = 9;
    int navio_diagonal2[TAM_NAVIO][2];
    for (int i = 0; i < TAM_NAVIO; i++) {
        navio_diagonal2[i][0] = linhaD2 - i;
        navio_diagonal2[i][1] = colunaD2 - i;
    }

    // Função para validar se todas as posições estão dentro do tabuleiro
    int todas_posicoes_validas(int posicoes[TAM_NAVIO][2]) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (!dentro_do_tabuleiro(posicoes[i][0], posicoes[i][1])) {
                return 0; // Fora dos limites
            }
        }
        return 1;
    }

    // Valida e posiciona navio horizontal
    if (!todas_posicoes_validas(navio_horizontal)) {
        printf("Navio horizontal fora do tabuleiro!\n");
        return 1;
    }
    if (verifica_sobreposicao(tabuleiro, navio_horizontal)) {
        printf("Navio horizontal sobrepõe outro navio!\n");
        return 1;
    }
    posiciona_navio(tabuleiro, navio_horizontal);

    // Valida e posiciona navio vertical
    if (!todas_posicoes_validas(navio_vertical)) {
        printf("Navio vertical fora do tabuleiro!\n");
        return 1;
    }
    if (verifica_sobreposicao(tabuleiro, navio_vertical)) {
        printf("Navio vertical sobrepõe outro navio!\n");
        return 1;
    }
    posiciona_navio(tabuleiro, navio_vertical);

    // Valida e posiciona navio diagonal 1
    if (!todas_posicoes_validas(navio_diagonal1)) {
        printf("Navio diagonal 1 fora do tabuleiro!\n");
        return 1;
    }
    if (verifica_sobreposicao(tabuleiro, navio_diagonal1)) {
        printf("Navio diagonal 1 sobrepõe outro navio!\n");
        return 1;
    }
    posiciona_navio(tabuleiro, navio_diagonal1);

    // Valida e posiciona navio diagonal 2
    if (!todas_posicoes_validas(navio_diagonal2)) {
        printf("Navio diagonal 2 fora do tabuleiro!\n");
        return 1;
    }
    if (verifica_sobreposicao(tabuleiro, navio_diagonal2)) {
        printf("Navio diagonal 2 sobrepõe outro navio!\n");
        return 1;
    }
    posiciona_navio(tabuleiro, navio_diagonal2);

    // Exibe o tabuleiro
    printf("\n=== Tabuleiro Batalha Naval ===\n\n");

    // Imprime cabeçalho das colunas
    printf("   ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i);  // índice da linha
        for (int j = 0; j < TAMANHO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nNavios posicionados com sucesso!\n");

    return 0;
}
