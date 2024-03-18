#include "stack.h"

int main () {
        int tam = 6;
        Stack* s = create (tam);
        Stack* aux = create(tam)
        srand(time(NULL));
        int i;

  //preenche s
        for (i = 0; i < tam; i++) {
                push (s, rand()%10);
        }
        print (s);
        //tira aos pares e coloca os impares na fila auxilia
        while(!empty(s)){
                int e = pop (s);
                if( e % 2 != 0){
                        push(aux, e);
                }
        //
        while (!empty(aux)){
                push(s, pop(aux));
        //e_aux = pop(aux);
        //push(s, e_aux);
        }
        print(s);
        destroy(s);
        destroy(aux);

}
