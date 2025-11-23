from collections import deque

def bfs(grafo, inicio):
    visitados = set()
    fila = deque([inicio])
    visitados.add(inicio)

    # --- PARTE DO O(V) ---
    # Este 'while' executa 1 vez para cada Vértice do grafo.
    # Se temos 10 vértices, ele roda 10 vezes (ao todo).
    while fila: 
        vertice = fila.popleft()
        print(vertice, end=" ")

        # --- PARTE DO O(E) ---
        # Este 'for' percorre os vizinhos (arestas).
        # Somando todas as vezes que este loop roda durante a execução inteira,
        # ele terá percorrido exatamente o número total de arestas (E).
        for vizinho in grafo[vertice]:
            if vizinho not in visitados:
                visitados.add(vizinho)
                fila.append(vizinho)