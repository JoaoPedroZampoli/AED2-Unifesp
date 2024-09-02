import csv

def maxHeapify(vet, n, i):
  # contrói um max heap a partir de vet parcialmente ordenado

  maior = i
  esq = 2*i + 1
  dir = 2*i + 2

  if esq<n and vet[i]<vet[esq]:
    maior = esq

  if dir<n and vet[maior]<vet[dir]:
    maior = dir

  if maior != i:
    vet[i], vet[maior] = vet[maior], vet[i]
    maxHeapify(vet, n, maior)


def buildMaxHeap(vet, n):
  # constrói max heap a partir de vet não ordenado

  i = n//2
  while i >= 0:
    maxHeapify(vet, n, i)
    i -= 1

  
def heapSort():
  # ordena um vetor por heapsort
  
  vet = []

  with open('TabelaXX.csv', 'r') as arq:
    reader = csv.reader(arq)
    for linha in reader:
      vet.append(int(linha[0]))
  # transfere dados para vet
  # converte dados para int
  
  n = len(vet)
  buildMaxHeap(vet, n)
  i = n-1
  while i > 0:
    vet[0], vet[i] = (vet[i], vet[0])
    n -= 1
    maxHeapify(vet, n, 0)
    i -= 1
  

heapSort()