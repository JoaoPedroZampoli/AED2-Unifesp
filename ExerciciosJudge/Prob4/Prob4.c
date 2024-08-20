#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHONOME = 15

typedef struct Cliente{
    char Nome[15];
    int *Quantidade;
    int Counter;
    struct Cliente *ProximoCliente;
}Cliente;

typedef struct Grupo{
    Cliente *GrupoClientes;
    int Counter;
}Grupo;

Grupo *CriarGrupo(){
    Grupo *NovoGrupo = (Grupo *)malloc(sizeof(Grupo));
    NovoGrupo->GrupoClientes = NULL;
    NovoGrupo->Counter = 0;
    return NovoGrupo;
}

int Hash(char *Nome, int m){
    int i, Hash = 0;
    for(i = 0; i < strlen(Nome); i++){
        Hash = (Hash * 128 + Nome[i]) % m;
    }
    return Hash;
}

Cliente *BuscarNome(Grupo *Grupo, int m, char *Nome){
    int Posicao = Hash(Nome, m);
    Cliente *Cliente = Grupo[Posicao].GrupoClientes;
    while(Cliente != NULL){
        if(strcmp(Cliente->Nome, Nome) == 0){
            return Cliente;
        }
        Cliente = Cliente->ProximoCliente;
    }
    return NULL;
}

void InserirCliente(Grupo *Grupo, Cliente *Cliente){
    Cliente->ProximoCliente = Grupo->GrupoClientes;
    Grupo->GrupoClientes = Cliente;
    Grupo->Counter++;
}

void InserirNovoCliente(Grupo *Grupo, int m, char *Nome, int Qtd){
    int Posicao = Hash(Nome, m);
    Cliente *NovoCliente = (Cliente *)malloc(sizeof(Cliente));
    strcpy(NovoCliente->Nome, Nome);
    NovoCliente->Quantidade = (int *)malloc(sizeof(int));
    NovoCliente->Quantidade[0] = Qtd;
    NovoCliente->Counter = 1;
    NovoCliente->ProximoCliente = NULL;
    InserirCliente(&Grupo[Posicao], NovoCliente);
}

void AtualizarCliente(Cliente *Cliente, int Qtd){
    Cliente->Quantidade = (int *)realloc(Cliente->Quantidade, (Cliente->Counter + 1) * sizeof(int));
    Cliente->Quantidade[Cliente->Counter] = Qtd;
    Cliente->Counter++;
}

void ImprimirLinha(Grupo *Grupo, char *Nome, int m){
    int Posicao = Hash(Nome, m);
    Cliente *ClienteAtual = Grupo[Posicao].GrupoClientes;
    Cliente *Buscado = NULL;
    while(ClienteAtual != NULL){
        if(Buscado == NULL && strcmp(ClienteAtual->Nome, Nome) == 0){
            Buscado = ClienteAtual;
        }
        ClienteAtual = ClienteAtual->ProximoCliente;
    }

    if(Grupo[Posicao].Counter > 0){
        Cliente *ClienteOrdenado = (Cliente *)malloc(Grupo[Posicao].Counter * sizeof(Cliente));
        int i = 0;
        for(ClienteAtual = Grupo[Posicao].GrupoClientes; ClienteAtual != NULL; ClienteAtual = ClienteAtual->ProximoCliente){
            ClienteOrdenado[i] = *ClienteAtual;
            i++;
        }
        for(i = 0; i < Grupo[Posicao].Counter - 1; i++){
            for(int j = i + 1; j < Grupo[Posicao].Counter; j++){
                if(strcmp(ClienteOrdenado[i].Nome, ClienteOrdenado[j].Nome) > 0){
                    Cliente Temporario = ClienteOrdenado[i];
                    ClienteOrdenado[i] = ClienteOrdenado[j];
                    ClienteOrdenado[j] = Temporario;
                }
            }
        }
        for(i = 0; i < Grupo[Posicao].Counter; i++){
            printf("%s ", ClienteOrdenado[i].Nome);
        }
        printf("\n");
    }
    else{
        printf("\n");
    }

    if(Buscado != NULL){
        for(int i = 0; i < Buscado->Counter; i++){
            printf("%i ", Buscado->Quantidade[i]);
        }
        printf("\n");
    }
    else{
        printf("0\n");
    }


}

int main(){
    int m, Opcao, Qtd;
    int i;
    char Nome[15];


    scanf("%i", &m);
    if(m <= 2 || m >= 1000000){
        return 0;
    }
    //1 - Insere
    //2 - Busca
    //3 - Encerra o programa

    Grupo *Grupos = (Grupo*)malloc(m * sizeof(Grupo));
    for(i = 0; i < m; i++){
        Grupos[i] = *CriarGrupo();
    }

    do{
        scanf("%i", &Opcao);
        if(Opcao == 1){
            scanf("%s", Nome);
            scanf("%i", &Qtd);
            // printf("\nHash: %i\n", Hash(Nome, m));
            Cliente *ClienteExistente = BuscarNome(Grupos, m, Nome);
            if(ClienteExistente != NULL){
                AtualizarCliente(ClienteExistente, Qtd);
            }
            else{
                InserirNovoCliente(Grupos, m, Nome, Qtd);
            }
        }
        else if(Opcao == 2){
            scanf("%s", Nome);
            ImprimirLinha(Grupos, Nome, m);
        }
    }while(Opcao != 0);


    for(i = 0; i < m; i++){
        Cliente *ClienteAtual = Grupos[i].GrupoClientes;
        while (ClienteAtual != NULL){
            Cliente *Temporario = ClienteAtual;
            ClienteAtual = ClienteAtual->ProximoCliente;
            free(Temporario->Quantidade);
            free(Temporario);
        }
    }
    free(Grupos);
}