import java.io.*;
import java.util.*;

public class CountingSort {
    void Sort(int Array[]){
        int N = Array.length;
        int Saida[] = new int[N];
        int Count[] = new int[10000000];

        for(int i = 0; i < 10000000; i++){
            Count[i] = 0;
        }
        for(int i = 0; i < N; i++){
            ++Count[Array[i]];
        }
        for(int i = 1; i <= 9999999; ++i){
            Count[i] += Count[i-1];
        }
        for(int i = N-1; i >= 0; i--){
            Saida[Count[Array[i]] - 1] = Array[i];
        }
        for(int i = 0; i < N; ++i){
            Array[i] = Saida[i];
        }
    }

    static void ImprimirArray(int Array[]){
        System.out.println("Array Ordenado:");
        for(int i = 0; i < Array.length; ++i){ //Comente esse laço caso não queira Imprimir
            System.out.print(Array[i] + " ");
        }
    }

    public static void main(String args[]){
        CountingSort cs = new CountingSort();
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
        cs.Sort(Array);

        //ImprimirArray(Array);
    }
}
