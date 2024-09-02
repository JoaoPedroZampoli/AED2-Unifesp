import csv
import random
import os

DiretorioAtual = os.path.dirname(os.path.realpath(__file__))

for i in range(1,6):
    Num = str(i)
    Numeros = []
    Counter = random.randint(1000,1000000)
    NomeArquivo = "TabelaB"+Num+".csv"
    CaminhoArquivo = os.path.join(DiretorioAtual, NomeArquivo)
    
    for j in range(Counter):
        Numeros.append(random.randint(0,10000000))
    
    Numeros.sort(reverse=True)
    
    with open(CaminhoArquivo, 'w', newline='') as file:
        csv_writer = csv.writer(file)
        for Pos in Numeros:
            csv_writer.writerow([Pos])