#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int Valor;
    int IndiceVetor;
    int IndiceElemento;
} No;

void Troca(No *A, No *B) {
    No Temporario = *A;
    *A = *B;
    *B = Temporario;
}

void MinHeapify(No *Heap, int Tamanho, int i) {
    int Menor = i;
    int Esquerda = 2 * i + 1;
    int Direita = 2 * i + 2;

    if (Esquerda < Tamanho && Heap[Esquerda].Valor < Heap[Menor].Valor)
        Menor = Esquerda;

    if (Direita < Tamanho && Heap[Direita].Valor < Heap[Menor].Valor)
        Menor = Direita;

    if (Menor != i) {
        Troca(&Heap[i], &Heap[Menor]);
        MinHeapify(Heap, Tamanho, Menor);
    }
}

void ConstruirMinHeap(No *Heap, int Tamanho) {
    for (int i = Tamanho / 2 - 1; i >= 0; i--)
        MinHeapify(Heap, Tamanho, i);
}

int Comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int K, i;
    scanf("%d %d", &K, &i);

    int **Vetores = malloc(K * sizeof(int*));
    int *TamanhoVetores = malloc(K * sizeof(int));
    int *Indice = calloc(K, sizeof(int));

    No *MinHeap = malloc(K * sizeof(No));
    int TamanhoHeap = 0;

    for (int j = 0; j < K; j++) {
        scanf("%d", &TamanhoVetores[j]);
        Vetores[j] = malloc(TamanhoVetores[j] * sizeof(int));
        for (int Counter = 0; Counter < TamanhoVetores[j]; Counter++) {
            scanf("%d", &Vetores[j][Counter]);
        }
        if (TamanhoVetores[j] > 0) {
            MinHeap[TamanhoHeap] = (No){Vetores[j][0], j, 0};
            TamanhoHeap++;
        }
    }

    ConstruirMinHeap(MinHeap, TamanhoHeap);

    int *Saida = malloc(TamanhoHeap * sizeof(int));
    int TamanhoSaida = 0;

    for (int Counter = 1; Counter <= i; Counter++) {
        if (Counter == i) {
            for (int j = 0; j < TamanhoHeap; j++) {
                Saida[TamanhoSaida++] = MinHeap[j].Valor;
            }
            qsort(Saida, TamanhoSaida, sizeof(int), Comparar);
            for (int j = 0; j < TamanhoSaida; j++) {
                printf("%d ", Saida[j]);
            }
            printf("\n");
            break;
        }

        No MenorElemento = MinHeap[0];
        int IndiceVetor = MenorElemento.IndiceVetor;
        int IndiceElemento = MenorElemento.IndiceElemento;

        Indice[IndiceVetor]++;
        
        if (Indice[IndiceVetor] < TamanhoVetores[IndiceVetor]) {
            MinHeap[0] = (No){Vetores[IndiceVetor][Indice[IndiceVetor]], IndiceVetor, Indice[IndiceVetor]};
        } else {
            MinHeap[0] = MinHeap[TamanhoHeap - 1];
            TamanhoHeap--;
        }

        MinHeapify(MinHeap, TamanhoHeap, 0);
    }

    for (int j = 0; j < K; j++) {
        free(Vetores[j]);
    }
    free(Vetores);
    free(TamanhoVetores);
    free(Indice);
    free(MinHeap);
    free(Saida);

    return 0;
}