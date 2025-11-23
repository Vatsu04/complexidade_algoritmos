public class FloydWarshall {
    final static int INF = 99999;
    final static int V = 4; // Número de vértices fixo para o exemplo

    void floydWarshall(int graph[][]) {
        int dist[][] = new int[V][V];
        int i, j, k;

        // Inicializa a matriz de distâncias
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                dist[i][j] = graph[i][j];

        // --- INÍCIO DO ALGORITMO O(V³) ---
        
        // Loop 1: Intermediário k
        for (k = 0; k < V; k++) {
            
            // Loop 2: Origem i
            for (i = 0; i < V; i++) {
                
                // Loop 3: Destino j
                for (j = 0; j < V; j++) {
                    
                    // Se o vértice k está no caminho mais curto de i para j, atualiza
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        // --- FIM DO ALGORITMO ---

        printSolution(dist);
    }

    void printSolution(int dist[][]) {
        System.out.println("Matriz de menores distâncias:");
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][j] == INF)
                    System.out.print("INF ");
                else
                    System.out.print(dist[i][j] + "   ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int graph[][] = { 
            {0,   5,  INF, 10},
            {INF, 0,   3,  INF},
            {INF, INF, 0,   1},
            {INF, INF, INF, 0}
        };
        
        FloydWarshall a = new FloydWarshall();
        a.floydWarshall(graph);
    }
}