public class BubbleSort {
    static void bubbleSort(int[] arr) {
        int n = arr.length;
        int temp;
        
        // Laço Externo (i)
        for (int i = 0; i < n - 1; i++) {
            
            // Laço Interno (j) - Processando pares
            for (int j = 0; j < n - i - 1; j++) {
                
                // Comparação e troca
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        bubbleSort(arr);
        
        System.out.println("Array ordenado:");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}