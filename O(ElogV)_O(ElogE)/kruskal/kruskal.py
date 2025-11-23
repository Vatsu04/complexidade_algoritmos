class Grafo:
    def __init__(self, vertices):
        self.V = vertices
        self.grafo = [] # Lista de arestas [u, v, peso]

    def adicionar_aresta(self, u, v, w):
        self.grafo.append([u, v, w])

    # --- Estrutura Union-Find ---
    def find(self, parent, i):
        if parent[i] == i:
            return i
        # Compressão de caminho (otimização)
        parent[i] = self.find(parent, parent[i])
        return parent[i]

    def union(self, parent, rank, x, y):
        raiz_x = self.find(parent, x)
        raiz_y = self.find(parent, y)

        # União por Rank (otimização)
        if rank[raiz_x] < rank[raiz_y]:
            parent[raiz_x] = raiz_y
        elif rank[raiz_x] > rank[raiz_y]:
            parent[raiz_y] = raiz_x
        else:
            parent[raiz_y] = raiz_x
            rank[raiz_x] += 1

    # --- Algoritmo de Kruskal ---
    def kruskal_mst(self):
        resultado = []
        i = 0 # Índice para arestas ordenadas
        e = 0 # Índice para arestas do resultado

        # 1. O(E log E): Ordena todas as arestas pelo peso
        self.grafo = sorted(self.grafo, key=lambda item: item[2])

        parent = []
        rank = []

        # Cria subconjuntos V
        for node in range(self.V):
            parent.append(node)
            rank.append(0)

        # 2. Itera sobre as arestas ordenadas
        while e < self.V - 1 and i < len(self.grafo):
            u, v, w = self.grafo[i]
            i = i + 1

            x = self.find(parent, u)
            y = self.find(parent, v)

            # 3. Se não forma ciclo (pais diferentes), inclui na MST
            if x != y:
                e = e + 1
                resultado.append([u, v, w])
                self.union(parent, rank, x, y)

        # Imprime o resultado
        print("Arestas na MST:")
        custo_total = 0
        for u, v, weight in resultado:
            custo_total += weight
            print(f"{u} -- {v} == {weight}")
        print(f"Custo Total: {custo_total}")

# Teste
g = Grafo(4)
g.adicionar_aresta(0, 1, 10)
g.adicionar_aresta(0, 2, 6)
g.adicionar_aresta(0, 3, 5)
g.adicionar_aresta(1, 3, 15)
g.adicionar_aresta(2, 3, 4)

g.kruskal_mst()