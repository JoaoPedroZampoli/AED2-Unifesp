#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 15
#define MAX_NAMES 100000
#define ALPHABET_SIZE 27 // 26 letras minúsculas + 1 caractere adicional

char ParaMinusculas(char C) {
    if (C >= 'A' && C <= 'Z') {
        return C + ('a' - 'A');
    }
    return C;
}

void countingSort(char **Vet, int N, int iRad) {
    int B[ALPHABET_SIZE+1] = {0};
    char **C = malloc(N * sizeof(char *));
    
    for (int i = 0; i < N; i++) {
        char c = ParaMinusculas(Vet[i][iRad]);
        int Pos = (c == '\0') ? 0 : c - 'a' + 1;
        B[Pos]++;
    }
    
    for (int i = 1; i <= ALPHABET_SIZE+1; i++) {
        B[i] += B[i - 1];
    }
    
    for (int i = N - 1; i >= 0; i--) {
        char c = ParaMinusculas(Vet[i][iRad]);
        int Pos = (c == '\0') ? 0 : c - 'a' + 1;
        C[B[Pos] - 1] = Vet[i];
        B[Pos]--;
    }
    
    for (int i = 0; i < N; i++) {
        Vet[i] = C[i];
    }
    
    free(C);
    
    for (int i = 1; i <= ALPHABET_SIZE; i++) {
        printf("%d ", B[i]);
    }
}

void radixSort(char **Vet, int N, int TamMax) {
    for (int iRad = TamMax - 1; iRad >= 0; iRad--) {
        countingSort(Vet, N, iRad);
        printf("\n");
    }
}

int main() {
    int N, P, M;
    char *Nomes[MAX_NAMES];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        Nomes[i] = malloc((MAX_LENGTH + 1) * sizeof(char));
        scanf("%s", Nomes[i]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; Nomes[i][j] != '\0'; j++) {
            Nomes[i][j] = ParaMinusculas(Nomes[i][j]);
        }
    }

    int TamMax = 0;
    for (int i = 0; i < N; i++) {
        int Tam = strlen(Nomes[i]);
        if (Tam > TamMax) {
            TamMax = Tam;
        }
    }

    scanf("%d %d", &P, &M);

    radixSort(Nomes, N, TamMax);

    for (int i = P - 1; i < P + M - 1 && i < N; i++) {
        printf("%s", Nomes[i]);
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        free(Nomes[i]);
    }

    return 0;
}