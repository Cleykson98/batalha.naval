#include <stdio.h>

#define TAMANHO 10     // Tamanho do tabuleiro (10x10)
#define NAVIO 3        // Valor que representa um navio
#define AGUA 0         // Valor que representa água
#define TAM_NAVIO 3    // Tamanho fixo dos navios
#define HABILIDADE 5   // Valor que representa área afetada pela habilidade

// Tamanho das matrizes de habilidade (5x5)
#define TAM_HABILIDADE 5

// Protótipos
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemLinha, int origemColuna);
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]);

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
    if (colunaH + TAM_NAVIO <= TAMANHO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = NAVIO;
        }
    } else {
        printf("Navio horizontal fora do tabuleiro!\n");
        return 1;
    }

    if (linhaV + TAM_NAVIO <= TAMANHO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
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

    // ----- Criar matrizes de habilidade -----

    // Matriz do Cone (apontando para baixo)
    // Formato de cone: top no meio superior, expandindo para base
    int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        int start = TAM_HABILIDADE/2 - i; // Limite inicial da linha (em relação ao centro)
        int end = TAM_HABILIDADE/2 + i;   // Limite final da linha
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= start && j <= end) {
                cone[i][j] = 1; // Área afetada
            }
        }
    }

    // Matriz da Cruz (ponto central)
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1; // Linha central e coluna central
            }
        }
    }

    // Matriz do Octaedro (formato losango)
    // Distância manhattan ao centro menor ou igual a 2 (raio 2)
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int dist = abs(i - centro) + abs(j - centro);
            if (dist <= 2) {
                octaedro[i][j] = 1;
            }
        }
    }

    // ----- Definir pontos de origem das habilidades no tabuleiro -----
    int origemConeLinha = 1;
    int origemConeColuna = 7;

    int origemCruzLinha = 7;
    int origemCruzColuna = 7;

    int origemOctaedroLinha = 5;
    int origemOctaedroColuna = 3;

    // ----- Aplicar habilidades no tabuleiro -----
    aplicarHabilidade(tabuleiro, cone, origemConeLinha, origemConeColuna);
    aplicarHabilidade(tabuleiro, cruz, origemCruzLinha, origemCruzColuna);
    aplicarHabilidade(tabuleiro, octaedro, origemOctaedroLinha, origemOctaedroColuna);

    // ----- Exibe o tabuleiro com navios e habilidades -----
    printf("=== Tabuleiro Batalha Naval com Habilidades ===\n\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}

// Função para sobrepor a matriz da habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemLinha, int origemColuna) {
    int meio = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha - meio + i;
                int colunaTab = origemColuna - meio + j;
                // Verifica se está dentro do tabuleiro
                if (linhaTab >= 0 && linhaTab < TAMANHO && colunaTab >= 0 && colunaTab < TAMANHO) {
                    // Se não for navio, marca a área de habilidade (5)
                    if (tabuleiro[linhaTab][colunaTab] == AGUA) {
                        tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                    }
                }
            }
        }
    }
}

// Função para imprimir o tabuleiro com símbolos diferenciados
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            int val = tabuleiro[i][j];
            if (val == AGUA) {
                printf("0 ");   // Água
            } else if (val == NAVIO) {
                printf("3 ");   // Navio
            } else if (val == HABILIDADE) {
                printf("5 ");   // Área afetada pela habilidade
            } else {
                printf("? ");   // Valor inesperado (para debug)
            }
        }
        printf("\n");
    }
}
