import csv
import random
import os

DiretorioAtual = os.path.dirname(os.path.realpath(__file__))

for i in range(1,6):
    Num = str(i)
    Numeros = []
    Counter = random.randint(1001,100001)
    NomeArquivo = "TabelaC"+Num+".csv"
    CaminhoArquivo = os.path.join(DiretorioAtual, NomeArquivo)
    
    for j in range(Counter):
        Numeros.append(random.randint(0,10000000))
    
    Numeros.sort()

    n = len(Numeros)
    troca = int(0.05*n//2)
    for j in range(troca):
      ind1 = random.randint(0,n-1)
      ind2 = random.randint(0,n-1)
      Numeros[ind1], Numeros[ind2] = Numeros[ind2], Numeros[ind1]
    
    with open(CaminhoArquivo, 'w', newline='') as file:
        csv_writer = csv.writer(file)
        for Pos in Numeros:
            csv_writer.writerow([Pos])