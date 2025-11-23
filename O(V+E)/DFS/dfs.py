def dfs_recursiva(grafo, vertice, visitados=None):
    if visitados is None:
        visitados = set()

    # --- PARTE DO O(V) ---
    # Marcamos o vértice atual. Esta função é chamada exatamente 1 vez
    # para cada vértice alcançável (V).
    visitados.add(vertice)
    print(vertice, end=" ")

    # --- PARTE DO O(E) ---
    # O loop percorre todos os vizinhos do vértice atual.
    # Somando todas as chamadas recursivas, este loop terá iterado
    # sobre todas as arestas (E) do grafo.
    for vizinho in grafo[vertice]:
        if vizinho not in visitados:
            dfs_recursiva(grafo, vizinho, visitados)

# Grafo de exemplo (Lista de Adjacência)
grafo = {
    0: [1, 2],
    1: [0, 3],
    2: [0, 4],
    3: [1],
    4: [2]
}

print("DFS Ordem de visitação:")
dfs_recursiva(grafo, 0)