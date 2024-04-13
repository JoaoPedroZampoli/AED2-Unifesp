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
    TipoIndice i, j, Min; //Todos esses guardarão as posições dos elementos
    TipoItem x; //Esse guardará o valor de um elemento
    for (i = 0; i < N; i++){//!!Questão de Otimização: "for" pode ser de (i < N - 1) devido ao fato de o último número a ser comparado já ser o último número de fato
        Min = i;
        //Primeiro laço serve para percorrer o vetor.  Min é definido como o elemento i para ser comparado com o restante após ele
        for(j = i + 1; j < N; j++){
            //Segundo laço serve para comparações entre o Min com cada elemento seguinte, de forma a se obter o menor elemento
            if(A[j].Chave < A[Min].Chave){
                Min = j;
                //A partir daqui, X serve como uma variável auxiliar para inverter A[Min] e A[i]
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