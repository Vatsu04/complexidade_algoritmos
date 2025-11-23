#include <stdio.h>
#include <stdlib.h> // Necessário para exit()

/**
 * Retorna o primeiro elemento de um array.
 * Esta função opera em tempo O(1), constante.
 *
 * @param array_de_numeros O ponteiro para o início do array.
 * @param tamanho_do_array O tamanho total do array (não usado no cálculo O(1)).
 * @return O primeiro elemento do array.
 */
int obter_primeiro_elemento(int *array_de_numeros, int tamanho_do_array) {
    if (array_de_numeros == NULL || tamanho_do_array == 0) {
        // Em um programa real, você lidaria com erros de forma mais robusta.
        printf("Erro: O array é nulo ou vazio.\n");
        exit(EXIT_FAILURE); 
    }
    
    // O acesso direto por índice (array_de_numeros[0]) é uma operação O(1)
    return array_de_numeros[0];
}

int main() {
    int array_pequeno[] = {10, 20, 30};
    int array_grande[1000]; // Um array muito maior

    // A operação de obter o primeiro elemento leva o mesmo tempo para ambos
    printf("Primeiro elemento do array pequeno: %d\n", obter_primeiro_elemento(array_pequeno, 3));
    printf("Primeiro elemento do array grande: %d\n", obter_primeiro_elemento(array_grande, 1000));

    return 0;
}