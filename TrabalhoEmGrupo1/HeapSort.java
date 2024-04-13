import java.io.*;
import java.util.*;

public class HeapSort {
    void Heapify(int Array[], int N, int i){
        int Maior = i;
        int Esquerda = 2*i+1;
        int Direita = 2*i+2;

        if(Esquerda < N && Array[Esquerda] > Array[Maior]){
            Maior = Esquerda;
        }

        if(Direita < N && Array[Direita] > Array[Maior]){
            Maior = Direita;
        }

        if(Maior != i){
            int Troca = Array[i];
            Array[i] = Array[Maior];
            Array[Maior] = Troca;

            Heapify(Array, N, Maior);
        }
    }

    public void sort(int Array[]){
        int N = Array.length;

        for(int i = N / 2 - 1; i >= 0; i--){
            Heapify(Array, N, i);
        }

        for(int i = N - 1; i >= 0; i--){
            int Temporario = Array[0];
            Array[0] = Array[i];
            Array[i] = Temporario;

            Heapify(Array, i, 0);
        }
    }

    static void ImprimirArray(int Array[]){
        int N = Array.length;
        System.out.println("Array Ordenado:");
        for(int i = 0; i < N; i++){
            System.out.print(Array[i] + " ");
        }
    }

    public static void main(String[] args){
        String CaminhoArquivo = "C:\\Users\\jpsza\\OneDrive\\Documentos\\GitHub\\AED2-Unifesp\\TrabalhoEmGrupo1\\TabelaA1.csv";
        List<Integer> Lista = new ArrayList<>();
        try(BufferedReader br = new BufferedReader(new FileReader(CaminhoArquivo))){
            String Linha;
            while((Linha = br.readLine()) != null){
                String[] Valores = Linha.split(",");
                Lista.add(Integer.parseInt(Valores[0]));
            }
        }
        catch(IOException error){
            error.printStackTrace();
        }
        //int Array[] = {11, 19, 18, 20, 3, 8, 74, 21, 19};
        int Array[] = Lista.stream().mapToInt(i -> i).toArray();
        int N = Array.length;

        HeapSort hs = new HeapSort();
        hs.sort(Array);

        //ImprimirArray(Array); //Comente isso caso não queira Imprimir
    }
}
