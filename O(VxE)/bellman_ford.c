

    #include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Estrutura para representar uma aresta
struct Aresta {
    int src, dest, weight;
};

struct Grafo {
    int V, E;
    struct Aresta* arestas;
};

struct Grafo* criarGrafo(int V, int E) {
    struct Grafo* grafo = (struct Grafo*) malloc(sizeof(struct Grafo));
    grafo->V = V;
    grafo->E = E;
    grafo->arestas = (struct Aresta*) malloc(grafo->E * sizeof(struct Aresta));
    return grafo;
}

void BellmanFord(struct Grafo* grafo, int src) {
    int V = grafo->V;
    int E = grafo->E;
    int *dist = (int*) malloc(V * sizeof(int));

    // int dist[V];

    // Passo 1: Inicializa distâncias
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // Passo 2: Relaxar todas as arestas V - 1 vezes
    
    // --- Loop Externo: O(V) ---
    // Executa V-1 vezes
    for (int i = 1; i <= V - 1; i++) {
        
        // --- Loop Interno: O(E) ---
        // Percorre o array de arestas inteiro
        for (int j = 0; j < E; j++) {
            int u = grafo->arestas[j].src;
            int v = grafo->arestas[j].dest;
            int weight = grafo->arestas[j].weight;
            
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Passo 3: Verificação de ciclo negativo
    for (int j = 0; j < E; j++) {
        int u = grafo->arestas[j].src;
        int v = grafo->arestas[j].dest;
        int weight = grafo->arestas[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Grafo contem ciclo de peso negativo\n");
            return;
        }
    }

    printf("Vertice \t Distancia da Origem\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int V = 5; 
    int E = 8; 
    struct Grafo* grafo = criarGrafo(V, E);

    // Adicionando aresta 0-1 peso -1
    grafo->arestas[0].src = 0;
    grafo->arestas[0].dest = 1;
    grafo->arestas[0].weight = -1;

    // ... (restante das arestas) ...

    BellmanFord(grafo, 0);
    return 0;
}