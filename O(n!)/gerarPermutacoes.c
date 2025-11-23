#include <stdio.h>

// Função para trocar os valores de dois ponteiros
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void gerarPermutacoes(int *arr, int inicio, int fim) {
    int i;
    // Se chegamos ao fim, imprime a permutação
    if (inicio == fim) {
        for (i = 0; i <= fim; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (i = inicio; i <= fim; i++) {
            // Troca o elemento atual pelo elemento do índice i
            trocar((arr + inicio), (arr + i));
            
            // Chama recursivamente
            gerarPermutacoes(arr, inicio + 1, fim);
            
            // Backtrack: desfaz a troca
            trocar((arr + inicio), (arr + i));
        }
    }
}

int main() {
    int dados[] = {1, 2, 3};
    int n = sizeof(dados) / sizeof(dados[0]);
    
    printf("Gerando permutacoes:\n");
    gerarPermutacoes(dados, 0, n - 1);
    
    return 0;
}