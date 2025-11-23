#include <stdio.h>

int buscaLinear(int arr[], int n, int alvo) {
    // O tempo aumenta proporcionalmente ao valor de 'n'
    for (int i = 0; i < n; i++) { // O(n) iterações
        if (arr[i] == alvo) {
            return i; // Retorna o índice
        }
    }
    return -1; // Não encontrado
}

int main() {
    int numeros[] = {10, 50, 30, 70, 80, 20};
    int n = sizeof(numeros) / sizeof(numeros[0]);
    int alvo = 30;
    
    int resultado = buscaLinear(numeros, n, alvo);
    
    if (resultado != -1)
        printf("Elemento encontrado no indice: %d", resultado);
    else
        printf("Elemento nao encontrado");
        
    return 0;
}