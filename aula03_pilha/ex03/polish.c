#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void reversed_polish_notation (char *c){
        Stack *s = create(strlen(c));
        Stack *aux = create(strlen(c));
        int i = 0;
        char elem;
        //enquanto nao chegar no elemento terminal
        while (c[i] != '\0') {
		elem = c[i];
                //se o elemento em peek for um sinal, empilha ele na stack auxiliar
                if (elem >= '0' && elem <= '9'){
		      	printf("%c", c[i]); 
                }
                //se for um abre, tira da pilha principal
                else if (elem >= 42 && elem <= 47){
			push(s, c[i]);
		}
		//se for um ')' ele tira o peek da pilha auxiliar e coloca na pilha polish
		else if (elem == ')'){
			printf ("%c", pop(s));
		}
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

