#BEATRIZ SANTOS DE OLIVEIRA

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    char input[MAX_SIZE];
    int cont;

    FILE *file = fopen("input_decimais.txt", "r"); // Abrir o arquivo para leitura
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

Q0:
    if (fgets(input, sizeof(input), file) != NULL) {
        cont = 0;
        goto Q1;
    } else {
        fclose(file);
        return 0;
    }

Q1:
    if (input[cont] == '+' || input[cont] == '-') { // "consome" o primeiro simbolo da cadeia, que e o sinal
        cont++;
        goto Q2;
    } else {
        input[strlen(input) - 1] = '\0'; // Remover o caractere de nova linha
        printf("%s      Cadeia rejeitada.\n", input); // rejeita se comecar com outro simbolo
        goto Q0;
    }

Q2: 
    if(input[cont] >= '0' && input[cont] <= '9'){ // "consome" os simbolos da cadeia antecessores ao ".", que sao digitos
        cont++;
        goto Q2;
    } else if(input[cont] == '.'){ // "consome" o simbolo "."
        cont++;
        goto Q3;  
    } else{
        input[strlen(input) - 1] = '\0'; // Remover o caractere de nova linha
        printf("%s      Cadeia rejeitada.\n", input);
        goto Q0;
    }

Q3:
    if (input[cont] == '\0' || input[cont] == '\n') { // "consome" os simbolos da cadeia sucessores ao ".", que sao digitos
        input[cont] = '\0'; // Substituir o caractere de nova linha por um caractere nulo
        printf("%s      Cadeia aceita.\n", input);
        goto Q0;
    } else if (input[cont] >= '0' && input[cont] <= '9') { // se foi possivel chegar ao final da cadeia, entao a palavra e aceita
        cont++;
        goto Q3;
    } else {
        input[strlen(input) - 1] = '\0'; // Remover o caractere de nova linha
        printf("%s      Cadeia rejeitada.\n", input);
        goto Q0;
    }
  
}
