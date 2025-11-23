#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma aresta
struct Aresta {
    int origem, destino, peso;
};

// Estrutura para representar o grafo
struct Grafo {
    int V, E;
    struct Aresta* arestas;
};

struct Grafo* criarGrafo(int V, int E) {
    struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
    grafo->V = V;
    grafo->E = E;
    grafo->arestas = (struct Aresta*)malloc(E * sizeof(struct Aresta));
    return grafo;
}

// Estrutura para Union-Find
struct Subconjunto {
    int pai;
    int rank;
};

int find(struct Subconjunto subconjuntos[], int i) {
    if (subconjuntos[i].pai != i)
        subconjuntos[i].pai = find(subconjuntos, subconjuntos[i].pai);
    return subconjuntos[i].pai;
}

void Uniao(struct Subconjunto subconjuntos[], int x, int y) {
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

// Função de comparação para o qsort - Define o O(E log E)
int compararArestas(const void* a, const void* b) {
    struct Aresta* a1 = (struct Aresta*)a;
    struct Aresta* b1 = (struct Aresta*)b;
    return a1->peso - b1->peso;
}

void KruskalMST(struct Grafo* grafo) {
    int V = grafo->V;
    struct Aresta *resultado = (struct Aresta*)malloc((V - 1) * sizeof(struct Aresta)); 
    int e = 0; 
    int i = 0; 

    // 1. Passo O(E log E): Ordenando as arestas usando QuickSort
    qsort(grafo->arestas, grafo->E, sizeof(grafo->arestas[0]), compararArestas);

    struct Subconjunto* subconjuntos = (struct Subconjunto*)malloc(V * sizeof(struct Subconjunto));

    for (int v = 0; v < V; ++v) {
        subconjuntos[v].pai = v;
        subconjuntos[v].rank = 0;
    }

    // 2. Iterando pelas arestas ordenadas
    while (e < V - 1 && i < grafo->E) {
        struct Aresta prox_aresta = grafo->arestas[i++];

        int x = find(subconjuntos, prox_aresta.origem);
        int y = find(subconjuntos, prox_aresta.destino);

        // 3. Se não forma ciclo
        if (x != y) {
            resultado[e++] = prox_aresta;
            Uniao(subconjuntos, x, y);
        }
    }

    printf("Arestas na MST:\n");
    int custoMinimo = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", resultado[i].origem, resultado[i].destino, resultado[i].peso);
        custoMinimo += resultado[i].peso;
    }
    printf("Custo Total: %d\n", custoMinimo);
    
    free(subconjuntos);
}

int main() {
    int V = 4; 
    int E = 5; 
    struct Grafo* grafo = criarGrafo(V, E);

    // Aresta 0-1
    grafo->arestas[0].origem = 0; grafo->arestas[0].destino = 1; grafo->arestas[0].peso = 10;
    // Aresta 0-2
    grafo->arestas[1].origem = 0; grafo->arestas[1].destino = 2; grafo->arestas[1].peso = 6;
    // Aresta 0-3
    grafo->arestas[2].origem = 0; grafo->arestas[2].destino = 3; grafo->arestas[2].peso = 5;
    // Aresta 1-3
    grafo->arestas[3].origem = 1; grafo->arestas[3].destino = 3; grafo->arestas[3].peso = 15;
    // Aresta 2-3
    grafo->arestas[4].origem = 2; grafo->arestas[4].destino = 3; grafo->arestas[4].peso = 4;

    KruskalMST(grafo);

    free(grafo->arestas);
    free(grafo);
    
    return 0;
}