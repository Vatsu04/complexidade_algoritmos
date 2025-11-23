public class ComplexidadeConstante {

    /**
     * Retorna o primeiro elemento de um array. 
     * Esta operação tem complexidade de tempo O(1), pois o tempo de execução 
     * não depende do número de elementos no array.
     *
     * @param arrayDeNumeros O array de inteiros.
     * @return O primeiro elemento do array.
     */
    public static int obterPrimeiroElemento(int[] arrayDeNumeros) {
        if (arrayDeNumeros == null || arrayDeNumeros.length == 0) {
            throw new IllegalArgumentException("O array não pode ser nulo ou vazio.");
        }
        // O acesso direto por índice (arrayDeNumeros[0]) é uma operação O(1)
        return arrayDeNumeros[0];
    }

    public static void main(String[] args) {
        int[] arrayPequeno = {10, 20, 30};
        int[] arrayGrande = new int[1000000];
        arrayGrande[0] = 5;
        // Preencher o resto do arrayGrande...

        System.out.println("Primeiro elemento do array pequeno: " + obterPrimeiroElemento(arrayPequeno));
        System.out.println("Primeiro elemento do array grande: " + obterPrimeiroElemento(arrayGrande));
    }
}