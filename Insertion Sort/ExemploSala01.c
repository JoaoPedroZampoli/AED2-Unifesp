void InsertionSort(int Vet[], int N){
    int i, j;
    for(i = 1; i < N; i++){
        j = i - 1;
        int Aux = Vet[i];
        while(j >= 0 && Vet[j] > Aux){
            Vet[j+1] = Vet[j];
            j--;
        }
        Vet[j+1] = Aux;
    }
}