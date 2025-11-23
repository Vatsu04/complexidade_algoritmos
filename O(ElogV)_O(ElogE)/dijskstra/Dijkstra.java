import java.util.*;

class Node implements Comparable<Node> {
    public int vertice;
    public int custo;

    public Node(int vertice, int custo) {
        this.vertice = vertice;
        this.custo = custo;
    }

    // Define que a prioridade é o menor custo (Min-Heap)
    @Override
    public int compareTo(Node other) {
        return Integer.compare(this.custo, other.custo);
    }
}

public class Dijkstra {
    // Método Dijkstra O(E log V)
    public static void calcular(List<List<Node>> adj, int src, int V) {
        // Heap de Prioridade (Min-Heap)
        PriorityQueue<Node> pq = new PriorityQueue<>();
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);

        pq.add(new Node(src, 0));
        dist[src] = 0;

        while (!pq.isEmpty()) {
            // --- PARTE DO log(V) ---
            // poll() remove o menor elemento em tempo logarítmico
            Node atual = pq.poll();
            int u = atual.vertice;

            // --- PARTE DO E ---
            // Itera sobre os vizinhos (arestas conectadas a u)
            for (Node vizinho : adj.get(u)) {
                int v = vizinho.vertice;
                int peso = vizinho.custo;

                if (dist[u] + peso < dist[v]) {
                    dist[v] = dist[u] + peso;
                    
                    // --- PARTE DO log(V) ---
                    // add() insere na fila de prioridade em tempo logarítmico
                    // No pior caso, fazemos isso para cada aresta (E)
                    pq.add(new Node(v, dist[v]));
                }
            }
        }

        // Impressão (apenas visualização)
        System.out.println("Distâncias a partir do vértice " + src + ":");
        for (int i = 0; i < V; i++) {
            System.out.println(i + " \t\t " + dist[i]);
        }
    }

    public static void main(String[] args) {
        int V = 5;
        List<List<Node>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());

        // Adicionando arestas (Exemplo: 0 -> 1 com peso 9)
        adj.get(0).add(new Node(1, 9));
        adj.get(0).add(new Node(2, 6));
        adj.get(0).add(new Node(3, 5));
        adj.get(0).add(new Node(4, 3));
        adj.get(2).add(new Node(1, 2));
        adj.get(2).add(new Node(3, 4));

        calcular(adj, 0, V);
    }
}