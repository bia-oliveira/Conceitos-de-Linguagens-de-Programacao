  #include <stdio.h>

  #define amax 2047 
  #define levmax 3  
  #define cxmax 200  

  typedef enum {LIT, OPR, LOD, STO, CAL, INT, JMP, JPC} fct;

  typedef struct {
      fct f;
      int l;
      int a;
  } instruction;

  instruction code[cxmax + 1] = {{INT, 0, 5}, //Reserva espaço na pilha para 5 variáveis locais
                                 {LIT, 0, 0}, // Empilha o valor 0
                                 {STO, 0, 4}, // Armazena o valor 0 na variável 4          
                                 {LIT, 0, 0}, // Empilha o valor 0
                                 {STO, 0, 3}, // Armazena o valor 0 na variável 3
                                 {LIT, 0, 1}, // Empilha o valor 1
                                 {LOD, 0, 3}, // Carrega o valor da variável 3 no topo da pilha
                                 {OPR, 0, 2}, // Realiza a operação de soma
                                 {STO, 0, 3}, // Armazena o resultado na variável 3
                                 {LOD, 0, 3}, // Carrega o valor da variável 3 no topo da pilha
                                 {LOD, 0, 3}, // Novamente carrega o valor da variável 3 no topo da pilha
                                 {OPR, 0, 4}, // Realiza a operação de mulitplicação
                                 {LOD, 0, 4}, // Carrega o valor da variável 4 no topo da pilha
                                 {OPR, 0, 2}, // Realiza a operação de soma
                                 {STO, 0, 4}, // Armazena o resultado na variável 4
                                 {LIT, 0, 100}, // Empilha o valor 100
                                 {LOD, 0, 3}, // Carrega o valor da variável 3 no topo da pilha
                                 {OPR, 0, 3}, // Realiza a operação de subtração
                                 {JPC, 0, 20}, // Pula para a linha 18
                                 {JMP, 0, 5}, // Pula para a linha 5   
                                 {OPR, 0, 0}}; // Encerrar programa

  int base(int l, int b, int *s) {
    int b1 = b;
    while (l > 0) {
        b1 = s[b1];
        l--;
    }
    return b1;
}

  void interpretacao(){
      const int stacksize = 500;
      int p, b, t; 
      instruction i; 
      int s[stacksize]; 
      const char *nomes_instrucoes[] = {"LIT", "OPR", "LOD", "STO", "CAL", "INT", "JMP", "JPC"};

      printf("Iniciar PL/0\n");
      t = 0;
      b = 1;
      p = 0;
      s[1] = 0;
      s[2] = 0;
      s[3] = 0;

  printf("inst:\tp:\t\tb:\t\tt:\t\ts[1]:\t\ts[2]:\t\ts[3]:\t\ts[4]:\t\ts[5]:\t\ts[6]:\t\ts[7]: \n");
  
printf("=============================================================================================================\n");

      do {
          i = code[p];
          p++;

          switch (i.f) {
              case LIT:
                  t++;
                  s[t] = i.a;
                  break;
              case OPR:
                  switch (i.a) {
                      case 0: t = b - 1; p = s[t + 3]; b = s[t + 2]; break;
                      case 1: s[t] = -s[t]; break;
                      case 2: t--; s[t] = s[t] + s[t + 1]; break;
                      case 3: t--; s[t] = s[t] - s[t + 1]; break;
                      case 4: t--; s[t] = s[t] * s[t + 1]; break;
                      case 5: t--; s[t] = s[t] / s[t + 1]; break;
                      case 6: s[t] = s[t] % 2; break;
                      case 8: s[t] = (s[t] == s[t + 1]) ? 1 : 0; t--; break; 
                      case 9: s[t] = (s[t] != s[t + 1]) ? 1 : 0; t--; break; 
                      case 10: s[t] = (s[t] < s[t + 1]) ? 1 : 0; t--; break; 
                      case 11: s[t] = (s[t] >= s[t + 1]) ? 1 : 0; t--; break; 
                      case 12: s[t] = (s[t] > s[t + 1]) ? 1 : 0; t--; break; 
                      case 13: s[t] = (s[t] <= s[t + 1]) ? 1 : 0; t--; break; 
                  } 
                  break;
              case LOD:
                  t++;
                  s[t] = s[base(i.l, b, s) + i.a]; 
                  break;
              case STO:
                  s[base(i.l, b, s) + i.a] = s[t];
                  //printf("%d\n", s[t]);
                  t--;
                  break;
              case CAL:
                  s[t + 1] = base(i.l, b, s);
                  s[t + 2] = b;
                  s[t + 3] = p;
                  b = t + 1;
                  p = i.a;
                  break;
              case INT:
                  t += i.a;
                  break;
              case JMP:
                  p = i.a;
                  break;
              case JPC:
                  if (s[t] == 0)
                      p = i.a;
                  t--;
                  break;
          }
        printf("%s\t\t%d\t\t%d\t\t%d",nomes_instrucoes[i.f], p, b, t);
        for (int j = 1; j <= t; j++) {
            printf("\t\t %d\t",s[j]);
        }

        printf("\n");
      } while (p != 0);

      printf("Fim PL/0\n");
  }

  int main() {
      interpretacao();
      return 0;
  }
