public class Linear {
    public static int buscaLinear(int[] array, int alvo) {
        // Percorre de 0 até n-1
        for (int i = 0; i < array.length; i++) { // (O(n) iterações
            if (array[i] == alvo) {
                return i; // Encontrou
            }
        }
        return -1; // Não encontrou
    }
        public static void main(String[] args) {
        int[] numeros = {10, 50, 30, 70, 80, 20};
        System.out.println("Índice: " + buscaLinear(numeros, 30));
    }
}
