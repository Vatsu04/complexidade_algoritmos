#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Estrutura para um nó do Heap
struct MinHeapNode {
    int v;
    int dist;
};

// Estrutura para o Min-Heap
struct MinHeap {
    int size;
    int capacity;
    int *pos; // Mapa de posições para decreaseKey (opcional, mas bom para performance)
    struct MinHeapNode **array;
};

// --- Funções Auxiliares do Heap (O log V) ---
struct MinHeapNode* novoNoHeap(int v, int dist) {
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}

struct MinHeap* criarMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->pos = (int*)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Função Heapify: Garante a propriedade do heap - O(log V)
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        // Atualiza mapa de posições
        struct MinHeapNode* smallestNode = minHeap->array[smallest];
        struct MinHeapNode* idxNode = minHeap->array[idx];
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Extrai o mínimo - O(log V)
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    if (minHeap->size == 0) return NULL;
    struct MinHeapNode* root = minHeap->array[0];
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);
    return root;
}

// Atualiza distância (Decrease Key) - O(log V)
void decreaseKey(struct MinHeap* minHeap, int v, int dist) {
    int i = minHeap->pos[v];
    minHeap->array[i]->dist = dist;

    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int isInMinHeap(struct MinHeap *minHeap, int v) {
    if (minHeap->pos[v] < minHeap->size) return 1;
    return 0;
}

// --- Estruturas de Grafo ---
struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};
struct AdjList { struct AdjListNode* head; };
struct Graph { int V; struct AdjList* array; };

// --- Algoritmo Dijkstra Principal ---
void dijkstra(struct Graph* graph, int src) {
    const int V = graph->V;
    int *dist = (int*)malloc(V * sizeof(int));
    struct MinHeap* minHeap = criarMinHeap(V);

    for (int v = 0; v < V; ++v) {
        dist[v] = INT_MAX;
        minHeap->array[v] = novoNoHeap(v, dist[v]);
        minHeap->pos[v] = v;
    }

    minHeap->array[src] = novoNoHeap(src, 0); // Inicializa fonte
    minHeap->pos[src] = 0;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);
    minHeap->size = V;

    // Loop principal do Dijkstra
    while (minHeap->size != 0) {
        // --- PARTE DO log(V) ---
        // O custo de extrair do heap manual
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;

        struct AdjListNode* pCrawl = graph->array[u].head;
        
        // --- PARTE DO E ---
        // Percorre vizinhos
        while (pCrawl != NULL) {
            int v = pCrawl->dest;

            if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && 
                pCrawl->weight + dist[u] < dist[v]) {
                
                dist[v] = dist[u] + pCrawl->weight;

                // --- PARTE DO log(V) ---
                // Atualiza a prioridade no heap
                decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    printf("Distancia da origem:\n");
    for (int i = 0; i < V; ++i) printf("%d \t\t %d\n", i, dist[i]);
}

// Nota: Funções de criarGrafo e main foram omitidas para brevidade, 
// mas o foco do TCC deve ser a estrutura 'minHeap' e 'decreaseKey'.