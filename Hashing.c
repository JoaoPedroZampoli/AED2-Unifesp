#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

#define TAMANHOTABELA 10
#define TAMANHOPALAVRA 100

typedef struct{
    char *Palavra;
    char *Traducao;
}Dicionario;

Dicionario * TabelaHash[TAMANHOTABELA];

int Hash(char *Palavra){
    int Tamanho = strlen(Palavra);
    unsigned int ValorHash = 0;
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

bool InserirPalavra(Dicionario *P){
    if(P == NULL){
        return false;
    }
    int Posicao = Hash(P->Palavra);
    if(TabelaHash[Posicao] != NULL){
        int PosicaoOriginal = Posicao;
        do {
            Posicao = (Posicao + 1) % TAMANHOTABELA;
        } while(Posicao != PosicaoOriginal && TabelaHash[Posicao] != NULL);
        if(TabelaHash[Posicao] != NULL) {
            return false;
        }
    }
    TabelaHash[Posicao] = P;
    return true;
}

Dicionario *BuscarNaTabelaHash(char *Palavra){
    int Posicao = Hash(Palavra);
    int PosicaoOriginal = Posicao;
    while(TabelaHash[Posicao] != NULL){
        if(strcmp(TabelaHash[Posicao]->Palavra, Palavra) == 0){
            return TabelaHash[Posicao];
        }
        Posicao = (Posicao + 1) % TAMANHOTABELA;
        if(Posicao == PosicaoOriginal){
            break;
        }
    }
    return NULL;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    //Problema 3 - AED II
    //M => Número de termos com traduções conhecidas: 1 <= M <= 10000
    //N => Número de linhas da música a serem traduzidas: 1 <= N <= 10000

    int M, N, i;
    char *Palavra = malloc(100 * sizeof(char));

    IniciarTabelaHash();
    ImprimirTabela();

    Dicionario Take = {.Palavra="Take", .Traducao="Tem"};
    Dicionario Side = {.Palavra="Side", .Traducao="Site"};
    Dicionario Tem = {.Palavra="The", .Traducao="Em"};
    Dicionario Agora = {.Palavra="Gotta", .Traducao="Agora"};

    InserirPalavra(&Take);
    InserirPalavra(&Side);
    InserirPalavra(&Tem);
    InserirPalavra(&Agora);

    ImprimirTabela();

    Dicionario *Temporario = BuscarNaTabelaHash("Take");
    if(Temporario == NULL){
        printf("Palavra nao encontrada\n");
    } else {
        printf("Traducao de Take: %s\n", Temporario->Traducao);
    }

    Temporario = BuscarNaTabelaHash("Side");
    if(Temporario == NULL){
        printf("Palavra nao encontrada\n");
    } else {
        printf("Traducao de Side: %s\n", Temporario->Traducao);
    }

    // scanf("%d", &M);
    // if(M < 1 || M > 10000){
    //     return 0;
    // }
    // scanf("%d", &N);
    // if(N < 1 || N > 10000){
    //     return 0;
    // }
    printf("Take => %u\n", Hash("Take"));
    printf("Side => %u\n", Hash("Side"));
    printf("The => %u\n", Hash("The"));
    printf("Gotta => %u\n", Hash("Gotta"));
}