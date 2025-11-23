public class DijkstraSemFilaDePrioridade {
    // Tamanho do grafo (fixo para exemplo)
    static final int V = 5;

    // Função auxiliar para encontrar a menor distância: O(V)
    int minDistance(int dist[], Boolean sptSet[]) {
        int min = Integer.MAX_VALUE, min_index = -1;

        for (int v = 0; v < V; v++)
            if (sptSet[v] == false && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }

        return min_index;
    }

    void dijkstra(int graph[][], int src) {
        int dist[] = new int[V]; 
        Boolean sptSet[] = new Boolean[V];

        // Inicialização
        for (int i = 0; i < V; i++) {
            dist[i] = Integer.MAX_VALUE;
            sptSet[i] = false;
        }

        dist[src] = 0;

        // --- Loop Externo: O(V) ---
        for (int count = 0; count < V - 1; count++) {
            
            // --- Busca Linear pelo Mínimo: O(V) ---
            int u = minDistance(dist, sptSet);
            sptSet[u] = true;

            // --- Loop Interno (Varredura da Matriz): O(V) ---
            for (int v = 0; v < V; v++)
                if (!sptSet[v] && graph[u][v] != 0 && 
                    dist[u] != Integer.MAX_VALUE && 
                    dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
        }

        printSolution(dist);
    }

    void printSolution(int dist[]) {
        System.out.println("Vértice \t Distância");
        for (int i = 0; i < V; i++)
            System.out.println(i + " \t\t " + dist[i]);
    }

    // O(v²) = O(V) * O(V)

        public static void main(String[] args) {
        // Matriz de Adjacência 5x5
        int graph[][] = new int[][] { 
            { 0, 10, 0, 30, 100 },
            { 10, 0, 50, 0, 0 },
            { 0, 50, 0, 20, 10 },
            { 30, 0, 20, 0, 60 },
            { 100, 0, 10, 60, 0 } 
        };
        
        DijkstraSemFilaDePrioridade t = new DijkstraSemFilaDePrioridade();
        t.dijkstra(graph, 0);
    }
}