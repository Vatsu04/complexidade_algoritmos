def multiplicar_matrizes(A, B):
    n = len(A)
    # Cria uma matriz resultado n x n preenchida com zeros
    C = [[0 for _ in range(n)] for _ in range(n)]


    for i in range(n): #   o(n) iterações

        for j in range(n):  #   o(n) iterações

            for k in range(n):  #   o(n) iterações
                C[i][j] += A[i][k] * B[k][j] # o(n) * o(n) * o(n) = o(n³)
    return C 

# Dados de Teste (Matrizes 3x3)
matriz_A = [[1, 2, 3],
            [4, 5, 6],
            [7, 8, 9]]

matriz_B = [[9, 8, 7],
            [6, 5, 4],
            [3, 2, 1]]

resultado = multiplicar_matrizes(matriz_A, matriz_B)

print("Matriz Resultante:")
for linha in resultado:
    print(linha)