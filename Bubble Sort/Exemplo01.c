#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void BubbleSort(int Vet[N]){
    int i, j, Aux;
    for(i = 0; i < N-1; i++){
        for(j = 1; j < N - i; j++){
            if(Vet[j-1] > Vet[j]){
                Aux = Vet[j];
                Vet[j] = Vet[j-1];
                Vet[j-1] = Aux;
            }
        }
    }
    
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    /*Aqui é realizado o preenchimento do Vetor, após isso a função é chamada*/
}