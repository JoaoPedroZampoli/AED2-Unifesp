import csv
import random
import os

DiretorioAtual = os.path.dirname(os.path.realpath(__file__))

for i in range(1,6):
    Num = str(i)
    Counter = random.randint(1001,1000001)
    NomeArquivo = "TabelaA"+Num+".csv"
    CaminhoArquivo = os.path.join(DiretorioAtual, NomeArquivo)
    with open(CaminhoArquivo, 'w', newline='') as file:
        csv_writer = csv.writer(file)
        for i in range(Counter):
            csv_writer.writerow([random.randint(0,10000000)])
