import csv

def countingSort(vet, n, k):
  # ordena vet por counting sort
  
  i = 0
  vetaux = []
  while i != k+1:
    # inicializa vetor auxiliar
    vetaux.append(0)
    i += 1
  
  for i in range(n):
    # conta quantidade de cada valor do vetor e armazena em vetaux
    vetaux[vet[i]] += 1
  
  i = 1
  while i != k+1:
    # calcula índices iniciais
    vetaux[i] += vetaux[i-1]
    i += 1
    
  i = k
  while i > 0:
    # acerta a posição dos índices iniciais 
    vetaux[i] = vetaux[i-1]
    i -= 1
  vetaux[0] = 0
  
  i = 0
  vetord = []
  while i != n:
    # inicializa vetor ordenado
    vetord.append(0)
    i += 1
    
  for i in range(n):
    # ordena vet em vetord
    vetord[vetaux[vet[i]]] = vet[i]
    vetaux[vet[i]] += 1


def main():

  vet = []

  with open('TabelaXX.csv', 'r') as arq:
    reader = csv.reader(arq)
    for linha in reader:
      vet.append(int(linha[0]))
  # transfere dados para vet
  # converte dados para int
  
  countingSort(vet, len(vet), max(vet))


main()