def process(lista, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    
    if left < n and lista[i] < lista[left]:
        largest = left
        
    if right < n and lista[largest] < lista[right]:
        largest = right
  
    if largest != i:
        lista[i],lista[largest] = lista[largest],lista[i]
  
        process(lista, n, largest)
  
def heapSort(lista):
    n = len(lista)
  
    for i in range(n//2 - 1, -1, -1):
        process(lista, n, i)
  
    for i in range(n-1, 0, -1):
        lista[i], lista[0] = lista[0], lista[i]
        process(lista, i, 0)
  
lista = [ 5, 4, 3, 2, 1, 0]
heapSort(lista)
n = len(lista)
print ("Sorted list is")
for i in range(n):
    print ("%d" %lista[i])
