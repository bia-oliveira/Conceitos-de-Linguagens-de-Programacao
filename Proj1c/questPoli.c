// p-code.cpp :  cpp.sh
//
// C conventions
// 0 == FALSE
//
#include <stdio.h>

#define levmax 3
#define amax 2047

typedef enum {LIT, OPR, LOD, STO, CAL, INT, JMP, JPC} fct;

typedef struct tinstruction {
     fct    f;
     int    l; // l: 0..levmax; // Level buffer
     int    a; // a: 0..amax;   // Address buffer
}instruction;

instruction code[2048];

//procedure interpret;
// const stacksize = 500;

#define stacksize 5012

 // p, b, t: integer; {program-, base-, topstack-registers}
 int p, // program-register
     b, // base-register
     t; // topstack-register

instruction i;            //: instruction; {instruction register}
int         s[stacksize]; //: array [1..stacksize] of integer; {datastore}

int base(int l){ //l: integer)
 int b1; //

 b1 = b; // {find base l levels down}
 while (l > 0) {
    b1 = s[b1];
    l  = l - 1;
 }
 return b1;
}//end-int-base

// Determina se seu argumento é impar
int odd(int x){ return (  ((x%2)==1) ); }

void pcodevhw(){ // begin 
 printf("\n start pl/0");
  printf("\n p   b   t     f   l   a                0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18");
 printf("\n === === ===   === === ===             === === === === === === === === === === === === === === === === === === ==="); 
 t = -1; // topstack-register
 b = 0;  // base-register
 p = 0;  // program-register

 // OBS: s[0] must not be used
 s[1] = 0; 
 s[2] = 0; 
 s[3] = 0;

 do {
  i = code[p];
  //printf("\n %3d %3d %3d - %3d %3d %3d", p, b, t, i.f, i.l, i.a);
  printf("\n %3d %3d %3d   ", p, b, t);
  p = p + 1;
 // switch case i.f-BEGIN
  switch  (i.f) { // with i do case f of
    case LIT : { t = t + 1; s[t] = i.a; printf("LIT %3d %3d", i.l, i.a); } break;
    case OPR :
               printf("OPR %3d %3d", i.l, i.a);
//             switch case i.a-BEGIN
               switch (i.a) { // case a of {operator}
                 case  0: { // return
                            t = b - 1; 
                            p = s[t + 3]; 
                            b = s[t + 2];
                          }
                          break;

                 case  1: { //
                            s[t] = -s[t];
                          }
                          break;

                 case  2: { //  ADD     : PUSH( POP()+POP() )
                            t    = t - 1; 
                            s[t] = s[t] + s[t + 1];
                          }
                          break;

                 case  3: { // SUBSTRACT: PUSH( POP()-POP() )
                            t    = t - 1; 
                            s[t] = s[t] - s[t + 1];
                          }
                          break;

                 case  4: { // MULTIPLY: PUSH( POP()*POP() )
                            t    = t - 1; 
                            s[t] = s[t] * s[t + 1];
                          }
                          break;

                 case  5: { // DIVIDE  : PUSH( POP()/POP() )
                            t    = t - 1; 
                            s[t] = s[t] / s[t + 1];
                          }
                          break;

                 case  6: { // 
                            s[t] = odd(s[t]); //s[t] = ord(odd(s[t]));
                          }
                          break;

                 case  8: { // EQUAL
                            t    = t - 1; 
                            s[t] = (s[t] == s[t + 1]);
                          }
                          break;

                 case  9: { // NOT.EQUAL
                            t    = t - 1; 
                            s[t] = (s[t] != s[t + 1]);
                          }
                          break;

                 case 10: { // LESS THAN
                            t    = t - 1; 
                            s[t] = (s[t] < s[t + 1]);
                          }
                          break;

                 case 11: { // GREATER EQUAL THAN
                            t    = t - 1; 
                            s[t] = (s[t] >= s[t + 1]);
                          }
                          break;

                 case 12: { // GREATER THAN
                            t = t - 1; 
                            s[t] = (s[t] > s[t + 1]);
                          }
                          break;

                 case 13: { // LESS EQUAL THAN
                            t    = t - 1; 
                            s[t] = (s[t] <= s[t + 1]);
                          }
                          break;
               } // end;
//         switch case i.a-END
           break;

   case LOD : { // LOAD
                printf("LOD %3d %3d", i.l, i.a);
                t    = t + 1; 
                s[t] = s[base(i.l) + i.a];
              }
              break;

   case STO : { // STORE
                printf("STO %3d %3d", i.l, i.a);
                s[base(i.l)+i.a] = s[t]; 
                t            = t - 1;
              }
              break;

   case CAL :
              { // {generate new block mark}
                printf("CAL %3d %3d", i.l, i.a);
                s[t + 1] = base(i.l); 
                s[t + 2] = b; 
                s[t + 3] = p;
                b        = t + 1; 
                p        = i.a;
              }
              break;

   case INT : t = t + i.a;printf("INT %3d %3d", i.l, i.a); break;
   case JMP : p = i.a;    printf("JMP %3d %3d", i.l, i.a); break;
   case JPC : if (s[t] != 0) { p = i.a; }  t = t - 1; printf("JPC %3d %3d", i.l, i.a); break;
  } // end {with, case}
  // switch case i.f-END

  // print stack
  printf("      s[] : ");
  for (int h=0; h<=t; h++) { printf(" %3d", s[h]); }
 } while ( p != 0 );

 printf("\n === === ===   === === ===             === === === === === === === === === === === === === === === === === === ==="); 
 printf("\n p   b   t     f   l   a                 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18");
 printf("\n end pl/0");
}//end-void-pcmachine() {interpret};

int main(){

  code[0].f = JMP; code[0].l = 0; code[0].a = 17; //inicia o programa "chamando" o main

  //funcao "soma"
  code[1].f = INT; code[1].l = 0; code[1].a = 7;
  code[2].f = LOD; code[2].l = 0; code[2].a = 4; //carrega o parametro 1
  code[3].f = LOD; code[3].l = 0; code[3].a = 5; //carrega o parametro 2
  code[4].f = OPR; code[4].l = 0; code[4].a = 2; //soma
  code[5].f = STO; code[5].l = 0; code[5].a = 6; //armazena o resultado na variavel local "resultado"
  code[6].f = LOD; code[6].l = 0; code[6].a = 6;
  code[7].f = STO; code[7].l = 1; code[7].a = 9; //armazena o resultado na variavel local DO MAIN "resultadoSoma"
  code[8].f = OPR; code[8].l = 0; code[8].a = 0;
  
  //funcao "multi"
  code[9].f = INT; code[9].l = 0; code[9].a = 7;
  code[10].f = LOD; code[10].l = 0; code[10].a = 5; //carrega o parametro 1
  code[11].f = LOD; code[11].l = 0; code[11].a = 4; //carrega o parametro 2
  code[12].f = OPR; code[12].l = 0; code[12].a = 4; //multiplica
  code[13].f = STO; code[13].l = 0; code[13].a = 6; //armazena o resultado na variavel local "resultado"
  code[14].f = LOD; code[14].l = 0; code[14].a = 6;
  code[15].f = STO; code[15].l = 1; code[15].a = 8; //armazena o resultado na variavel local DO MAIN "resultadoMulti"
  code[16].f = OPR; code[16].l = 0; code[16].a = 0;

  //funcao "main"
  code[17].f = INT; code[17].l = 0; code[17].a = 10; //alocando espaço para 9 variáveis
  code[18].f = LIT; code[18].l = 0; code[18].a = 1; 
  code[19].f = STO; code[19].l = 0; code[19].a = 4; //a = 1
  code[20].f = LIT; code[20].l = 0; code[20].a = 2;
  code[21].f = STO; code[21].l = 0; code[21].a = 5; //b = 2
  code[22].f = LIT; code[22].l = 0; code[22].a = 3;
  code[23].f = STO; code[23].l = 0; code[23].a = 6; //c = 3
  code[24].f = LIT; code[24].l = 0; code[24].a = 4;
  code[25].f = STO; code[25].l = 0; code[25].a = 7; //x = 4
  //x^2
  code[26].f = LOD; code[26].l = 0; code[26].a = 7; //passando como parametro a variavel "x" para a funcao "multi"
  code[27].f = STO; code[27].l = 0; code[27].a = 14; 
  code[28].f = LOD; code[28].l = 0; code[28].a = 7; //passando novamente o "x"
  code[29].f = STO; code[29].l = 0; code[29].a = 15;
  code[30].f = CAL; code[30].l = 0; code[30].a = 9; //chamando a funcao "multi"
  //a*x^2
  code[31].f = LOD; code[31].l = 0; code[31].a = 4; //passando como parametro a variavel "a" para a funcao "multi"
  code[32].f = STO; code[32].l = 0; code[32].a = 14; 
  code[33].f = LOD; code[33].l = 0; code[33].a = 8; //passando a variavel "resultadoMulti" que guarda x^2
  code[34].f = STO; code[34].l = 0; code[34].a = 15;
  code[35].f = CAL; code[35].l = 0; code[35].a = 9; //chamando a funcao "multi"
  //Guardando o primeiro parametro da funcao "soma" (a*x^2)
  code[36].f = LOD; code[36].l = 0; code[36].a = 8;
  code[37].f = STO; code[37].l = 0; code[37].a = 9;
  //b*x
  code[38].f = LOD; code[38].l = 0; code[38].a = 5; //passando como parametro a variavel "b" para a funcao "multi"
  code[39].f = STO; code[39].l = 0; code[39].a = 14; 
  code[40].f = LOD; code[40].l = 0; code[40].a = 7; //passando o "x"
  code[41].f = STO; code[41].l = 0; code[41].a = 15;
  code[42].f = CAL; code[42].l = 0; code[42].a = 9; //chamando a funcao "multi"
  //Usando a função "soma" para calcular a*x^2 + b*x
  code[43].f = LOD; code[43].l = 0; code[43].a = 9;
  code[44].f = STO; code[44].l = 0; code[44].a = 14;
  code[45].f = LOD; code[45].l = 0; code[45].a = 8;
  code[46].f = STO; code[46].l = 0; code[46].a = 15;
  code[47].f = CAL; code[47].l = 0; code[47].a = 1; //chamando a funcao "soma"
  //finalmente calculando a*(x^2) + b*x + c
  code[48].f = LOD; code[48].l = 0; code[48].a = 6; //passando como parametro a variavel "c" para a funcao "soma"
  code[49].f = STO; code[49].l = 0; code[49].a = 14; 
  code[50].f = LOD; code[50].l = 0; code[50].a = 9; //passando a variavel "resultadoSoma" que guarda a*x^2 + b*x
  code[51].f = STO; code[51].l = 0; code[51].a = 15;
  code[52].f = CAL; code[52].l = 0; code[52].a = 1; //chamando a funcao "soma"
  code[53].f = OPR; code[53].l = 0; code[53].a = 0;

  pcodevhw();
  return 0;
}

