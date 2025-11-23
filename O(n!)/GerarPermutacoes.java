import java.util.Arrays;

public class GerarPermutacoes {
    // Função auxiliar para trocar elementos
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void gerarPermutacoes(int[] arr, int inicio, int fim) {
        // Se inicio for igual a fim, imprimimos a permutação atual
        if (inicio == fim) {
            System.out.println(Arrays.toString(arr));
        } else {
            for (int i = inicio; i <= fim; i++) {
                // Troca
                swap(arr, inicio, i);
                
                // Recursão
                gerarPermutacoes(arr, inicio + 1, fim);
                
                // Backtrack (Desfaz a troca)
                swap(arr, inicio, i);
            }
        }
    }

    public static void main(String[] args) {
        int[] dados = {1, 2, 3};
        System.out.println("Gerando permutações:");
        gerarPermutacoes(dados, 0, dados.length - 1);
    }
}