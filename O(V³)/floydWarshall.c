#include <stdio.h>

#define V 4
#define INF 99999

void printSolution(int dist[][V]);

void floydWarshall(int graph[][V]) {
    int dist[V][V], i, j, k;

    // Inicializa a matriz de solução igual à matriz de entrada
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // --- ALGORITMO O(V³) ---
    // A estrutura de três laços aninhados é a assinatura desta complexidade
    
    for (k = 0; k < V; k++) {        // 1. Testa todos os vértices como intermediários
        for (i = 0; i < V; i++) {    // 2. Para cada fonte
            for (j = 0; j < V; j++) { // 3. Para cada destino
                
                // Se k é um atalho válido, atualiza a distância
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist);
}

void printSolution(int dist[][V]) {
    printf("Matriz de menores distancias: \n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = { 
        {0,   5,  INF, 10},
        {INF, 0,   3,  INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph);
    return 0;
}