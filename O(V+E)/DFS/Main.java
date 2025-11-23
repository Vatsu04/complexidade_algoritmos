import java.util.*;

public class Main {
    private int V;
    private LinkedList<Integer> adj[];

    Main(int v) {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i)
            adj[i] = new LinkedList();
    }

    void adicionarAresta(int v, int w) {
        adj[v].add(w);
    }

    // Função auxiliar recursiva usada pela DFS
    void DFSUtil(int v, boolean visitados[]) {
        // --- PARTE DO O(V) ---
        // Marca o nó atual como visitado e imprime.
        // Executado 1 vez por vértice.
        visitados[v] = true;
        System.out.print(v + " ");

        // --- PARTE DO O(E) ---
        // O Iterator percorre a lista de adjacência deste nó específico.
        // A soma de todas as iterações em todo o processo é igual a E.
        Iterator<Integer> i = adj[v].listIterator();
        while (i.hasNext()) {
            int n = i.next();
            if (!visitados[n])
                DFSUtil(n, visitados);
        }
    }

    // Função principal que chama a recursão
    void DFS(int v) {
        boolean visitados[] = new boolean[V];
        DFSUtil(v, visitados);
    }

    public static void main(String args[]) {
        Main g = new Main(5); // 5 vértices

        g.adicionarAresta(0, 1);
        g.adicionarAresta(0, 2);
        g.adicionarAresta(1, 3);
        g.adicionarAresta(2, 4);

        System.out.print("DFS Ordem: ");
        g.DFS(0);
    }
}