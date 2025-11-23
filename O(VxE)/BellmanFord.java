
class Grafo {
    // Classe interna para representar uma aresta
    class Aresta {
        int src, dest, weight;
        Aresta() { src = dest = weight = 0; }
    };

    int V, E;
    Aresta arestas[];

    // Cria o grafo com V vértices e E arestas
    Grafo(int v, int e) {
        V = v;
        E = e;
        arestas = new Aresta[e];
        for (int i = 0; i < e; ++i)
            arestas[i] = new Aresta();
    }

    void BellmanFord(int src) {
        int dist[] = new int[V];

        // Passo 1: Inicializa distâncias
        for (int i = 0; i < V; ++i)
            dist[i] = Integer.MAX_VALUE;
        dist[src] = 0;

        // Passo 2: Relaxar todas as arestas |V| - 1 vezes
        
        // --- Loop Externo: O(V) ---
        for (int i = 1; i < V; ++i) {
            
            // --- Loop Interno: O(E) ---
            for (int j = 0; j < E; ++j) {
                int u = arestas[j].src;
                int v = arestas[j].dest;
                int weight = arestas[j].weight;
                
                if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v])
                    dist[v] = dist[u] + weight;
            }
        }

        // O O(E) está dentro do O(V) => O(V) * O(E) = O(V*E)

        // Passo 3: Verificação de ciclos negativos
        for (int j = 0; j < E; ++j) {
            int u = arestas[j].src;
            int v = arestas[j].dest;
            int weight = arestas[j].weight;
            if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]) {
                System.out.println("Ciclo negativo detectado");
                return;
            }
        }
        printArr(dist, V);
    }

    void printArr(int dist[], int V) {
        System.out.println("Vértice \t Distância");
        for (int i = 0; i < V; ++i)
            System.out.println(i + "\t\t" + dist[i]);
    }

    public static void main(String[] args) {
        int V = 5; 
        int E = 8; 
        Grafo graph = new Grafo(V, E);

        // Aresta 0-1 (-1)
        graph.arestas[0].src = 0; graph.arestas[0].dest = 1; graph.arestas[0].weight = -1;
        // ... (outras arestas omitidas para brevidade, lógica igual ao Python) ...
        
        // Apenas para exemplo funcional, repetindo a aresta para não dar erro
        for(int i=1; i<E; i++) { 
             graph.arestas[i].src = 0; graph.arestas[i].dest = 1; graph.arestas[i].weight = -1; 
        }

        graph.BellmanFord(0);
    }
}