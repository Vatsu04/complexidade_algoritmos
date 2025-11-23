import heapq

def dijkstra(grafo, inicio):
    # Inicialização das distâncias com infinito
    distancias = {v: float('infinity') for v in grafo}
    distancias[inicio] = 0
    
    # Fila de Prioridade (Min-Heap)
    # Armazena tuplas: (distância_acumulada, vértice_atual)
    pq = [(0, inicio)]

    while pq:
        # --- PARTE DO log(V) ---
        # A operação heappop custa O(log V) ou O(log E).
        # Ela remove o vértice com a menor distância da fila.
        dist_atual, u = heapq.heappop(pq)

        # Se encontramos um caminho mais longo do que o já conhecido, ignoramos (Lazy Deletion)
        if dist_atual > distancias[u]:
            continue

        # --- PARTE DO E ---
        # Este loop percorre os vizinhos. Somando todas as iterações do while,
        # passaremos por todas as arestas (E) do grafo.
        for vizinho, peso in grafo[u].items():
            distancia = dist_atual + peso

            # Relaxamento da aresta
            if distancia < distancias[vizinho]:
                distancias[vizinho] = distancia
                
                # --- PARTE DO log(V) ---
                # A operação heappush insere na fila custando O(log V) ou O(log E).
                # Como isso pode acontecer para cada aresta, temos E * log V.
                heapq.heappush(pq, (distancia, vizinho))

    return distancias

'''
CÁLCULO DA COMPLEXIDADE (PARA O TCC):
1. Extrair Mínimo: O loop principal executa V vezes para extrair o mínimo.
   Custo: V * log V
2. Relaxar Arestas: O loop interno percorre cada aresta (E) do grafo.
   Para cada aresta, podemos fazer uma inserção no Heap (log V).
   Custo: E * log V
   
Total = (V * log V) + (E * log V)
Como geralmente E >= V - 1 em grafos conexos, simplificamos para:
RESULTADO = O(E log V)
'''

# Grafo (Lista de Adjacência)
grafo = {
    'A': {'B': 4, 'C': 2},
    'B': {'D': 3, 'E': 1},
    'C': {'B': 1, 'D': 5},
    'D': {'E': 2},
    'E': {}
}

print(dijkstra(grafo, 'A'))