#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

#define TAMANHOTABELA 10000
#define TAMANHOPALAVRA 100

typedef struct{
    char *Palavra;
    char *Traducao;
}Dicionario;

Dicionario * TabelaHash[TAMANHOTABELA];

int Hash(char *Palavra){
    int Tamanho = strlen(Palavra);
    int ValorHash = 0;
    for(int i = 0; i < Tamanho; i++){
        ValorHash = (ValorHash * 31 + Palavra[i]) % TAMANHOTABELA;
    }
    return ValorHash;
}

void IniciarTabelaHash(){
    for(int i = 0; i < TAMANHOTABELA; i++){
        TabelaHash[i] = NULL;
    }
}

void ImprimirTabela(){
    for(int i = 0; i < TAMANHOTABELA; i++){
        if(TabelaHash[i] == NULL){
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t%s => %s\n", i, TabelaHash[i]->Palavra, TabelaHash[i]->Traducao);
        }
    }
}

bool InserirPalavra(char *Palavra, char *Traducao){
    int Posicao = Hash(Palavra);
    int PosicaoOriginal = Posicao;

    do {
        if(TabelaHash[Posicao] == NULL) {
            Dicionario *NovaEntrada = malloc(sizeof(Dicionario));
            NovaEntrada->Palavra = strdup(Palavra);
            NovaEntrada->Traducao = strdup(Traducao);
            TabelaHash[Posicao] = NovaEntrada;
            return true;
        }
        Posicao = (Posicao + 1) % TAMANHOTABELA;
    } while(Posicao != PosicaoOriginal);

    return false;
}

char *BuscarNaTabelaHash(char *Palavra){
    int Posicao = Hash(Palavra);
    int PosicaoOriginal = Posicao;
    
    do{
        if(TabelaHash[Posicao] != NULL && strcmp(TabelaHash[Posicao]->Palavra, Palavra) == 0) {
            return TabelaHash[Posicao]->Traducao;
        }
        Posicao = (Posicao + 1) % TAMANHOTABELA;
    }while(Posicao != PosicaoOriginal && TabelaHash[Posicao] != NULL);
    
    return NULL;
}

void ProcessarLinha(char *Linha){
    char *Inicio = Linha;
    char *Fim = Linha;

    while(*Fim != '\0'){
        if(*Fim == ' '){
            *Fim = '\0';
            char *Traducao = BuscarNaTabelaHash(Inicio);
            if (Traducao != NULL) {
                printf("%s ", Traducao);
            }else{
                printf("%s ", Inicio);
            }
            Inicio = Fim + 1;
        }
        Fim++;
    }
    if(*Inicio != '\0'){
        char *Traducao = BuscarNaTabelaHash(Inicio);
        if(Traducao != NULL){
            printf("%s ", Traducao);
        }else{
            printf("%s ", Inicio);
        }
    }
    printf("\n");
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    //Problema 3 - AED II
    //M => Número de termos com traduções conhecidas: 1 <= M <= 10000
    //N => Número de linhas da música a serem traduzidas: 1 <= N <= 10000

    int M, N, i;

    scanf("%d", &M);
    if(M < 1 || M > 10000){
        return 0;
    }
    scanf("%d", &N);
    if(N < 1 || N > 10000){
        return 0;
    }

    IniciarTabelaHash();

    char Palavra[TAMANHOPALAVRA];
    char Traducao[TAMANHOPALAVRA];
    char Linha[TAMANHOPALAVRA * 10];

    for(int i = 0; i < M; i++) {
        scanf("%s", Palavra);
        getchar();
        if (fgets(Traducao, sizeof(Traducao), stdin) != NULL) {
            Traducao[strcspn(Traducao, "\n")] = '\0';
            InserirPalavra(Palavra, Traducao);
        }
    }

    for(int i = 0; i < N; i++) {
        if (fgets(Linha, sizeof(Linha), stdin) != NULL) {
            Linha[strcspn(Linha, "\n")] = '\0';
            ProcessarLinha(Linha);
        }
    }

    //Liberação das Memórias (free)
    for(int i = 0; i < TAMANHOTABELA; i++) {
        if(TabelaHash[i] != NULL) {
            free(TabelaHash[i]->Palavra);
            free(TabelaHash[i]->Traducao);
            free(TabelaHash[i]);
        }
    }
}