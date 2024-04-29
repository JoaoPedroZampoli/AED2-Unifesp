#include <stdio.h>

void InsertionSort(int Vet[], int N){
    int i, j;
    for(i = 1; i < N; i++){
        j = i - 1;
        int Aux = Vet[i];
        while(j >= 0 && Vet[j] > Aux){
            Vet[j+1] = Vet[j];
            j--;
        }
        Vet[j+1] = Aux;
    }
}

void ImprimirVetor(int Vet[], int Tamanho){
    for(int i = 0; i < Tamanho; i++){
        printf("%d ", Vet[i]);
    }
}

int main(){
    int Vetor[] = {5, 3, 2, 4, 7, 1, 0, 6};
    int Tamanho = sizeof(Vetor)/sizeof(Vetor[0]);
    InsertionSort(Vetor, Tamanho);
    printf("Vetor ordenado: \n");
    ImprimirVetor(Vetor, Tamanho);
}