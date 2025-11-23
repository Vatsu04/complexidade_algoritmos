#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5 // Número de vértices

// Função para encontrar o vértice com a menor distância: O(V)
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[]) {
    printf("Vertice \t Distancia da Origem\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V]; 
    bool sptSet[V]; 

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    // --- Loop Principal: Executa V vezes ---
    for (int count = 0; count < V - 1; count++) {
        
        // --- Passo Crítico: Busca Linear O(V) ---
        // Em vez de usar um Heap O(log V), varremos o array inteiro.
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        // --- Varredura da Linha da Matriz: O(V) ---
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);
}

// O(V²) = O(V) * O(V)

int main() {
    // Grafo representado por Matriz de Adjacência
    int graph[V][V] = { 
        { 0, 10, 0, 30, 100 },
        { 10, 0, 50, 0, 0 },
        { 0, 50, 0, 20, 10 },
        { 30, 0, 20, 0, 60 },
        { 100, 0, 10, 60, 0 } 
    };

    dijkstra(graph, 0);

    return 0;
}