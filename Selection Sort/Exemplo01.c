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

void SelectionSort(TipoItem *A, TipoIndice N){
    TipoIndice i, j, Min;
    TipoItem x;
    for (i = 0; i < N; i++){
        Min = i;
        for(j = i + 1; j < N; j++){
            if(A[j].Chave < A[Min].Chave){
                Min = j;
                x = A[Min];
                A[Min] = A[i];
                A[i] = x;
            }
        }
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    /*Aqui é realizado o preenchimento do Vetor, após isso a função é chamada*/
}