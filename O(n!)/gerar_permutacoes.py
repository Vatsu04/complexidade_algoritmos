def gerar_permutacoes(lista, inicio, fim):
    # Caso base: se chegamos ao último elemento, imprimimos a lista
    if inicio == fim:
        print(lista)
    else:
        # Explora todas as possibilidades
        for i in range(inicio, fim + 1):
            # Troca o elemento atual com o elemento do loop
            lista[inicio], lista[i] = lista[i], lista[inicio]
            
            # Chama recursivamente para o próximo índice
            gerar_permutacoes(lista, inicio + 1, fim)
            
            # Backtracking: Desfaz a troca para tentar o próximo caminho
            lista[inicio], lista[i] = lista[i], lista[inicio]

# Teste
dados = [1, 2, 3]
n = len(dados)
print(f"Todas as permutações de {n} elementos:")
gerar_permutacoes(dados, 0, n - 1)