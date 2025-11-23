public class MergeSort {
    
    public static void sort(int arr[], int l, int r) {
        // ---------------------------------------------------------
        // PARTE 1: O(log n) - A Divisão
        // A recursão cria uma árvore binária de chamadas.
        // A profundidade (altura) dessa árvore é determinada por quantas
        // vezes conseguimos dividir n por 2: exatamente log n vezes.
        // ---------------------------------------------------------
        if (l < r) {
            int m = l + (r - l) / 2; 

            sort(arr, l, m);
            sort(arr, m + 1, r);

            // Chama a função que realiza o trabalho linear
            merge(arr, l, m, r);
        }
    }

    public static void merge(int arr[], int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        int E[] = new int[n1];
        int D[] = new int[n2];

        for (int i = 0; i < n1; ++i) E[i] = arr[l + i];
        for (int j = 0; j < n2; ++j) D[j] = arr[m + 1 + j];

        int i = 0, j = 0;
        int k = l; 

        // ---------------------------------------------------------
        // PARTE 2: O(n) - A Conquista (Intercalação)
        // Independentemente de estarmos no topo ou na base da recursão,
        // a soma das iterações deste while para um nível inteiro da árvore
        // será proporcional a n (tamanho total do array).
        // ---------------------------------------------------------
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

        while (i < n1) arr[k++] = E[i++];
        while (j < n2) arr[k++] = D[j++];
    }

    /*
    ------------------------------------------------------------------
    CÁLCULO DA COMPLEXIDADE:

    O Merge Sort aplica a estratégia "Dividir para Conquistar".

    1. Custo da Divisão (Recursão): 
       O problema é dividido em subproblemas de tamanho n/2.
       Isso gera uma altura de árvore de log n.
       
    2. Custo da Conquista (Merge):
       Em cada nível da recursão, o algoritmo precisa percorrer e copiar
       todos os n elementos para seus lugares ordenados.
       Custo por nível: O(n).

    3. Resultado Matemático:
       Complexidade = O(n) operações repetidas O(log n) vezes.
       Total = O(n log n).
    ------------------------------------------------------------------
    */

    public static void main(String args[]) {
        int arr[] = {12, 11, 13, 5, 6, 7};
        sort(arr, 0, arr.length - 1);
        System.out.println("Array ordenado");
        for (int n : arr) System.out.print(n + " ");
    }
}