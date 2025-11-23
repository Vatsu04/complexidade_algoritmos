# Definindo Infinito
INF = float('inf')

def floyd_warshall(grafo):
    # Número de vértices
    V = len(grafo)
    
    # Cria uma cópia da matriz para armazenar as distâncias
    # (Para não alterar o grafo original diretamente, se não quiser)
    dist = [linha[:] for linha in grafo]

    # --- O(V³): Três Loops Aninhados ---
    
    # 1. Loop do Vértice Intermediário (k)
    for k in range(V):
        
        # 2. Loop do Vértice de Origem (i)
        for i in range(V):
            
            # 3. Loop do Vértice de Destino (j)
            for j in range(V):
                
                # A Lógica: Se passar por 'k' for mais rápido que ir direto de 'i' para 'j'
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

    imprimir_solucao(dist, V)

def imprimir_solucao(dist, V):
    print("Matriz de menores distâncias entre cada par de vértices:")
    for i in range(V):
        for j in range(V):
            if dist[i][j] == INF:
                print("INF", end=" \t")
            else:
                print(f"{dist[i][j]}", end=" \t")
        print()

# Teste com Grafo de 4 vértices
# INF representa sem conexão direta
grafo = [
    [0,   5,  INF, 10],
    [INF, 0,   3,  INF],
    [INF, INF, 0,   1],
    [INF, INF, INF, 0]
]

floyd_warshall(grafo)