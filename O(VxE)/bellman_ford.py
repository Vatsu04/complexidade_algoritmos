class Grafo:
    def __init__(self, vertices):
        self.V = vertices
        self.grafo = [] # Lista de arestas: [u, v, peso]

    def adicionar_aresta(self, u, v, w):
        self.grafo.append([u, v, w])

    def bellman_ford(self, src):
        # Inicializa distâncias com Infinito
        dist = [float("Inf")] * self.V
        dist[src] = 0

        # --- PARTE DO O(V) ---
        # Loop Externo: Executa V - 1 vezes
        # (O caminho mais longo sem ciclos tem V-1 arestas)
        for _ in range(self.V - 1):
            
            # --- PARTE DO O(E) ---
            # Loop Interno: Percorre TODAS as arestas do grafo
            for u, v, w in self.grafo:
                if dist[u] != float("Inf") and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w

        # Verificação de Ciclo Negativo (Opcional, custo O(E))
        for u, v, w in self.grafo:
            if dist[u] != float("Inf") and dist[u] + w < dist[v]:
                print("Grafo contém ciclo de peso negativo")
                return

        self.imprimir_solucao(dist)

    def imprimir_solucao(self, dist):
        print("Vértice \t Distância da Origem")
        for i in range(self.V):
            print(f"{i} \t\t {dist[i]}")

# Teste
g = Grafo(5)
g.adicionar_aresta(0, 1, -1)
g.adicionar_aresta(0, 2, 4)
g.adicionar_aresta(1, 2, 3)
g.adicionar_aresta(1, 3, 2)
g.adicionar_aresta(1, 4, 2)
g.adicionar_aresta(3, 2, 5)
g.adicionar_aresta(3, 1, 1)
g.adicionar_aresta(4, 3, -3)

g.bellman_ford(0)