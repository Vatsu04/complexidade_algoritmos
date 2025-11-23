#include <stdio.h>

int buscaBinaria(int arr[], int tamanho, int alvo) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;   // Encontra o índice do meio

        if (arr[meio] == alvo)
            return meio; // Elemento encontrado

        if (arr[meio] < alvo)
            inicio = meio + 1; // Descarta a metade inferior
        else
            fim = meio - 1; //Descarta a metade superior
    }
    return -1; // Não encontrado
}

int main() {
    int numeros[] = {1, 3, 5, 7, 9, 11, 13};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    int alvo = 7;
    
    int resultado = buscaBinaria(numeros, tamanho, alvo);
    
    if (resultado != -1)
        printf("Elemento encontrado no indice: %d", resultado);
    else
        printf("Elemento nao encontrado");
        
    return 0;
}