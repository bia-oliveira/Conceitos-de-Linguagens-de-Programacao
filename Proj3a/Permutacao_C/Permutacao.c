#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para calcular o fatorial de um número
long long int fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}

// Função para calcular e imprimir todas as permutações de n elementos
void permutar(int *arr, int inicio, int fim) {
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

int main() {
    clock_t inicio, fim;
    double tempo_decorrido;

    int n = 2; // Começa com n = 2
    long long int permutacoes;

    do {
        // Inicia o cronômetro
        inicio = clock();

        // Calcula e imprime todas as permutações de n elementos
        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
        permutar(arr, 0, n - 1);

        // Para o cronômetro
        fim = clock();

        // Calcula o tempo decorrido em segundos
        tempo_decorrido = (double)(fim - inicio) / CLOCKS_PER_SEC;

        // Calcula o número total de permutações de n elementos
        permutacoes = fatorial(n);

        printf("Tempo decorrido para n = %d: %.6f segundos\n", n-1, tempo_decorrido);

        // Libera a memória alocada para arr
        free(arr);

        n++; // Incrementa n para testar o próximo valor

    } while (tempo_decorrido < 60); // Repete até o tempo decorrido ser maior ou igual a 1 minuto

    return 0;
}
