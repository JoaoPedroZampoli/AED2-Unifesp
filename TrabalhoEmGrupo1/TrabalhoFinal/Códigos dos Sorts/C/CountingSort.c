#include <stdio.h>
#include <stdlib.h>

void counting(int *A,int n,int *B,int *C,int k){
  int i;
  for(i=0;i<=k;i++)
    C[i] = 0;
  for(i=1;i<=n;i++)
    C[A[i]]++;
  for(i=1;i<=k;i++)
    C[i] += C[i-1];
  for(i=n;i>=1;i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
}

int main(){
  int *A,*B,*C,i,k=0;
  int tam=0;
  int aux;
  FILE *arq;
  arq = fopen("TabelaXX.csv","r");
  if (arq == NULL) {
    printf("Arquivo não encontrado.\n");
    return 0;
  }
  while(fscanf(arq,"%d,",&aux)!= EOF){
    tam++;  // Calcula o tamanho do vetor
  }
  A = malloc(sizeof(int)*(tam+1));
  rewind(arq); // Retorna ao início do arquivo
  for(i=1;i<=tam;i++){
    fscanf(arq,"%d",&A[i]);
    if(A[i]>k){
      k = A[i];
    }
  }
  B = malloc(sizeof(int)*(tam+1));
  C = malloc(sizeof(int)*(k+1));
  counting(A,tam,B,C,k);
  /*for(i=1;i<=tam;i++)
    printf("%d\n",B[i]); */ //Imprimindo
  free(A);
  free(B);
  free(C);
  fclose(arq);
  return 0;
}