#include "stack.h"

Stack* create () {
  return NULL;
}

void destroy (Stack *s) {
  while (s != NULL) {
        Stack *t = s->next;
        free (s);
        s = t;

  }	  
}

Stack* push (Stack *s, int elem) {


}

Stack* pop (Stack *s) {
  /*Terminar*/
  /*Remove o elemento (free) do início da lista.*/	
}

int get_peek (Stack *s) {
  /*Terminar*/
  /*Retorna a informação (data) armazenada no início da lista.*/	
}

int empty (Stack *s) {
  /*Terminar*/
}

void print (Stack *s) {
  /*Terminar*/
}
