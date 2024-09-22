import os

Leitura = 0
Escrita = 0
QtdNumeros = 5000
ParteDeExecucao = 1
TamanhoTotal = len(open('input2.txt').readlines())

def ContarLeitura():
    global Leitura
    Leitura += 1

def ContarEscrita():
    global Escrita
    Escrita += 1

def Heapify(Vet, Tamanho, Indice, min_heap=False):
    Extremo = Indice
    Esquerda = 2 * Indice + 1
    Direita = 2 * Indice + 2

    if Esquerda < Tamanho and ((not min_heap and Vet[Indice] < Vet[Esquerda]) or (min_heap and Vet[Indice] > Vet[Esquerda])):
        Extremo = Esquerda

    if Direita < Tamanho and ((not min_heap and Vet[Extremo] < Vet[Direita]) or (min_heap and Vet[Extremo] > Vet[Direita])):
        Extremo = Direita

    if Extremo != Indice:
        Vet[Indice], Vet[Extremo] = Vet[Extremo], Vet[Indice]
        Heapify(Vet, Tamanho, Extremo, min_heap)

def HeapSort(Vet):
    Tamanho = len(Vet)

    for i in range(Tamanho // 2 - 1, -1, -1):
        Heapify(Vet, Tamanho, i, min_heap=False)

    for i in range(Tamanho - 1, 0, -1):
        Vet[i], Vet[0] = Vet[0], Vet[i]
        Heapify(Vet, i, 0, min_heap=False)

def CriarArquivosIntermediarios():
    Pedacos = []
    with open('input2.txt', 'r') as f:
        Pedaco = []
        for Linha in f:
            ContarLeitura()
            Pedaco.append(int(Linha))
            if len(Pedaco) == QtdNumeros:
                HeapSort(Pedaco)
                Pedacos.append(Pedaco[:])
                Pedaco = []
        if Pedaco:
            HeapSort(Pedaco)
            Pedacos.append(Pedaco[:])
    return Pedacos
    
def EscreverArquivosIntermediarios(Pedacos):
    if not os.path.exists("Pedacos"):
        os.makedirs("Pedacos")
    for i in range(len(Pedacos)):
        with open(f'Pedacos/Parte0{ParteDeExecucao}Pedaco_0{i+1}.txt', 'w') as f:
            for Num in Pedacos[i]:
                ContarEscrita()
                f.write(f'{Num}\n')

def CriarPartes():
    global ParteDeExecucao
    global QtdNumeros
    global TamanhoTotal

    Pedacos = CriarArquivosIntermediarios()
    EscreverArquivosIntermediarios(Pedacos)
    while len(Pedacos) > 1:
        ParteDeExecucao += 1
        QtdNumeros *= 2
        Pedacos = CriarArquivosIntermediarios()
        EscreverArquivosIntermediarios(Pedacos)
        
    MergeFinal()
    return Pedacos

def CriarOutput():
    Arquivos = [open(f'Pedacos/Parte0{ParteDeExecucao}Pedaco_01.txt', 'r') for i in range(len(os.listdir("Pedacos"))]
                
    

    

Pedacos = CriarPartes()

print("Tamanho Total: ", TamanhoTotal)

print(f'Leituras: {Leitura}')
print(f'Escritas: {Escrita}')

LeituraRegistro = Leitura / TamanhoTotal
EscritaRegistro = Escrita / TamanhoTotal

RQuantidade = len(Pedacos)
QuantidadeReal = 0

while RQuantidade > 1:
    RQuantidade = RQuantidade // 2 + RQuantidade % 2
    QuantidadeReal += 1
print(f'Quantidade de Leituras dos Registros: {QuantidadeReal+1}')
print(f'Quantidade de Escritas dos Registros: {QuantidadeReal+1}')

# def MergeFinal():
#     Arquivos = [open(f'Pedacos/Parte0{ParteDeExecucao}Pedaco_0{i+1}.txt', 'r') for i in range(len(os.listdir("Pedacos")))]

#     Heap = []
#     for i, f in enumerate(Arquivos):
#         Linha = f.readline()
#         if Linha:
#             ContarLeitura()
#             Heap.append((int(Linha), i))

#     for i in range(len(Heap) // 2 - 1, -1, -1):
#         Heapify(Heap, len(Heap), i, min_heap=True)

#     with open('output2.txt', 'w') as f:
#         while Heap:
#             Menor, Indice = Heap[0]
#             ContarEscrita()
#             f.write(f'{Menor}\n')
#             Linha = Arquivos[Indice].readline()
#             if Linha:
#                 ContarLeitura()
#                 Heap[0] = (int(Linha), Indice)
#             else:
#                 Heap[0] = Heap[-1]
#                 Heap.pop()
#             Heapify(Heap, len(Heap), 0, min_heap=True)

#     for f in Arquivos:
#         f.close()
