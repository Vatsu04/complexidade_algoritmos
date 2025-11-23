def merge_sort(arr):
    # ---------------------------------------------------------
    # PARTE 1: O(log n) - A Divisão
    # A recursão divide o array ao meio sucessivamente.
    # Quantas vezes podemos dividir N por 2 até chegar em 1?
    # Resposta: log₂(n) vezes. Isso define a "altura" da árvore de chamadas.
    # ---------------------------------------------------------
    if len(arr) > 1:
        meio = len(arr) // 2
        esquerda = arr[:meio]
        direita = arr[meio:]

        # Chamada recursiva para cada metade
        merge_sort(esquerda)
        merge_sort(direita)

        # -----------------------------------------------------
        # PARTE 2: O(n) - A Conquista (Intercalação)
        # Aqui ocorre o trabalho real de ordenar e juntar.
        # Em CADA nível da árvore de recursão (do topo à base),
        # nós percorremos e ordenamos TODOS os n elementos.
        # -----------------------------------------------------
        i = j = k = 0

        # O laço while percorre os elementos das sub-listas.
        # Somando todas as iterações deste laço em um mesmo nível de profundidade,
        # o total de operações é proporcional a n.
        while i < len(esquerda) and j < len(direita):
            if esquerda[i] < direita[j]:
                arr[k] = esquerda[i]
                i += 1
            else:
                arr[k] = direita[j]
                j += 1
            k += 1

        # Os laços abaixo copiam os elementos restantes.
        # Eles fazem parte do custo linear O(n) deste nível.
        while i < len(esquerda):
            arr[k] = esquerda[i]
            i += 1
            k += 1

        while j < len(direita):
            arr[k] = direita[j]
            j += 1
            k += 1

'''
------------------------------------------------------------------
COMENTÁRIO COM O CÁLCULO DA COMPLEXIDADE (PARA O TCC):

A complexidade final é o produto da "Altura da Árvore" pela "Largura do Trabalho".

1. Altura (Níveis de Recursão):
   O algoritmo divide n por 2 repetidamente.
   Ex: 8 -> 4 -> 2 -> 1.
   Isso gera uma profundidade de log₂ n.
   -> Custo: log n

2. Largura (Trabalho por Nível):
   Em cada nível da árvore, o processo de 'merge' (os whiles)
   precisa iterar sobre todos os elementos para juntá-los.
   Independente se são 2 listas de n/2 ou 4 listas de n/4,
   a soma total de elementos processados naquele nível é n.
   -> Custo: n

3. Cálculo Final:
   Total = (Trabalho por Nível) * (Número de Níveis)
   Total = (n) * (log n)
   Resultado = O(n log n)
------------------------------------------------------------------
'''

# Teste
numeros = [12, 11, 13, 5, 6, 7]
merge_sort(numeros)
print(f"Array ordenado: {numeros}")