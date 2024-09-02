import csv

def insertionSort(vet):
  # ordena vetor vet por insertion sort

  for i in range(len(vet)):
      # percorre vetor vet
      aux = vet[i]
      j = i - 1

      while j >= 0 and aux < vet[j]:
          # faz trocas
          vet[j + 1] = vet[j]
          j = j - 1

      vet[j + 1] = aux


def main():

  vet = []
  
  with open('TabelaXX.csv', 'r') as arq:
    reader = csv.reader(arq)
    for linha in reader:
      vet.append(int(linha[0]))
  # transfere dados para vet
  # converte dados para int
  
  insertionSort(vet)


main()