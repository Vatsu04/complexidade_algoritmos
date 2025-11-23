#include <stdio.h>

#define N 3 // Tamanho da matriz (3x3)

void multiplicarMatrizes(int A[N][N], int B[N][N], int C[N][N]) {
    int i, j, k;
    
    // Inicializa a matriz C com zeros (boa prática em C)
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            C[i][j] = 0;

    // Algoritmo O(n³)
    for (i = 0; i < N; i++) {        // Loop Externo
        for (j = 0; j < N; j++) {    // Loop do Meio
            for (k = 0; k < N; k++) { // Loop Interno
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[N][N] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int B[N][N] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
    int C[N][N]; // Matriz onde guardaremos o resultado

    multiplicarMatrizes(A, B, C);

    printf("Matriz Resultante: \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}