#include <stdio.h>
#include <stdlib.h>

void exchange(int *vet,int i,int j){
  int aux;
  aux = vet[i];
  vet[i] = vet[j];
  vet[j] = aux;
}

void max_heapfy(int *vet,int n,int i){
  int maior=i;
  int esq = 2*i+1;
  int dir = 2*i+2;
  if(esq<n && vet[esq]>vet[i])
    maior = esq;
  if(dir<n && vet[dir]>vet[maior])
    maior = dir;
  if(maior!=i){
    exchange(vet,i,maior);
    max_heapfy(vet,n,maior);
  }
}

void buildMaxHeap(int *vet,int n){
  int i;
  for(i=(n/2);i>=0;i--)
    max_heapfy(vet,n,i);
}

void heapsort(int *vet,int n){
  int i;
  buildMaxHeap(vet,n);
  for(i=n-1;i>=1;i--){
    exchange(vet,0,i);
    max_heapfy(vet,i,0);
  }
}

int main(){
  int *vet,n=0;
  int i;
  int aux;
  FILE *arq;
  arq = fopen("TabelaXX.csv","r");
  if (arq == NULL) {
    printf("Arquivo não encontrado.\n");
    return 0;
  }
  while(fscanf(arq,"%d,",&aux)!= EOF){
    n++;  // Calcula o tamanho do vetor
  }
  vet = malloc(n*sizeof(int));
  rewind(arq); // Retorna ao início do arquivo
  for(i=0;i<n;i++){
    fscanf(arq,"%d",&vet[i]);
  }
  heapsort(vet,n);
  /*for(i=0;i<n;i++)
    printf("%d\n",vet[i]); */ //Imprimindo
  free(vet);
  fclose(arq);
  return 0;
}