#BEATRIZ SANTOS DE OLIVEIRA

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    char input[MAX_SIZE];
    int cont;

    FILE *file = fopen("input_binarios.txt", "r"); // Abrir o arquivo para leitura
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

Q0:
    if (fgets(input, sizeof(input), file) != NULL) { // le a linha e confere se chegou ao final do arquivo
        cont = 0;
        goto Q1;
    } else {
        fclose(file); 
        return 0;
    }

Q1:
    if (input[cont] == '0' || input[cont] == '1') { // consome o simbolo 0 ou 1 e passa para o estado Q2
        cont++;
        goto Q2;
    } else {
        input[strlen(input) - 1] = '\0'; // Remover o caractere de nova linha
        printf("%s      Cadeia rejeitada.\n", input); // se comecar com outra coisa, a cadeia e rejeitada
        goto Q0;
    }

Q2:
    if (input[cont] == '\0' || input[cont] == '\n') { // confere se chegou ao final da cadeia, se sim, ela é aceita
        input[cont] = '\0'; // Substituir o caractere de nova linha por um caractere nulo
        printf("%s      Cadeia aceita.\n", input);
        goto Q0;
    } else if (input[cont] == '0' || input[cont] == '1') { // consome os caracteres restantes ate chegar ao final da cadeia
        cont++;
        goto Q2;
    } else {
        input[strlen(input) - 1] = '\0'; // Remover o caractere de nova linha
        printf("%s      Cadeia rejeitada.\n", input);
        goto Q0;
    }
}
