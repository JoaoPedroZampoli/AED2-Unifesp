#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int X;
    int Y;
}Posicao;

int BFS(char **Mapa, int PosX, int PosY, int L){
    int MovimentoEixoX[] = {-1, 1, 0, 0};
    int MovimentoEixoY[] = {0, 0, -1, 1};
    int i, j, Distancia[L][80], Visitado[L][80];
    Posicao Fila[L * 80];
    int Inicio = 0, Fim = 0, NovoX, NovoY;

    for(i = 0; i < L; i++){
        for(j = 0; j < strlen(Mapa[i]); j++){
            Distancia[i][j] = -1;
            Visitado[i][j] = 0;
        }
    }

    Distancia[PosX][PosY] = 0;
    Visitado[PosX][PosY] = 1;
    Fila[Fim].X = PosX;
    Fila[Fim].Y = PosY;
    Fim++;

    while(Inicio < Fim){
        Posicao P = Fila[Inicio];
        Inicio++;
        for(i = 0; i < 4; i++){
            NovoX = P.X + MovimentoEixoX[i];
            NovoY = P.Y + MovimentoEixoY[i];

            if(NovoX >= 0 && NovoX < L && NovoY >= 0 && NovoY < 80 && Visitado[NovoX][NovoY] == 0 && (Mapa[NovoX][NovoY] == ' ' || Mapa[NovoX][NovoY] == '$' || Mapa[NovoX][NovoY] == '+' || Mapa[NovoX][NovoY] == '*')){
                Visitado[NovoX][NovoY] = 1;
                Distancia[NovoX][NovoY] = Distancia[P.X][P.Y] + 1;
                Fila[Fim].X = NovoX;
                Fila[Fim].Y = NovoY;
                Fim++;

                if(Mapa[NovoX][NovoY] == '$'){
                    return Distancia[NovoX][NovoY];
                }
            }
        }
    }

    return -1;
}

void CompararDistancia(char **Mapa, int JoaoX, int JoaoY, int PedrinhoX, int PedrinhoY, int L){
    int DistanciaJoao, DistanciaPedrinho;

    DistanciaJoao = BFS(Mapa, JoaoX, JoaoY, L);
    DistanciaPedrinho = BFS(Mapa, PedrinhoX, PedrinhoY, L);

    if(DistanciaJoao != -1 && (DistanciaPedrinho == -1 || DistanciaJoao < DistanciaPedrinho)){
        printf("1\n");
    }
    else if(DistanciaPedrinho != -1 && (DistanciaJoao == -1 || DistanciaJoao > DistanciaPedrinho)){
        printf("2\n");
    }
    else if(DistanciaJoao == DistanciaPedrinho && DistanciaJoao != -1){
        printf("0\n");
    }
    else{
        printf("-1\n");
    }
}

int main(){
    //L = Quantidade de Linhas do Mapa
    //"*" = Posição de João
    //"+" = Posição de Pedrinho
    //"$" = Posição do Tesouro
    //JoaoX = Posição X (Linha) de João
    //JoaoY = Posição Y (Coluna) de João
    //PedrinhoX = Posição X (Linha) de Pedrinho
    //PedrinhoY = Posição Y (Coluna) de Pedrinho
    
    int i, j, L, JoaoX, JoaoY, PedrinhoX, PedrinhoY;
    scanf("%i", &L);
    if(L > 30){
        return 0;
    }
    char **Mapa = (char**)malloc(L * sizeof(char*));
    getchar();
    for(i = 0; i < L; i++){
        Mapa[i] = (char*)malloc(80 * sizeof(char));
    }
    for(i = 0; i < L; i++){
        fgets(Mapa[i], 80, stdin);
        size_t Len = strlen(Mapa[i]);
        if(Len > 0 && Mapa[i][Len - 1] == '\n'){
            Mapa[i][Len - 1] = '\0';
        }
    }

    for(i = 0; i < L; i++){
        for(j = 0; j < strlen(Mapa[i]); j++){
            if(Mapa[i][j] == '*'){
                JoaoX = i;
                JoaoY = j;
            }
            if(Mapa[i][j] == '+'){
                PedrinhoX = i;
                PedrinhoY = j;
            }
        }
    }

    CompararDistancia(Mapa, JoaoX, JoaoY, PedrinhoX, PedrinhoY, L);
    // for(i = 0; i < L; i++){
    //     printf("%s\n", Mapa[i]);
    // }

    for(i = 0; i < L; i++){
        free(Mapa[i]);
    }
    free(Mapa);

}