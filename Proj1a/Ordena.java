import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.text.DecimalFormat;

public class Ordena{
    public static void main(String[] args){
        int[] vet = new int[100];
        Random rand = new Random();

        try {
            FileWriter csvWriter = new FileWriter("tempos_execucao.csv");

            for (int i = 0; i < 1024; i++) {
                for (int j = 0; j < 100; j++) {
                    vet[j] = rand.nextInt(1000);
                }

                long start = System.nanoTime();
                insertionSort(vet);
                long end = System.nanoTime();
                double tempo = (double) (end - start) / 1000000.0;
              
                DecimalFormat df = new DecimalFormat("#.###");
                csvWriter.append(df.format(tempo) + ", ");
            }

            csvWriter.flush();
            csvWriter.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void insertionSort(int[] vet) {
        int n = vet.length;
        for (int i = 1; i < n; i++) {
            int key = vet[i];
            int j = i - 1;

            while (j >= 0 && vet[j] > key) {
                vet[j + 1] = vet[j];
                j = j - 1;
            }
            vet[j + 1] = key;
        }
    }
}
