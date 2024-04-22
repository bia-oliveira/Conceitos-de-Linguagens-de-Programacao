#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Classes de caracteres */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99
/* Códigos de tokens */
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

/* Declarações globais */
int charClass;
char lexeme[100];
char nextChar;
int lexLen;
int token;
int nextToken;
FILE *in_fp, *fopen();
typedef struct {char *producoes;} Arvore;
Arvore a[1000];


/* Funções de Declarações */
void addChar();
void getChar();
void getNonBlank();
int lex();
void expr(int index);
void term(int index);
void factor(int index);
int lookup(char ch); 

void imprimirArvore(Arvore arvore[], int tamanho) {
    printf("+--------------+--------------+--------------+\n");
    printf("|  esq(i) 3i+1 |  esq(i) 3i+2 |  dir(i) 3i+3 |\n");
    printf("+--------------+--------------+--------------+\n");

    printf("| %-12s |              |              |\n", arvore[0].producoes);
  
    for (int i = 1; i < tamanho; i += 3) {
        if(strcmp(a[i].producoes, " ") != 0 ||
         strcmp(a[i + 1].producoes, " ") != 0 ||
         strcmp(a[i + 2].producoes, " ") != 0){
          printf("| %-12s | %-12s | %-12s |\n", 
              arvore[i].producoes, 
              arvore[i + 1].producoes, 
              arvore[i + 2].producoes);
         }
    }

    printf("+--------------+--------------+--------------+\n");
}

/* Função principal */
int main() {
    int idxArvore = 0;

    if ((in_fp = fopen("front.in", "r")) == NULL) {
        printf("ERROR - cannot open front.in \n");
    } else {
        getChar();
        do {
            for(int i=0; i<1000; i++){
                a[i].producoes = " ";
            }
          
            lex();
            a[idxArvore].producoes = "<expr>";
            expr(idxArvore);

        
        } while (nextToken != EOF);
    }  

    return 0;
}

/* Função para adicionar próximo caractere ao lexema */
void addChar() {
    if (lexLen <= 98) {
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = 0;
    } else {
        printf("Erro - lexema é muito longo \n");
    }
}

/* Função para obter o próximo caractere da entrada e determinar sua classe de caracteres */
void getChar() {
    if ((nextChar = getc(in_fp)) != EOF) {
        if (isalpha(nextChar)) {
            charClass = LETTER;
        } else if (isdigit(nextChar)) {
            charClass = DIGIT;
        } else {
            charClass = UNKNOWN;
        }
    } else {
        charClass = EOF;
    }
}

/* Função para chamar getChar até que ela retorne um caractere diferente de espaço em branco */
void getNonBlank() {
    while (isspace(nextChar)) {
        getChar();
    }
}

/* Analisador léxico simples para expressões aritméticas */
int lex() {
    lexLen = 0;
    getNonBlank();
    switch (charClass) {
        case LETTER:
            addChar();
            getChar();
            while (charClass == LETTER || charClass == DIGIT) {
                addChar();
                getChar();
            }
            nextToken = IDENT;
            break;
        case DIGIT:
            addChar();
            getChar();
            while (charClass == DIGIT) {
                addChar();
                getChar();
            }
            nextToken = INT_LIT;
            break;
        case UNKNOWN:
            lookup(nextChar);
            getChar();
            break;
        case EOF:
            nextToken = EOF;
            lexeme[0] = 'E';
            lexeme[1] = 'O';
            lexeme[2] = 'F';
            lexeme[3] = 0;
            break;
    }
    printf("Próximo token é: %d, Próximo lexema é %s\n", nextToken, lexeme);
    return nextToken;
}

/* Função para processar operadores e parênteses e retornar o token */
int lookup(char ch) {
    switch (ch) {
        case '(':
            addChar();
            nextToken = LEFT_PAREN;
            break;
        case ')':
            addChar();
            nextToken = RIGHT_PAREN;
            break;
        case '+':
            addChar();
            nextToken = ADD_OP;
            break;
        case '-':
            addChar();
            nextToken = SUB_OP;
            break;
        case '*':
            addChar();
            nextToken = MULT_OP;
            break;
        case '/':
            addChar();
            nextToken = DIV_OP;
            break;
        case ';':
            printf("\nExpressão aceita\n\n");
            break;
        default:
            addChar();
            nextToken = EOF;
            break;
    }
    return nextToken;
}

/* Analisa sintaticamente cadeias na linguagem gerada pela regra: <expr> -> <term> {(+ | -) <term>} */
void expr(int index) {
    printf("Enter <expr>\n");
    a[index*3 + 1].producoes = "<term>";
    term(index*3 + 1); 

    while (nextToken == ADD_OP || nextToken == SUB_OP) {
        if (nextToken == ADD_OP) {
          a[index*3 + 2].producoes = "+";  
        } else {
          a[index*3 + 2].producoes = "-";  
        }
        a[index*3 + 3].producoes = "<term>";

        lex();
        term(index*3 + 3); 
    }

    printf("Exit <expr>\n");
}

/* Analisa sintaticamente cadeias na linguagem gerada pela regra: <term> -> <factor> {(* | /) <factor>} */
void term(int index) {
    printf("Enter <term>\n");
    a[index*3 + 1].producoes = "<factor>";
    factor(index*3 + 1);

    while (nextToken == MULT_OP || nextToken == DIV_OP) {
        if (nextToken == MULT_OP) {
          a[index*3 + 2].producoes = "*";  
        } else {
          a[index*3 + 2].producoes = "/";  
        }
        a[index*3 + 3].producoes = "<factor>";

        lex();
        factor(index*3 + 3); 
    }

    printf("Exit <term>\n");
}

/* Analisa sintaticamente cadeias na linguagem gerada pela regra: <factor> -> id | int_constant | (<expr) */
void factor(int index) {
    printf("Enter <factor>\n");
    if (nextToken == IDENT || nextToken == INT_LIT) {
        a[index*3 + 2].producoes = "id";
        lex(); 
    } else {
        if (nextToken == LEFT_PAREN) {
            a[index*3 + 1].producoes = "(";
            lex();
            a[index*3 + 2].producoes = "<expr>";
            expr(index*3 + 2); 
            if (nextToken == RIGHT_PAREN) {
                a[index*3 + 3].producoes = ")";
                lex(); 
            } else {
                printf("Erro sintático: esperado ')'\n");
            }
        } else {
            printf("Erro sintático: esperado identificador, constante inteira ou '('\n");
        }
    }
    printf("Exit <factor>\n");
}
