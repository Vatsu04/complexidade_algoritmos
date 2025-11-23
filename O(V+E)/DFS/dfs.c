#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estruturas de Grafo (iguais ao exemplo anterior)
struct No {
    int vertice;
    struct No* proximo;
};

struct Grafo {
    int numVertices;
    struct No** listasAdj;
    bool* visitado;
};

struct No* criarNo(int v) {
    struct No* novoNo = malloc(sizeof(struct No));
    novoNo->vertice = v;
    novoNo->proximo = NULL;
    return novoNo;
}

struct Grafo* criarGrafo(int vertices) {
    struct Grafo* grafo = malloc(sizeof(struct Grafo));
    grafo->numVertices = vertices;
    grafo->listasAdj = malloc(vertices * sizeof(struct No*));
    grafo->visitado = malloc(vertices * sizeof(bool));

    for (int i = 0; i < vertices; i++) {
        grafo->listasAdj[i] = NULL;
        grafo->visitado[i] = false;
    }
    return grafo;
}

void adicionarAresta(struct Grafo* grafo, int s, int d) {
    struct No* novoNo = criarNo(d);
    novoNo->proximo = grafo->listasAdj[s];
    grafo->listasAdj[s] = novoNo;
}

// Algoritmo DFS Recursivo
void dfs(struct Grafo* grafo, int vertice) {
    struct No* adjLista = grafo->listasAdj[vertice];
    struct No* temp = adjLista;

    // --- PARTE DO O(V) ---
    // Marca o vértice atual como visitado.
    // Garante que não entraremos em loop infinito e visitamos cada V uma vez.
    grafo->visitado[vertice] = true;
    printf("%d ", vertice);

    // --- PARTE DO O(E) ---
    // Percorre a lista encadeada (vizinhos) deste vértice.
    // O ponteiro 'temp' avança por todas as arestas conectadas a este nó.
    while (temp != NULL) {
        int verticeConectado = temp->vertice;

        if (grafo->visitado[verticeConectado] == false) {
            dfs(grafo, verticeConectado);
        }
        temp = temp->proximo;
    }
}

int main() {
    struct Grafo* grafo = criarGrafo(5);
    
    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 2);
    adicionarAresta(grafo, 1, 3);
    adicionarAresta(grafo, 2, 4);

    printf("DFS Ordem: ");
    dfs(grafo, 0);

    return 0;
}