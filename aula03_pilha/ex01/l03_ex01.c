#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
        int tam = 6, i;
        Stack* s = create (tam);
        Stack* aux = create(tam);

  //preenche s
        for (i = 0; i < tam; i++) {
                push(s, rand()%10);
        }
        //printa a pilha original
        print (s);

        //tira os pares e coloca os impares na pilha auxiliar
        while(!empty(s)){
                //tira e salva o elemento de cima
                int e = pop (s);
                //se ele for impar,coloca na pilha auxiliar
                if( e % 2 != 0){
                        push(aux, e);
                        print(aux);
                }
        }
        //re-oderna a pilha s tirando e colocando os elementos de aux em s
        while (!empty(aux)){
                push(s, pop(aux));
	}
}
