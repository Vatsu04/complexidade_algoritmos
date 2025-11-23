public class Matriz {
    public static void main(String[] args) {
        int[][] A = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
        int[][] B = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
        
        int n = A.length; // Assumindo matriz quadrada N x N
        int[][] C = new int[n][n];

        // O(n³): Três loops aninhados
        for (int i = 0; i < n; i++) {          // Linhas
            for (int j = 0; j < n; j++) {      // Colunas
                for (int k = 0; k < n; k++) {  // Cálculo do produto
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        System.out.println("Matriz Resultante:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(C[i][j] + " ");
            }
            System.out.println();
        }
    }
}