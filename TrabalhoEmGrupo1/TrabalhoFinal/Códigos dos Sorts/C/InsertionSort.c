#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 1024

void insertion(int vet[],int N){ //melhor caso: O(n)
  int i,j,aux;                   //pior caso: O(n²)
  for(i=1;i<N;i++){
    j = i - 1;
    aux = vet[i];
    while(j>=0 && vet[j]>aux){
      vet[j+1] = vet[j];
      j--;
    }
    vet[j+1] = aux;
  }
}

int main(){
  int *vet;
  int aux;
  int i,tam=0;
  FILE *arq;
  arq = fopen("TabelaC1.csv","r");
  if(arq == NULL) {
    printf("Arquivo não encontrado.\n");
    return 0;
  }
  while(fscanf(arq,"%d,",&aux)!=EOF){
    tam++; // Calcula o tamanho do vetor
  }
  vet = malloc(tam*sizeof(int));
  rewind(arq); // Retorna ao início do arquivo
  for(i=0;i<tam;i++)
    fscanf(arq,"%d",&vet[i]);
  insertion(vet,tam);
  /*for(i=0;i<tam;i++)
    printf("%d\n",vet[i]); */ //Imprimindo
  free(vet);
  fclose(arq);
  return 0;
}