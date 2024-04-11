//BEATRIZ SANTOS DE OLIVEIRA

//p1 -> aSb
//p2 -> c

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define PRODUCOES_SIZE 10
#define ARVORE_SIZE 100

typedef struct 
{
    char producoes[2];
} Producoes; 

char stack[STACK_SIZE];
int top = -1;


void push(char symbol) {
    if (top < STACK_SIZE - 1) {
        top++;
        stack[top] = symbol;
    } else {
        printf("Stack overflow!\n");
        exit(1);
    }
}

void pop() {
    if (top >= 0) {
        top--;
    } else {
        printf("Stack underflow!\n");
        exit(1);
    }
}

int main() {
    FILE *fp;
    char token, arv[ARVORE_SIZE];
    int cont=0, i=0;
    Producoes p[PRODUCOES_SIZE];

    // Open file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("erro ao abrir o arquivo\n");
        return 1;
    }

    printf("\n i   q   w   d   p             0   1   2   3   4   5   6   7   8   9   10"); //d do delta
    printf("\n === === === === ===           === === === === === === === === === === ===");
  
//inicializa a pilha
//d0
q0:
    printf("\n %d   q0  .   d0  -  ", i);
    printf("     s[] : ");
    ++i;
  
    push('S');
  
    token = fgetc(fp);
    goto q1;

q1:
    //d1 | p1 
    if (token == 'a' && stack[top] == 'S') { 
        printf("\n %d   q1  .   d1  p1  ", i);
        printf("    s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;
      
        pop();
        push('b');
        push('S');
        push('a');
        p[cont].producoes[0] = 'p';
        p[cont].producoes[1] = '1';
        ++cont;
    //d2 | p1
    } else if (token == 'b' && stack[top] == 'S') {
        printf("\n %d   q1  .   d2  p1  ", i);
        printf("    s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;
      
        pop();
        push('a');
        push('S');
        push('b');
        p[cont].producoes[0] = 'p';
        p[cont].producoes[1] = '1';
        ++cont;
    //d3| p2
    } else if (token == 'c' && stack[top] == 'S') {
        printf("\n %d   q1  .   d3  p2  ", i);
        printf("    s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;
      
        pop();
        push('c');
        p[cont].producoes[0] = 'p';
        p[cont].producoes[1] = '2';
        ++cont;
    //d4
    } else if (token == 'a' && stack[top] == 'a') {
        printf("\n %d   q1  .   d4  -  ", i);
        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;
      
        pop();
        token = fgetc(fp);
    //d5
    } else if (token == 'b' && stack[top] == 'b') {
        printf("\n %d   q1  .   d5  -  ", i);
        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;
      
        pop();
        token = fgetc(fp);
    //d6
    } else if (token == 'c' && stack[top] == 'c') {
        printf("\n %d   q1  .   d6  -  ", i);
        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;
      
        pop();
        token = fgetc(fp);
    //chegou no final do arquivo
    //d7
    } else if (token == EOF) {
        printf("\n %d   q1  .   d7  -  ", i);
        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;
        goto ARV;
    }
    goto q1;

ARV: 
    arv[0] = 'S';

    for(int j=0; j<cont; j++){
        //armazena na arvore aSb
        if(p[j].producoes[0] == 'p' && p[j].producoes[1] == '1'){
          arv[3*j+1] = 'a';
          arv[3*j+2] = 'S';
          arv[3*j+3] = 'b';
        } else if(p[j].producoes[0] == 'p' && p[j].producoes[1] == '2'){ //armazena o c, ultima folha da arvores
            arv[3*j+1] = 'c'; 
          }  
    }
    
    //print da arvore 
    printf("\n\n=== ARVORE DE ANALISE SINTATICA ===\n\n");
  
    printf("   %c   ", arv[0]); printf("\n / | \\"); //imprime a raiz
  
    for(int j=0; j<cont; j++){
      if(arv[3*j+1] == 'c'){
        printf("\n   %c   ", arv[3*j+1]); //imprime a ultima folha
      }else{
        printf("\n%c  %c  %c", arv[3*j+1], arv[3*j+2], arv[3*j+2]); printf("\n / | \\"); //imprime as demais folhas
      }
    }

    fclose(fp);
    return 0;
}
