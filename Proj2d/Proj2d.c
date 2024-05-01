//BEATRIZ SANTOS DE OLIVEIRA

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define PRODUCOES_SIZE 100
#define ARVORE_SIZE 122
#define STACK_IDX_SIZE 100

char w[16];
int  len=0;
int top = -1;
int top2 = -1;
int producoes[PRODUCOES_SIZE];
int stack_index[STACK_IDX_SIZE];
char stack[STACK_SIZE];
char arv[ARVORE_SIZE];
char notPolonesa[20];
int z = 0;
char arvBin[ARVORE_SIZE];
int y = 0;

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

void arvore(int producao){
  
  if(producao == 0){
    arv[0] = 'E';
    top2++;
    stack_index[top2] = 0;
    
  } else if(producao == 1 ){
    int posicao = stack_index[top2];
    top2--;
    arv[posicao*5 + 1] = '(';
    arv[posicao*5 + 2] = 'E';
    arv[posicao*5 + 3] = 'X';
    arv[posicao*5 + 4] = 'E';
    arv[posicao*5 + 5] = ')';
    top2++;
    stack_index[top2] = posicao*5 + 2;
    top2++;
    stack_index[top2] = posicao*5 + 3;
    top2++;
    stack_index[top2] = posicao*5 + 4;
    
  } else if(producao == 2){
    int posicao = stack_index[top2];
    top2--;
    arv[posicao*5 + 1] = '0';
    
  } else if(producao == 3){
    int posicao = stack_index[top2];
    top2--;
    arv[posicao*5 + 1] = '1';
    
  } else if(producao == 4){
    int posicao = stack_index[top2];
    top2--;
    arv[posicao*5 + 1] = 'a';
    
  } else if(producao == 5){
    int posicao = stack_index[top2];
    top2--;
    arv[posicao*5 + 1] = 'b';
    
  } else if(producao == 6){
    int posicao = stack_index[top2];
    top2--;
    arv[posicao*5 + 1] = 'c';
    
  } else if(producao == 7){
    int posicao = stack_index[top2];
    top2--;
    arv[posicao*5 + 1] = '+';
    
  } else if(producao == 8){
    int posicao = stack_index[top2];
    top2--;
    arv[posicao*5 + 1] = '-';
    
  } else if(producao == 9){
    int posicao = stack_index[top2];
    top2--;
    arv[posicao*5 + 1] = '*';
    
  } else if(producao == 10){
    int posicao = stack_index[top2];
    top2--;
    arv[posicao*5 + 1] = '/';
  }
  
}

// Função para converter a arvore penta-aria para uma arvore binaria
void arvoreBinaria(char arvore[]) {

    //remove os parenteses
    for(int i = 0; i < ARVORE_SIZE; i++){
        if (arvore[i] == '(' || arvore[i] == ')'){
            arvore[i] = ' ';
        }
    }

    for (int i = 0; i < ARVORE_SIZE; ++i) {
        // Se encontrar um operador
        if (arvore[i] == '+' || arvore[i] == '-' || arvore[i] == '*' || arvore[i] == '/') {
            // Substitui o avo pelo operador
            int avo = (i - 1) / 5;
            avo = (avo - 1) / 5;
            arvore[avo] = arvore[i];
            // Apaga o operador
            arvore[i] = ' ';
            
        }
        // Se encontrar um operando
        else if (arvore[i] == '0' || arvore[i] == '1' || arvore[i] == 'a' || arvore[i] == 'b' || arvore[i] == 'c') {
            // Substitui o pai pelo operando
            int pai = (i - 1) / 5;
            arvore[pai] = arvore[i];
            // Apaga o operando
            arvore[i] = ' ';
            
        }
    }

    for(int i = 0; i < ARVORE_SIZE; i++){
        if (arvore[i] != '0' && arvore[i] != '1' && arvore[i] != 'a' && arvore[i] != 'b' && arvore[i] != 'c' && arvore[i] != '+' && arvore[i] != '-' && arvore[i] != '*' && arvore[i] != '/'){
            arvore[i] = ' ';
        }
    }

    for(int i = 0; i < ARVORE_SIZE; i++){
        if (arvore[i] != ' '){
            arvBin[y] = arvore[i];
            y++;
        }
    }

}

void postOrder(char arvore[], int index) {
  
    if (arvore[index] == '\0') return;
    // Percorre a subarvore esquerda
    postOrder(arvore, 2 * index + 1);
    // Percorre a subarvore direita
    postOrder(arvore, 2 * index + 2);
    // Visita o no
    notPolonesa[z] = arvore[index];
    z++;
    
}

void nprToPCode(char *npr) {
    int memPos = 3;  // Começar a armazenar variáveis a partir da posição de memória 3

    int i = 0;
    while (npr[i] != '\0') {
        if (npr[i] >= 'a' && npr[i] <= 'z') {
            printf("LOD 0 %d\n", memPos++);
        } else if (npr[i] >= '0' && npr[i] <= '9') {
            printf("LIT 0 %c\n", npr[i]);
        } else if (npr[i] == '+') {
            printf("OPR 0 2\n");  // Operação de soma
        } else if (npr[i] == '-') {
            printf("OPR 0 3\n");  // Operação de subtração
        } else if (npr[i] == '*') {
            printf("OPR 0 4\n");  // Operação de multiplicação
        } else if (npr[i] == '/') {
            printf("OPR 0 5\n");  // Operação de divisão
        }
        i++;
    }
}

int main() {
    FILE *fp;
    char token;
    int cont=0, i=0;

    // Open file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("erro ao abrir o arquivo\n");
        return 1;
    }

    printf("\n i   q   w                d   p              0   1   2   3   4   5   6   7   8   9   10"); //d do delta
    printf("\n === === ================ === ===            === === === === === === === === === === ===");

//d0
q0:
    printf("\n %2d   q0  .%12s   d0  -- ", i, w);
    printf("      s[] : ");
    ++i;

    //Criando a arvore
    for(int i=0; i<ARVORE_SIZE; i++){
        arv[i] = ' ';
    }
  
    push('E');
    producoes[cont] = 0;
    arvore(producoes[0]);
    cont++;
    
    token = fgetc(fp);
    w[len] = token;
    len++;
    w[len] = '\0';
    goto q1;
int k;

q1:
    //d1 | p1
    if (token == '(' && stack[top] == 'E') {

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d1  p1  ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push(')');
        push('E');
        push('X');
        push('E');
        push('(');
        producoes[cont] = 1;
        arvore(producoes[cont]);
        cont++;

    //d2| p2
    } else if (token == '0' && stack[top] == 'E') {

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d2  p2  ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push(token);
        producoes[cont] = 2;
        arvore(producoes[cont]);
        ++cont;

    //d3| p3
    } else if (token == '1' && stack[top] == 'E') {

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d3  p3  ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push(token);
        producoes[cont] = 3;
        arvore(producoes[cont]);
        ++cont;

    //d4| p4
    } else if (token == 'a' && stack[top] == 'E') {

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d4  p4  ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push(token);
        producoes[cont] = 4;
        arvore(producoes[cont]);
        ++cont;

    //d5| p5
    } else if (token == 'b' && stack[top] == 'E') {

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d5  p5  ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push(token);
        producoes[cont] = 5;
        arvore(producoes[cont]);
        ++cont;

    //d6| p6
    } else if (token == 'c' && stack[top] == 'E') {

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d6  p6  ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push(token);
        producoes[cont] = 6;
        arvore(producoes[cont]);
        ++cont;

    //d7| p7
    } else if (token == '+' && stack[top] == 'X') {

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d7  p7  ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push(token);
        producoes[cont] = 7;
        arvore(producoes[cont]);
        ++cont;

    //d8| p8
    } else if (token == '-' && stack[top] == 'X') {

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d8  p8  ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;  

        pop();
        push(token);
        producoes[cont] = 8;
        arvore(producoes[cont]);
        ++cont;

    //d9| p9
    } else if (token == '*' && stack[top] == 'X') {

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d9  p9  ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push(token);
        producoes[cont] = 9;
        arvore(producoes[cont]);
        ++cont;

    //d10| p10
    } else if (token == '/' && stack[top] == 'X') {

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d10 p10  ");

        printf("    s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push(token);
        producoes[cont] = 10;
        arvore(producoes[cont]);
        ++cont;

    //d11
    } else if (token=='a' && stack[top]=='a'){

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d11 --  ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';

    //d12
    } else if (token=='b' && stack[top]=='b'){

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d12 --  ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;
      
        pop();
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';

    //d13
    }else if (token=='c' && stack[top]=='c'){

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d13 --  ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;
      
        pop();
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';

    //d14
    } else if (token=='0' && stack[top]=='0'){

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d14 --  ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;
      
        pop();
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';

    //d15
    } else if (token=='1' && stack[top]=='1'){

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d15 --  ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';

    //d16
    } else if (token=='(' && stack[top]=='('){

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d16 --  ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';

    //d17
    } else if (token==')' && stack[top]==')'){

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d17 --  ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';

    //d18
    } else if (token=='+' && stack[top]=='+'){

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d18 --  ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';

    //d19
    } else if (token=='-' && stack[top]=='-'){

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d19 --  ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';

    //d20
    } else if (token=='*' && stack[top]=='*'){

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d20 --  ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';

    //d21
    } else if (token=='/' && stack[top]=='/'){

        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("        d21 --  ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';

    } else if (token == EOF) {

        push(' ');
      
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("    --  -- ");

        printf("           s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;
      

        //print da arvore
        printf("\n\n=== ARVORE DE ANALISE SINTATICA ===\n\n");
        for(int j=0; j<ARVORE_SIZE; j++){
            if(arv[j] != ' '){
                printf("[%d] ", j);
                printf("%c \n", arv[j]);
            }
        }

        arvoreBinaria(arv);
        printf("\n\n=== ARVORE DE ANALISE SINTATICA EM BINÁRIO ===\n\n");
        for (int i = 0; i < y; i++) {
            if (arvBin[i] != ' ') {
                printf("[%d] ", i);
                printf("%c \n", arvBin[i]);
            }
        }

        postOrder(arvBin, 0);
        printf("\n\n=== NOTAÇÃO POLONESA ===\n\n");
        printf("%s\n", notPolonesa);
        
        printf("\n\n=== CÓDIGO P-CODE === \n\n");
        nprToPCode(notPolonesa);

        fclose(fp);
        return 0;
      
    }else {
        printf("\nErro!\n");
        goto fim;
      
    }
    goto q1;

fim:
      fclose(fp);
      return 0;
}
