def busca_binaria(lista, alvo):
    inicio = 0
    fim = len(lista) - 1

    while inicio <= fim:
        meio = (inicio + fim) // 2  # Encontra o índice do meio
        chute = lista[meio]

        if chute == alvo:
            return meio  # Encontrado
        if chute > alvo:
            fim = meio - 1  # Descarta a metade superior
        else:
            inicio = meio + 1  # Descarta a metade inferior
    
    return -1  # Não encontrado

# Teste
numeros = [1, 3, 5, 7, 9, 11, 13] # Lista deve estar ordenada
resultado = busca_binaria(numeros, 7)
print(f"Elemento encontrado no índice: {resultado}")