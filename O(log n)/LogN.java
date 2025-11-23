public class LogN {
    public static int buscaBinaria(int[] array, int alvo) {
        int inicio = 0;
        int fim = array.length - 1;

        while (inicio <= fim) {
            // Evita overflow de inteiros que ocorreria com (inicio + fim) / 2
            int meio = inicio + (fim - inicio) / 2;

            if (array[meio] == alvo) {
                return meio;
            }
            if (array[meio] < alvo) {
                inicio = meio + 1;
            } else {
                fim = meio - 1;
            }
        }
        return -1; // Não encontrado
    }

    public static void main(String[] args) {
        int[] numeros = {1, 3, 5, 7, 9, 11, 13};
        System.out.println("Índice: " + buscaBinaria(numeros, 7));
    }
}
