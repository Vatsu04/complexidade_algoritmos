def partition(arr, low, high):
    pivot = arr[high]  # Escolhe o último elemento como pivô
    i = low - 1        # Índice do menor elemento
    
    for j in range(low, high):
        # Se o elemento atual é menor ou igual ao pivô
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i] # Troca
            
    # Coloca o pivô na posição correta
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quick_sort(arr, low, high):
    if low < high:
        # pi é o índice de particionamento
        pi = partition(arr, low, high)
        
        # Ordena os elementos antes e depois da partição
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

# Teste
numeros = [10, 7, 8, 9, 1, 5]
n = len(numeros)
quick_sort(numeros, 0, n - 1)
print(f"Array ordenado: {numeros}")