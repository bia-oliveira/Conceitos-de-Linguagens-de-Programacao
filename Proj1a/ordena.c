#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int* vet);

int main(void) {
  
    FILE *arquivo;
    arquivo = fopen("tempos_execucao.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    int vet[100];
    double tempos[1024];
    clock_t t;
    srand((unsigned)time(NULL));

    for (int i = 0; i < 1024; i++) { //"gera" os 1024 vetores
        for (int i = 0; i < 100; i++) { //preenche cada vetor com 100 elementos aleatorios
            vet[i] = rand() % 1000;
        }
        t = clock();
        insertion_sort(vet);
        t = clock() - t;
        tempos[i] = ((double)t) / ((CLOCKS_PER_SEC / 1000));
        fprintf(arquivo, "%.3lf, ", tempos[i]); //salva os tempos de ordenacao em um arquivo
    }

    fclose(arquivo);
    return 0;
}

void insertion_sort(int* vet) {
    int i, j, aux;

    for (i = 1; i < 100; i++) {
        aux = vet[i];
        j = i - 1;

        while (j >= 0 && vet[j] > aux) {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = aux;
    }
}
