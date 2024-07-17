#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int Valor;
    int IndiceVetor;
    int IndiceElemento;
}No;

void Insertion(No Vetor[], int Tamanho, No NovoElemento){
    int i = Tamanho-1;
    while(i >= 0 && Vetor[i].Valor > NovoElemento.Valor){
        Vetor[i+1] = Vetor[i];
        i--;
    }
    Vetor[i+1] = NovoElemento;
}

int main(){
    //K = Número de Vetores Ordenados
    //i = Iteração de Intercalação
    //Counter = Contador (Utilizado para percorrer o Vetor de Tamanho)
    //j = Segundo Contador (Utilizado para percorrer os Vetores dos Números)
    //Vetor = Vetor dos Números Ordenados
    //TamanhoVetor = Vetor que guarda o tamanho de cada Vetor

    int K, i;
    int Counter, j;
    scanf("%i %i", &K, &i);

    int **Vetor = malloc(K * sizeof(int*));
    int *TamanhoVetor = malloc(K * sizeof(int));

    for(Counter = 0; Counter < K; Counter++){
        scanf("%i", &TamanhoVetor[Counter]);
        Vetor[Counter] = malloc(TamanhoVetor[Counter] *sizeof(int));
        for(j = 0; j < TamanhoVetor[Counter]; j++){
            scanf("%i", &Vetor[Counter][j]);
        }
    }

    No* VetorOrdenado = malloc(K * sizeof(No));

    int QtdElementosInseridos = 0;
    for(Counter = 0; Counter < K; Counter++){
        if(TamanhoVetor[Counter] > 0){
            No NovoElemento = {Vetor[Counter][0], Counter, 0}; //Declarando Valor, Indice do Vetor e Indice do Elemento
            Insertion(VetorOrdenado, QtdElementosInseridos, NovoElemento);
            QtdElementosInseridos+=1;
        }
    }

    for(Counter = 0; Counter < i; Counter++){
        if(Counter == i-1){
            for(j = 0; j < QtdElementosInseridos; j++){
                printf("%i ", VetorOrdenado[j].Valor);
            }
            printf("\n");
            break;
        }

        No MenorElemento = VetorOrdenado[0];
        int IndiceVetorMin = MenorElemento.IndiceVetor;
        int IndiceElementoMin = MenorElemento.IndiceElemento;

        for(j = 0; j < QtdElementosInseridos-1; j++){
             VetorOrdenado[j] = VetorOrdenado[j+1];
        }
        QtdElementosInseridos-=1;

        if(IndiceElementoMin+1 < TamanhoVetor[IndiceVetorMin]){
            No NovoElemento = {Vetor[IndiceVetorMin][IndiceElementoMin+1], IndiceVetorMin, IndiceElementoMin+1};
            Insertion(VetorOrdenado, QtdElementosInseridos, NovoElemento);
            QtdElementosInseridos+=1;
        }
    }

    for(Counter = 0; Counter < K; Counter++){
        free(Vetor[Counter]);
    }
    free(Vetor);
    free(TamanhoVetor);
    free(VetorOrdenado);
}