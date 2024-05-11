import java.util.Arrays;

public class Permutacao {

    // Função para calcular o fatorial de um número
    public static long fatorial(int n) {
        if (n == 0 || n == 1) {
            return 1;
        } else {
            return n * fatorial(n - 1);
        }
    }

    // Função para calcular e imprimir todas as permutações de n elementos
    public static void permutar(int[] arr, int inicio, int fim) {
            for (int i = inicio; i <= fim; i++) {
                // Troca arr[inicio] com arr[i]
                int temp = arr[inicio];
                arr[inicio] = arr[i];
                arr[i] = temp;

                // Chama recursivamente permutar para o próximo elemento
                permutar(arr, inicio + 1, fim);

                // Desfaz a troca para restaurar o arr para o seu estado original
                temp = arr[inicio];
                arr[inicio] = arr[i];
                arr[i] = temp;
            }
    }

    public static void main(String[] args) {
        long inicio, fim;
        double tempoDecorrido;

        int n = 2; // Começa com n = 2
        long permutacoes;

        do {
            // Inicia o cronômetro
            inicio = System.currentTimeMillis();

            // Calcula e imprime todas as permutações de n elementos
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = i + 1;
            }
            permutar(arr, 0, n - 1);

            // Para o cronômetro
            fim = System.currentTimeMillis();

            // Calcula o tempo decorrido em segundos
            tempoDecorrido = (double) (fim - inicio) / 1000;

            // Calcula o número total de permutações de n elementos
            permutacoes = fatorial(n);

            System.out.printf("Tempo decorrido para n = %d: %.6f segundos\n", n-1, tempoDecorrido);

            n++; // Incrementa n para testar o próximo valor

        } while (tempoDecorrido < 60); // Repete até o tempo decorrido ser maior ou igual a 1 minuto
    }
}
