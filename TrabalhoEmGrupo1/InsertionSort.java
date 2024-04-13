import java.io.*;
import java.util.*;

public class InsertionSort{
    void Sort(int Array[]){
        int N = Array.length; //Recebe tamanho do Array
        for(int i = 1; i < N; i++){
            int Valor = Array[i]; //Atribui valor do Array na Posição i para uma variável
            int j = i - 1; //Define j como um menor do que i para realizar a comparação

            while(j >= 0 && Array[j] > Valor){ //Parte da troca de Posições
                Array[j+1] = Array[j];
                j = j - 1;
            }
            Array[j + 1] = Valor; //Atribuição do Valor em j+1 para finalizar a troca
        }
    }

    static void ImprimirArray(int Array[]){
        int N = Array.length;
        System.out.println("Array Ordenado: ");
        for(int i = 0; i < N; ++i){
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
        InsertionSort is = new InsertionSort();
        is.Sort(Array);
        
        //ImprimirArray(Array); //Comente isso caso não queira Imprimir
    }
}