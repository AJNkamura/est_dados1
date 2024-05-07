
/* Escreva uma funcao que retorna verdadeiro se uma sequencia de parenteses e/ou              colchetes em uma string c esta “bem formada” (ou seja, parenteses e colchetes sao fechados na ordem                                                                                         inversa `aquela em que foram abertos), ou falso caso contrario. A ideia é empilhar "(" e "[" ,que abrem, e quando encontrarmos um que fecha, verificar se ele bate encaixa com o topo da pilha*/

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int parser (char *c) {
  Stack* s = create(strlen(c));
  int i = 0;

  while (c[i] != '\0'){
        //se for um que abre -> empilho
        if (c[i] == '(' || c[i] =='['){
                push (s, c[i]);
        }

        //se for um que fecha:
        //se for ']' verificamos sea pilha n esta vazia E se o elemento n se encaixa
        else if (c[i] ==']'){
                if (empty(s) || pop(s) == '('){
                        return 0;
                }
        }
        //se for ')' verifica se a pilha n esta vazia E se o elemento n se encaixa
        else if (c[i] ==')'){
                if (empty(s)||pop(s) == '['){
                        return 0;
                }
        }
  i++;
  }

        //a string so vai ser bem formada quando os pares se anularem e a pilha ficar vazia
        if(empty(s))
                return 1;
        else
                return 0;
}
int main () {
   char *c = "( ( ) [ ( ) ] )";
  //char *c = "( [ ) ]";
  //char *c = "( ) [ ]";
  //char *c = "( [ ]";
  //char *c = ") (";
  if (parser(c))
    printf("true  (bem formada)\n");
  else
    printf("false (mal formada)\n");
  return 0;
}


