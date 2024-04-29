#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void BubbleSort(int Vet[], int Tamanho){
    int i, j, Aux;
    for(i = 0; i < Tamanho-1; i++){
        for(j = 1; j < Tamanho - i; j++){
            if(Vet[j-1] > Vet[j]){
                Aux = Vet[j];
                Vet[j] = Vet[j-1];
                Vet[j-1] = Aux;
            }
        }
    }
}

void ImprimirVetor(int Vet[], int Tamanho){
    for(int i = 0; i < Tamanho; i++){
        printf("%d ", Vet[i]);
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    /*Aqui é realizado o preenchimento do Vetor, após isso a função é chamada*/
    int Vetor[] = {5, 3, 2, 4, 7, 1, 0, 6};
    int Tamanho = sizeof(Vetor)/sizeof(Vetor[0]);
    BubbleSort(Vetor, Tamanho);
    printf("Vetor ordenado: \n");
    ImprimirVetor(Vetor, Tamanho);
}