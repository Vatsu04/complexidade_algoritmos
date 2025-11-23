def busca_linear(lista, alvo):
    # O(n): O laço percorre cada elemento da lista
    for i in range(len(lista)): # O(n) iterações
        if lista[i] == alvo:
            return i  # Retorna o índice encontrado
    return -1  # Retorna -1 se não encontrar

# Teste
numeros = [10, 50, 30, 70, 80, 20]
alvo = 30
indice = busca_linear(numeros, alvo)
print(f"Elemento encontrado no índice: {indice}")