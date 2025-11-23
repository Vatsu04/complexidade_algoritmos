#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Estrutura para um nó da lista de adjacência
struct No {
    int vertice;
    struct No* proximo;
};

// Estrutura para o grafo
struct Grafo {
    int numVertices;
    struct No** listasAdj;
    bool* visitado;
};

// Cria um novo nó
struct No* criarNo(int v) {
    struct No* novoNo = malloc(sizeof(struct No));
    novoNo->vertice = v;
    novoNo->proximo = NULL;
    return novoNo;
}

// Cria o grafo
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

// Adiciona aresta
void adicionarAresta(struct Grafo* grafo, int s, int d) {
    struct No* novoNo = criarNo(d);
    novoNo->proximo = grafo->listasAdj[s];
    grafo->listasAdj[s] = novoNo;
}

// Algoritmo BFS
void bfs(struct Grafo* grafo, int verticeInicial) {
    int fila[MAX];
    int frente = 0; 
    int tras = 0;

    grafo->visitado[verticeInicial] = true;
    fila[tras++] = verticeInicial;

    // --- PARTE DO O(V) ---
    // Enquanto a fila tiver elementos (frente < tras).
    // Garante o processamento linear dos Vértices.
    while (frente < tras) {
        int verticeAtual = fila[frente++];
        printf("%d ", verticeAtual);

        struct No* temp = grafo->listasAdj[verticeAtual];

        // --- PARTE DO O(E) ---
        // Percorre a lista encadeada de vizinhos.
        // Visita cada aresta conectada ao 'verticeAtual'.
        while (temp) {
            int adjVertice = temp->vertice;

            if (!grafo->visitado[adjVertice]) {
                grafo->visitado[adjVertice] = true;
                fila[tras++] = adjVertice;
            }
            temp = temp->proximo;
        }
    }
}

int main() {
    struct Grafo* grafo = criarGrafo(4);
    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 2);
    adicionarAresta(grafo, 1, 2);
    adicionarAresta(grafo, 2, 0);
    adicionarAresta(grafo, 2, 3);
    adicionarAresta(grafo, 3, 3);

    bfs(grafo, 2);

    return 0;
}