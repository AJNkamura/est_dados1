#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void reversed_polish_notation (char *c) {
        Stack *s = create(strlen(c));
        Stack *aux = create(strlen(c));
        char vetor[strlen(c)];
        int i = 0;
        char elem;
        //enquanto n chegar no elemento terminal
        while (c[i] != '\0') {
                elem = pop(s);

                //se o elemento em peek for um sinal, empilha ele na stack auxiliar
                if (elem >= 42 && elem <= 47){
                        push (aux, elem);
                }
                //se for um numero, coloco no vetor
                else if (elem >= '0' && elem <= '9'){








        i++;
        }
        printf("\n");
        destroy(s);
}

int main () {
        char *c = "( 9 + ( ( 0 + 1 ) * ( 2 * 3 ) ) )";
        reversed_polish_notation (c);
        return 0;
}

