def bubble_sort(lista):
    n = len(lista)
    # Laço Externo: Garante que passaremos pela lista n vezes
    for i in range(n):
        # Laço Interno: Compara os pares adjacentes
        # O "- i - 1" é uma pequena otimização, pois os últimos i elementos já estão ordenados
        for j in range(0, n - i - 1):
            # Se o elemento atual for maior que o próximo, troca
            if lista[j] > lista[j + 1]:
                lista[j], lista[j + 1] = lista[j + 1], lista[j]

# Teste
numeros = [64, 34, 25, 12, 22, 11, 90]
bubble_sort(numeros)
print(f"Array ordenado: {numeros}")