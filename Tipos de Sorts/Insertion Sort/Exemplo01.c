#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAXTAM 100
typedef int TipoIndice;

typedef struct{
    int Chave;
    /*Outros campos entram aqui*/
}TipoItem;

typedef TipoItem TipoVetor[MAXTAM + 1];

void InsertionSort(TipoItem *Vet, TipoIndice N){
    TipoIndice i, j;
    TipoItem x;
    for(i = 2; i <= N; i++){
        x = Vet[i];
        j = i - 1;
        Vet[0] = x;
        while(x.Chave < Vet[j].Chave){
            Vet[j+1] = Vet[j];
            j--;
        }
        Vet[j+1] = x;
    }
}

void ImprimirVetor(TipoVetor Vetor, TipoIndice Tamanho){
    for(int i = 1; i <= Tamanho; i++){
        printf("%d ", Vetor[i].Chave);
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    /*Aqui é realizado o preenchimento do Vetor, após isso a função é chamada*/
    TipoVetor Vetor;
    for(int i = 1; i <= 10; i++){
        Vetor[i].Chave = rand() % 100;
    }
    InsertionSort(Vetor, 10);
    printf("Vetor ordenado: \n");
    ImprimirVetor(Vetor, 10);
}