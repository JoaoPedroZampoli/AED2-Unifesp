#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
#define NUMEROMAXIMOVERTICES 500
 
typedef struct{
    bool Mat[NUMEROMAXIMOVERTICES + 1][NUMEROMAXIMOVERTICES + 1];
    int Vertices;
    int Arestas;
} Grafo;
 
bool InicializarGrafo(Grafo *Grafo, int NumeroVertices){
    int i, j;
    if(NumeroVertices > NUMEROMAXIMOVERTICES || NumeroVertices <= 0){
        return false;
    }
    Grafo->Vertices = NumeroVertices;
    Grafo->Arestas = 0;
    for(i = 0; i <= Grafo->Vertices; i++){
        for(j = 0; j <= Grafo->Vertices; j++){
            Grafo->Mat[i][j] = 0;
        }
    }
    return true;
}
 
void InserirAresta(Grafo *Grafo, int VerticeX, int VerticeY){
    if(Grafo->Mat[VerticeX][VerticeY] == 0){
        Grafo->Mat[VerticeX][VerticeY] = 1;
        Grafo->Arestas++;
    }
}
 
void ImprimirGrafo(Grafo *Grafo){
    int i, j;
    for(i = 1; i <= Grafo->Vertices; i++){
        for(j = 1; j <= Grafo->Vertices; j++){
            printf("%i ", Grafo->Mat[i][j]);
        }
        printf("\n");
    }
}
 
void ImprimirVetor(int *Vetor, int Tamanho){
    int i;
    for(i = 0; i < Tamanho; i++){
        printf("%i ", Vetor[i]);
    }
    printf("\n");
}
 
void TrocarChefia(Grafo *Grafo, int VerticeA, int VerticeB, int *T) {
    for (int i = 1; i <= Grafo->Vertices; i++) {
        bool temp = Grafo->Mat[VerticeA][i];
        Grafo->Mat[VerticeA][i] = Grafo->Mat[VerticeB][i];
        Grafo->Mat[VerticeB][i] = temp;
    }
    
    for (int i = 1; i <= Grafo->Vertices; i++) {
        bool temp = Grafo->Mat[i][VerticeA];
        Grafo->Mat[i][VerticeA] = Grafo->Mat[i][VerticeB];
        Grafo->Mat[i][VerticeB] = temp;
    }
}


 
void DFS(Grafo *Grafo, int Vertice, bool *Visitado, int *T, int *MaiorTempoPrisao) {
    Visitado[Vertice] = true;
    for (int i = 1; i <= Grafo->Vertices; i++) {
        if (Grafo->Mat[i][Vertice] == 1 && !Visitado[i]) {
            if (T[i - 1] > *MaiorTempoPrisao) {
                *MaiorTempoPrisao = T[i - 1];
            }
            DFS(Grafo, i, Visitado, T, MaiorTempoPrisao);
        }
    }
}

void Consultar(Grafo *Grafo, int Vertice, int *T) {
    int MaiorTempoPrisao = -1;
    bool Visitado[NUMEROMAXIMOVERTICES + 1] = {0};

    DFS(Grafo, Vertice, Visitado, T, &MaiorTempoPrisao);

    if (MaiorTempoPrisao == -1) {
        printf("*\n");
    } else {
        printf("%d\n", MaiorTempoPrisao);
    }
}

 
 
int main(){
    int N, M, L, i, *T, X, Y, A, B, E;
    char Opcao;
    Grafo GFC;
 
    //N = Número de Membros
    //M = Número de Relações
    //L = Número de Instruções
    //T = Tempo de Prisão dos Membros
    //X = Membro que Comanda
    //Y = Membro que é Comandado por X
    //Opcao = Escolha entre P e T onde P é uma instrução de consulta e T é uma instrução de troca de chefes
 
    scanf("%i %i %i", &N, &M, &L);
    if(N < 1 || N > 500 || M < 0 || M > 60000 || L < 0 || L > 500){
        return 0;
    }
 
    T = (int*)malloc(N * sizeof(int));
    InicializarGrafo(&GFC, N);
 
    for(i = 0; i < N; i++){
        scanf("%i", &T[i]);
    }
 
    for(i = 0; i < M; i++){
        scanf("%i %i", &X, &Y);
        if(X < 1 || X == Y){
            return 0;
        }
        if(Y > N){
            return 0;
        }
        InserirAresta(&GFC, X, Y);
        //ImprimirGrafo(&GFC);
        //ImprimirVetor(T, N);
    }
 
    for(i = 0; i < L; i++){
        scanf(" %c", &Opcao);
        if(Opcao == 'P'){
            scanf("%i", &E);
            Consultar(&GFC, E, T);
        }
        else{
            if(Opcao == 'T'){
                scanf("%i %i", &A, &B);
                if(A < 1 || A > N){
                    return 0;
                }
                if(B < 1 || B > N){
                    return 0;
                }
                TrocarChefia(&GFC, A, B, T);
                //ImprimirGrafo(&GFC);
                //ImprimirVetor(T, N);
            }
        }
    }
 
    free(T);
 
}