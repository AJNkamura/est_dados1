#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void reversed_polish_notation (char *c){
        Stack *s = create(strlen(c));
        Stack *aux = create(strlen(c));
        Stack *polish = create(strlen(c));
        int i = 0;
        char elem;
        //enquanto nao chegar no elemento terminal
        while (get_peek(s) != '\0' && !empty) {
		//analisando o elemento do topo
                elem = get_peek(s);
		printf("%char", elem);
                //se o elemento em peek for um sinal, empilha ele na stack auxiliar
                if (elem >= 42 && elem <= 47){
		      	push (aux, elem);
                }
                //se for um numero, coloco na pilha
                else if (elem >= '0' && elem <= '9'){
			push (polish, elem);
		}
		//se for um ')' ele tira o peek da pilha auxiliar e coloca na pilha polish
		else if (elem == ')'){
		//	pop (aux);
			push (polish, elem);
		}
	i++;
	}

	print(polish);
	printf("\n");
	destroy(s);
	destroy(aux);
	destroy(polish);
	
}

int main () {
        char *c = "( 9 + ( ( 0 + 1 ) * ( 2 * 3 ) ) )";
        reversed_polish_notation (c);
        return 0;
}

