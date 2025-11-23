#include <stdio.h>
#include <stdlib.h> // Necessário para malloc e free

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Arrays temporários
    int *E = (int*)malloc(n1 * sizeof(int));
    int *D = (int*)malloc(n2 * sizeof(int));

    // Copia dados para arrays temporários
    for (i = 0; i < n1; i++)
        E[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        D[j] = arr[m + 1 + j];

    // ---------------------------------------------------------
    // PARTE 2: O(n) - A Conquista (Intercalação)
    // O trabalho pesado acontece aqui.
    // Em cada nível da árvore de recursão, estes laços while somados
    // percorrem todos os 'n' elementos daquele nível para ordená-los.
    // ---------------------------------------------------------
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (E[i] <= D[j]) {
            arr[k] = E[i];
            i++;
        } else {
            arr[k] = D[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes (ainda parte do custo O(n))
    while (i < n1) {
        arr[k] = E[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = D[j];
        j++;
        k++;
    }

    // Libera a memória alocada (Importante em C!)
    free(E);
    free(D);
}

void mergeSort(int arr[], int l, int r) {
    // ---------------------------------------------------------
    // PARTE 1: O(log n) - A Divisão
    // Esta estrutura recursiva divide o array pela metade sucessivamente.
    // O número de divisões necessárias para reduzir 'n' até 1
    // define a altura da árvore de recursão: log2(n).
    // ---------------------------------------------------------
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);     // Divide lado esquerdo
        mergeSort(arr, m + 1, r); // Divide lado direito

        merge(arr, l, m, r);      // Chama a função de custo linear O(n)
    }
}

/*
------------------------------------------------------------------
COMENTÁRIO COM O CÁLCULO DA COMPLEXIDADE (PARA O TCC):

A complexidade O(n log n) é derivada da estrutura da árvore de execução:

1. Altura da Árvore (Divisão): 
   O algoritmo divide o problema pela metade a cada passo.
   Matematicamente, log₂(n) níveis de profundidade.
   -> Fator: log n

2. Trabalho por Nível (Intercalação):
   Dentro da função merge(), percorremos os elementos para ordená-los.
   A soma de todos os elementos processados em um único nível da árvore
   é sempre igual ao total de elementos n.
   -> Fator: n

3. Cálculo Final:
   Total = (Trabalho por nível) * (Altura da árvore)
   Total = n * log n
   Resultado = O(n log n)
------------------------------------------------------------------
*/

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, arr_size - 1);

    printf("Array ordenado: \n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    
    return 0;
}