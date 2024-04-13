import csv

def insertionSort(array):
  for step in range(1, len(array)):
        key = array[step]
        j = step - 1
        
        # Compare key with each element on the left of it until an element smaller than it is found
        # For descending order, change key<array[j] to key>array[j].        
        while j >= 0 and key < array[j]:
            array[j + 1] = array[j]
            j = j - 1
        
        # Place key at after the element just smaller than it.
        array[j + 1] = key

def ImprimirArray(array):
   print("Array Ordenado: ")
   for i in range(len(array)):
      print(array[i]," ")

def main():
  
  with open('TrabalhoEmGrupo1\\TabelaB2.csv', 'r') as arq:
    reader = csv.reader(arq)
    vet = []
    for linha in reader:
      vet.append(list(map(int, linha)))
  
  insertionSort(vet)

  ImprimirArray(vet)
main()