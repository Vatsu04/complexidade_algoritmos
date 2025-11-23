import java.util.*;

public class Main {
    private int V; // Número de vértices
    private LinkedList<Integer> adj[]; // Lista de Adjacência

    // Construtor
    Main(int v) {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i)
            adj[i] = new LinkedList();
    }

    // Adicionar aresta
    void adicionarAresta(int v, int w) {
        adj[v].add(w);
    }

    // Algoritmo BFS
void BFS(int s) {
        boolean visitados[] = new boolean[V];
        LinkedList<Integer> fila = new LinkedList<Integer>();

        visitados[s] = true;
        fila.add(s);

        // --- PARTE DO O(V) ---
        // O loop principal continua enquanto houver vértices na fila.
        // Cada vértice entra e sai da fila apenas uma vez.
        while (fila.size() != 0) {
            s = fila.poll();
            System.out.print(s + " ");

            Iterator<Integer> i = adj[s].listIterator();
            
            // --- PARTE DO O(E) ---
            // O 'while' interno percorre a lista de adjacência do vértice 's'.
            // A soma total de iterações deste while ao final do programa é igual a E.
            while (i.hasNext()) {
                int n = i.next();
                if (!visitados[n]) {
                    visitados[n] = true;
                    fila.add(n);
                }
            }
        }
    }

    public static void main(String args[]) {
        Main g = new Main(4);

        g.adicionarAresta(0, 1);
        g.adicionarAresta(0, 2);
        g.adicionarAresta(1, 2);
        g.adicionarAresta(2, 0);
        g.adicionarAresta(2, 3);
        g.adicionarAresta(3, 3);

        g.BFS(2);
    }
}