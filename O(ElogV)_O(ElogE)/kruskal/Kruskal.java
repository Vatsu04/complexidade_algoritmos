import java.util.*;

class Aresta implements Comparable<Aresta> {
    int origem, destino, peso;

    public int compareTo(Aresta outra) {
        return this.peso - outra.peso;
    }
};

class Subconjunto {
    int pai, rank;
};

public class Kruskal {
    int V, E;
    Aresta[] arestas;

    Kruskal(int v, int e) {
        V = v;
        E = e;
        arestas = new Aresta[E];
        for (int i = 0; i < e; ++i)
            arestas[i] = new Aresta();
    }

    // --- Union-Find ---
    int find(Subconjunto[] subconjuntos, int i) {
        if (subconjuntos[i].pai != i)
            subconjuntos[i].pai = find(subconjuntos, subconjuntos[i].pai);
        return subconjuntos[i].pai;
    }

    void union(Subconjunto[] subconjuntos, int x, int y) {
        int raizX = find(subconjuntos, x);
        int raizY = find(subconjuntos, y);

        if (subconjuntos[raizX].rank < subconjuntos[raizY].rank)
            subconjuntos[raizX].pai = raizY;
        else if (subconjuntos[raizX].rank > subconjuntos[raizY].rank)
            subconjuntos[raizY].pai = raizX;
        else {
            subconjuntos[raizY].pai = raizX;
            subconjuntos[raizX].rank++;
        }
    }

    void kruskalMST() {
        Aresta[] resultado = new Aresta[V];
        int e = 0; 
        int i = 0; 
        
        for (int j = 0; j < V; ++j) resultado[j] = new Aresta();

        // 1. O(E log E): Passo crucial de Ordenação
        Arrays.sort(arestas);

        Subconjunto[] subconjuntos = new Subconjunto[V];
        for (int j = 0; j < V; ++j) {
            subconjuntos[j] = new Subconjunto();
            subconjuntos[j].pai = j;
            subconjuntos[j].rank = 0;
        }

        // 2. Itera pelas arestas ordenadas
        while (e < V - 1 && i < E) {
            Aresta prox_aresta = arestas[i++];

            int x = find(subconjuntos, prox_aresta.origem);
            int y = find(subconjuntos, prox_aresta.destino);

            // 3. Verifica ciclo
            if (x != y) {
                resultado[e++] = prox_aresta;
                union(subconjuntos, x, y);
            }
        }

        System.out.println("MST construída:");
        int custoMinimo = 0;
        for (i = 0; i < e; ++i) {
            System.out.println(resultado[i].origem + " -- " + resultado[i].destino + " == " + resultado[i].peso);
            custoMinimo += resultado[i].peso;
        }
        System.out.println("Custo Total: " + custoMinimo);
    }

    public static void main(String[] args) {
        int V = 4; 
        int E = 5; 
        Kruskal grafo = new Kruskal(V, E);

        // 0-1: 10
        grafo.arestas[0].origem = 0; grafo.arestas[0].destino = 1; grafo.arestas[0].peso = 10;
        // 0-2: 6
        grafo.arestas[1].origem = 0; grafo.arestas[1].destino = 2; grafo.arestas[1].peso = 6;
        // 0-3: 5
        grafo.arestas[2].origem = 0; grafo.arestas[2].destino = 3; grafo.arestas[2].peso = 5;
        // 1-3: 15
        grafo.arestas[3].origem = 1; grafo.arestas[3].destino = 3; grafo.arestas[3].peso = 15;
        // 2-3: 4
        grafo.arestas[4].origem = 2; grafo.arestas[4].destino = 3; grafo.arestas[4].peso = 4;

        grafo.kruskalMST();
    }
}