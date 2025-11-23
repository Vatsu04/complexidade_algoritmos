class Grafo:
    def __init__(self, vertices):
        self.V = vertices
        # Matriz de Adjacência V x V
        self.grafo = [[0 for column in range(vertices)] 
                      for row in range(vertices)]

    def imprimir_solucao(self, dist):
        print("Vértice \t Distância da Origem")
        for node in range(self.V):
            print(f"{node} \t\t {dist[node]}")

    # Função auxiliar para encontrar o vértice com a menor distância
    # entre os vértices ainda não visitados.
    # Custo desta função: O(V)
    def min_distance(self, dist, sptSet):
        min_val = float('inf')
        min_index = -1

        for v in range(self.V):
            if dist[v] < min_val and sptSet[v] == False:
                min_val = dist[v]
                min_index = v

        return min_index

    def dijkstra_matriz(self, src):
        dist = [float('inf')] * self.V
        dist[src] = 0
        sptSet = [False] * self.V

        # --- PARTE 1: Loop Externo (Roda V vezes) ---
        for cout in range(self.V):

            # --- PARTE 2: Busca Linear (Roda V vezes) ---
            # Escolhe o vértice de mínima distância do conjunto não processado.
            u = self.min_distance(dist, sptSet)

            # Marca o vértice escolhido como processado
            if u != -1:
                sptSet[u] = True

                # --- PARTE 3: Atualização (Relaxamento) ---
                # Percorre a linha da matriz de adjacência (V colunas)
                for v in range(self.V):
                    if (self.grafo[u][v] > 0 and
                       sptSet[v] == False and
                       dist[v] > dist[u] + self.grafo[u][v]):
                        dist[v] = dist[u] + self.grafo[u][v]

        self.imprimir_solucao(dist)

# Teste
g = Grafo(5)
# Matriz de Adjacência (0 indica sem aresta)
g.grafo = [
    [0, 10, 0, 30, 100],
    [10, 0, 50, 0, 0],
    [0, 50, 0, 20, 10],
    [30, 0, 20, 0, 60],
    [100, 0, 10, 60, 0]
]

g.dijkstra_matriz(0)